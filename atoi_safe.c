/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_safe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:01:18 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:24:01 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	skip_spaces_and_sign(const char **p, int *sign)
{
	*sign = 1;
	while (is_space(**p))
		(*p)++;
	if (**p == '+' || **p == '-')
	{
		if (**p == '-')
			*sign = -1;
		(*p)++;
	}
	if (!is_digit(**p))
		return (0);
	return (1);
}

int	atoi_clamped(const char *s, int *out)
{
	long	acc;
	int		sign;

	if (!s || !out)
		return (0);
	if (!skip_spaces_and_sign(&s, &sign))
		return (0);
	acc = 0;
	while (is_digit(*s))
	{
		acc = acc * 10 + (*s - '0');
		if (sign == 1 && acc > INT_MAX)
			return (0);
		if (sign == -1 && acc > (long)INT_MAX + 1)
			return (0);
		s++;
	}
	while (is_space(*s))
		s++;
	if (*s != '\0')
		return (0);
	*out = (int)(sign * acc);
	return (1);
}
