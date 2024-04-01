/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:07:51 by haouky            #+#    #+#             */
/*   Updated: 2024/04/01 16:35:54 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_stack	*stack_b;
	t_stack	*stack_a;
	char	**p;
	int		j;
	int		i;

	stack_b = 0;
	stack_a = 0;
	j = 0;
	i = 1;
	fr_lst(&stack_a, &stack_b, 1);
	if (c < 2)
		return (0);
	while (v[i])
	{
		p = ft_split(v[i], ' ');
		j = 0;
		while (p[j])
		{
			add_back(&stack_a, new_node(ft_atoi(p[j])));
			j++;
		}
		free_dp(p, j);
		i++;
	}
	repetition_check(stack_a);
	if (is_sorted(stack_a))
		return (0);
	i = ft_lstsize(stack_a);
	if (i == 3)
		sort_three(&stack_a, 'a');
	else if (i == 2)
		swap(&stack_a, 'a');
	else
		sort_stack(&stack_a, &stack_b);
}

