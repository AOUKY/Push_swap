/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:41:23 by haouky            #+#    #+#             */
/*   Updated: 2024/04/01 12:48:21 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	double_rotate_s(t_stack **a, t_stack **b)
{
	rotate_s(a, 'x');
	rotate_s(b, 'x');
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	revers_rotate_s(a, 'x');
	revers_rotate_s(b, 'x');
	ft_printf("rrr\n");
}

void	db_r(t_stack **a, t_stack **b, t_stack *cur)
{
	while ((*a) != cur && (*b) != cur->target)
		double_rotate_s(a, b);
}

void	db_rr(t_stack **a, t_stack **b, t_stack *cur)
{
	while ((*a) != cur && (*b) != cur->target)
		rrr(a, b);
}

void	move_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapset_node;

	cheapset_node = get_cheapset(*a);
	if ((cheapset_node->above_med_line)
		&& (cheapset_node->target->above_med_line))
	{
		db_r(a, b, cheapset_node);
	}
	else if ((!(cheapset_node->above_med_line))
		&& (!(cheapset_node->target->above_med_line)))
		db_rr(a, b, cheapset_node);
	get_to_push(a, cheapset_node, 'a');
	get_to_push(b, cheapset_node->target, 'b');
	push(a, b, 'b');
}