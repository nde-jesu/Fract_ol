/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:40:55 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/05 17:27:42 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include "../libft/includes/libft.h"
#include <mlx.h>

float	ft_pow(int n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	if (p == 1)
		return (n);
	return (n * ft_pow(n, (p - 1)));
}

t_pt	init_point(int x, int y)
{
	t_pt	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

#include <unistd.h>
#include <stdio.h>
void	koch(t_fract *fract)
{
	int		n;
	int		i;
	int		j;
	int		k;
	int		l;
	int		*x;
	int		*y;
	int		max;
	t_pt	a;
	t_pt	b;

	x = NULL;
	y = NULL;
	n = 2;
	i = 1;
	max = ft_pow(4, n);
	x = ft_memalloc(max);
	y = ft_memalloc(max);
	x[max] = 450;
	while (i < n)
	{
		k = ft_pow(4, n - i);
		j = 0;
		while (j < ft_pow(4, i - 1) - 1)
		{
			l = 4 * j * k;
			x[l + k] = (2 * x[l] + x[l + 4 * k]) / 3;
			y[l + k] = (2 * y[l] + y[l + 4 * k]) / 3;
			x[l + 3 * k] = (x[l] + 2 * x[l + 4 * k]) / 3;
			y[l + 3 * k] = (y[l] + 2 * y[l + 4 * k]) / 3;
			x[l + 2 * k] = (x[l + k] + x[l + 3 * k] + sqrt(3)\
					* (y[l + k] - y[l + 3 * k])) / 2;
			y[l + 2 * k] = (y[l + k] + y[l + 3 * k] + sqrt(3)\
					* (x[l + k] - x[l + 3 * k])) / 2;
			++j;
		}
		++i;
	}
	i = 0;
	while (i < max - 1)
	{
		a = init_point(x[i], y[i]);
		b = init_point(x[i + 1], y[i + 1]);
		printf("%f; %f\n", a.x, a.y);
		img_draw_line(a, b, fract->mlx->win);
		++i;
	}
	mlx_put_image_to_window(fract->mlx->ptr, fract->mlx->win, \
			fract->mlx->img->ptr, MENU_WIDTH, 0);
}
