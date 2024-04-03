/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_for_checkr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:39:56 by haouky            #+#    #+#             */
/*   Updated: 2024/04/03 11:21:18 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cmp(char *s, char *p)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != p[i])
			return (0);
		i++;
	}
	return (1);
}

static void drrr(t_stack **a, t_stack **b)
{
	revers_rotate_s(a, 'x');
	revers_rotate_s(b, 'x');
}
static void sss(t_stack **a, t_stack **b)
{
	swap(a, 'x');
	swap(b, 'x');
}

static	void	rr(t_stack **a, t_stack **b)
{
	rotate_s(a, 'x');
	rotate_s(b, 'x');
}
int	valid_move(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (cmp(line, "sa\n"))
		swap(stack_a, 'x');
	else if (cmp(line, "sb\n"))
		swap(stack_b, 'x');
	else if (cmp(line, "ss\n"))
		sss(stack_a, stack_b);
	else if (cmp(line, "pa\n"))
		push(stack_b, stack_a, 'x');
	else if (cmp(line, "pb\n"))
		push(stack_a, stack_b, 'x');
	else if (cmp(line, "ra\n"))
		rotate_s(stack_a, 'x');
	else if (cmp(line, "rb\n"))
		rotate_s(stack_b, 'x');
	else if (cmp(line, "rr\n"))
		rr(stack_a, stack_b);
	else if (cmp(line, "rra\n"))
		revers_rotate_s(stack_a, 'x');
	else if (cmp(line, "rrb\n"))
		revers_rotate_s(stack_b, 'x');
	else if (cmp(line, "rrr\n"))
		drrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}
