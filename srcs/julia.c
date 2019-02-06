/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/06 09:24:04 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static int		norme(t_fract *fract, int i)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y + fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp + fract->c.y;
	++i;
	return (i);
}

void			julia(t_fract *fract)
{
	int		i;
	t_pt	ct;

	ct.x = -1;
	while (++ct.x < WIDTH)
	{
		ct.y = 0;
		while (ct.y < HEIGHT)
		{
			fract->c = init_pt(0.285, 0.01);
			fract->z = init_pt(ct.x / fract->zoom + fract->min.x, \
				ct.y / fract->zoom + fract->min.y);
			i = 0;
			while (fract->z.x * fract->z.x + fract->z.y * fract->z.y < 4 && \
					i < fract->i_max)
				i = norme(fract, i);
			if (i == fract->i_max)
				put_pixel_img(fract->mlx->img, ct.x + MENU_WIDTH, \
						ct.y, 0xEAEAEA);
			++ct.y;
		}
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, MENU_WIDTH, 0);
}
