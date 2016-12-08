/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglandai <tglandai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:41:32 by tglandai          #+#    #+#             */
/*   Updated: 2016/12/08 12:22:23 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_hook(t_fdf *fdf)
{
	draw_y(fdf);
	draw_x(fdf);
	return (1);
}

int		key_hook(int keycode, void *param)
{
	param = 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

void	read_file(t_fdf *fdf, int fd)
{
	if (!(fdf->nbr = (int **)malloc(sizeof(int *) * fdf->nbr_line)) || \
			!(fdf->nbr_split = (int *)malloc(sizeof(int) * fdf->nbr_line)))
		exit(1);
	while (ft_get_next_line(fd, &(fdf->line)) == 1)
	{
		if (fdf->line)
		{
			fdf->i = 0;
			fdf->line = fdf_to_space(fdf->line);
			fdf->split = ft_strsplit(fdf->line, ' ');
			fdf->nbr_split[fdf->k] = ft_count_split(fdf->split);
			if (!(fdf->nbr[fdf->j] = (int *)malloc(sizeof(int) * \
							fdf->nbr_split[fdf->k])))
				exit(1);
			while (fdf->split[fdf->i])
			{
				fdf->nbr[fdf->j][fdf->i] = ft_getnbr(fdf->split[fdf->i]);
				(fdf->i)++;
			}
			free(fdf->split);
			(fdf->j)++;
			(fdf->k)++;
		}
	}
}

void	init(t_fdf *fdf)
{
	fdf->j = 0;
	fdf->k = 0;
	fdf->scalx = 20;
	fdf->scaly = 20;
	fdf->startx = 850;
	fdf->starty = 50;
}

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_count_line(&fdf, fd);
		fd = open(av[1], O_RDONLY);
		init(&fdf);
		read_file(&fdf, fd);
		close(fd);
		fdf.mlx = mlx_init();
		fdf.win = mlx_new_window(fdf.mlx, 1920, 1080, "FdF 42 tglandai");
		mlx_expose_hook(fdf.win, get_hook, &fdf);
		mlx_key_hook(fdf.win, key_hook, &fdf);
		mlx_loop(fdf.mlx);
	}
	else
		ft_putendl("usage /fdf \"file\"");
	return (0);
}
