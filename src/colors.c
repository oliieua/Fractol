/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:53:43 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 12:10:00 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	img(t_p *p, int x, int y, int i)
{
	double	t;

	t = (double)i / p->max_iter;
	if (p->cn == 1)
		red(p, &t);
	else if (p->cn == 2)
		green(p, &t);
	else if (p->cn == 3)
		blue(p, &t);
	p->data[y * p->sl + x * p->bpp / 8] = p->b;
	p->data[y * p->sl + x * p->bpp / 8 + 1] = p->g;
	p->data[y * p->sl + x * p->bpp / 8 + 2] = p->r;
}

void	blue(t_p *p, double *t)
{
	p->r = (int)(9 * (1 - *t) * *t * *t * *t * 255);
	p->g = (int)(15 * (1 - *t) * (1 - *t) * *t * *t * 255);
	p->b = (int)(8.5 * (1 - *t) * (1 - *t) * (1 - *t) * *t * 255);
}

void	red(t_p *p, double *t)
{
	p->r = (int)(8.5 * (1 - *t) * (1 - *t) * (1 - *t) * *t * 255);
	p->g = (int)(15 * (1 - *t) * (1 - *t) * *t * *t * 255);
	p->b = (int)(9 * (1 - *t) * *t * *t * *t * 255);
}

void	green(t_p *p, double *t)
{
	p->r = (int)(15 * (1 - *t) * (1 - *t) * *t * *t * 255);
	p->g = (int)(8.5 * (1 - *t) * (1 - *t) * (1 - *t) * *t * 255);
	p->b = (int)(9 * (1 - *t) * *t * *t * *t * 255);
}
