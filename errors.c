/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:03:17 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/15 02:25:42 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	print_error(t_stack *a, t_stack *b)
{
	stack_free(a);
	stack_free(b);
	write(2, "Error\n", 6);
	exit(1);
}
