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
    while (av[i])
    {
        if (av[i] == 'x')
        {
            i++;
            if (av[i] == '^')
                i++;
            if (av[i] > '2' || av[i] < '0')
            {
                if (av[i] > '9' || av[i] < '0')
                    if (av[i] != ' ' && av[i] != '\0' && av[i] != '=')
                        error(FORMAT_ERROR);
                if (av[i] != ' ' && av[i] != '\0' && av[i] != '=')
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
    for (int v = 0; av[v]; v++)
        if (av[v] == '=')
            a++;
    if (a != 1)
    {
        std::cout << "eto" << std::endl;
        error(FORMAT_ERROR);
    }
}


float dix_puis(int c, char str)
{
    int i = 0;
    float ret = 1;
    while (i < c)
    {
        ret = ret * 0.1;
        i++;
    }
    ret = ret * (str - 48);
    return (ret);
}

void left_right_(std::string left, int sign)
{
    int i = 0;
    float a = 0;
    float b = 0;
    float c = 0;
    const char *str = left.c_str();
    float temp = 0;
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
        if (str[i] == '.')
        {
            i++;
            float temp_after_point = 0;
            int count = 1;
            while (isdigit(str[i]))
            {
                temp_after_point = temp_after_point + dix_puis(count, str[i]);
                i++;
                count++;
            }
            temp = temp_after_point + temp;
        }
        if (str[i] == 'x')
        {
            if (str[i + 1] == '^')
                i = i + 2;
            else
                i = i + 1;
            temp = temp * signn;
            if (str[i] == '2')
                a = a + temp;
            if (str[i] == '1')
                b = b + temp;
            if (str[i] == '0')
                c = c + temp;
            if (!isdigit(str[i]))
            {
                if (temp)
                    b = b + temp;
                else
                    b = 1 + b;
            }
            temp = 0;
            signn = 1;
        }
        if (temp && (str[i + 1] == '\0' || str[i] == '+' || str[i] == '-'))
        {
            c = c + temp;
            temp = 0;
        }
        i++;
    }
    if (!sign)
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
    if (computor.a < 0)
    {
        computor.a = -1 * computor.a;
        computor.b = -1 * computor.b;
        computor.c = -1 * computor.c;
    }
    if (computor.a == 0 && computor.b < 0)
    {
        computor.b = -1 * computor.b;
        computor.c = -1 * computor.c;
    }
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


float delta(void)
{
    float delta = computor.b * computor.b - 4 * computor.a * computor.c;
    return (delta);
}

float v_abs(float f)
{
    if (f < 0)
        return(f * -1);
    else
        return(f);
}

float sqrt_delta(float d)
{
    int i = 0;
    double deb;
    double fin;


    while(i * i < d)
        i++;
    fin = i;
    deb = i - 1;
    double ret = 0;
    while(v_abs(ret * ret - d) > eupsi)
    {
        ret = (fin + deb) / 2.0;
        if (ret * ret > d)
        {
            fin = ret;
        }
        else
        {
            deb = ret;
        }
    }
    return(ret);
}

void solve(void)
{
    if (computor.deg == 1)
    {
        computor.s1 = computor.c / (computor.b * -1);
        return;
    }
    computor.delta = delta();
    if (computor.delta == 0)
    {
        if (computor.c)
            computor.s1 = computor.b / (-2 * computor.c);
        else
            computor.s1 = 0;
        return;
    }
    else if (computor.delta > 0)
    {
        float sq = sqrt_delta(computor.delta);
        if (computor.c)
        {
            computor.s1 = (-1 * computor.b - sq) / (2 * computor.c);
            computor.s2 = (-1 * computor.b + sq) / (2 * computor.c);
        }
        else
        {
            computor.s1 = 0;
            computor.s2 = -1 * (computor.b / computor.a);
        }
        return;
    }
    else
    {
        float temp_ = sqrt_delta(v_abs(computor.delta));
        if (computor.c)
        {
            computor.s1 = computor.c / (-2 * computor.c);
            computor.s2 = computor.c / (-2 * computor.c);
            computor.is1 = temp_ / (-2 * computor.c);
            computor.is2 = temp_ / (2 * computor.c);
        }
        return;
    }
}

t_computor_v1 input_validation(char *av)
{
    computor.a = 0;
    computor.b = 0;
    computor.c = 0;
    degree_validation(av);
    left_value(av);
    solve();
    return (computor);
}
