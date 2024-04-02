/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:56:01 by haouky            #+#    #+#             */
/*   Updated: 2024/04/02 14:09:06 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static	void	full_stack(t_stack **stack_a, char **v)
{
	char	**p;
	int		j; 
	int		i;

	i = 1;
	j = 0;
	p = 0;
	while (v[i])
	{
		p = ft_split(v[i], ' ');
		j = 0;
		while (p[j])
		{
			add_back(stack_a, new_node(ft_atoi(p[j])));
			j++;
		}
		free_dp(p, j);
		i++;
	}
}

static	void	se_main(t_stack **stack_a, t_stack **stack_b, char **v)
{
	int	i;

	full_stack(stack_a, v);
	repetition_check(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	i = ft_lstsize(*stack_a);
	if (i == 3)
		sort_three(stack_a, 'a');
	else if (i == 2)
		swap(stack_a, 'a');
	else
		sort_stack(stack_a, stack_b);
}

int	main(int c, char **v)
{
	t_stack	*stack_b;
	t_stack	*stack_a;

	stack_b = 0;
	stack_a = 0;
	fr_lst(&stack_a, &stack_b, 1);
	if (c < 2)
		return (0);
	se_main(&stack_a, &stack_b, v);
}                                   