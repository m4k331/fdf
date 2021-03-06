/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:16:29 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/28 23:20:55 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' || c == '\r' || c == ' ');
}
