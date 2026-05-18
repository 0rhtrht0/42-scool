#include "computor.hpp"

size_t data::puiss(size_t nbr, int puis)
{
    size_t ret = 1;

    if (puis == 0)
        return (ret);
    while (puis)
    {
        ret = nbr * ret;
        puis--;
    }
    return (ret);
}

std::string trim(const std::string& s) 
{
    const std::string whitespace = " \n\r\t\f\v";

    size_t start = s.find_first_not_of(whitespace);
    if (start == std::string::npos) return "";
    size_t end = s.find_last_not_of(whitespace);
    return s.substr(start, end - start + 1);
}
