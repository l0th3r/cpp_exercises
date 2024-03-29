#include <iostream>
#include <string>
#include <fstream>

void print_fibonnaci(int first, int last, std::string file)
{
    std::fstream f (file, std::ios::app | std::ios::in);

    // temporary string to read file content
    std::string tmp;

    // main iterator
    int i = 0;

    // store values values
    uint value = 0;
    uint last_one = 0;
    uint last_two = 0;

    // loop through file's content
    while(getline(f, tmp) && i <= last)
    {
        last_one = value;
        value = std::stoi(tmp);

        if(i >= first)
            std::cout << value << std::endl;

        i++;
    }

    f.clear();

    // if the file doest content all wanted values, complete the file
    while(i <= last)
    {
        if(i == 1)
            value = 1;
        else
        {
            last_two = last_one;
            last_one = value;
            value = last_one + last_two;
        }

        f << value << std::endl;

        if(i >= first)
            std::cout << value << std::endl;

        i++;
    }

    f.close();
}
