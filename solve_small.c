/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:22:33 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:23:46 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort2(t_stack *a)
{
	if (a && a->size == 2 && a->data[0] > a->data[1])
		op_sa(a);
}

void	sort3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	if (!a || a->size != 3)
		return ;
	x = a->data[0];
	y = a->data[1];
	z = a->data[2];
	if (x > y && y < z && x < z)
		op_sa(a);
	else if (x > y && y > z)
	{
		op_sa(a);
		op_rra(a);
	}
	else if (x > y && y < z && x > z)
		op_ra(a);
	else if (x < y && y > z && x < z)
	{
		op_sa(a);
		op_ra(a);
	}
	else if (x < y && y > z && x > z)
		op_rra(a);
}

static int	index_of_min(t_stack *a)
{
	int	i;
	int	mi;

	mi = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->data[i] < a->data[mi])
			mi = i;
		i++;
	}
	return (mi);
}

static void	bring_top_by_rotate(t_stack *a, int idx)
{
	if (idx <= a->size / 2)
		while (idx-- > 0)
			op_ra(a);
	else
		while (idx++ < a->size)
			op_rra(a);
}

void	sort5(t_stack *a, t_stack *b)
{
	int	idx;

	if (!a || !b)
		return ;
	while (a->size > 3)
	{
		idx = index_of_min(a);
		bring_top_by_rotate(a, idx);
		op_pb(a, b);
	}
	sort3(a);
	while (!is_empty(b))
		op_pa(a, b);
}
