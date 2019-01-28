/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 09:33:45 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/28 09:37:46 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_img(t_fract *fract, int x, int y, int color)
{
	int		i;

	i = (x * fract->mlx->img->bpp / 8) + (y * fract->mlx->img->size_l);
	fract->mlx->img->data[i] = color;
	fract->mlx->img->data[++i] = color >> 8;
	fract->mlx->img->data[++i] = color >> 8;
}
