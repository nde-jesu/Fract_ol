/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:12:01 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/06 17:23:04 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 500
# define WIDTH 750
# define MENU_WIDTH 0

typedef struct	s_pt
{
	float	x;
	float	y;
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
	int		pressed;
	int		act_x;
	int		act_y;
	int		prev_x;
	int		prev_y;
}				t_mouse;

typedef struct	s_fract
{
	t_pt	min;
	t_pt	max;
	t_pt	z;
	t_pt	c;
	t_pt	delta;
	int		i_max;
	t_mlx	*mlx;
	int		type;
	float	zoom;
	t_mouse	mouse;
	int		toggle;
}				t_fract;

void		put_pixel_img(t_img *img, int x, int y, int color);
void		img_draw_line(t_pt a, t_pt b, t_img *img);
t_fract		*init_fract(const char *s);
void		mandel(t_fract *fract);
void		julia(t_fract *fract);
void		koch(t_fract *fract);
t_pt		init_pt(float x, float y);
void		print_menu(t_fract *fract);
void		get_ctrl(t_fract *fract);
t_fract		*new_img(t_fract *fract);
void		zoom(int key, t_fract *fract);
int			press(int click, int x, int y, void *param);
int			release();
int			move(int x, int y, void *param);
void		img_draw_line(t_pt a, t_pt b, t_img *img);
void		space(t_fract *fract);
void		translation(int key, t_fract *fract);

#endif
