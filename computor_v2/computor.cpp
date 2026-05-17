#include "computor.hpp"

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
    if (input.find('='))
        egual_(input);
    else
        nothing_egual(input);
}

