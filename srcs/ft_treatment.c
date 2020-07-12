#include "ft_printf.h"

char	*ft_format(char *origine, int align, int width, char flag)
{
	char	*result;
	char	*tmp;
	int	i;

	i = 0;
	if (ft_strlen(origine) < width)
	{
		int	j;

		j = width - ft_strlen(origine);
		tmp = malloc (sizeof(char) * (j + 1));
		if (tmp != NULL)
		{
			while (i < j)
			{
				tmp[i] = flag;
				i++;
			}
			tmp[i] = '\0';
			if (align == 1)
				result = ft_strjoin(tmp, origine);
			else
				result = ft_strjoin(origine, tmp);
			free(tmp);
		}
	}
	else
		result = ft_strdup(origine);
	return (result);
}
