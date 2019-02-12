/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:38:27 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/12 16:26:56 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static int	norme(t_fract *fract, int i)
{
	float	tmp;

	tmp = fract->z.x;
	fract->z.x = fract->z.x * fract->z.x - fract->z.y * fract->z.y + fract->c.x;
	fract->z.y = 2 * fract->z.y * tmp + fract->c.y;
	++i;
	return (i);
}

void		mandel(t_fract *fract)
{
	t_pt	ct;
	int		i;

	ct.x = -1;
	while (++ct.x < WIDTH)
	{
		ct.y = -1;
		while (++ct.y < HEIGHT)
		{
			fract->c = init_pt(ct.x / fract->zoom + fract->min.x, \
					ct.y / fract->zoom + fract->min.y);
			fract->z = init_pt(0, 0);
			i = 0;
			while (fract->z.x * fract->z.x + fract->z.y * fract->z.y < 4 \
					&& i < fract->i_max)
				i = norme(fract, i);
			put_pixel_img(fract->mlx->img, ct.x, ct.y,\
					get_clr(0, fract->i_max, i, fract));
		}
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
	if (fract->toggle_menu == 1)
		print_menu(fract);
}
