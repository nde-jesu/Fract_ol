/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/11 14:52:11 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static int		norme2(t_fract *fract, int i)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y - fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp - fract->c.y;
	--i;
	return (i);
}

static int		norme(t_fract *fract, int i)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y + fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp + fract->c.y;
	++i;
	return (i);
}

static int		norme3(t_fract *fract)
{
	int		i;

	i = 0;
	if (fract->i_max > 0)
		while (fract->z.x * fract->z.x + fract->z.y * fract->z.y < 4 &&\
				i < fract->i_max)
			i = norme(fract, i);
	else
		while (fract->z.x * fract->z.x + fract->z.y * fract->z.y < 4 &&\
				i > fract->i_max)
			i = norme2(fract, i);
	return (i);
}

void			julia(t_fract *fract)
{
	t_pt	ct;

	ct.x = -1;
	while (++ct.x < WIDTH)
	{
		ct.y = -1;
		while (++ct.y < HEIGHT)
		{
			fract->c = init_pt(0.285, 0.01);
			fract->z = init_pt(ct.x / fract->zoom + fract->min.x, \
					ct.y / fract->zoom + fract->min.y);
			if (norme3(fract) == fract->i_max)
				put_pixel_img(fract->mlx->img, ct.x, ct.y, 0xEAEAEA);
		}
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
	if (fract->toggle_menu == 1)
		print_menu(fract);
}
