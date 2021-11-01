#include <iostream>
#include <string>
#include <fstream>

void record_fibonnaci(std::string filename, size_t values)
{
    std::fstream f (filename, std::ios::out);

    int i = 0;
    int n = 0;
    int last_one = 0;
    int last_two = 0;

    while(i < values)
    {
        if (i == 0)
        {
            n = 0;
            last_one = 1;
            last_two = 0;
        }
        else
        {
            last_two = last_one;
            last_one = n;
            n = last_one + last_two;
        }

        f << n << std::endl;

        i++;
    }
    f.close();
}