/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:09:46 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/11 14:03:35 by reda-con         ###   ########.fr       */
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
	mlx_string_put(ptr, win, 10, 10, 0xEAEAEA, "Fract'ol");
	if (fract->type == 1)
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Mandelbrot");
	else if (fract->type == 2)
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Julia");
	else if (fract->type == 3)
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Von Koch");
	else
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Barnsley");
	mlx_string_put(ptr, win, 10, 100, 0xEAEAEA, "How to use :");
	mlx_string_put(ptr, win, 10, 120, 0xEAEAEA, "< or > : change fractal");
	mlx_string_put(ptr, win, 10, 140, 0xEAEAEA, "Move: arrows keys");
	if (fract->type == 2 || fract->type == 4)
		mlx_string_put(ptr, win, 10, 160, 0xEAEAEA, "M : activate iterations");
	mlx_string_put(ptr, win, 10, 180, 0xEAEAEA, "ESC : quit");
	mlx_string_put(ptr, win, 620, 440, 0xEAEAEA, "Created by :");
	mlx_string_put(ptr, win, 620, 460, 0xEAEAEA, "Reda-con");
	mlx_string_put(ptr, win, 620, 480, 0xEAEAEA, "Nde-Jesu");
}
