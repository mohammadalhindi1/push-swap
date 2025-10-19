/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:26:48 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/15 02:26:24 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	get_parts(int n)
{
	if (n <= 100)
		return (5);
	return (10);
}

static int	sort_big_cases(t_stack *a, t_stack *b)
{
	int	parts;

	parts = get_parts(a->size);
	return (sort_chunks(a, b, parts));
}

static void	sort_small_cases(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort2(a);
	else if (a->size == 3)
		sort3(a);
	else if (a->size <= 5)
		sort5(a, b);
}

static int	build_stacks(int ac, char **av, t_stack **a, t_stack **b)
{
	int	tok;

	tok = total_tokens(ac, av);
	if (tok <= 0)
		return (0);
	*a = stack_init(tok);
	*b = stack_init(tok);
	if (!*a || !*b)
		return (0);
	if (!parse_into_stack(ac, av, *a))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = 0;
	b = 0;
	if (!build_stacks(ac, av, &a, &b))
		print_error(a, b);
	if (!is_sorted(a))
	{
		if (a->size <= 5)
			sort_small_cases(a, b);
		else
			if (!sort_big_cases(a, b))
				print_error(a, b);
	}
	stack_free(a);
	stack_free(b);
	return (0);
}
