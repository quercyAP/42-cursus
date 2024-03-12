/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/14 13:30:32 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

static int	check_ws(int c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int	check(int *i, char *str)
{
	int	sign;

	sign = 1;
	while (str[*i])
	{
		if (check_ws(str[*i]))
			(*i)++;
		else
			break ;
	}
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
			return (0);
	}
	if (str[*i] == '+')
	{
		(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
			return (0);
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	ret;
	int	i;
	int	sign;

	i = 0;
	sign = check(&i, (char *)str);
	if (sign == 0)
		return (0);
	ret = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		ret = (ret * 10) + (str[i] - 48);
		i++;
	}
	return (ret * sign);
}

long long int	ft_atoll(const char *str, int *has_overflown)
{
	long long int			ret;
	long long unsigned int	tmp;
	int						i;
	int						sign;
	long long int			l_sign;

	i = 0;
	sign = check(&i, (char *)str);
	if (sign == 0)
		return (0);
	else if (sign == -1)
		l_sign = -1;
	tmp = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		tmp = (tmp * 10) + (str[i] - 48);
		i++;
	}
	if (tmp > (9223372036854775808ULL) && l_sign < 0)
			*has_overflown = 1;
	else if (tmp > LONG_MAX && l_sign > 0)
			*has_overflown = 1;
	ret = tmp;
	return (ret * l_sign);
}
