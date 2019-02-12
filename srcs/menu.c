/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:23:36 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/12 17:23:37 by reda-con         ###   ########.fr       */
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
	{
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Julia");
		mlx_string_put(ptr, win, 10, 140, 0xEAEAEA, "M : activate iterations");
		mlx_string_put(ptr, win, 10, 160, 0xEAEAEA,\
				"Pge Up / Down : change type");
	}
	else if (fract->type == 3)
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Von Koch");
	else
		mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "Fractal : Barnsley");
	mlx_string_put(ptr, win, 10, 100, 0xEAEAEA, "How to use :");
	mlx_string_put(ptr, win, 10, 120, 0xEAEAEA, "< or > : change fractal");
	mlx_string_put(ptr, win, 10, 180, 0xEAEAEA, "ESC : quit");
	mlx_string_put(ptr, win, 620, 540, 0xEAEAEA, "Created by :");
	mlx_string_put(ptr, win, 620, 560, 0xEAEAEA, "Reda-con");
	mlx_string_put(ptr, win, 620, 580, 0xEAEAEA, "Nde-Jesu");
}
