#ifndef UNTITLED_STRING_H
#define UNTITLED_STRING_H


class String
{
public:
    char* element;
    int string_size;
    String ();
    String (const String &object);
    int Size (char* object);
    explicit String (char* object);
    ~String();
    operator= (String &object);
    bool operator== (String &object);
};


#endif //UNTITLED_STRING_H
