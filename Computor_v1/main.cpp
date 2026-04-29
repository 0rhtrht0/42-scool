#include "computor_v1.hpp"

void aff(t_computor_v1 computor)
{
    if (computor.a)
        std::cout << computor.a << " * x^2";
    if (computor.b)
    {
        if (computor.a)
            std::cout << " " << computor.b << " * x^1";
        else
            std::cout << computor.b << " * x^1";
    }
    if (computor.c)
    {
        if (computor.a || computor.b)
            std::cout << " " << computor.c << " * x^0";
    }
    else
            std::cout << "0 * " << computor.c << " * x^0";
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        error(ARG_ERROR);
    computor = input_validation(av[1]);
    aff(computor);
    return(0);
}