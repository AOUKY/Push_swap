/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:28:57 by haouky            #+#    #+#             */
/*   Updated: 2024/04/03 11:50:08 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Get_Next_Line/get_next_line.h"
# include "push_swap.h"

static void	full_stack(t_stack **stack_a, char **v)
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

static void	se_main(t_stack **stack_a, t_stack **stack_b, char **v)
{
	char	*line;
	int		i;

	full_stack(stack_a, v);
	repetition_check(*stack_a);
	line = get_next_line(0);
	while (line)
	{
		i = valid_move(stack_a, stack_b, line);
		free(line);
		if (!i)
		{
			write(2, "Error\n", 6);
			fr_lst(0, 0, 0);
		}
		line = get_next_line(0);
	}
	if (is_sorted(*stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	fr_lst(0, 0, 0);
}

int	main(int c, char **v)
{
	t_stack *stack_b;
	t_stack *stack_a;

	stack_b = 0;
	stack_a = 0;
	fr_lst(&stack_a, &stack_b, 1);
	if (c < 2)
		return (0);
	se_main(&stack_a, &stack_b, v);
}