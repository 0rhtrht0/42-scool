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
            std::cout << computor.c << " * x^0";
    std::cout << " = 0" << std::endl;
    if (!computor.a && !computor.b && !computor.c)
    {
        std::cout << "Polynomial degree : " << computor.deg << std::endl;
    }
    else
        std::cout << "Polynomial degree : " << computor.deg << std::endl;
    if (computor.deg == 1)
    {
        std::cout << "The solution is:" << std::endl;
        std::cout << computor.s1 << std::endl;
    }
    else if (computor.deg == 2 && computor.delta == 0)
    {
        std::cout << "The solution is:" << std::endl;
        std::cout << computor.s1 << std::endl;
    }
    else if (computor.deg == 2 && computor.delta > 0)
    {
        std::cout << "Discriminant is strictly positive, the two solutions are:" << std::endl;
        std::cout << "The solution is:" << std::endl;
        std::cout << computor.s1 << std::endl;
        std::cout << computor.s2 << std::endl;
    }
    else if (computor.deg == 2 && computor.delta < 0)
    {
        std::cout << "Discriminant is strictly negative, the two complex solutions are:" << std::endl;
        std::cout << "The solution is:" << std::endl;
        if (computor.is1 > 0)
            std::cout << computor.s1 << " + " << computor.is1 << "i" <<  std::endl;
        else
            std::cout << computor.s1 << " - " << -1 * computor.is1 << "i" <<  std::endl;
        if (computor.is2 > 0)
            std::cout << computor.s2 << " + " << computor.is2 << "i" << std::endl;
        else
            std::cout << computor.s2 << " - " << -1 * computor.is2 << "i" << std::endl;
        return;
    }
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