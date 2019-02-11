/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:31:47 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/11 10:20:41 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx.h"

static t_pt	norme(int r, t_pt pt)
{
	if (r < 2)
	{
		pt.x = 50;
		pt.y = 0.27 * pt.y;
	}
	else if (r < 17)
	{
		pt.x = -0.139 * pt.x + 0.263 * pt.y + 57;
		pt.y = 0.246 * pt.x + 0.224 * pt.y - 8.28;
	}
	else if (r < 30)
	{
		pt.x = 0.17 * pt.x - 0.215 * pt.y + 40.8;
		pt.y = 0.222 * pt.x + 0.176 * pt.y + 20.539;
	}
	else
	{
		pt.x = 0.781 * pt.x + 0.034 * pt.y + 10.75;
		pt.y = -0.032 * pt.x + 0.739 * pt.y + 62.1;
	}
	return (pt);
}

void	barnsley(t_fract *fract)
{
	int		k;
	int		r;
	t_pt	pt;

	pt.x = 0;
	pt.y = 50;
	k = 0;
	while (++k < fract->i_max)
	{
		r = rand()%100;
		pt = norme(r, pt);
		pt.x = pt.x * fract->zoom - fract->min.x;
		pt.y = pt.y * fract->zoom - fract->min.y;
		put_pixel_img(fract->mlx->img, 3 * (235 - pt.y), 3 * (pt.x - 5)
				+ 10, 0xEAEAEA);
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win,
			fract->mlx->img->ptr, 0, 0);
	if (fract->toggle_menu == 1)
		print_menu(fract);
}
