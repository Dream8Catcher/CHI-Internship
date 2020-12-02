
/*class Тхt, который управляет динамически выделяемым массивом строк.
При создании экземпляра класса Тхt объект ничего не получает или получает ссылку на неизменяемую строку.
Если файл не существует, объект Тхt принимает безопасное пустое состояние.
Если файл существует, конструктор с одним аргументом выделяет память для количества строк,
содержащихся в файле, и копирует их в память.

Класс Тхt включает следующие функции-члены:
• конструктор копирования;
• оператор присваивания копий;
• конструктор перемещения;
• оператор присваивания перемещения;
• деструктор;
• функция-член с именем size_t size () const, которая возвращает количество записей текстовых данных;
Определите свой класс и его реализацию в пространстве имен l1.
Сохраните определение класса в файле заголовка с именем Txt.h, а
определения функций-членов - в файле реализации с именем Txt.cpp.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Txt.h"

// default constructor
l1::Txt::Txt() {
    m_data = nullptr;
    m_length = 0;
    capacity = 150;
}

// constructor with the name of the file
l1::Txt::Txt( std::string fileName) :Txt() {
    std::ifstream file(fileName, std::ios::in);
    if (file.is_open() && file.good())
    {
        std::string line;
        while(!file.eof())
        {
            std::getline(file, line);
            add(line);
        }
        file.close();
        shrink_to_fit();
    }
    else
        std::cout << "Failed to open file \"" << fileName << "\"" << std::endl;
}

// copy constructor
l1::Txt::Txt(const Txt& src) {
    m_data = new std::string [src.capacity];
    for (size_t i = 0; i < src.m_length; ++i)
        m_data[i] = src.m_data[i];
    capacity = src.capacity;
    m_length = src.m_length;
}

// assignment constructor
l1::Txt& l1::Txt::operator = ( const Txt& src) {
    if (&src == this)
        return *this;
    delete[] m_data;
    m_data = new std::string[src.capacity];
    if (src.m_data)
    {
        for (size_t i = 0; i < src.m_length; ++i)
            m_data[i] = src.m_data[i];
    }
    capacity = src.capacity;
    m_length = src.m_length;
    return *this;
}

// move constructor
l1::Txt::Txt( Txt&& src) noexcept : m_data(src.m_data), m_length(src.m_length), capacity(src.capacity) {
    src.m_data = nullptr;
}

// assignment move constructor
l1::Txt& l1::Txt::operator = (Txt&& src) noexcept {
    if (&src == this)
        return *this;

    if (m_length > 0)
        delete[] m_data;
    m_data = src.m_data;
    src.m_data = nullptr;

    return *this;
}

// destructor
l1::Txt::~Txt(){
    if (m_length > 0)
        delete[] m_data;
}

void l1::Txt::resize () {
    capacity = capacity << 1u;
    std::string* new_data = new std::string[capacity];
    for (size_t i = 0; i < m_length; ++i)
        new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
}

void l1::Txt::shrink_to_fit() {
    std::string* new_data = new std::string[m_length];
    for (size_t i = 0; i < m_length; ++i)
        new_data[i] = m_data[i];
    delete[] m_data;
    m_data = new_data;
    capacity = m_length;
}

void l1::Txt::add(std::string item) {
    if (!m_data){
        m_data = new std::string[capacity];
    }
    if (m_length == capacity)
        resize();
    m_data[m_length] = item;
    ++m_length;
}

void l1::Txt::clear() {
    delete[] m_data;
}

void l1::Txt::show() const {
    for (size_t i = 0; i < m_length; ++i)
        std::cout << m_data[i] << std::endl;
}