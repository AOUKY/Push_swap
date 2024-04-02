/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:34:38 by haouky            #+#    #+#             */
/*   Updated: 2024/04/02 12:42:17 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *lst)
{
	t_stack	*cmp;

	cmp = 0;
	while (lst->next)
	{
		cmp = lst->next;
		if (lst->nbr > cmp->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	repetition_check(t_stack *stack)
{
	t_stack	*lst;
	t_stack	*tmp;

	lst = stack;
	tmp = 0;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->nbr == tmp->nbr)
			{
				write(2, "Error\n", 6);
				fr_lst(0, 0, 0);
				system("leaks push_swap");
			}
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

t_stack	*ft_before_last(t_stack *lst)
{
	if (!lst)
		return (0);
	while ((lst->next)->next)
		lst = lst->next;
	return (lst);
}

void	set_index(t_stack *x)
{
	int	i;
	int	med_line;

	i = 0;
	med_line = ft_lstsize(x) / 2;
	while (x)
	{
		if (i <= med_line)
			x->above_med_line = 1;
		else
			x->above_med_line = 0;
		x->index = i;
		x->cheap = 0;
		i++;
		x = x->next;
	}
}

void	moveto_a(t_stack **a, t_stack **b)
{
	get_to_push(a, (*b)->target, 'a');
	push(b, a, 'a');
}
