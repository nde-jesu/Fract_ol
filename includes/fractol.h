/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:12:01 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/14 12:02:27 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 600
# define WIDTH 750
# define X_M -2.5
# define X_L 1.0
# define Y_M -1.5
# define Y_L 0.6

typedef struct	s_pt
{
	float	x;
	float	y;
	int		clr;
}				t_pt;

typedef struct	s_line
{
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		r_offset;
	int		c_offset;
}				t_line;

typedef struct	s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	t_img	*img;
}				t_mlx;

typedef struct	s_mouse
{
	int		toggle_mouse;
	int		pressed;
	int		act_x;
	int		act_y;
	int		prev_x;
	int		prev_y;
}				t_mouse;

typedef struct	s_fract
{
	int		paddle[5];
	t_pt	min;
	t_pt	max;
	t_pt	z;
	t_pt	c;
	t_pt	delta;
	int		i_max;
	t_mlx	*mlx;
	int		type;
	int		type_julia;
	float	zoom;
	t_mouse	mouse;
	int		toggle_menu;
}				t_fract;

void			put_pixel_img(t_img *img, int x, int y, int color);
void			img_draw_line(t_pt a, t_pt b, t_img *img, int color);
t_fract			*init_fract(const char *s);
void			init_params(t_fract *fract, int cases);
void			mandel(t_fract *fract);
void			julia(t_fract *fract);
void			barnsley(t_fract *fract);
t_pt			init_pt(float x, float y);
void			print_menu(t_fract *fract);
void			get_ctrl(t_fract *fract);
t_fract			*new_img(t_fract *fract);
void			zoom(int key, t_fract *fract);
int				press(int click, int x, int y, void *param);
int				move(int x, int y, void *param);
void			space(t_fract *fract);
void			translation(int key, t_fract *fract);
void			change_fract(int key, t_fract *fract);
void			change_type_julia(int key, t_fract *fract);
void			reload(t_fract *fract);
int				get_clr(int min, int max, int act, t_fract *fract);
float			square(float n);
void			choice_color(t_fract *fract, int paddle_choice);
double			percent(int start, int end, int act);
void			change_paddle(t_fract *fract);

#endif
