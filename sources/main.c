/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:12:45 by oabdalha          #+#    #+#             */
/*   Updated: 2017/02/01 23:15:47 by tzior            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*read_inputs(int fd)
{
	char	buf[BUF_SIZE + 1];
	int		ret;
	long	size_str;
	char	*temp;
	char	*res;

	size_str = 0;
	if (fd == -1)
		return ("0\n0");
	res = (char *)malloc(42);
	*res = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		temp = ft_strdup(res);
		free(res);
		size_str += ret;
		res = (char*)malloc(sizeof(char) * (size_str + 1));
		*res = '\0';
		buf[ret] = '\0';
		ft_strcat(res, temp);
		ft_strcat(res, buf);
		free(temp);
	}
	close(fd);
	return (res);
}

char	***insert_ingrid(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;
	char	***grid_ptr;

	grid_ptr = (char***)malloc(sizeof(char**) * (ac + 1));
	i = 1;
	if (ac == 1)
	{
		str = read_inputs(0);
		*grid_ptr = divytable(str);
		if (str)
			free(str);
		grid_ptr[1] = NULL;
	}
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		str = read_inputs(fd);
		grid_ptr[i - 1] = divytable(str);
		grid_ptr[i] = NULL;
		i++;
	}
	return (grid_ptr);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	***grid_ptr;

	grid_ptr = insert_ingrid(ac, av);
	i = 0;
	while (grid_ptr[i])
	{
		if (biggestsq(grid_ptr[i]))
			ft_putstr("map error\n");
		j = 0;
		while (grid_ptr[i][j])
			free(grid_ptr[i][j++]);
		free(grid_ptr[i]);
		i++;
		if (ac > 2 && grid_ptr[i])
			ft_putchar('\n');
	}
	free(grid_ptr);
	return (0);
}
