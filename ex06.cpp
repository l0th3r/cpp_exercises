#include <iostream>
#include <string>

void free_hundred_strings(std::string** arr)
{
    for(int i=0; i<100; i++)
    {
        delete arr[i];
    }
    delete arr;
}