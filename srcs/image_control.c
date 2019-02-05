/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:33:45 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/05 16:22:10 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * img->bpp / 8) + (y * img->size_l);
		img->data[i] = color;
		img->data[++i] = color >> 8;
		img->data[++i] = color >> 16;
	}
}

static int	ft_abs(int nb)
{
	return (nb < 0 ? -nb : nb);
}

void	img_draw_line(t_pt a, t_pt b, t_img *img)
{
	t_pt	curr;
	t_line	params;

	params.delta_y = ft_abs(b.y - a.y);
	params.delta_x = ft_abs(b.x - a.x);
	params.sign_x = (a.x - b.x ? 1 : -1);
	params.sign_y = (a.y - b.y ? 1 : -1);
	params.c_offset = params.delta_x - params.delta_y;
	curr = a;
	while (curr.y != b.y || curr.x != b.x)
	{
		put_pixel_img(img, curr.x, curr.y, 0xEAEAEA);
		if ((params.r_offset = params.c_offset * 2) > -params.delta_y)
		{
			params.c_offset -= params.delta_y;
			curr.x += params.sign_x;
		}
		if (params.r_offset < params.delta_x)
		{
			params.c_offset += params.delta_x;
			curr.y += params.sign_y;
		}
	}
}
