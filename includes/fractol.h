/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:12:01 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/28 12:10:58 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1250
# define WIDTH 2500

typedef struct	s_pt
{
	float	x;
	float	y;
}				t_pt;

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

typedef struct	s_fract
{
	t_mlx	*mlx;
	int		type;
}				t_fract;

void		put_pixel_img(t_fract *fract, int x, int y, int color);
t_fract		*init_fract(const char *s);
void		mandel(t_fract *fract);
void		julia(t_fract *fract);

#endif