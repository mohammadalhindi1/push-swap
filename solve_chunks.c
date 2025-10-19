/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 06:55:32 by malhendi@st       #+#    #+#             */
/*   Updated: 2025/10/15 02:22:35 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	find_nearest_in_range(t_stack *a, int lo, int hi)
{
	int	i;
	int	j;

	i = 0;
	j = a->size - 1;
	while (i <= j)
	{
		if (a->data[i] >= lo && a->data[i] < hi)
			return (i);
		if (a->data[j] >= lo && a->data[j] < hi)
			return (j);
		i++;
		j--;
	}
	return (-1);
}

static void	push_all_chunks(t_stack *a, t_stack *b, int chunk, int n)
{
	int	lo;
	int	hi;
	int	pushed;
	int	idx;

	lo = 0;
	hi = chunk;
	pushed = 0;
	while (pushed < n)
	{
		idx = find_nearest_in_range(a, lo, hi);
		if (idx < 0)
		{
			lo = hi;
			hi += chunk;
			if (hi > n)
				hi = n;
			continue ;
		}
		rotate_short_a(a, idx);
		op_pb(a, b);
		if (b->size > 1 && b->data[0] < (lo + hi) / 2)
			op_rb(b);
		pushed++;
	}
}

static void	drain_b_to_a(t_stack *a, t_stack *b)
{
	int	idx;
	int	k;

	while (!is_empty(b))
	{
		idx = idx_max(b);
		if (idx <= b->size / 2)
		{
			k = idx;
			while (k-- > 0)
				op_rb(b);
		}
		else
		{
			k = b->size - idx;
			while (k-- > 0)
				op_rrb(b);
		}
		op_pa(a, b);
	}
}

int	sort_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	n;
	int	chunk;

	if (!a || !b || a->size <= 1)
		return (0);
	if (!make_ranks(a))
		return (0);
	n = a->size;
	if (chunks < 1)
		chunks = 1;
	chunk = (n + chunks - 1) / chunks;
	push_all_chunks(a, b, chunk, n);
	drain_b_to_a(a, b);
	return (1);
}
