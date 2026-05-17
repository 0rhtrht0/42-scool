
//#include "computor.hpp"
#include <iostream>

int main(int ac ,char **av)
{
    char in_[128];
    //data data_;

    while (1)
    {
        std::cout << "> ";
        std::cin >> in_; 
        if (in_ == "quit")
            return(0);

        std::cout << "l'entre est : " << in_ << std::endl; 
    }
    return(0);
}