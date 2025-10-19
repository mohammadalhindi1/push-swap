/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:09:07 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/15 02:27:08 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	index_of(const int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int	make_ranks(t_stack *a)
{
	int	*copy;
	int	i;

	if (!a || a->size <= 1)
		return (0);
	copy = (int *)malloc(sizeof(int) * a->size);
	if (!copy)
		return (0);
	i = 0;
	while (i < a->size)
	{
		copy[i] = a->data[i];
		i++;
	}
	insertion_sort(copy, a->size);
	i = 0;
	while (i < a->size)
	{
		a->data[i] = index_of(copy, a->size, a->data[i]);
		i++;
	}
	free(copy);
	return (1);
}
