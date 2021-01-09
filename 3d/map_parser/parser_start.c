#include <mlx.h>
#include "../headers/libcub.h"

int	ft_map_rec(t_options *qu, char *save, char *line)
{
	if(save == NULL)
	{
		free(line);
		free(save);
		return(0);
	}
	if(save != NULL)
	{
		save = ft_strjoin(save, line);
		qu->map = ft_split(save, '\n');
	}
	free(line);
	free(save);
	return(1);
}

int ft_read_and_rec(t_options *qu)
{
	int fd;
	char *line;
	char *save;

	save = NULL;
	fd = open(qu->filename, O_RDONLY);
	while(get_next_line(fd, &line, ((ft_acces_checker(qu)) > 0) ? 1 : 0) > 0)
	{
		if(qu->acces == 2)
			return(0);
		else if(qu->acces == 1)
		{
			if(!(ft_check_0_line_in_map(save, line)))
				return(0);
			save = ft_strjoin(save, line);
		}
		else
			pars_check(qu, line);
		free(line);
	}
	return((ft_map_rec(qu, save, line)));
}

int ft_parser_start(t_data *img, int ar, char **arg)
{
	img->qu = (t_options*)malloc(sizeof(t_options));
	ft_all_null_now(img->qu);
	if(!(ft_check_argv(img->qu, arg, ar)))
	{
		free(img->qu);
		return(0);
	}
	if(!(ft_read_and_rec(img->qu)))
	{
		printf("%s\n", "Error: invalid options");
		free(img->qu);
		return(0);
	}
	if(ft_parser_map(img->qu))
	{
		img->map = img->qu->map;
		return(1);
	}
	return(0);
}