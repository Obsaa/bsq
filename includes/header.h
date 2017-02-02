/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:59:02 by oabdalha          #+#    #+#             */
/*   Updated: 2017/02/01 20:53:55 by oabdalha         ###   ########.fr       */
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

int				ft_bsq(char **grid);
char			**ft_split_nl(char *str);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_print_grid(char **grid);
void			ft_print_sol(char **grid, t_square sol, char x);

int				min(int a, int b, int c);

int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);

#endif
