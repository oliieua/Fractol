/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:59:09 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/07/03 15:22:32 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H
# include "../lib/libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define SCREEN_W 1200
# define SCREEN_H 600
# define THREADS 8
# define FRACT 5

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			cn;
}				t_color;

typedef struct	s_camera
{
	double		move_x;
	double		move_y;
	double		zoom;
	double		x;
	double		y;
}				t_camera;

typedef struct	s_fractal
{
	double		curr_re;
	double		curr_im;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		min_re;
	double		min_im;
	double		max_re;
	double		max_im;
	double		mouse_re;
	double		mouse_im;
	int			max_iter;
	int			is_space;
	double		c_re;
	double		c_im;
}				t_fractal;

typedef struct	s_p
{
	void		*mlx_p;
	void		*win_p;
	void		*img_p;
	double		curr_re;
	double		curr_im;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		min_re;
	double		min_im;
	double		max_re;
	double		max_im;
	double		mouse_re;
	double		mouse_im;
	int			max_iter;
	int			is_space;
	double		c_re;
	double		c_im;
	double		move_x;
	double		move_y;
	double		zoom;
	double		x;
	double		y;
	double		yyy;
	double		y_max;
	double		move_re;
	double		move_im;
	int			r;
	int			g;
	int			b;
	int			bpp;
	int			sl;
	int			endian;
	char		*data;
	int			cn;
	double		mr;
	double		mi;
}				t_p;

typedef struct	s_mlx
{
	void		*mlx_p;
	void		*win_p;
	void		*img_p;
	t_color		c;
	t_fractal	f;
	t_camera	cm;
	t_p			*p;
	char		*name;
	char		*fract_name;
	pthread_t	thread[THREADS];
}				t_mlx;

int				move(int key, t_mlx *a);
int				mouse_move(int x, int y, t_mlx *a);
int				draw_fract(t_mlx *a);
void			init(t_mlx *a);
void			init2(t_mlx *a);
void			img(t_p *p, int x, int y, int i);
void			*mandelbrot(void *args);
void			*julia(void *args);
void			blue(t_p *p, double *t);
void			red(t_p *p, double *t);
void			green(t_p *p, double *t);
int				color_switch(int key, t_mlx *a);
void			win_name(t_mlx *a, char *num);
void			*fractaw(void *args);
void			*mandel4(void *args);
void			*bsh(void *args);
void			*chiken(void *args);
int				ft_close(void *param);
int				zoom(int button, int x, int y, t_mlx *a);
void			mandel4_h(t_p *p, int *i, int *x, int *yy);
void			usage(char *num, int ac);
void			instr(char *num);

#endif
