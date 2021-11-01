#include <iostream>
#include <string>
#include <fstream>

bool check_fibonnaci_file(std::string filename)
{
    std::fstream f (filename, std::ios::in);

    // value to return
    bool is_valid = true;

    // temporary string to read file content
    std::string tmp;

    // store values values
    int value = 0;
    int last_one = 1;
    int last_two = 0;

    // main iterator
    int i = 0;

    // loop through file's content
    while(getline(f, tmp) && is_valid == true)
    {
        if(i == 0)
        {
            if(std::stoi(tmp) != 0)
                is_valid = false;
        }
        else if(i == 1)
        {
            if(std::stoi(tmp) != 1)
                is_valid = false;
        }
        else if(std::stoi(tmp) != last_one + last_two)
            is_valid = false;
        else
        {
            last_two = last_one;
            last_one = std::stoi(tmp);
        }

        i++;
    }

    f.close();
    return is_valid;
}
