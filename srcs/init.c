/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:59:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/06 10:43:25 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"
#include "libft.h"

t_pt		init_pt(float x, float y)
{
	t_pt	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void		init_fract2(t_fract *fract)
{
	if (fract->type == 2)
	{
		fract->min = init_pt(-1, -1.2);
		fract->max = init_pt(1, 1.2);
	}
	else
	{
		fract->min = init_pt(-2.1, -1.2);
		fract->max = init_pt(0.6, 1.2);
	}
	fract->i_max = 150;
	fract->zoom = 500;
	fract->delta = init_pt(0, 0);
	fract->mlx->img->data = mlx_get_data_addr(fract->mlx->img->ptr,
			&(fract->mlx->img->bpp), &(fract->mlx->img->size_l),
			&(fract->mlx->img->endian));
}

t_fract		*init_fract(const char *s)
{
	t_fract		*fract;

	if (!(fract = (t_fract*)malloc(sizeof(t_fract))))
		return (NULL);
	if (!(fract->mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(fract->mlx->img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	fract->type = 0;
	if (!(ft_strcmp(s, "mandelbrot")))
		fract->type = 1;
	else if (!(ft_strcmp(s, "julia")))
		fract->type = 2;
	else if (!(ft_strcmp(s, "koch")))
		fract->type = 3;
	else
		return (NULL);
	fract->mlx->ptr = mlx_init();
	if (!(fract->mlx->win = mlx_new_window(fract->mlx->ptr, WIDTH,
					HEIGHT, "Fract_ol")))
		return (NULL);
	if (!(fract->mlx->img->ptr = mlx_new_image(fract->mlx->ptr, WIDTH, HEIGHT)))
		return (NULL);
	init_fract2(fract);
	return (fract);
}
