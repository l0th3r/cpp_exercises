#include <iostream>
#include <string>

std::string* sequence_as_strings(int start, int end)
{
    std::string* str;
    int range = end - start;
    start > end ? range = -range + 1 : range += 1;

    str = new std::string[range];

    int r = 0;
    while(r < range)
    {
        int valeur;
        start > end ? valeur = -(r + -start) : valeur = r + start;
        str[r++] = valeur;
    }

    return str;
}
