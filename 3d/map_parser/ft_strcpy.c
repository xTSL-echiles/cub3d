#include "../headers/libcub.h"

char *ft_strcpy(char *src)
{
	char *dest;
	int i;
	int j;

	i = 0;
	j = ft_strlen(src, '\0');
	dest = malloc(sizeof(char) * (j + 1));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}