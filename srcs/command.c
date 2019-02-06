/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:05:47 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/06 16:51:52 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "mlx_macro_keys.h"

#include <stdio.h>
void	reload(t_fract *fract)
{
	if (fract->type == 1)
		mandel(fract);
	if (fract->type == 2)
		julia(fract);
	if (fract->type == 3)
		koch(fract);
}

void	zoom(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_PAD_ADD || key == KEY_EQUAL || key == MOUSE_SCROLL_UP)
		fract->zoom *= 1.1;
	else if (key == KEY_PAD_SUB || key == KEY_MINUS || key == MOUSE_SCROLL_DOWN)
		if (fract->zoom > 1)
			fract->zoom /= 1.1;
	reload(fract);
}

void	space(t_fract *fract)
{
	fract = new_img(fract);
	fract->toggle *= -1;
	reload(fract);
}

void	translation(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_LEFT)
		fract->delta.x = (fract->delta.x > -3 ? fract->delta.x - 0.05\
				/ fract->zoom : -3);
	if (key == KEY_RIGHT)
		fract->delta.x = (fract->delta.x < 3 ? fract->delta.x + 0.05\
				/ fract->zoom : 3);
	if (key == KEY_UP)
		fract->delta.y = (fract->delta.y > -2 ? fract->delta.y - 0.05\
				/ fract->zoom : -2);
	if (key == KEY_DOWN)
		fract->delta.y = (fract->delta.y < 2 ? fract->delta.y + 0.05\
				/ fract->zoom : 2);
	reload(fract);
}
