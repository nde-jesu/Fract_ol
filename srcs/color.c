/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:53:47 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/12 17:09:31 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_clr(int min, int max, int act, t_fract *fract)
{
	double	prct;

	prct = percent(min, max, act);
	if (prct < 0.2)
		return (fract->paddle[0]);
	else if (prct < 0.4)
		return (fract->paddle[1]);
	else if (prct < 0.6)
		return (fract->paddle[2]);
	else if (prct < 0.8)
		return (fract->paddle[3]);
	else
		return (fract->paddle[4]);
}

static void	norme(t_fract *fract)
{
	if (fract->paddle_choice == 2)
	{
		fract->paddle[0] = 0x00ff00;
		fract->paddle[1] = 0xff0000;
		fract->paddle[2] = 0x0000ff;
		fract->paddle[3] = 0xff00ff;
		fract->paddle[4] = 0xffff00;
	}
	else
	{
		fract->paddle[0] = 0x00ff00;
		fract->paddle[1] = 0xff0000;
		fract->paddle[2] = 0x0000ff;
		fract->paddle[3] = 0xff00ff;
		fract->paddle[4] = 0xffff00;
	}
}

void		choice_color(t_fract *fract)
{
	if (fract->paddle_choice == 0)
	{
		fract->paddle[0] = 0x00ff00;
		fract->paddle[1] = 0xff0000;
		fract->paddle[2] = 0x0000ff;
		fract->paddle[3] = 0xff00ff;
		fract->paddle[4] = 0xffff00;
	}
	else if (fract->paddle_choice == 1)
	{
		fract->paddle[0] = 0xffff00;
		fract->paddle[1] = 0xff00ff;
		fract->paddle[2] = 0x0000ff;
		fract->paddle[3] = 0xff0000;
		fract->paddle[4] = 0x00ff00;
	}
	norme(fract);
}
