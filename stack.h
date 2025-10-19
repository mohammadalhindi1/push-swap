/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:42:11 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/15 02:25:32 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* ==== data structure ====*/

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}		t_stack;

t_stack	*stack_init(int capacity);
void	stack_free(t_stack *s);
int		is_empty(t_stack *s);
int		is_full(t_stack *s);

/* stack ops (top = data[0]) */
int		stack_push(t_stack *s, int value);
int		stack_pop(t_stack *s, int *out);

/* ==== all ops ==== */

void	op_sa(t_stack *a);
void	op_sb(t_stack *b);
void	op_ss(t_stack *a, t_stack *b);
int		op_pa(t_stack *a, t_stack *b);
int		op_pb(t_stack *a, t_stack *b);

void	op_ra(t_stack *a);
void	op_rb(t_stack *b);
void	op_rr(t_stack *a, t_stack *b);
void	op_rra(t_stack *a);
void	op_rrb(t_stack *b);
void	op_rrr(t_stack *a, t_stack *b);

/* ==== parsing ==== */

int		parse_into_stack(int ac, char **av, t_stack *a);
int		is_sorted(t_stack *a);
void	print_error(t_stack *a, t_stack *b);
int		atoi_clamped(const char *s, int *out);

/* ==== small sorts ==== */

void	sort2(t_stack *a);
void	sort3(t_stack *a);
void	sort5(t_stack *a, t_stack *b);

/* ==== ranking + chunked sort ==== */

int		make_ranks(t_stack *a);
int		sort_chunks(t_stack *a, t_stack *b, int chunks);

/* chunk helpers */
int		idx_max(t_stack *s);
void	rotate_short_a(t_stack *a, int idx);

int		is_space(char c);
int		is_digit(char c);

/* utils for ops (ops.c) */
void	swap_top_two_impl(t_stack *s);
void	rotate_impl(t_stack *s);
void	rev_rotate_impl(t_stack *s);

/* parsing helpers */

int		has_dup(const int *arr, int n);
int		total_tokens(int ac, char **av);

#endif
