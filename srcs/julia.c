/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/28 12:57:37 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

t_pt	init_pt(float x, float y)
{
	t_pt	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void	julia(t_fract *fract)
{
	t_pt	a;
	t_pt	b;
	int		zoom;
	int		i_max;
	t_pt	image;
	t_pt	ct;
	t_pt	c;
	t_pt	z;
	int		i;
	float	tmp;

	a = init_pt(-1, -1.2);
	b = init_pt(1, 1.2);
	zoom = 500;
	image = init_pt ((b.x - a.x) * zoom, (b.y - a.y) * zoom);
	i_max = 150;
	ct.x = 0;
	while (ct.x < image.x)
	{
		ct.y = 0;
		while (ct.y < image.y)
		{
			c = init_pt(0.285, 0.01);
			z = init_pt(ct.x / zoom + a.x, ct.y / zoom + a.y);
			i = 0;
			while (z.x * z.x + z.y * z.y < 4 && i < i_max)
			{
				tmp = z.x;
				z.x = z.x * z.x - z.y * z.y + c.x;
				z.y = 2 * z.y * tmp + c.y;
				++i;
			}
			if (i == i_max)
				put_pixel_img(fract, ct.x, ct.y, 0xEAEAEA);
			++ct.y;
		}
		++ct.x;
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
}
