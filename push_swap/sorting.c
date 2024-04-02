/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:50:45 by haouky            #+#    #+#             */
/*   Updated: 2024/04/01 17:22:37 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !(is_sorted(*a)))
		push(a, b, 'b');
	if (len_a-- > 3 && !(is_sorted(*a)))
		push(a, b, 'b');
	while (len_a-- > 3 && !(is_sorted(*a)))
	{
		work_stack_a(*a, *b);
		move_to_b(a, b);
	}
	sort_three(a, 'a');
	while (*b)
	{
		work_stack_b(*a, *b);
		moveto_a(a, b);
	}
	set_index(*a);
	make_min_top(a);
}

void	sort_three(t_stack **stack_a, char x)
{
	t_stack	*befor_last;
	t_stack	*last;

	befor_last = ft_before_last(*stack_a);
	last = last_node(*stack_a);
	if (befor_last->nbr > last->nbr && befor_last->nbr > (*stack_a)->nbr)
		revers_rotate_s(stack_a, x);
	else if ((*stack_a)->nbr > last->nbr && (*stack_a)->nbr > befor_last->nbr)
		rotate_s(stack_a, x);
	befor_last = ft_before_last(*stack_a);
	if (befor_last->nbr < (*stack_a)->nbr)
		swap(stack_a, x);
}

void	work_stack_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_price_of_push(a, b);
	cheapset_move(a);
}

void	work_stack_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
