/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:05:47 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/03/06 08:50:10 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "mlx_macro_keys.h"

void	change_type_julia(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_PAGE_UP)
	{
		++fract->type_julia;
		if (fract->type_julia == 6)
			fract->type_julia = 0;
	}
	else if (key == KEY_PAGE_DOWN)
	{
		--fract->type_julia;
		if (fract->type_julia == -1)
			fract->type_julia = 5;
	}
	init_params(fract, 1);
	reload(fract);
}

void	change_fract(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_LESS_THAN)
	{
		--fract->type;
		if (fract->type == 0)
			fract->type = 3;
	}
	if (key == KEY_MORE_THAN)
	{
		++fract->type;
		if (fract->type == 4)
			fract->type = 1;
	}
	init_params(fract, 1);
	reload(fract);
}

void	space(t_fract *fract)
{
	fract = new_img(fract);
	fract->toggle_menu *= -1;
	reload(fract);
}

void	translation(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_LEFT)
		fract->min.x += 30 / fract->zoom;
	if (key == KEY_RIGHT)
		fract->min.x -= 30 / fract->zoom;
	if (key == KEY_UP)
		fract->min.y += 30 / fract->zoom;
	if (key == KEY_DOWN)
		fract->min.y -= 30 / fract->zoom;
	reload(fract);
}
