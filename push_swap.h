/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouky <haouky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:04:08 by haouky            #+#    #+#             */
/*   Updated: 2024/04/03 12:37:29 by haouky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

/*file---helper func-------*/

void	fr_lst(t_stack **stack_a, t_stack **stack_b, int nf);
char	*ft_substr(char const *s, unsigned int st, size_t l);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *s);
char	**ft_split(char const *s, char c);
void	free_dp(char **s, int i);
/*linked list func------*/
t_stack	*new_node(long nbr);
void	add_back(t_stack **stack, t_stack *new);
void	add_front(t_stack **stack, t_stack *new);
t_stack	*last_node(t_stack *lst);
int		ft_lstsize(t_stack *lst);
/*check-----&&&-add func--------*/
void	repetition_check(t_stack *stack);
int		is_sorted(t_stack *lst);
void	set_index(t_stack *x);
t_stack	*ft_before_last(t_stack *lst);
void	moveto_a(t_stack **a, t_stack **b);

/*operations-------*/
void	swap(t_stack **lst, char x);
void	push(t_stack **src, t_stack **dst, char x);
void	rotate_s(t_stack **lst, char x);
void	revers_rotate_s(t_stack **lst, char x);
void	sswap(t_stack **a, t_stack **b);
void	double_rotate_s(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	db_r(t_stack **a, t_stack **b, t_stack *cur);
void	db_rr(t_stack **a, t_stack **b, t_stack *cur);
void	move_to_b(t_stack **a, t_stack **b);

/*soritng-----*/
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **stack_a, char x);
void	work_stack_b(t_stack *a, t_stack *b);
void	work_stack_a(t_stack *a, t_stack *b);

/*setup------------*/
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	get_to_push(t_stack **stack, t_stack *get_top, char x);
void	set_price_of_push(t_stack *a, t_stack *b);
t_stack	*get_cheapset(t_stack *lst);
/*hellper function-----------*/
void	make_min_top(t_stack **a);
t_stack	*min_nd(t_stack *nd);
t_stack	*max_nd(t_stack *nd);
void	cheapset_move(t_stack *node);
/*bonus------checkr*/
int		valid_move(t_stack **stack_a, t_stack **stack_b, char *line);

#endif
