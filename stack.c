/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:18:44 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/10 03:23:51 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(int capacity)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->data = (int *)malloc(sizeof(int) * capacity);
	if (!s->data)
	{
		free(s);
		return (NULL);
	}
	s->size = 0;
	s->cap = capacity;
	return (s);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	free(s->data);
	free(s);
}

int	is_empty(t_stack *s)
{
	return (!s || s->size == 0);
}

int	is_full(t_stack *s)
{
	return (s && s->size == s->cap);
}
