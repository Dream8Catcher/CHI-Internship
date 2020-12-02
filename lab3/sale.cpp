#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sale.h"

namespace sict {

    Sale::Sale(const char* fileName)
            : m_products()
    {
        std::ifstream file(fileName, std::ios::in);

        file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try {
            while(!file.eof())
            {
                auto* item = iProduct::readRecord(file);
                if (item)
                {
                    m_products.push_back(item);
                }
            }
            file.close();
        }
        catch (std::ifstream::failure& e) {
            std::cout << "Exception opening/reading/closing file \"" << fileName << "\"" << std::endl;
        }
    }

    void Sale::display (std::ostream & os) const {
        os << std::setw(FW) << "Product No" << std::setw(FW) << "Cost" << std::setw(FW) << "Taxable\n";
        double sum = 0;

        for (auto item : m_products)
        {
            item->display(os);
            sum += item->price();
        }

        std::cout << std::setw(FW) << "Total" << std::setw(FW) << sum << std::endl;
    }
}