#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H


class String
{
public:
    char* element;
    int string_size;
    String(); //1
    String(const String& object); //2
    int Size(char* object); //7
    explicit String(char* object); //3
    ~String(); //4
    String operator= (String& object); //5
    bool operator== (String& object); //6
    int Find(String& object); //8
    bool Find_help(String& object, int& h, int& time);
    char operator[] (int& index); //10
    String operator+(String& object);
};


#endif //UNTITLED_STRING_H
