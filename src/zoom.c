/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:10:08 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 15:28:56 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double	intrpolate(double start, double end, double interpolation)
{
	return (start + (end - start) * interpolation);
}

void	plus_zoom(t_mlx *a)
{
	int		i;
	double	interpolation;

	i = -1;
	interpolation = 1 / 1.04;
	while (++i < THREADS)
	{
		a->p[i].mouse_re = (double)a->cm.x /
		(SCREEN_W / (a->p[i].max_re - a->p[i].min_re)) + a->p[i].min_re;
		a->p[i].mouse_im = (double)a->cm.y /
		(SCREEN_H / (a->p[i].max_im - a->p[i].min_im)) + a->p[i].min_im;
		a->p[i].min_re = intrpolate(a->p[i].mouse_re,
			a->p[i].min_re, interpolation);
		a->p[i].max_re = intrpolate(a->p[i].mouse_re,
			a->p[i].max_re, interpolation);
		a->p[i].min_im = intrpolate(a->p[i].mouse_im,
			a->p[i].min_im, interpolation);
		a->p[i].max_im = intrpolate(a->p[i].mouse_im,
			a->p[i].max_im, interpolation);
	}
	mlx_loop_hook(a->mlx_p, draw_fract, a);
}

void	minus_zoom(t_mlx *a)
{
	int		i;
	double	interpolation;

	i = -1;
	interpolation = 1 * 1.04;
	while (++i < THREADS)
	{
		a->p[i].move_re = (a->p[i].max_re - a->p[i].min_re) / (SCREEN_W / 6);
		a->p[i].mouse_re = (double)a->cm.x /
		(SCREEN_W / (a->p[i].max_re - a->p[i].min_re)) + a->p[i].min_re;
		a->p[i].mouse_im = (double)a->cm.y /
		(SCREEN_H / (a->p[i].max_im - a->p[i].min_im)) + a->p[i].min_im;
		a->p[i].min_re = intrpolate(a->p[i].mouse_re,
			a->p[i].min_re, interpolation);
		a->p[i].max_re = intrpolate(a->p[i].mouse_re,
			a->p[i].max_re, interpolation);
		a->p[i].min_im = intrpolate(a->p[i].mouse_im,
			a->p[i].min_im, interpolation);
		a->p[i].max_im = intrpolate(a->p[i].mouse_im,
			a->p[i].max_im, interpolation);
	}
	mlx_loop_hook(a->mlx_p, draw_fract, a);
}

void	reset_zoom(t_mlx *a)
{
	int	i;

	i = -1;
	while (++i < THREADS)
	{
		a->p[i].min_re = -2.0;
		a->p[i].min_im = -1.4;
		a->p[i].max_re = 2;
		a->p[i].max_im = 1.4;
		a->p[i].move_x = 0;
		a->p[i].move_y = 0;
		a->p[i].mr = 0;
		a->p[i].mi = 0;
		a->f.is_space = 0;
		a->p[i].max_iter = 100;
	}
}

int		zoom(int button, int x, int y, t_mlx *a)
{
	a->cm.x = x;
	a->cm.y = y;
	if (button == 5)
		plus_zoom(a);
	if (button == 4)
		minus_zoom(a);
	if (button == 3)
		reset_zoom(a);
	return (0);
}
