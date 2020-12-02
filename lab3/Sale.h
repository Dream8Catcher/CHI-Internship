#ifndef CLION_SALE_H
#define CLION_SALE_H

#include <ostream>
#include <vector>
#include "Product.h"

namespace sict {
    class Sale{

    public:
        explicit Sale(const char* fileName);
        void display (std::ostream & os) const;
        ~Sale() {
            for (auto item : m_products)
                delete item;
        }
    private:
        std::vector<sict::iProduct*> m_products;
    };
}

#endif //CLION_SALE_H
