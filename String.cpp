#include "String.h"
#include <iostream>

String::String() //1
{
    element = nullptr;
    string_size = 0;
}

String::String(const String& object) //2
{
    string_size = object.string_size;
    element = object.element;
}

int String::Size(char* object) //7
{
    int string_size = 0;
    while (object[string_size] != '\0')
    {
        string_size += 1;
    }
    return string_size;
}

String::String(char* object) //3
{
    element = object;
    string_size = Size(object);
}

String::~String() //4
{
    delete[] element;
}

String String::operator=(String& object) //5
{
    if (this != &object) {
        delete[]element;
        element = object.element;
        string_size = object.string_size;
    }
    return *this;
}

bool String::operator==(String& object) //6
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

bool String::Find_help(String& object, int& h, int& time)
{
    if (element[h] == object.element[time])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int String::Find(String& object) //8
{
    int time = 0;
    int rezult = 0;
    for (int h = 0; h <= (string_size - object.string_size); h++)
    {
        if (Find_help(object, h, time) == true)
        {
            time += 1;
            if (rezult == 0)
            {
                rezult = h;
            }
            if (time == object.string_size)
            {
                return rezult;
            }
        }
        else
        {
            if (time != 0)
            {
                time = 0;
            }
            if (rezult != 0)
            {
                rezult = 0;
            }
            if (Find_help(object, h, time) == true)
            {
                time += 1;
                rezult = h;
            }
        }
    }
    return -1;
}

char String::operator[] (int& index) //10
{
    return element[index];
}

String String::operator+(String& object)
{
    for (int h = 0; h < object.string_size; h++)
    {
        element[string_size + h] = object.element[h];
    }
    string_size += object.string_size;
    return *this;
}
