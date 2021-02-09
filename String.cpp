#include "String.h"
#include <iostream>

String::String()
{
    element = nullptr;
    string_size = 0;
}

String::String(const String &object)
{
    string_size = object.string_size;
    element = object.element;
}

String::Size(char* object)
{
    int string_size = 0;
    while (object[string_size] != '\0')
    {
        string_size += 1;
    }
    return string_size;
}

String::String(char* object)
{
    element = object;
    string_size = Size(object);
}

String::~String()
{
    delete[] element;
}

String::operator=(String &object)
{
    if (this != &object) {
        delete[]element;
        element = object.element;
        string_size = object.string_size;
    }
}

String::operator==(String &object)
{
    int time = 0;
    while (element[time] == object.element[time])
    {
        time += 1;
    }
    if (time == string_size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

