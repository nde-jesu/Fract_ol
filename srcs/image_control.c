/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:33:45 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/08 13:52:35 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * img->bpp / 8) + (y * img->size_l);
		img->data[i] = color;
		img->data[++i] = color >> 8;
		img->data[++i] = color >> 16;
	}
}

void	img_draw_line(t_pt a, t_pt b, t_img *img)
{
	double		x;
	double		y;
	double		inc_x;
	double		inc_y;
	double		m;

	x = (double)a.x;
	y = (double)a.y;
	inc_x = (double)(b.x - a.x);
	inc_y = (double)(b.y - a.y);
	m = (double)ft_max(ft_abs((int)inc_x), ft_abs((int)inc_y));
	inc_x /= m;
	inc_y /= m;
	while (m >= 0)
	{
		put_pixel_img(img, (int)x, (int)y, 0xEAEAEA);
		x += inc_x;
		y += inc_y;
		--m;
	}
}
