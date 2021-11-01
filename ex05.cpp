#include <iostream>
#include <string>

std::string** hundred_string_pointers()
{
    return new std::string*[100];
}
