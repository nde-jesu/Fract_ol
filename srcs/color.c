/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:53:47 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/14 11:54:56 by reda-con         ###   ########.fr       */
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

void		change_paddle(t_fract *fract)
{
	int		tmp;
	int		i;

	i = -1;
	fract = new_img(fract);
	tmp = fract->paddle[0];
	while (++i < 4)
		fract->paddle[i] = fract->paddle[i + 1];
	fract->paddle[4] = tmp;
	reload(fract);
}

static void	norme(t_fract *fract, int paddle_choice)
{
	if (paddle_choice == 2)
	{
		fract->paddle[0] = 0xffd700;
		fract->paddle[1] = 0xffe436;
		fract->paddle[2] = 0xf7e55f;
		fract->paddle[3] = 0xfeea73;
		fract->paddle[4] = 0xffff00;
	}
	else
	{
		fract->paddle[0] = 0x8b0000;
		fract->paddle[1] = 0xb22222;
		fract->paddle[2] = 0xcd5c5c;
		fract->paddle[3] = 0xf08080;
		fract->paddle[4] = 0xff0000;
	}
}

void		choice_color(t_fract *fract, int paddle_choice)
{
	if (paddle_choice == 0)
	{
		fract->paddle[0] = 0x00ff00;
		fract->paddle[1] = 0xff0000;
		fract->paddle[2] = 0x0000ff;
		fract->paddle[3] = 0xff00ff;
		fract->paddle[4] = 0xffff00;
	}
	else if (paddle_choice == 1)
	{
		fract->paddle[0] = 0xfee7f0;
		fract->paddle[1] = 0xe9c9b1;
		fract->paddle[2] = 0xdfff00;
		fract->paddle[3] = 0x6c0277;
		fract->paddle[4] = 0x4b0082;
	}
	else
		norme(fract, paddle_choice);
}
