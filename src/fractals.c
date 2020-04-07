/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:44:42 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 12:15:05 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot_h(t_p *p, int *i, int *x, int *yy)
{
	while (*i < p->max_iter)
	{
		p->old_re = p->new_re;
		p->old_im = p->new_im;
		p->new_re = p->old_re * p->old_re - p->old_im * p->old_im + p->curr_re;
		p->new_im = 2 * p->old_re * p->old_im + p->curr_im;
		if ((p->new_re * p->new_re + p->new_im * p->new_im) > 4)
		{
			img(p, *x, *yy, *i);
			break ;
		}
		*i += 1;
	}
}

void	*mandelbrot(void *args)
{
	t_p		*p;
	int		x;
	int		i;
	int		yy;

	yy = 0;
	p = args;
	while (p->y < p->y_max)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			i = 0;
			p->new_re = 0;
			p->new_im = 0;
			p->curr_re = p->min_re + x * (p->max_re - p->min_re) /
			(SCREEN_W) + p->move_x;
			p->curr_im = p->min_im + p->y * (p->max_im - p->min_im) /
			(SCREEN_H) + p->move_y;
			mandelbrot_h(p, &i, &x, &yy);
		}
		yy++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	julia_h(t_p *p, int *i, int *x, int *yy)
{
	while (*i < p->max_iter)
	{
		p->old_re = p->new_re;
		p->old_im = p->new_im;
		p->new_re = p->old_re * p->old_re - p->old_im * p->old_im + p->c_re;
		p->new_im = 2 * p->old_re * p->old_im + p->c_im;
		if (p->new_re * p->new_re + p->new_im * p->new_im > 4)
		{
			img(p, *x, *yy, *i);
			break ;
		}
		*i += 1;
	}
}

void	*julia(void *args)
{
	int		x;
	int		yy;
	int		i;
	t_p		*p;

	p = args;
	yy = 0;
	p->c_re = -0.70176 + p->mr;
	p->c_im = -0.3842 + p->mi;
	while (p->y < p->y_max)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			i = 0;
			p->new_re = p->min_re + x * (p->max_re - p->min_re) /
			(SCREEN_W) + p->move_x;
			p->new_im = p->min_im + p->y * (p->max_im - p->min_im) /
			(SCREEN_H) + p->move_y;
			julia_h(p, &i, &x, &yy);
		}
		yy++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	*mandel4(void *args)
{
	t_p		*p;
	int		x;
	int		i;
	int		yy;

	yy = 0;
	p = args;
	while (p->y < p->y_max)
	{
		x = -1;
		while (++x < SCREEN_W)
		{
			i = 0;
			p->new_re = 0;
			p->new_im = 0;
			p->curr_re = p->min_re + x * (p->max_re - p->min_re) /
			(SCREEN_W) + p->move_x;
			p->curr_im = p->min_im + p->y * (p->max_im - p->min_im) /
			(SCREEN_H) + p->move_y;
			mandel4_h(p, &i, &x, &yy);
		}
		yy++;
		p->y++;
	}
	pthread_exit(NULL);
}
