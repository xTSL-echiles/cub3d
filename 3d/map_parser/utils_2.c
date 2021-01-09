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
		free(qu);
		return(0);
	}
	return(1);
}