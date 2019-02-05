/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 08:12:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/02/05 14:56:06 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_macro_keys.h"
#include "fractol.h"
#include <mlx.h>

int		close(void *param)
{
	free(param);
	exit(0);
	return (0);
}

int		user_command(int key, void *param)
{
	t_fract	*fract;

	fract = (t_fract*)param;
	if (key == KEY_ESCAPE)
		close(param);
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB || key == KEY_MINUS \
			|| key == KEY_EQUAL)
		zoom(key, fract);
/*	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN \
			|| key == KEY_UP)
		translation(key, fdf);
	else if (key == KEY_PAD_1 || key == KEY_PAD_2 || key == KEY_PAD_3\
			|| key == KEY_PAD_4 || key == KEY_PAD_6\
			|| key == KEY_PAD_7 || key == KEY_PAD_8 || key == KEY_PAD_9)
		rotation(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		projection(key, fdf);
	else if (key == KEY_PAGE_UP || key == KEY_PAGE_DOWN)
		change_z(key, fdf);*/
	return (0);
}

void	get_ctrl(t_fract *fract)
{
	mlx_hook(fract->mlx->win, 2, 0, user_command, fract);
	mlx_hook(fract->mlx->win, 17, 0, close, fract);
	mlx_hook(fract->mlx->win, 4, 0, press, fract);
	mlx_hook(fract->mlx->win, 5, 0, release, fract);
	mlx_hook(fract->mlx->win, 6, 0, move, fract);
}

t_fract	*new_img(t_fract *fract)
{
	mlx_destroy_image(fract->mlx->ptr, fract->mlx->img->ptr);
	fract->mlx->img->ptr = mlx_new_image(fract->mlx->ptr, WIDTH, HEIGHT);
	fract->mlx->img->data = mlx_get_data_addr(fract->mlx->img->ptr,
		&(fract->mlx->img->bpp), &(fract->mlx->img->size_l),
			&(fract->mlx->img->endian));
	return (fract);
}
