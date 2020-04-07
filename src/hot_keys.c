/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hot_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:23:01 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 15:27:40 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	iter(int key, int i, t_mlx *a)
{
	if (key == 24 || key == 69)
		while (++i < THREADS)
			a->p[i].max_iter++;
	if (key == 27 || key == 78)
		while ((++i < THREADS) && a->p[i].max_iter > 2)
			a->p[i].max_iter--;
}

int		move(int key, t_mlx *a)
{
	int	i;

	i = -1;
	if (key == 124)
		while (++i < THREADS)
			a->p[i].move_x += a->p[i].move_re;
	if (key == 123)
		while (++i < THREADS)
			a->p[i].move_x -= a->p[i].move_re;
	if (key == 125)
		while (++i < THREADS)
			a->p[i].move_y += a->p[i].move_im;
	if (key == 126)
		while (++i < THREADS)
			a->p[i].move_y -= a->p[i].move_im;
	if (key == 49 && a->f.is_space != 1 && ft_atoi(a->name) == 2)
		a->f.is_space = 1;
	else
		a->f.is_space = 0;
	if (key == 53)
		exit(0);
	iter(key, i, a);
	mlx_loop_hook(a->mlx_p, draw_fract, a);
	return (0);
}

int		mouse_move(int x, int y, t_mlx *a)
{
	int	i;

	i = -1;
	if ((x >= 0 && x <= SCREEN_W) && (y >= 0 && y <= SCREEN_H))
	{
		a->cm.x = x;
		a->cm.y = y;
	}
	while (++i < THREADS)
	{
		a->p[i].mouse_re = (double)a->cm.x /
		(SCREEN_W / (a->p[i].max_re - a->p[i].min_re)) + a->p[i].min_re;
		a->p[i].mouse_im = (double)a->cm.y /
		(SCREEN_H / (a->p[i].max_im - a->p[i].min_im)) + a->p[i].min_im;
		if (a->f.is_space == 1)
		{
			a->p[i].mr = a->p[i].mouse_re;
			a->p[i].mi = a->p[i].mouse_im;
		}
	}
	mlx_loop_hook(a->mlx_p, draw_fract, a);
	return (0);
}

int		color_switch(int key, t_mlx *a)
{
	int	i;

	i = -1;
	if (key == 15)
		while (++i < THREADS)
			a->p[i].cn = 1;
	else if (key == 5)
		while (++i < THREADS)
			a->p[i].cn = 2;
	else if (key == 11)
		while (++i < THREADS)
			a->p[i].cn = 3;
	return (0);
}

int		ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
