/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 08:22:09 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/03/06 09:27:40 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_macro_keys.h"

static void		zoom_in(t_fract *fract, t_pt pt)
{
	t_pt	i;
	t_pt	zoom;

	i.x = fract->mouse.act_x / fract->zoom * 1.1 + fract->min.x;
	i.y = fract->mouse.act_y / fract->zoom * 1.1 + fract->min.y;
	zoom.x = pt.x * (0.1 / 1.1);
	zoom.y = pt.y * (0.1 / 1.1);
	i.x = (pt.x - (i.x - fract->min.x)) * 0.1 / 1.1 ;
	i.y = (pt.y - (i.y - fract->min.y)) * 0.1 / 1.1;
	fract->min.x += zoom.x - i.x;
	fract->min.y += zoom.y - i.y;
	fract->max.x += -zoom.x - i.x;
	fract->max.y += -zoom.y - i.y;
}

static void		zoom_out(t_fract *fract, t_pt pt)
{
	t_pt	i;
	t_pt	zoom;

	i.x = fract->mouse.act_x / fract->zoom * 1.1 + fract->min.x;
	i.y = fract->mouse.act_y / fract->zoom * 1.1 + fract->min.y;
	zoom.x = pt.x * (0.1 / 1.1);
	zoom.y = pt.y * (0.1 / 1.1);
	i.x = ((pt.x - i.x) - fract->min.x) * 0.1 / 1.1;
	i.y = ((pt.y - i.y) - fract->min.y) * 0.1 / 1.1;
	fract->min.x += -zoom.x - i.x;
	fract->min.y += -zoom.y - i.y;
	fract->max.x += zoom.x - i.x;
	fract->max.y += zoom.y - i.y;
}

static void		new_bounds(t_fract *fract, int cases)
{
	t_pt	pt;

	if (fract->zoom == 1)
		return (init_params(fract, 1));
	pt.x = (fract->max.x - fract->min.x) / 2.0;
	pt.y = (fract->max.y - fract->min.y) / 2.0;
	cases == 1 ? zoom_in(fract, pt) : zoom_out(fract, pt);
}

void			zoom(int key, t_fract *fract)
{
	int		cases;
	
	fract = new_img(fract);
	if (key == KEY_PAD_ADD || key == KEY_EQUAL || key == MOUSE_SCROLL_UP)
	{
		cases = 1;
		fract->zoom *= 1.1;
		new_bounds(fract, cases);
	}
	if (key == KEY_PAD_SUB || key == KEY_MINUS || key == MOUSE_SCROLL_DOWN)
	{
		cases = 0;
		fract->zoom /= 1.1;
		new_bounds(fract, cases);
	}
	reload(fract);
}
