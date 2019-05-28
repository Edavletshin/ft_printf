#include <stdio.h>
#include "libft.h"

int main()
{
	int i;
	i = ft_printf("%5.2s is a string", "");
	printf("/%d/", i);
	return (0);
}
