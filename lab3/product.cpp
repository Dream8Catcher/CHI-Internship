#include <string>
#include <sstream>
#include <iomanip>
#include "Product.h"

namespace sict {
    iProduct* iProduct::readRecord(std::ifstream & file)
    {
        std::string line;
        std::getline(file, line);
        std::stringstream is;
        is.str(line);

        ssize_t id = -1;
        double price = -1.0;
        char tax = 'Q';

        is>> id >> price >> tax;

        if (tax != 'Q')
            return new TaxableProduct(id, price, tax == 'H' ? tax : 'P');

        return new Product(id, price);
    }

    std::ostream& operator << (std::ostream & os, const iProduct & p)
    {
        p.display(os);
        return os;
    }

    double Product::price () const
    {
        return m_value;
    }

    void Product::display (std::ostream & os) const
    {
        os << std::setw(FW) << m_id << std::setw(FW) << m_value << std::endl;
    }

    double TaxableProduct::price () const
    {
        return m_value * (m_tax == 'H' ? 0.13 : 0.08);
    }

    void TaxableProduct::display (std::ostream & os) const
    {
        std::string tax = (m_tax == 'H') ? std::string{"HST"} : std::string{"PST"};
        os << std::setw(FW) << m_id << std::setw(FW) << m_value << ' ' << tax << std::endl;
    }
}