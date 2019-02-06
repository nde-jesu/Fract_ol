/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:56:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/06 18:22:05 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#define X_M -1.5
#define X_L  1.
#define Y_M -1.5
#define Y_L  0.6

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

	fract->min = init_pt(X_M+(X_L/2)-(X_L/(2 * fract->zoom)+fract->delta.x), \
			Y_M+(Y_L/2)-(Y_L/(2*fract->zoom)+fract->delta.y));
	fract->max = init_pt(fract->min.x+(X_L/fract->zoom), \
			fract->min.y+(Y_L/fract->zoom));
	ct.x = -1;
	while (++ct.x < WIDTH)
	{
		ct.y = -1;
		while (++ct.y < HEIGHT)
		{
			fract->c = init_pt(0.285, 0.01);
			fract->z = init_pt(ct.x / fract->zoom + fract->min.x, \
				ct.y / fract->zoom + fract->min.y);
			i = 0;
			while (fract->z.x * fract->z.x + fract->z.y * fract->z.y < 4 && \
					i < fract->i_max)
				i = norme(fract, i);
			if (i == fract->i_max)
				put_pixel_img(fract->mlx->img, ct.x, ct.y, 0xEAEAEA);
		}
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
	if (fract->toggle == 1)
		print_menu(fract);
}
