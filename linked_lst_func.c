/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lst_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:21:06 by haouky            #+#    #+#             */
/*   Updated: 2024/04/02 12:40:52 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(long nbr)
{
	t_stack	*new;

	if (nbr > INT_MAX || nbr < INT_MIN)
	{
		write(2, "Error\n", 6);
		fr_lst(0, 0, 0);
	}
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*stack_a;

	stack_a = 0;
	if (!(*stack))
		*stack = new;
	else
	{
		stack_a = *stack;
		while (stack_a->next)
		{
			stack_a = stack_a->next;
		}
		stack_a->next = new;
	}
}

void	add_front(t_stack **stack, t_stack *new)
{
	t_stack	*stack_a;

	stack_a = *stack;
	new->next = stack_a;
	*stack = new;
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*last_node(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
