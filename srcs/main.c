/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:27:13 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/11 10:18:29 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/includes/libft.h"
#include <mlx.h>
#include <stdlib.h>

int		error(void)
{
	ft_putendl_fd("usage: ./fractol <fractal you want>\n", 2);
	ft_putendl_fd("Availables fractals:\n-Mandelbrot\n-Julia\n-Koch\n-Barnsley"
			, 2);
	exit(1);
	return (1);
}

int		main(int ac, char **av)
{
	t_fract		*fract;

	if (ac != 2)
		return (error());
	if (!(fract = init_fract(ft_strlowcase(av[1]))))
		return (error());
	fract->i_max = 100;
		if (fract->type == 1)
		mandel(fract);
	else if (fract->type == 2)
		julia(fract);
	else if (fract->type == 3 || fract->type == 4)
	{
		fract->i_max = 10000;
		fract->zoom = 1;
		fract->min = init_pt(0, 0);
		fract->max = init_pt(0, 0);
		if (fract->type == 3)
			koch(fract);
		else
			barnsley(fract);
	}
	get_ctrl(fract);
	mlx_loop(fract->mlx->ptr);
	return (0);
}
