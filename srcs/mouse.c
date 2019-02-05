/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:51:13 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/05 15:22:56 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_macro_keys.h"

#include <stdio.h>
int		press(int click, int x, int y, void *param)
{
	t_fract		*fract;

	(void)x;
	(void)y;
	fract = (t_fract*)param;
	if (click == MOUSE_SCROLL_UP || click == MOUSE_SCROLL_DOWN)
		zoom(click, param);
	else if (click == MOUSE_LEFT_BUTTON)
		return (1);
	return (0);
}

int		release()
{
	return (1);
}

int		move(int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract*)param;
	(void)y;
	if (fract->type == 2)
	{
		fract = new_img(fract);
		fract->i_max = x / 10;
		if (fract->i_max < 1)
			fract->i_max = 1;
		else if (fract->i_max > 250)
			fract->i_max = 250;
		julia(fract);
	}
	return (0);
}
