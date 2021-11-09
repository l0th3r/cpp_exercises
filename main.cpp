#include <iostream>
#include <string>
#include <vector>

std::string conc(std::string str1, std::string str2);

std::string get_million(int value);
std::string get_thousand(int value);
std::string get_hundred(int value);
std::string get_dozen_unit(int dozen, int value);
std::string get_dozen(int value);
std::string get_single(int value);

int main()
{

    return 0;
}

std::string conc(std::string str1, std::string str2)
{
    return str1 + "-" + str2;
}

std::string get_million(int value)
{
    return conc(get_single(value), "million");
}

std::string get_thousand(int value)
{
    if(value == 1)
        return "mille";
    else
        return conc(get_single(value), get_thousand(1));
}

std::string get_hundred(int value)
{
    if(value == 1)
        return "cent";
    else
        return conc(get_single(value), get_hundred(1));
}

std::string get_dozen_unit(int dozen, int value)
{
    if(dozen == 1)
    {
        if(value == 1)
            return "onze";
        else if(value == 2)
            return "douze";
        else if(value == 3)
            return "treize";
        else if(value == 4)
                return "quatorze";
        else if(value == 5)
            return "quinze";
        else if(value == 6)
            return "seize";
        else
            return conc(get_dozen(dozen), get_single(value));
    }
    else
    {
        if(value == 1)
            return conc(get_dozen(dozen), conc("et", get_single(value)));
        else
            return conc(get_dozen(dozen), get_single(value));
    }
}

std::string get_dozen(int value)
{
    switch (value) {
    case 1:
        return "dix";
        break;
    case 2:
        return "vingt";
        break;
    case 3:
        return "trente";
        break;
    case 4:
        return "quarante";
        break;
    case 5:
        return "cinquante";
        break;
    case 6:
        return "soixante";
        break;
    case 7:
        return conc(get_dozen(6), get_dozen(1));
        break;
    case 8:
        return  conc(get_single(4), get_dozen(2));
        break;
    case 9:
        return conc(get_single(4), conc(get_dozen(2), get_dozen(1)));
        break;
    default:
        return "DOZEN_"+ std::to_string(value) + "_ERR";
        break;
    }
}

std::string get_single(int value)
{
    switch (value) {
    case 1:
        return "un";
        break;
    case 2:
        return "deux";
        break;
    case 3:
        return "trois";
        break;
    case 4:
        return "quatre";
        break;
    case 5:
        return "cinq";
        break;
    case 6:
        return "six";
        break;
    case 7:
        return "sept";
        break;
    case 8:
        return "huit";
        break;
    case 9:
        return "neuf";
        break;
    default:
        return "SINGLE_"+ std::to_string(value) + "_ERR";
        break;
    }
}
