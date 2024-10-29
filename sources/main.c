#include "philosopher.h"



int main(int ac, char **av)
{
    if (ac >= 4)
    {
        t_table table;
        table = set_table(av, ac);
        start_dinner(table);
    }
    else
        printf("Wrong arguments");
    return (0);
}