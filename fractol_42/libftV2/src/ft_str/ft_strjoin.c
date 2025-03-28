/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkantzer <lkantzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:13:14 by lkantzer          #+#    #+#             */
/*   Updated: 2025/02/13 18:13:15 by lkantzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	buffer;

	buffer = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (buffer + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1));
	ft_strlcat(res, s2, buffer + 1);
	return (res);
}
