/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 22:55:00 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/14 03:17:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	process_token(const char *p, int len, int *out_val)
{
	char	*tok;
	int		i;
	int		v;

	tok = (char *)malloc((size_t)len + 1);
	if (!tok)
		return (0);
	i = 0;
	while (i < len)
	{
		tok[i] = p[i];
		i++;
	}
	tok[len] = '\0';
	if (!atoi_clamped(tok, &v))
		return (free(tok), 0);
	free(tok);
	*out_val = v;
	return (1);
}

static int	append_tokens_from_str(const char *s, int *vals, int *nptr)
{
	const char	*p;
	const char	*q;
	int			len;
	int			val;

	p = s;
	while (*p)
	{
		while (*p && is_space(*p))
			p++;
		if (!*p)
			break ;
		q = p;
		while (*q && !is_space(*q))
			q++;
		len = (int)(q - p);
		if (!process_token(p, len, &val))
			return (0);
		vals[*nptr] = val;
		(*nptr)++;
		p = q;
	}
	return (1);
}

static int	fill_all_args(int ac, char **av, int *vals, int *out_n)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (i < ac)
	{
		if (!append_tokens_from_str(av[i], vals, &n))
			return (0);
		i++;
	}
	*out_n = n;
	return (1);
}

static int	read_all_args_flex(int ac, char **av, int **out_vals, int *out_n)
{
	int	*vals;
	int	tok;

	tok = total_tokens(ac, av);
	if (tok <= 0)
		return (0);
	vals = (int *)malloc(sizeof(int) * tok);
	if (!vals)
		return (0);
	if (!fill_all_args(ac, av, vals, out_n))
		return (free(vals), 0);
	*out_vals = vals;
	return (1);
}

int	parse_into_stack(int ac, char **av, t_stack *a)
{
	int	*vals;
	int	n;
	int	i;

	if (!a || ac <= 1)
		return (0);
	if (!read_all_args_flex(ac, av, &vals, &n))
		return (0);
	if (has_dup(vals, n))
		return (free(vals), 0);
	i = n - 1;
	while (i >= 0)
	{
		if (!stack_push(a, vals[i]))
			return (free(vals), 0);
		i--;
	}
	free(vals);
	return (1);
}
