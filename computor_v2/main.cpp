#include "computor.hpp"

int main(int ac ,char **av)
{
    data data_;
    while(1)
    {
        std::string in_;
        std::cout << "> ";
        std::getline(std::cin, in_);
        if (in_ == "quit")
            break;
        data_.update_data(in_);
    }
    return(0);
}