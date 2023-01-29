#include "libft.h"

void	print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("%d: %s\n", i, array[i]);
		i++;
	}
}
