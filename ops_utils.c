/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:41:01 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:24:35 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap_top_two_impl(t_stack *s)
{
	int	tmp;

	if (!s || s->size < 2)
		return ;
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
}

void	rotate_impl(t_stack *s)
{
	int	first;
	int	i;

	if (!s || s->size < 2)
		return ;
	first = s->data[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->size - 1] = first;
}

void	rev_rotate_impl(t_stack *s)
{
	int	last;
	int	i;

	if (!s || s->size < 2)
		return ;
	last = s->data[s->size - 1];
	i = s->size - 1;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = last;
}
