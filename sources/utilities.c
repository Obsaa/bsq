/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:34:32 by oabdalha          #+#    #+#             */
/*   Updated: 2017/02/01 23:16:02 by tzior            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <unistd.h>
#define SEP(x) (x=='\n')

char	**table_allocation(char **table, char *str)
{
	int		i;
	int		n_words;

	i = 0;
	n_words = 0;
	while (SEP(str[i]))
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (SEP(str[i]))
		{
			n_words++;
			while (SEP(str[i]))
				i++;
		}
	}
	if (!SEP(str[i - 1]))
		n_words++;
	table = (char**)malloc(sizeof(*table) * (n_words + 10));
	table[n_words] = 0;
	return (table);
}

int		*chart(char **grid, char a1, char a2)
{
	int		*dim;
	int		i;

	dim = (int *)malloc(sizeof(int) * 2);
	dim[0] = 0;
	dim[1] = 0;
	while (grid[dim[1]])
	{
		i = 0;
		while (grid[dim[1]][i])
		{
			if (grid[dim[1]][i] != a1 && grid[dim[1]][i] != a2)
				return (NULL);
			i++;
		}
		if (dim[1] == 0)
			dim[0] = i;
		if (i != dim[0])
			return (NULL);
		dim[1]++;
	}
	return (dim);
}

int		modify(int is_vide, int *i, int *a[2], t_square *sol)
{
	int		out;

	if (i[0] == 0 || i[1] == 0)
		out = (is_vide) ? 1 : 0;
	else
		out = (is_vide) ?
			(1 + low(a[1][i[1] - 1], a[0][i[1] - 1], a[0][i[1]])) : 0;
	if (out > sol->size)
	{
		sol->x = i[1];
		sol->y = i[0];
		sol->size = out;
	}
	return (out);
}

t_square			solution(char **grid, char vide, int x, int y)
{
	int			*a[2];
	int			i[2];
	t_square	sol;

	sol.size = 0;
	a[0] = (int *)(malloc(sizeof(int) * (x + 1)));
	a[1] = (int *)(malloc(sizeof(int) * (x + 1)));
	i[0] = -1;
	while (++i[0] < y)
	{
		i[1] = -1;
		while (++i[1] < x)
		{
			a[1][i[1]] = modify((grid[i[0]][i[1]] == vide), i, a, &sol);
			if (i[1] > 0)
				a[0][i[1] - 1] = a[1][i[1] - 1];
		}
		a[0][i[1] - 1] = a[1][i[1] - 1];
	}
	free(a[0]);
	free(a[1]);
	return (sol);
}

t_data	manage_data(char *str)
{
	t_data	out;
	int		len;

	len = ft_strlen(str);
	out.plein = str[len - 1];
	out.obstacle = str[len - 2];
	out.vide = str[len - 3];
	str[len - 3] = '\0';
	out.size = ft_atoi(str);
	return (out);
}

int		biggestsq(char **grid)
{
	t_square	sol;
	t_data		data;
	int			*dim;

	data = manage_data(grid[0]);
	grid++;
	if (!(dim = chart(grid, data.vide, data.obstacle)))
		return (1);
	if (data.size != dim[1])
		return (1);
	sol = solution(grid, data.vide, dim[0], dim[1]);
	print_solution(grid, sol, data.plein);
	free(dim);
	return (0);
}

char	**allocatewrd(char **table, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (SEP(str[i]))
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (SEP(str[i]) || !str[i])
		{
			table[j] = (char*)malloc(sizeof(**table) * (k + 10));
			j++;
			k = 0;
			while (SEP(str[i]))
				i++;
		}
		k++;
	}
	return (table);
}

char	**populate_world(char **table, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (SEP(str[i]))
		i++;
	while (str[i] != '\0')
	{
		table[j][k] = str[i];
		i++;
		k++;
		if (SEP(str[i]) || !str[i])
		{
			table[j][k] = '\0';
			j++;
			k = 0;
			while (SEP(str[i]))
				i++;
		}
	}
	return (table);
}

char	**divytable(char *str)
{
	char	**table;

	table = 0;
	table = table_allocation(table, str);
	table = allocatewrd(table, str);
	table = populate_world(table, str);
	return (table);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		cmp;
	int		i;

	i = 0;
	cmp = 0;
	while (1)
	{
		cmp += (s1[i] - s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (cmp);
		if (s1[i] == s2[i])
			i++;
		else
			return (cmp);
	}
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	dup = (char*)malloc(sizeof(*dup) * (size + 1));
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	print_map(char **grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

void	print_solution(char **grid, t_square sol, char x)
{
	int		i;
	int		j;

	i = sol.y;
	while (i >= 0 && i > sol.y - sol.size)
	{
		j = sol.x;
		while (j >= 0 && j > sol.x - sol.size)
		{
			grid[i][j] = x;
			j--;
		}
		i--;
	}
	print_map(grid);
}

int		low(int a, int b, int c)
{
	int		m;

	m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;
	return (m);
}

int		ft_atoi(char *str)
{
	int		if_negativ;
	int		count;
	int		num;

	if_negativ = 0;
	count = 0;
	num = 0;
	while (str[0] == ' ')
		str++;
	if (str[0] == '-')
		if_negativ = 1;
	if (str[0] == '+' || str[0] == '-')
		str++;
	while ((str[count] >= '0' && str[count] <= '9'))
	{
		num += str[count] - 48;
		if (str[count + 1] >= '0' && str[count + 1] <= '9')
			num *= 10;
		count++;
	}
	if (if_negativ == 1)
		return (-num);
	return (num);
}
