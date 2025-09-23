#include "includes/philosophers.h"

int main(int argc, char **argv)
{
    t_table table;
    if (argc == 5 || argc == 6)
    {
        prase_input(&table, argv);
        data_init(&table);
        dinner_start(&table);
        clean(&table);
    }
    else
        error_exit("Wrong input!\n Usage: ./philo 5 1200 200 200 [5]");
}