/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:53:47 by reda-con          #+#    #+#             */
/*   Updated: 2019/02/12 15:25:00 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	percent(int start, int end, int act)
{
	double	plc;
	double	dist;

	plc = act - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (plc / dist));
}

int		get_clr(int min, int max, int act)
{
	double	prct;

	prct = percent(min, max, act);
	if (prct < 0.2)
		return (0x00ff00);
	else if (prct < 0.4)
		return (0xff0000);
	else if (prct < 0.6)
		return (0x0000ff);
	else if (prct < 0.8)
		return (0xff00ff);
	else
		return (0xffff00);
}
