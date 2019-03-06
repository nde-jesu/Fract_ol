/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:33:45 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/03/06 09:40:46 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

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
