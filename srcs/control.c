/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:53:28 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/03/06 09:19:32 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_macro_keys.h"
#include "fractol.h"
#include <mlx.h>

int			close(void *param)
{
	free_all((t_fract*)param);
	exit(0);
	return (0);
}

static void	change_color(int key, t_fract *fract)
{
	fract = new_img(fract);
	if (key == KEY_PAD_1)
		choice_color(fract, 0);
	else if (key == KEY_PAD_2)
		choice_color(fract, 1);
	else if (key == KEY_PAD_3)
		choice_color(fract, 2);
	else if (key == KEY_PAD_4)
		choice_color(fract, 3);
	reload(fract);
}

int			user_command(int key, void *param)
{
	t_fract*fract;

	fract = (t_fract*)param;
	if (key == KEY_ESCAPE)
		close(param);
	if (key == KEY_M)
		fract->mouse.toggle_mouse *= -1;
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB || key == KEY_MINUS \
			|| key == KEY_EQUAL)
		zoom(key, fract);
	if (key == KEY_SPACEBAR)
		space(fract);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN \
			|| key == KEY_UP)
		translation(key, fract);
	else if (key == KEY_LESS_THAN || key == KEY_MORE_THAN)
		change_fract(key, fract);
	else if (key == KEY_PAGE_UP || key == KEY_PAGE_DOWN)
		change_type_julia(key, fract);
	if (key == KEY_PAD_1 || key == KEY_PAD_2 || key == KEY_PAD_3\
			|| key == KEY_PAD_4)
		change_color(key, fract);
	if (key == KEY_ENTER)
		change_paddle(fract);
	return (0);
}

void		get_ctrl(t_fract *fract)
{
	mlx_hook(fract->mlx->win, 2, 0, user_command, fract);
	mlx_hook(fract->mlx->win, 17, 0, close, fract);
	mlx_hook(fract->mlx->win, 4, 0, press, fract);
	mlx_hook(fract->mlx->win, 6, 0, move, fract);
}

t_fract		*new_img(t_fract *fract)
{
	mlx_destroy_image(fract->mlx->ptr, fract->mlx->img->ptr);
	fract->mlx->img->ptr = mlx_new_image(fract->mlx->ptr, WIDTH, HEIGHT);
	fract->mlx->img->data = mlx_get_data_addr(fract->mlx->img->ptr,
			&(fract->mlx->img->bpp), &(fract->mlx->img->size_l),
			&(fract->mlx->img->endian));
	return (fract);
}
