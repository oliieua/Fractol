/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:09:27 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 12:20:44 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandel4_h(t_p *p, int *i, int *x, int *yy)
{
	while (*i < p->max_iter)
	{
		p->old_im = 4 * p->old_re * p->old_im *
		(p->new_re - p->new_im) + p->curr_im;
		p->old_re = p->new_re * p->new_re + p->new_im * p->new_im - 6
		* p->new_re * p->new_im + p->curr_re;
		p->new_im = p->old_im * p->old_im;
		p->new_re = p->old_re * p->old_re;
		if ((p->new_re * p->new_re + p->new_im * p->new_im) > 4)
		{
			img(p, *x, *yy, *i);
			break ;
		}
		*i += 1;
	}
}

void	bsh_h(t_p *p, int *i, int *x, int *yy)
{
	while (*i < p->max_iter)
	{
		p->old_im = p->new_im;
		p->old_re = p->new_re;
		p->new_im = fabs(p->old_re * p->old_im) * 2.0 + p->curr_im;
		p->new_re = (p->old_re * p->old_re) -
		(p->old_im * p->old_im) + p->curr_re;
		if ((p->new_re * p->new_re + p->new_im * p->new_im) > 4)
		{
			img(p, *x, *yy, *i);
			break ;
		}
		*i += 1;
	}
}

void	*bsh(void *args)
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
			bsh_h(p, &i, &x, &yy);
		}
		yy++;
		p->y++;
	}
	pthread_exit(NULL);
}

void	chiken_h(t_p *p, int *i, int *x, int *yy)
{
	while (*i < p->max_iter)
	{
		p->old_im = p->new_im;
		p->old_re = p->new_re;
		p->new_im = p->old_re * fabs(p->old_im) * 2.0 + p->curr_im;
		p->new_re = (p->old_re * p->old_re) -
		(p->old_im * p->old_im) + p->curr_re;
		if ((p->new_re * p->new_re + p->new_im * p->new_im) > 4)
		{
			img(p, *x, *yy, *i);
			break ;
		}
		*i += 1;
	}
}

void	*chiken(void *args)
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
			chiken_h(p, &i, &x, &yy);
		}
		yy++;
		p->y++;
	}
	pthread_exit(NULL);
}
