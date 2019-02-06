/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:05:47 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/06 09:32:32 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "mlx_macro_keys.h"


void	zoom(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_PAD_ADD || key == KEY_EQUAL || key == MOUSE_SCROLL_UP)
	{
		fract->zoom *= 1.1;
	}
	else if (key == KEY_PAD_SUB || key == KEY_MINUS || key == MOUSE_SCROLL_DOWN)
	{
		if (fract->zoom > 1)
			fract->zoom /= 1.1;
	}
	else if (fract->type == 1)
	{
		fract->min.x = (-2.1 / fract->zoom) + fract->delta.x;
		fract->min.y = (-1.2 / fract->zoom) + fract->delta.y;
		fract->max.x = (0.6 / fract->zoom) + fract->delta.x;
		fract->max.y = (1.2 / fract->zoom) + fract->delta.y;
		mandel(fract);
	}
	if (fract->type == 2)
	{
		fract->min.x = (-1 / fract->zoom) + fract->delta.x;
		fract->min.y = (-1.2 / fract->zoom) + fract->delta.y;
		fract->max.x = (1 / fract->zoom) + fract->delta.x;
		fract->max.y = (1.2 / fract->zoom) + fract->delta.y;
		julia(fract);
	}
	else
	{
		koch(fract);
	}
}

void	translation(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_LEFT)
		fract->delta.x -= 0.05 / fract->zoom;
	if (key == KEY_RIGHT)
		fract->delta.x += 0.05 / fract->zoom;
	if (key == KEY_UP)
		fract->delta.y -= 0.05 / fract->zoom;
	if (key == KEY_DOWN)
		fract->delta.y += 0.05 / fract->zoom;
}

