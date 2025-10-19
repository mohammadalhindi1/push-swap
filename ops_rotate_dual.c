/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate_dual.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 02:44:00 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:24:31 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	op_rr(t_stack *a, t_stack *b)
{
	int	did;

	did = 0;
	if (a && a->size >= 2)
	{
		rotate_impl(a);
		did = 1;
	}
	if (b && b->size >= 2)
	{
		rotate_impl(b);
		did = 1;
	}
	if (did)
		write(1, "rr\n", 3);
}

void	op_rrr(t_stack *a, t_stack *b)
{
	int	did;

	did = 0;
	if (a && a->size >= 2)
	{
		rev_rotate_impl(a);
		did = 1;
	}
	if (b && b->size >= 2)
	{
		rev_rotate_impl(b);
		did = 1;
	}
	if (did)
		write(1, "rrr\n", 4);
}
