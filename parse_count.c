/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 00:15:00 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/14 03:17:37 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	count_tokens_in_str(const char *s)
{
	int	cnt;
	int	in_num;

	cnt = 0;
	in_num = 0;
	while (*s)
	{
		if (is_space(*s))
			in_num = 0;
		else if (!in_num)
		{
			cnt++;
			in_num = 1;
		}
		s++;
	}
	return (cnt);
}

int	total_tokens(int ac, char **av)
{
	int	i;
	int	total;

	total = 0;
	i = 1;
	while (i < ac)
	{
		total += count_tokens_in_str(av[i]);
		i++;
	}
	return (total);
}

int	has_dup(const int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
