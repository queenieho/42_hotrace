/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:25:40 by qho               #+#    #+#             */
/*   Updated: 2017/05/13 13:13:59 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (dst != NULL)
	{
		ft_strcpy(dst, s1);
		return (dst);
	}
	else
		return (0);
}
