#include "main.h"

/**
 * main - source code
 * @argc:arg count
 * @argv:the arg
 *
 * Return:exit success
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    interpreter(argv[1]);
    return (EXIT_SUCCESS);
}
