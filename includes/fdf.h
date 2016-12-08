/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:18:51 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/08 12:14:50 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				**nbr;
	int				nbr_line;
	int				*nbr_split;
	int				a;
	int				scalx;
	int				scaly;
	int				startx;
	int				x1;
	int				starty;
	char			**split;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				i;
	int				j;
	int				k;
	char			*line;
	int				incx;
	int				incy;
}					t_fdf;

void				init(t_fdf *fdf);
int					ft_count_split(char **split);
char				*fdf_to_space(char *str);
void				ft_count_line(t_fdf *fdf, int fd);
int					ft_getnbr(char *str);
int					get_hook(t_fdf *fdf);
void				change_scale(t_fdf *fdf, int i);
int					key_hook(int keycode, void *param);
int					coord_x(t_fdf *fdf, int x, int y);
int					get_color(int z1, int z2);
void				draw_y(t_fdf *fdf);
void				draw_x(t_fdf *fdf);
void				bh_dispatch(t_fdf *fdf);
void				m_neg(t_fdf *fdf);
void				m_pos(t_fdf *fdf);
#endif
