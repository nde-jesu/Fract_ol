/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:38:27 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/28 12:55:37 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	mandel(t_fract *fract)
{
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		img_x;
	int		img_y;
	int		x;
	int		y;
	float	zoom;
	int		ite_max;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		i;
	float	tmp;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 500;
	ite_max = 50;
	img_x = (x2 - x1) * zoom;
	img_y = (y2 - y1) * zoom;
	x = 0;
	while (x < img_x)
	{
		y = 0;
		while (y < img_y)
		{
			c_r = x / zoom + x1;
			c_i = y / zoom + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < ite_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				++i;
			}
			if (i == ite_max)
				put_pixel_img(fract, x, y, 0xEAEAEA);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
}
