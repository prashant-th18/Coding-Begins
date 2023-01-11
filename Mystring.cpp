#include "Mystring.h"
// #include <iostream>
#include <cstring>

// this is a pointer to the object str can be written as this ->str!!!!!
// cant return this!!
// see the diagram in

// copy assignment!!
Mystring &Mystring ::operator=(const Mystring &rhs)
{
    std::cout << "Copy assignment is called!!!" << std::endl;
    if (this == &rhs)
        return *this;

    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcmp(str, rhs.str);
    return *this;
}

// getters
// displaying the string
void Mystring ::display() const
{
    std::cout << str << ":" << get_length << std::endl;
}

// getting the length
int Mystring::get_length() const
{
    return std::strlen(str);
}

// getting the string
const char *Mystring::get_str() const
{
    return str;
}

// no arg constructor
Mystring ::Mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
Mystring ::Mystring(const char *s) : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// copy constructor
Mystring ::Mystring(const Mystring &source) : str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// destructor
Mystring ::~Mystring()
{

    delete[] str;
    std::cout << "destructor is called!!!" << std::endl;
}