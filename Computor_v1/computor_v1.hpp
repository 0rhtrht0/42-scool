#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>

#define ARG_ERROR  1
#define DEG_SUP 2
#define NO_SOLUTION 3
#define FORMAT_ERROR 4
#define eupsi 0.0001

struct t_computor_v1
{
    std::string eq;
    int deg;
    float delta;
    float a;
    float b;
    float c;
    float s1;
    float s2;
    float is1;
    float is2;
};

extern t_computor_v1 computor;

void error(int i);
t_computor_v1 input_validation(char *av);