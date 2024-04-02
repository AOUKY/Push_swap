/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:27:14 by haouky            #+#    #+#             */
/*   Updated: 2024/04/02 14:06:52 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	int				push_cost;
	int				above_med_line;
	int				cheap;
	int				index;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;


#endif