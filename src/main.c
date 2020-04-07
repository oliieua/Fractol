/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:25:10 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 16:08:34 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	nof(t_mlx *a, char *num, int i)
{
	if (ft_atoi(num) == 1 && ft_strlen(num) == 1)
		pthread_create(&a->thread[i], NULL, mandelbrot, (void*)&a->p[i]);
	else if (ft_atoi(num) == 2 && ft_strlen(num) == 1)
		pthread_create(&a->thread[i], NULL, julia, (void*)&a->p[i]);
	else if (ft_atoi(num) == 3 && ft_strlen(num) == 1)
		pthread_create(&a->thread[i], NULL, mandel4, (void*)&a->p[i]);
	else if (ft_atoi(num) == 4 && ft_strlen(num) == 1)
		pthread_create(&a->thread[i], NULL, bsh, (void*)&a->p[i]);
	else if (ft_atoi(num) == 5 && ft_strlen(num) == 1)
		pthread_create(&a->thread[i], NULL, chiken, (void*)&a->p[i]);
	else
		exit(0);
}

void	win_name(t_mlx *a, char *num)
{
	if (ft_atoi(num) == 1 && ft_strlen(num) == 1)
		a->fract_name = "Mandelbrot";
	else if (ft_atoi(num) == 2 && ft_strlen(num) == 1)
		a->fract_name = "Julia";
	else if (ft_atoi(num) == 3 && ft_strlen(num) == 1)
		a->fract_name = "Mandelbrot 4th Order";
	else if (ft_atoi(num) == 4 && ft_strlen(num) == 1)
		a->fract_name = "Burning ship";
	else if (ft_atoi(num) == 5 && ft_strlen(num) == 1)
		a->fract_name = "Chiken";
	else
		exit(0);
}

int		draw_fract(t_mlx *a)
{
	int	i;

	i = -1;
	init2(a);
	while (++i < THREADS)
		nof(a, a->name, i);
	i = -1;
	while (++i < THREADS)
		pthread_join(a->thread[i], NULL);
	mlx_clear_window(a->mlx_p, a->win_p);
	i = -1;
	while (++i < THREADS)
	{
		mlx_put_image_to_window(a->mlx_p,
			a->win_p, a->p[i].img_p, 0, a->p[i].yyy);
		mlx_destroy_image(a->mlx_p, a->p[i].img_p);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_mlx	a;

	if (ac >= 1)
	{
		usage(av[1], ac);
		a.name = av[1];
		init(&a);
		mlx_loop_hook(a.mlx_p, draw_fract, &a);
		instr(a.name);
		mlx_hook(a.win_p, 6, 6, mouse_move, &a);
		mlx_hook(a.win_p, 2, 2, move, &a);
		mlx_hook(a.win_p, 3, 3, color_switch, &a);
		mlx_hook(a.win_p, 4, 4, zoom, &a);
		mlx_hook(a.win_p, 17, 1L << 17, ft_close, &a);
		mlx_loop(a.mlx_p);
	}
}
