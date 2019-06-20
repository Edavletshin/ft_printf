#include "./includes/libft.h"
#include <stdio.h>

int main()
{
	/*printf("%d\n", ft_printf("%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f", 0., 0., 0., 0., 0., 0.));
	printf("%d\n", printf("%15.8f|%-15.8f|%+15.8f|% 15.8f|%#15.8f|%015.8f", 0., 0., 0., 0., 0., 0.));*/
	printf("%d\n", ft_printf("%15.8f\n", 0., 0., 0., 0., 0., 0.));
	printf("%d\n", printf("%15.8f\n", 0., 0., 0., 0., 0., 0.));
}
