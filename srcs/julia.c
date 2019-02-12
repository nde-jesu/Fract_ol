/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/12 14:01:40 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static t_pt		type_julia(t_fract *fract)
{
	if (fract->type_julia == 0)
		return (init_pt(-0.7927, 0.1609));
	else if (fract->type_julia == 1)
		return (init_pt(0.32, 0.043));
	else if (fract->type_julia == 2)
		return (init_pt(-1.1380, 0.2403));
	else if (fract->type_julia == 3)
		return (init_pt(-0.0986, -0.65186));
	else if (fract->type_julia == 4)
		return (init_pt(-0.1225, 0.7449));
	else if (fract->type_julia == 5)
		return (init_pt(-0.3380, -0.6230));
	return (init_pt(0, 0));
}

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
			fract->c = type_julia(fract);;
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
