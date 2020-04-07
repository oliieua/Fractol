/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:40:30 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 16:08:07 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	inith(t_mlx *a, int i)
{
	a->p[i].cn = 3;
	a->p[i].max_iter = 100;
	a->p[i].move_x = 0;
	a->p[i].move_y = 0;
	a->p[i].min_re = -2.0;
	a->p[i].min_im = -1.4;
	a->p[i].max_re = 2;
	a->p[i].move_re = 0;
	a->p[i].move_im = 0;
	a->p[i].mr = 0;
	a->p[i].mi = 0;
	a->p[i].max_im = 1.4;
}

void	init(t_mlx *a)
{
	int	i;
	int y;

	i = -1;
	y = 0;
	a->p = (t_p *)malloc(sizeof(t_p) * THREADS);
	win_name(a, a->name);
	a->mlx_p = mlx_init();
	a->win_p = mlx_new_window(a->mlx_p, SCREEN_W, SCREEN_H, a->fract_name);
	while (++i < THREADS)
	{
		inith(a, i);
		a->p[i].yyy = y;
		y += SCREEN_H / THREADS;
		a->p[i].y_max = y;
		a->p[i].mlx_p = a->mlx_p;
		a->p[i].win_p = a->win_p;
	}
}

void	init2(t_mlx *a)
{
	int	i;
	int y;

	i = -1;
	y = 0;
	a->c.cn = 1;
	while (++i < THREADS)
	{
		a->p[i].img_p = mlx_new_image(a->mlx_p, SCREEN_W, SCREEN_H / THREADS);
		a->p[i].data = mlx_get_data_addr(a->p[i].img_p,
			&a->p[i].bpp, &a->p[i].sl, &a->p[i].endian);
		a->p[i].y = y;
		y += SCREEN_H / THREADS;
		a->p[i].move_re = (a->p[i].max_re - a->p[i].min_re)
		/ (SCREEN_W / 6);
		a->p[i].move_im = (a->p[i].max_im - a->p[i].min_im)
		/ (SCREEN_H / 6);
	}
}
