#include "../headers/libcub.h"

void ft_all_null_now(t_options *qu)
{
	qu->Rwid_x = 0;
	qu->Rheig_y = 0;
	qu->no = NULL;
	qu->so = NULL;
	qu->we = NULL;
	qu->ea = NULL;
	qu->s = NULL;
	qu->fr = -1;
	qu->fg = -1;
	qu->fb = -1;
	qu->cr = -1;
	qu->cg = -1;
	qu->cb = -1;
	qu->player = 0;
	qu->filename = NULL;
	qu->acces = 0;
}

void	ft_cleaner_mass(char **ans)
{
	int i;
	
	i = 0;
	while(ans[i])
	{
		free(ans[i]);
		i++;
	}
	free(ans);
}

int		ft_cptain_prise(t_options *qu)
{
	int fd;
	int i;
	
	i = 0;
	if((fd = open(qu->no, O_RDONLY)) < 0)
		i++;
	if((fd = open(qu->so, O_RDONLY)) < 0)
		i++;
	if((fd = open(qu->we, O_RDONLY)) < 0)
		i++;
	if((fd = open(qu->ea, O_RDONLY)) < 0)
		i++;
	if((fd = open(qu->s, O_RDONLY)) < 0)
		i++;
	close(fd);
	return((i > 0) ? 2 : 0);
}

int	ft_check_digit_in_colors(char **ans)
{
	int j;
	int i;

	j = 0;
	while( 3 > j)
	{
		i = 0;
		while((ans[j][i]) && !(ft_isdigit(ans[j][i])))
			i++;
		if(ans[j][i] == '\0')
		{
			return(1);
		}
		j++;	
	}
	return(0);
}

int	ft_check_file_name(t_options *qu)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(qu->filename[i] != '\0')
		i++;
	if(i > 5)
	{
		if(qu->filename[i - 1] == 'b')
			j++;
		if(qu->filename[i - 2] == 'u')
			j++;
		if(qu->filename[i - 3] == 'c')
			j++;
		if(qu->filename[i - 4] == '.')
			j++;
	}
	return(((j == 4) ? 0 : 1));
}