#include <math.h>
#include <stdio.h>

int	main()
{
	int i = -1;
	char *s = "Hello";
	while(s[++i])
	{
		printf("%c\n", s[i]);
	}
}