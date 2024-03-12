/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tdechand <tdechand@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2022/10/31 13:35:46 by Tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		ret = ft_calloc((1), sizeof(char));
		if (!ret)
			return (NULL);
	}
	else if (len < (size_t)(ft_strlen(s + start)))
	{
		ret = ft_calloc((len + 1), sizeof(char));
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, (s + start), (len + 1));
	}
	else
	{
		ret = ft_calloc((ft_strlen(s + start) + 1), sizeof(char));
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, (s + start), (ft_strlen(s + start) + 1));
	}
	return (ret);
}
