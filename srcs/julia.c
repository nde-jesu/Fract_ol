/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/12 13:37:21 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

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
	return (init_pt(-1, 1));
}

static int		norme2(t_fract *fract, int i)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y - fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp + fract->c.y;
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
	fract->c = type_julia(fract);
	while (++ct.x < WIDTH)
	{
		ct.y = -1;
		while (++ct.y < HEIGHT)
		{
			fract->z = init_pt(ct.x / fract->zoom + fract->min.x,\
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
