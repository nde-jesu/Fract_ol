/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:23:36 by reda-con          #+#    #+#             */
/*   Updated: 2019/03/06 11:03:05 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	print_menu(t_fract *fract)
{
	void	*win;
	void	*ptr;

	win = fract->mlx->win;
	ptr = fract->mlx->ptr;
	mlx_string_put(ptr, win, 10, 10, ME_COLOR, "Fract'ol");
	if (fract->type == 1)
		mlx_string_put(ptr, win, 10, 60, ME_COLOR, "Fractal : Mandelbrot");
	else if (fract->type == 2)
	{
		mlx_string_put(ptr, win, 10, 60, ME_COLOR, "Fractal : Julia");
		mlx_string_put(ptr, win, 10, 200, ME_COLOR, "M : activate iterations");
		mlx_string_put(ptr, win, 10, 220, ME_COLOR, "Pg Up/Down : change type");
	}
	else
		mlx_string_put(ptr, win, 10, 60, ME_COLOR, "Fractal : Barnsley");
	mlx_string_put(ptr, win, 10, 100, ME_COLOR, "How to use :");
	mlx_string_put(ptr, win, 10, 120, ME_COLOR, "< or > : change fractal");
	mlx_string_put(ptr, win, 10, 140, ME_COLOR, "Numpad : Change color paddle");
	mlx_string_put(ptr, win, 10, 160, ME_COLOR, "Enter : Swap color in paddle");
	mlx_string_put(ptr, win, 10, 180, ME_COLOR, "ESC : quit");
	mlx_string_put(ptr, win, 620, 540, ME_COLOR, "Created by :");
	mlx_string_put(ptr, win, 620, 560, ME_COLOR, "Reda-con");
	mlx_string_put(ptr, win, 620, 580, ME_COLOR, "Nde-Jesu");
}
