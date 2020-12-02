#ifndef CLION_TXT_H
#define CLION_TXT_H
#include <string>

// default constructor
namespace l1 {
    class Txt{
        std::string* m_data;
    public:
        size_t m_length;
        size_t capacity;
        // default constructor
        Txt();
        // constructor with the name of the file
        Txt( std::string );
        // copy constructor
        Txt( const Txt& );
        // assignment constructor
        Txt& operator = ( const Txt& );
        // move constructor
        Txt( Txt&& ) noexcept;
        // assignment move constructor
        Txt& operator = ( Txt&& ) noexcept;
        // destructor
        ~Txt();
        size_t size () const { return m_length; }
        void resize ();
        void shrink_to_fit();
        void add(std::string );
        void clear();
        void show() const;
    };
}
#endif //CLION_TXT_H
