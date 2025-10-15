#include "push_swap.h"
#include <stdio.h>
int main(int argc,char **argv)
{
    int             i;
    char            **num;

    i = 0;
    if (argc == 2)
        num = ft_split(argv[1],' ');
    else
        num = argv + 1;
    while(num[i])
    {
        printf("%d\n",atoi(num[i]));
        i++;
    }
}