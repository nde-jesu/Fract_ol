/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:27:13 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/28 10:18:31 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

int		error(void)
{
	ft_putendl_fd("usage: ./fractol <fractal you want>\n", 2);
	ft_putendl_fd("Availables fractals:\n-Mandelbrot\n-Julia\n-Another", 2);
	exit(1);
	return (1);
}

int		main(int ac, char **av)
{
	t_fract		*fract;

	if (ac != 2)
		return (error());
	//if ((!(ft_strcmp(av[1], "Mandelbrot"))) || (!(ft_strcmp(av[1],"Julia"))) ||
//			(!(ft_strcmp(av[1], "Another"))))
//		return (error());
	fract = init_fract(av[1]);
	mandel(fract);
	mlx_loop(fract->mlx->ptr);
	return (0);
}
