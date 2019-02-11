/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:40:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/11 09:50:13 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include "../libft/includes/libft.h"
#include <mlx.h>

void	fractale(t_pt a, t_pt b, t_fract *fract, int level)
{
	t_pt		pt1;
	t_pt		pt2;
	t_pt		pt3;

	if (level > 0)
	{
		pt1 = init_pt((2 * a.x + b.x) / 3, (2 * a.y + b.y) / 3);
		pt2 = init_pt((a.x + 2 * b.x) / 3, (a.y + 2 * b.y) / 3);
		pt3 = init_pt((pt1.x + (pt2.x - pt1.x) / 2
					+ (pt2.y - pt1.y) * sqrt(3) / 2)
						, (pt1.y - (pt2.x - pt1.x) * sqrt(3) / 2
							+ (pt2.y - pt1.y) / 2));
		fractale(a, pt1, fract, level - 1);
		fractale(pt1, pt3, fract, level - 1);
		fractale(pt3, pt2, fract, level - 1);
		fractale(pt2, b, fract, level - 1);
	}
	else
	{
		a.x = a.x * fract->zoom - fract->min.x;
		a.y = a.y * fract->zoom - fract->min.y;
		b.x = b.x * fract->zoom - fract->min.x;
		b.y = b.y * fract->zoom - fract->min.y;
		img_draw_line(a, b, fract->mlx->img);
	}
}

void	koch(t_fract *fract)
{
	fractale(init_pt(320, 60), init_pt(520, 340), fract, 10);
	fractale(init_pt(520, 340), init_pt(120, 340), fract, 10);
	fractale(init_pt(120, 340), init_pt(320, 60), fract, 10);
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, 0, 0);
	if (fract->toggle_menu == 1)
		print_menu(fract);
}
