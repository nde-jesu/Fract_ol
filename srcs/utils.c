/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:08:38 by reda-con          #+#    #+#             */
/*   Updated: 2019/03/06 10:05:40 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

float	square(float n)
{
	return (n * n);
}

double	percent(int start, int end, int act)
{
	double	plc;
	double	dist;

	plc = act - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (plc / dist));
}

void	reload(t_fract *fract)
{
	if (fract->type == 1)
		mandel(fract);
	else if (fract->type == 2)
		julia(fract, 1);
	else if (fract->type == 3)
		barnsley(fract);
}

void	free_all(t_fract *fract)
{
	mlx_destroy_image(fract->mlx->ptr, fract->mlx->img->ptr);
	free(fract->mlx->img);
	mlx_destroy_window(fract->mlx->ptr, fract->mlx->win);
	free(fract->mlx);
	free(fract);
}
