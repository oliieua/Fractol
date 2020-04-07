/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:31:35 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 16:03:23 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	usage(char *num, int ac)
{
	int	i;

	if (ac == 1 || ac >= 3)
	{
		ft_putendl("usage: ./fractol [fractal number ..]");
		exit(0);
	}
	i = ft_atoi(num);
	if (i > FRACT || i == 0 || ft_strlen(num) > 1)
		ft_putendl("\033[1;32mPut valid number of fractal:\n\t[1] - \
Mandelbrot\n\t[2] - Julia\n\t[3] - Mandelbrot 4th \
Order\n\t[4] - Burning ship\n\t[5] - Chiken");
}

void	instr(char *num)
{
	int	i;

	i = ft_atoi(num);
	ft_putendl("\033[1;32mHot keys:\n\tCamera move: \
Arrows\n\tColors: R/G/B\n\tChange iterations: +/-\n\tZoom: Mouse wheel\n\t\
Reset: Wheel button\n\tExit: ESC");
	if (i == 2)
		ft_putendl("\tJulia change: Space");
	ft_putstr("\033[0m");
}
