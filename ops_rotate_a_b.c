/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:20:00 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/14 03:11:25 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	op_ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate_impl(a);
	write(1, "ra\n", 3);
}

void	op_rra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rev_rotate_impl(a);
	write(1, "rra\n", 4);
}

void	op_rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate_impl(b);
	write(1, "rb\n", 3);
}

void	op_rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rev_rotate_impl(b);
	write(1, "rrb\n", 4);
}
