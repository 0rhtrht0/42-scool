#include "computor_v1.hpp"

void aff(t_computor_v1 computor)
{
    std::cout << "Reduced form: ";
    if (computor.a)
        std::cout << computor.a << " * x^2";
    if (computor.b)
    {
        if (computor.a)
            std::cout << " + " << computor.b << " * x^1";
        else
            std::cout << computor.b << " * x^1";
    }
    if (computor.c)
    {
        std::cout << "\n" << computor.c << std::endl;
        if (computor.a || computor.b)
            std::cout << " + " << computor.c << " * x^0";
    }
    else if (!computor.a && !computor.b)
            std::cout << "0 * " << computor.c << " * x^0";
    std::cout << " = 0" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        error(ARG_ERROR);
    computor = input_validation(av[1]);
    aff(computor);
    return(0);
}