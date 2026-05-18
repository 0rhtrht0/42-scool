#include "computor.hpp"


std::vector<std::string> parse_(std::string input)
{
    int i = 0;
    std::vector<std::string> ret;
    std::string conteneur;

    while (input[i] != std::string::npos)
    {
        if (input[i] == '+' || input[i] == '-')
        {
            if (i != 0)
            {
                ret.push_back(trim(conteneur));
                i++;
            }
        }
        conteneur += input[i];
        i++;
    }
    ret.push_back(trim(conteneur));
    
    return(ret);
}

std::vector<std::string>    partage_parentaise(std::string input)
{
    int i = 0;
    std::vector<std::string> l_r;
    std::string in;

    while(input[i] != ')')
    {
        if (input[i] == '(')
        {
            l_r.push_back(trim(in));
            in.clear();
            i++;
        }
        if (input[i] != ' ')
            in += input[i];
        i++;
    }
    l_r.push_back(trim(in));
    return(l_r);
}

void    egual_(std::string input)
{
    std::cout << "coucou" << std::endl;
}

void    nothing_egual(std::string input)
{
    std::cout << "tisy egual" << std::endl;

}

void    data::update_data(std::string input)
{
    if (input.find('=') == std::string::npos)
        egual_(input);
    else
        nothing_egual(input);
}

