/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:00:19 by djon-con          #+#    #+#             */
/*   Updated: 2019/03/28 23:12:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		low_alpha(char c)
{
	if (c >= 'a' && c <= 'f')
		return (1);
	else
		return (0);
}

static int		big_alpha(char c)
{
	if (c >= 'A' && c <= 'F')
		return (1);
	else
		return (0);
}

static int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

unsigned long	ft_atoi_move_hex(char **str)
{
	unsigned long a;

	a = 0;
	while ((**str >= 9 && **str <= 13) || **str == ' ')
		(*str)++;
	if (**str == '0' && (*(*str + 1) == 'x' || *(*str + 1) == 'X'))
		(*str) += 2;
	if (!is_number(**str) && !low_alpha(**str) && !big_alpha(**str))
		return (0);
	while (is_number(**str) || low_alpha(**str) || big_alpha(**str))
	{
		if (low_alpha(**str))
			a = (is_number(**str)) ? \
				a * 16 + (*(*str)++ - 48) : a * 16 + (*(*str)++ + 10 - 'a');
		else
			a = (is_number(**str)) ? \
				a * 16 + (*(*str)++ - 48) : a * 16 + (*(*str)++ + 10 - 'A');
	}
	return (a);
}
