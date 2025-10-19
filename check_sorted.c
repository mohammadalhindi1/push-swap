/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:49:22 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/14 03:13:19 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *a)
{
	int	i;

	if (!a || a->size < 2)
		return (1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] > a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	idx_max(t_stack *s)
{
	int	i;
	int	mi;

	mi = 0;
	i = 1;
	while (i < s->size)
	{
		if (s->data[i] > s->data[mi])
			mi = i;
		i++;
	}
	return (mi);
}

void	rotate_short_a(t_stack *a, int idx)
{
	int	k;

	if (idx <= a->size / 2)
	{
		k = idx;
		while (k-- > 0)
			op_ra(a);
	}
	else
	{
		k = a->size - idx;
		while (k-- > 0)
			op_rra(a);
	}
}
