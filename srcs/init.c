/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:59:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/28 10:11:56 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"
#include "libft.h"

t_fract		*init_fract(const char *s)
{
	t_fract		*fract;

	if (!(fract = (t_fract*)malloc(sizeof(t_fract))))
		return (NULL);
	if (!(fract->mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(fract->mlx->img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	fract->mlx->ptr = mlx_init();
	if (!(fract->mlx->win = mlx_new_window(fract->mlx->ptr, WIDTH,
			HEIGHT, "Fract_ol")))
		return (NULL);
	if (!(fract->mlx->img->ptr = mlx_new_image(fract->mlx->ptr, WIDTH, HEIGHT)))
		return (NULL);
	fract->mlx->img->data = mlx_get_data_addr(fract->mlx->img->ptr,
		&(fract->mlx->img->bpp), &(fract->mlx->img->size_l),
			&(fract->mlx->img->endian));
	if (ft_strcmp(s, "Mandelbrot") || ft_strcmp(s, "mandelbrot"))
		fract->type = 1;
	else if (ft_strcmp(s, "Julia") || ft_strcmp(s, "julia"))
		fract->type = 2;
	else if (ft_strcmp(s, "Another") || ft_strcmp(s, "another"))
		fract->type = 3;
	return (fract);
}
