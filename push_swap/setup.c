/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:14:48 by haouky            #+#    #+#             */
/*   Updated: 2024/04/01 16:25:44 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*tmp;
	long	near_smallnb;

	while (a)
	{
		near_smallnb = LONG_MIN;
		tmp = b;
		while (tmp)
		{
			if (a->nbr > tmp->nbr && tmp->nbr > near_smallnb)
			{
				near_smallnb = tmp->nbr;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (near_smallnb == LONG_MIN)
			a->target = max_nd(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*tmp;
	long	near_bignb;

	while (b)
	{
		near_bignb = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (b->nbr < tmp->nbr && tmp->nbr < near_bignb)
			{
				near_bignb = tmp->nbr;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (near_bignb == LONG_MAX)
			b->target = min_nd(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	get_to_push(t_stack **stack, t_stack *get_top, char x)
{
	while ((*stack) != get_top)
	{
		if (get_top->above_med_line)
			rotate_s(stack, x);
		else
			revers_rotate_s(stack, x);
	}
}

void	set_price_of_push(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_med_line))
			a->push_cost = len_a - (a->index);
		if (a->target->above_med_line)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		if(a->above_med_line && a->target->above_med_line)
		{
			if(a->index < a->target->index)
				a->push_cost = a->index + (a->target->index - a->index);
			else
				a->push_cost = a->target->index + (a->index - a->target->index);
		}
		a = a->next;
	}
}
t_stack	*get_cheapset(t_stack *lst)
{
	t_stack *cheap_node;

	while (lst)
	{
		if (lst->cheap == 1)
		{
			cheap_node = lst;
		}
		lst = lst->next;
	}
	return (cheap_node);
}