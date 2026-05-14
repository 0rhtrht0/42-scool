#include "computor_v1.hpp"



void aff(t_computor_v1 computor)
{
    if (computor.err == 1)
        return;
    std::cout << "Reduced form: ";
    if (computor.a)
        std::cout << computor.a << " * x^2";
    if (computor.b)
    {
        if (computor.a)
        {
            if (computor.b > 0)
                std::cout << " + " << computor.b << " * x^1";
            if(computor.b < 0)
                std::cout << " - " << (computor.b * -1) << " * x^1";
        }
        else
            std::cout << computor.b << " * x^1";
    }
    if (computor.c)
    {
        if (computor.a || computor.b)
        {
            if (computor.c > 0)
                std::cout << " + " << computor.c << " * x^0";
            else
                std::cout << " - " << (computor.c * -1) << " * x^0";
        }
    }
    else if (!computor.a && !computor.b && !computor.c)
            std::cout << "0 * " << computor.c << " * x^0";
    std::cout << " = 0" << std::endl;
    std::cout << "Polynomial degree : " << computor.deg << std::endl;
    std::cout << "delta = " << computor.delta << std::endl;
    std::cout << "The solution is:" << std::endl;
    if (!computor.sol1.empty())
        std::cout << computor.sol1 << std::endl;
    if (!computor.sol2.empty())
        std::cout << computor.sol2 << std::endl;
}

int main(int ac, char **av)
{
    if (ac > 2)
    {
        error(ARG_ERROR);
        return(1);
    }
    if (ac == 1)
    {
        char str[2056];
        printf("Entrez l'equation : ");
        fgets(str, sizeof(str), stdin);
        computor = input_validation(str);
        aff(computor);
    }
    else
    {
        computor = input_validation(av[1]);
        aff(computor);
    }
    return(0);
}

