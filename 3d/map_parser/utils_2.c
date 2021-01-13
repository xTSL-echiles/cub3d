#include "../headers/libcub.h"

int ft_check_argv(t_options *qu, char **argv, int argc)
{
	if(argc > 2)
	{
		write(1, "to many arg\n", 12);
		return(0);
	}
	if(argv[1])
		qu->filename = ft_strcpy(argv[1]);
	else
	{
		write(1, "1st arg need map\n", 17);
		return(0);
	}
	if(ft_check_file_name(qu))
	{
		write(1, "Error: wrong file name or no argument\n", 39);
		return(0);
	}
	return(1);
}

void	ft_putstr_fd(char *s)
{
	int i;

	if (s > 0)
	{
		i = 0;
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int		ft_error_msg(char *s)
{
	ft_putstr_fd(s);
	return(0);
}