#include <stdio.h>
#include "reset/head.h"

int main()
{
	ft_printf("ft{%f}{%lf}{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	printf("pf{%f}{%lf}{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	return(0);
}