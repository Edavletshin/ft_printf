#include "./includes/libft.h"
#include <stdio.h>

int main()
{
	printf("%d\n" , ft_printf("%+23.5d|% 23.5d\n", 0, 0, 0, 0, 0));
	printf("%d\n" , printf("%+23.5d|% 23.5d\n", 0, 0, 0, 0, 0));
}
