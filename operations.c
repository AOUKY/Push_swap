/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:30:36 by haouky            #+#    #+#             */
/*   Updated: 2024/04/03 11:04:14 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst, char x)
{
	t_stack	*node2;
	t_stack	*node1;

	if(!(*lst) || ft_lstsize(*lst) < 2)
		return ;
	node1 = *lst;
	node2 = node1->next;
	node1->next = node2->next;
	node2->next = node1;
	*lst = node2;
	if (x == 'a')
		ft_printf("sa\n");
	else if (x == 'b')
		ft_printf("sb\n");
}

void	sswap(t_stack **a, t_stack **b)
{
	swap(a, 'x');
	swap(b, 'x');
	ft_printf("ss\n");
}

void	push(t_stack **src, t_stack **dst, char x)
{
	t_stack	*node;

	if(!(*src))
		return ;
	node = (*src);
	(*src) = node->next;
	node->next = 0;
	add_front(dst, node);
	if (x == 'a')
		ft_printf("pa\n");
	else if (x == 'b')
		ft_printf("pb\n");
}

void	rotate_s(t_stack **lst, char x)
{
	t_stack	*node;

	if(!(*lst) || ft_lstsize(*lst) < 2)
		return ;
	node = *lst;
	*lst = (*lst)->next;
	node->next = 0;
	add_back(lst, node);
	if (x == 'a')
		ft_printf("ra\n");
	else if (x == 'b')
		ft_printf("rb\n");
}

void	revers_rotate_s(t_stack **lst, char x)
{
	t_stack	*last_node;
	t_stack	*before_last;
	t_stack	*stack_a;

	if(!(*lst) || ft_lstsize(*lst) < 2)
		return ;
	stack_a = *lst;
	last_node = (ft_before_last(stack_a))->next;
	before_last = ft_before_last(stack_a);
	before_last->next = NULL;
	add_front(lst, last_node);
	*lst = last_node;
	if (x == 'a')
		ft_printf("rra\n");
	else if (x == 'b')
		ft_printf("rrb\n");
}
