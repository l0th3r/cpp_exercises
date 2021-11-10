#include <iostream>
#include <string>

std::string** hundred_string_pointers()
{
    std::string** cont = new std::string*[100];

    for(int i = 0; i < 100; i++)
    {
        cont[i] = new std::string();
    }

    return cont;
}
