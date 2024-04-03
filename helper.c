/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:21:08 by haouky            #+#    #+#             */
/*   Updated: 2024/04/03 12:30:08 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_min_top(t_stack **a)
{
	t_stack	*min;

	min = min_nd(*a);
	while ((*a) != min)
	{
		if (min->above_med_line)
			rotate_s(a, 'a');
		else
			revers_rotate_s(a, 'a');
	}
}

t_stack	*min_nd(t_stack *nd)
{
	int		min_nbr;
	t_stack	*minnd;

	min_nbr = nd->nbr;
	minnd = nd;
	while (nd)
	{
		if (nd->nbr < min_nbr)
		{
			min_nbr = nd->nbr;
			minnd = nd;
		}
		nd = nd->next;
	}
	return (minnd);
}

t_stack	*max_nd(t_stack *nd)
{
	int		maxnb;
	t_stack	*maxnd;

	maxnb = nd->nbr;
	maxnd = nd;
	while (nd)
	{
		if (nd->nbr > maxnb)
		{
			maxnb = nd->nbr;
			maxnd = nd;
		}
		nd = nd->next;
	}
	return (maxnd);
}

void	cheapset_move(t_stack *node)
{
	long	cheap_value;
	t_stack	*cheap_node;

	cheap_value = LONG_MAX;
	while (node)
	{
		if (node->push_cost <= cheap_value)
		{
			cheap_value = node->push_cost;
			cheap_node = node;
		}
		node = node->next;
	}
	cheap_node->cheap = 1;
}
