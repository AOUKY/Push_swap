/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:15:46 by haouky            #+#    #+#             */
/*   Updated: 2024/04/01 12:17:14 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

static char	*sub(char const *s, unsigned int st, size_t l)
{
	size_t	i;
	char	*c;

	i = 0;
	while (s[st + i] != 0 && i < l)
		i++;
	c = malloc(i + 1);
	if (c == 0)
		return (0);
	i = 0;
	while (s[st + i] != 0 && i < l)
	{
		c[i] = s[st + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int st, size_t l)
{
	char	*c;

	if (!s)
		return (0);
	if (ft_strlen(s) < st)
	{
		c = malloc(1);
		if (c == 0)
			return (0);
		c[0] = '\0';
		return (c);
	}
	return (sub(s, st, l));
}

long	ft_atoi(const char *s)
{
	int		i;
	long	r;
	int		sn;

	sn = 1;
	i = 0;
	r = 0;
	if ((s[i] == '-' || s[i] == '+') && (s[i + 1] <= '9' && s[i + 1] >= '0'))
	{
		if (s[i] == '-')
			sn = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
		{
			ft_printf("Error\n");
			fr_lst(0, 0, 0);
		}
		r = r * 10 + (s[i] - 48);
		i++;
	}
	return (r * sn);
}

void	fr_lst(t_stack **stack_a, t_stack **stack_b, int nf)
{
	static t_stack	**stack_1;
	static t_stack	**stack_2;
	t_stack			*tmp;

	tmp = 0;
	if (nf == 1)
		stack_1 = stack_a;
	if (nf == 1)
		stack_2 = stack_b;
	else
	{
		while (*stack_1)
		{
			tmp = (*stack_1)->next;
			free(*stack_1);
			(*stack_1) = tmp;
		}
		while (*stack_2)
		{
			tmp = (*stack_2)->next;
			free(*stack_2);
			(*stack_2) = tmp;
		}
		exit(0);
	}
}