/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:05:33 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:23:49 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack *s, int value)
{
	int	i;

	if (!s || is_full(s))
		return (0);
	i = s->size;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = value;
	s->size++;
	return (1);
}

int	stack_pop(t_stack *s, int *out)
{
	int	i;

	if (!s || is_empty(s))
		return (0);
	if (out)
		*out = s->data[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->size--;
	return (1);
}

int	stack_peek(t_stack *s, int *out)
{
	if (!s || is_empty(s))
		return (0);
	if (out)
		*out = s->data[0];
	return (1);
}
