/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:49:25 by amtadevo          #+#    #+#             */
/*   Updated: 2022/03/19 17:49:36 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	v;

	i = 0;
	str = (unsigned char *)b;
	v = (unsigned char)c;
	while (i < len)
	{
		str[i] = v;
		i++;
	}
	return (b);
}
