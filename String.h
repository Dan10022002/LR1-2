#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H
#include <iostream>

class String
{
    char* element;
    size_t string_size;
public:
    String(); //1
    String(const String& object); //2
    size_t Size_help(const char* object); 
    explicit String(const char* object); //3
    ~String(); //4
    String operator= (String& object); //5
    bool operator== (String& object); //6
    size_t Size(); //7
    int Find(String& object); //8
    char operator[] (int index); //10
    String operator+(String& object); //11
    String Change(char letter, char needed_letter); //9
    friend std::ostream& operator<<(std::ostream& output, String& object); //12
    friend std::istream& operator>>(std::istream& input, String& object); //12
};

#endif //UNTITLED_STRING_H
