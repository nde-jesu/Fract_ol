/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/12 13:33:37 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static void		norme2(t_fract *fract)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y - fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp + fract->c.y;
}

static void		norme(t_fract *fract)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y + fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp + fract->c.y;
}

#include <stdio.h>
static int		norme3(t_fract *fract, t_pt *ct)
{
	int		i;
	int		neg;
	int		tmp;

	neg = (fract->i_max < 0) ? 1 : 0;
	tmp = (fract->i_max < 0) ? fract->i_max * -1 : fract->i_max;
	ct->clr = 0xFF0000;
	i = 0;
	while (fract->z.x * fract->z.x + fract->z.y * fract->z.y < 4 &&\
			i < tmp)
	{
		if (neg == 0)
			norme(fract);
		else
			norme2(fract);
		++ct->clr;
		++i;
	}
	return (i);
}

void			julia(t_fract *fract)
{
	t_pt	*ct;

	ct = malloc(sizeof(t_pt));
	ct->x = -1;
	while (++ct->x < WIDTH)
	{
		ct->y = -1;
		while (++ct->y < HEIGHT)
		{
			fract->c = init_pt(-0.772691322542185, 0.124281466072787);
			fract->z = init_pt(ct->x / fract->zoom + fract->min.x,\
					ct->y / fract->zoom + fract->min.y);
			if (norme3(fract, ct) == fract->i_max)
				put_pixel_img(fract->mlx->img, ct->x, ct->y, ct->clr);
			else
				put_pixel_img(fract->mlx->img, ct->x, ct->y, 0x000000);
		}
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
	if (fract->toggle_menu == 1)
		print_menu(fract);
}
