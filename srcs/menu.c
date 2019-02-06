/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:09:46 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/06 15:07:37 by reda-con         ###   ########.fr       */
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
	mlx_string_put(ptr, win, 10, 20, 0xEAEAEA, "Fract'ol");
	if (fract->type == 1)
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Mandelbrot");
	else if (fract->type == 2)
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Julia");
	else
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Von Koch");
	mlx_string_put(ptr, win, 10, 100, 0xEAEAEA, "How to use :");
	mlx_string_put(ptr, win, 10, 120, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 140, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 160, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 180, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 200, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 220, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 240, 0xEAEAEA, "WIP");
	mlx_string_put(ptr, win, 10, 300, 0xEAEAEA, "ESC to quit");
	mlx_string_put(ptr, win, 10, 1180, 0xEAEAEA, "Created by :");
	mlx_string_put(ptr, win, 10, 1200, 0xEAEAEA, "Reda-Con");
	mlx_string_put(ptr, win, 10, 1220, 0xEAEAEA, "Nde-Jesu");
}
