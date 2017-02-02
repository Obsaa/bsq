/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:12:31 by oabdalha          #+#    #+#             */
/*   Updated: 2017/02/01 23:17:19 by tzior            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 4096
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_data
{
	unsigned char	vide;
	unsigned char	obstacle;
	unsigned char	plein;
	int				size;
}				t_data;

typedef struct	s_square
{
	int	x;
	int	y;
	int	size;
}				t_square;

int				biggestsq(char **grid);
char			**divytable(char *str);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			print_map(char **grid);
void			print_solution(char **grid, t_square sol, char x);

int				low(int a, int b, int c);

int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);

#endif
