#include "../headers/libcub.h"

int	ft_pars_str_utils(t_options *qu, int i, int j, int k)
{
	if(k == 2)
	{
		if ((qu->map[i][j + 1] != '0' && qu->map[i][j + 1] != '1' &&
		qu->map[i][j + 1] != '2' &&
		qu->map[i][j + 1] != qu->player) || (qu->map[i + 1][j] != '1' &&
		qu->map[i + 1][j] != '0' && qu->map[i + 1][j] != '2' &&
		qu->map[i + 1][j] != qu->player))
			return(0);
	}
	if(k == 1)
	{
		if(qu->map[i][j] != '0' && qu->map[i][j] != '1' &&
		qu->map[i][j] != '2' && qu->map[i][j] != qu->player &&
		qu->map[i][j] != ' ' && qu->map[i][j] != '\n')
		{
			write(1, "Error: Wrong symbol\n", 20);
			return(0);
		}
	}
	return(1);
}
int ft_pars_str(t_options *qu, int i)
{
	int j;
	int str1;
	int str2;

	j = 0;
	if (qu->map[i][0] != '1' && qu->map[i][0] != ' ')
		return(0);
	str1 = ft_strlen(qu->map[i - 1], '\0');
	str2 = ft_strlen(qu->map[i + 1], '\0');
	while (qu->map[i][j] != '\0')
	{
		if(!(ft_pars_str_utils(qu, i, j, 1)))
			return(0);
		if (qu->map[i][j] == '0' || qu->map[i][j] == '2' ||
		qu->map[i][j] == qu->player)
		{
			if (j > str2 || str1 <= j)
				return(0);
			if (!(ft_pars_str_utils(qu, i, j, 2)))
				return(0);
		}
	j++;
	}
	return(1);
}

int	ft_check_fst_and_lst(t_options *qu, int i)
{
	int j;
	int str2;
	
	j = 0;
	str2 = ft_strlen(qu->map[i], '\0');
	while(qu->map[i][j] != '\0')
	{
		if(j > str2)
			return(0);
		if(qu->map[i][j] != '1' && qu->map[i][j] != ' ')
		{
			write(1, "Error: cancer map\n", 18);
			return(0);
		}
	j++;
	}
	return(1);
}

int ft_player_pos(t_options *qu)
{
	int i;
	int j;

	i = 0;
	while(qu->map[i])
	{
		j = 0;
		while(qu->map[i][j] != '\0')
		{
			if(qu->map[i][j] == 'N' || qu->map[i][j] == 'S' ||
			qu->map[i][j] == 'E' || qu->map[i][j] == 'W')
			{
				if(!qu->player)
					qu->player = qu->map[i][j];
				else
				{
					write(1, "Error: many player position\n", 29);
					return(0);
				}
			}
			j++;
		}
		i++;
	}
	if(!(qu->player))
	{
		write(1, "Error: no player position\n", 29);
		return(0);
	}
	return(1);
}

int ft_parser_map(t_options *qu)
{
	int i;

	i = 0;
	if(!ft_player_pos(qu))	
		return(0);
	while(qu->map[i + 1] != 0)
	{
		if(i == 0)
		{
			if(!(ft_check_fst_and_lst(qu, i)))
				return(0);
		}
		else
		{
			if(!(ft_pars_str(qu, i)))
			{	
				write(1, "Error: cancer map\n", 18);
				return(0);
			}
		}	
	i++;
	}
	if(!(ft_check_fst_and_lst(qu, i)))
		return(0);
	return(1);
}