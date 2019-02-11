/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 08:59:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/11 09:56:46 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"
#include "../libft/includes/libft.h"

t_pt		init_pt(float x, float y)
{
	t_pt	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void		reload(t_fract *fract)
{
	if (fract->type == 1)
		mandel(fract);
	if (fract->type == 2)
		julia(fract);
	if (fract->type == 3)
		koch(fract);
	if (fract->type == 4)
		barnsley(fract);
}

void		init_params(t_fract *fract, int cases)
{
	fract->i_max = 250;
	fract->zoom = 200;
	fract->delta = init_pt(0, 0);
	if (cases == 0)
	{
		fract->mouse.toggle_mouse = -1;
		fract->toggle_menu = 1;
		fract->mlx->img->data = mlx_get_data_addr(fract->mlx->img->ptr,
				&(fract->mlx->img->bpp), &(fract->mlx->img->size_l),
				&(fract->mlx->img->endian));
	}
	fract->min = init_pt(X_M + (X_L / 2) - (X_L / (2 * fract->zoom))\
			+ fract->delta.x, Y_M + (Y_L / 2) - (Y_L / (2 * fract->zoom))\
			+ fract->delta.y);
	fract->max = init_pt(fract->min.x + (X_L / fract->zoom), \
			fract->min.y + (Y_L / fract->zoom));
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
	else if (!(ft_strcmp(s, "barnsley")))
		fract->type = 4;
	else
		return (NULL);
	fract->mlx->ptr = mlx_init();
	if (!(fract->mlx->win = mlx_new_window(fract->mlx->ptr, WIDTH,
					HEIGHT, "Fract_ol")))
		return (NULL);
	if (!(fract->mlx->img->ptr = mlx_new_image(fract->mlx->ptr, WIDTH, HEIGHT)))
		return (NULL);
	init_params(fract, 0);
	return (fract);
}
