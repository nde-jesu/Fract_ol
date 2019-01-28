/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:38:27 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/28 10:38:01 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

void	mandel(t_fract *fract)
{
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			max_x;
	int			max_y;
	int			x;
	int			y;
	int			zoom;
	int			ite_max;
	int			c_r;
	int			c_i;
	int			z_r;
	int			z_i;
	int			i;
	int			tmp;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	zoom = 500;
	ite_max = 50;
	max_x = (x2 - x1) * zoom;
	max_y = (y2 - y1) * zoom;
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
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
