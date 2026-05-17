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
