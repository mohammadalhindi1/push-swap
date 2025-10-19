/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:26:07 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:24:24 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	op_sa(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	swap_top_two_impl(a);
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	swap_top_two_impl(b);
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *a, t_stack *b)
{
	if ((a && a->size >= 2) || (b && b->size >= 2))
	{
		if (a && a->size >= 2)
			swap_top_two_impl(a);
		if (b && b->size >= 2)
			swap_top_two_impl(b);
		write(1, "ss\n", 3);
	}
}

int	op_pa(t_stack *a, t_stack *b)
{
	int	val;

	if (!a || !b)
		return (0);
	if (!stack_pop(b, &val))
		return (0);
	if (!stack_push(a, val))
		return (0);
	write(1, "pa\n", 3);
	return (1);
}

int	op_pb(t_stack *a, t_stack *b)
{
	int	val;

	if (!a || !b)
		return (0);
	if (!stack_pop(a, &val))
		return (0);
	if (!stack_push(b, val))
		return (0);
	write(1, "pb\n", 3);
	return (1);
}
