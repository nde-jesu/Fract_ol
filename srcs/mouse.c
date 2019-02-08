/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:51:13 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/08 13:51:15 by reda-con         ###   ########.fr       */
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
	{
		zoom(click, param);
	}
	else if (click == MOUSE_LEFT_BUTTON)
		return (1);
	return (0);
}

int		release(void)
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
		fract->mouse.prev_x = fract->mouse.act_x;
		fract->mouse.act_x = x;
		if (fract->mouse.act_x < fract->mouse.prev_x)
			fract->i_max = x / 10;
		else
			fract->i_max = x / 10;
		if (fract->i_max == 0)
			fract->i_max = 1;
		julia(fract);
	}
	return (0);
}
