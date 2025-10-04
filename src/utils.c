#include "../includes/philosophers.h"

void error_exit(char *error)
{
    printf("%s\n", error);
    exit (EXIT_FAILURE);
}

long    gettime(t_time_code timecode)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL))
        error_exit("Gettimeofday failed!");
    if (timecode == SECOND)
        return (tv.tv_sec + tv.tv_usec / 1e6);
    else if (timecode == MILLISECOND)
        return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
    else if (timecode == MICROSECOND)
        return ((tv.tv_sec * 1e6) + (tv.tv_usec));
    else
        error_exit("Wrong input to gettime");
    return (1337);
}

void    precise_usleep(long usec, t_table *table)
{
    long    start;
    long    elapsed;
    long    rem;

    start = gettime(MICROSECOND);
    while (gettime(MICROSECOND) - start < usec)
    {
        if (simulation_finished(table))
            break ;
        elapsed = gettime(MICROSECOND) - start;
        rem = usec - elapsed;
        if (rem > 1e3)
            usleep(rem / 2);
        else
        {
            while (gettime(MICROSECOND) - start < usec)
                ;
        }
    }
}