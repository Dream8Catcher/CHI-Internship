#ifndef CLION_PRODUCT_H
#define CLION_PRODUCT_H

#include <ostream>
#include <fstream>

extern int FW;

namespace sict {

    class iProduct
    {
    public:
        virtual ~iProduct() = default;
        virtual double price () const = 0;
        virtual void display (std::ostream & os) const = 0;

        static iProduct* readRecord(std::ifstream & file);
        friend std::ostream& operator << (std::ostream & os, const iProduct & p);
    };

    class Product : public iProduct
    {
    public:
        Product()
                : m_id(), m_value() {}
        Product(size_t id, double value)
                : m_id(id), m_value(value)
        {}

        double price () const override;
        void display (std::ostream & os) const override;

    protected:
        size_t m_id;
        double m_value;
    };

    class TaxableProduct : public Product {
    public:
        TaxableProduct(size_t id, double price, char tax)
                : Product(id, price), m_tax(tax)
        {}

        double price () const override;
        void display (std::ostream & os) const override;

    private:
        char m_tax;
    };
}

#endif //CLION_PRODUCT_H
