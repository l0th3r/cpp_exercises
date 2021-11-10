#include <iostream>
#include <string>
#include <vector>

std::string get_number_in_french(long lg);

std::string conc(std::string str1, std::string str2);
std::string parse(std::string raw);

bool is_trio_null(std::string trio);
std::string handle_trio(std::string trio);

std::string get_hundred(int value);
std::string get_dozen_unit(int dozen, int value);
std::string get_dozen(int value);
std::string get_single(int value);

int main()
{
    std::cout << get_number_in_french((long)-130325183) << std::endl;
    return 0;
}

std::string get_number_in_french(long lg)
{
    std::string result = "";
    std::string raw = std::to_string(lg);

    int i = 0;

    if(raw[i] == '-')
    {
        result = "moins ";
        raw = raw.substr(1);
    }

    return result + parse(raw);
}

std::string parse(std::string raw)
{
    std::string result = "";

    std::string current_trio;
    int i = 0;
    while(i < raw.length())
    {
        if(i % 3 == 0)
        {
            current_trio = handle_trio(raw.substr(i, 3));

            if(i != 0)
                result = conc(result, current_trio);
            else
                result += current_trio;
        }
        else if(i % 3 == 2)
        {
            std::string definer;

            if(raw.length() - i == 7)
                definer = "million";
            else if(raw.length() - i == 4)
                definer ="mille";
            else
                definer = "";

            for(int j = i; j < raw.length(); j++)
            {
                if(raw[j] != '0')
                    definer += "s";
            }

            if(!is_trio_null(current_trio))
                result = conc(result, definer);
        }

        i++;
    }

    return result;
}

bool is_trio_null(std::string trio)
{
    bool is_null = true;

    for(int i = 0; i < trio.length(); i++)
    {
        if(trio[i] != '0')
            is_null = false;
    }

    return is_null;
}

std::string handle_trio(std::string trio)
{
    std::string hundred = get_hundred(std::stoi(trio.substr(0,1)));
    std::string dozen = get_dozen_unit(std::stoi(trio.substr(1, 1)), std::stoi(trio.substr(2, 1)));

    if(std::stoi(trio.substr(0, 1)) > 1)
        hundred += "s";


    return conc(hundred, dozen);
}

std::string conc(std::string str1, std::string str2)
{
    if(str1 == "")
        return str2;
    else if(str2 == "")
        return str1;
    else
        return str1 + "-" + str2;
}

std::string get_hundred(int value)
{
    if(value == 1)
        return "cent";
    else if(value == 0)
        return "";
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
    else if(dozen == 0)
    {
        return get_single(value);
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
    switch (value)
    {
    case 0:
        return "";
        break;
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
