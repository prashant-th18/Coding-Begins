#ifndef MYSTRING_H_
#define MYSTRING_H_

    class Mystring
    {
      private:
      char *str ; //str is pointer to character that holds a C style string

      public :
      //no arg constructor
      Mystring();
      //overloaded costructor
      Mystring (const char*s);
      //copy constructor
      Mystring (const Mystring &source);
      //copy assignment
      Mystring &operator = (const Mystring &rhs);
      
      
      
         //destructor
      ~Mystring();

      

      //getters
    void display() const;
    int get_length() const;                           // getters
    const char *get_str() const;
    };
#endif