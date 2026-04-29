#include "computor_v1.hpp"

t_computor_v1 computor;

void error(int i)
{
    if (i == ARG_ERROR)
    {
        const char *msg = "Argument must be greater than 1.\n";
        write(2, msg, strlen(msg));
    }
    else if (i == DEG_SUP)
    {
        const char *msg = "The polynomial degree is strictly greater than 2, I can't solve.\n";
        write(2, msg, strlen(msg));
    }
    else if (i == NO_SOLUTION)
    {
        const char *msg = "No solution.\n";
        write(2, msg, strlen(msg));
    }
    else if (i == FORMAT_ERROR)
    {
        const char *msg = "format error.\n";
        write(2, msg, strlen(msg));
    }
    exit(1);
}

void degree_validation(char *av)
{
    int i = 0;
    int a = 0;
    while(av[i])
    {
        if (av[i] == '=')
            a++;
        if (av[i] == 'x')
        {
            i++;
            if (av[i] != '^')
            {
                error(FORMAT_ERROR);
            }
            i++;
            if (av[i] > '2' || av[i] < '0')
            {
                if (av[i] > '9' || av[i] < '0')
                    error(FORMAT_ERROR);
                error(DEG_SUP);
            }
            i++;
            if (isdigit(av[i]))
                error(DEG_SUP);
            while (isdigit(av[i]))
                i++;
        }
        else    
            i++;
    }
    if (a != 1)
        error(FORMAT_ERROR);
}

void left_right_(std::string left, int sign)
{
    int i = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    const char *str = left.c_str();
    int temp = 0;
    int signn = 1;
    while (str[i])
    {
        if (str[i] == '-')
            signn = -1;
        while (isdigit(str[i]))
        {
            temp = temp * 10 + str[i] - 48;
            i++;
        }
        if (str[i] == 'x')
        {
            i = i + 2;
            temp = temp * signn;
            if (str[i] == '2')
                a = temp;
            if (str[i] == '1')
                b = temp;
            if (str[i] == '0')
                c = temp;
            temp = 0;
            signn = 1;
        }
        i++;
    }
    if (sign)
    {
        computor.a = computor.a + a;
        computor.b = computor.b + b;
        computor.c = computor.c + c;
    }
    else
    {
        computor.a = computor.a - a;
        computor.b = computor.b - b;
        computor.c = computor.c - c;        
    }
}

void left_value(char *av)
{
    std::string str = av;
    std::string temp;
    std::stringstream stream_(str);
    std::vector<std::string> left_rigt;
    while (std::getline(stream_, temp, '='))
    {
        left_rigt.push_back(temp);
    }
    left_right_(left_rigt[0], 0);
    left_right_(left_rigt[1], 1);
    if (computor.a)
        computor.deg = 2;
    if (computor.deg == 0 && computor.b)
        computor.deg = 1;
    if (computor.deg == 0)
    {
        if (computor.c)
            error(NO_SOLUTION);
    }
}

t_computor_v1 input_validation(char *av)
{
    computor.a = 0;
    computor.b = 0;
    computor.c = 0;
    degree_validation(av);
    left_value(av);
    return(computor);
}
