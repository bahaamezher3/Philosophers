#include "includes/philosophers.h"

void error_exit(char *error)
{
    printf("%s\n", error);
    exit (EXIT_FAILURE);
}