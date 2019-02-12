/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 08:12:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/15 17:01:58 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_macro_keys.h"
#include "fdf.h"
#include <mlx.h>

int		user_command(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB || key == KEY_MINUS \
			|| key == KEY_EQUAL)
		zoom(key, fdf);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN \
			|| key == KEY_UP)
		translation(key, fdf);
	else if (key == KEY_PAD_1 || key == KEY_PAD_2 || key == KEY_PAD_3\
			|| key == KEY_PAD_4 || key == KEY_PAD_6\
			|| key == KEY_PAD_7 || key == KEY_PAD_8 || key == KEY_PAD_9)
		rotation(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		projection(key, fdf);
	return (0);
}

int		close(void *param)
{
	free_all(param);
	exit(0);
	return (0);
}

void	get_ctrl(t_fdf *fdf)
{
	mlx_hook(fdf->mlx->win, 2, 0, user_command, fdf);
	mlx_hook(fdf->mlx->win, 17, 0, close, fdf);
}
