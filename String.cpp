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
    element = new char[string_size + 1];
    for (int h = 0; h < object.string_size; h++)
    {
        element[h] = object.element[h];
    }
    element[string_size] = '\0';
}

size_t String::Size_help(const char* object) 
{
    size_t string_size = 0;
    while (object[string_size] != '\0')
    {
        string_size += 1;
    }
    return string_size;
}

String::String(const char* object) //3
{
    string_size = Size_help(object);
    element = new char[string_size + 1];
    for (int h = 0; h < string_size; h++)
    {
        element[h] = object[h];
    }
    element[string_size] = '\0';
}

String::~String() //4
{
    delete[] element;
}

String String::operator=(String& object) //5
{
    if (this != &object) {
        delete[]element;
        string_size = object.string_size;
        element = new char[string_size + 1];
        for (int h = 0; h < string_size; h++)
        {
            element[h] = object[h];
        }
        element[string_size] = '\0';
    }
    return *this;
}

bool String::operator==(String& object) //6
{
    if (object.string_size != string_size)
    {
        return false;
    }
    else
    {
        for (int h = 0; h < string_size; ++h)
        {
            if (element[h] != object.element[h])
            {
                return false;
            }
        }
        return true;
    }
}

size_t String::Size() //7
{
    return string_size;
}

int String::Find(String& object) //8
{
    int time = 0;
    int rezult = -1;
    for (int h = 0; h < string_size; h++)
    {
        if (element[h] == object.element[time])
        {
            time += 1;
            if (rezult == -1)
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
                h = rezult + 1;
                rezult = -1;
            }
        }
    }
    return -1;
}

char String::operator[] (int index) //10
{
    return element[index];
}

String String::operator+(String& object) //11
{
    String rezult;
    rezult.string_size = string_size + object.string_size;
    char* time = new char[rezult.string_size + 1];
    for (int h = 0; h < string_size; h++)
    {
        time[h] = element[h];
    }
    for (int h = string_size; h < rezult.string_size; h++)
    {
        time[h] = object.element[h - string_size];
    }
    time[rezult.string_size] = '\0';
    return rezult;
}

std::ostream& operator<<(std::ostream& output, String& object) //12
{
    for (int h = 0; h < object.string_size; h++)
    {
        output << object.element[h];
    }
    return output;
}

std::istream& operator>>(std::istream& input, String& object) //12
{
    char* time = new char[256];
    input >> time;
    String rezult(time);
    object = rezult;
    delete[] time;
    return input;
}

String String::Change(char letter, char needed_letter) //9
{
    for (int h = 0; h < string_size; h++)
    {
        if (element[h] == letter)
        {
            element[h] = needed_letter;
        }
    }
    return *this;
}
