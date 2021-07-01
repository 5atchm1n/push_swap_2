/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:51:36 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/01 19:43:44 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_psdata
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				*pivots;
	int				*list;
	int				size;
}				t_psdata;

typedef struct s_moves
{
	int		rr;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		rrr;
}	t_moves;

typedef struct s_stack
{
	int				n;
	int				index;
	int				in_a;
	int				tot;
	struct s_moves	moves;
	struct s_stack	*head;
	struct s_stack	*tail;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/*
** INIT
*/
t_psdata	ps_init_stack(int n, char **args);
void		ps_set_tail(t_stack *head);
int			ps_set(int argc, char **argv, t_psdata *stack);
/*
** MOVES
*/
void	ps_rotate(t_stack *list, char stack);
void	ps_swap(t_stack *list, char stack);
void	ps_reverse(t_stack *list, char stack);
t_stack	*ps_push(t_stack **src, t_stack *dest, char stack);
/*
** SORT
*/
void	ps_sort_pivots(t_stack **stack_a, t_stack **stack_b);
void	ps_sort_max(t_stack **stack_a, t_stack **stack_b);
void	ps_pivot_sort(t_stack **stack_a, t_stack **stack_b);

void	ps_sort(t_psdata *stack);

int	ps_issorted(t_stack *stack);

void	ps_set_moves(t_psdata *stack, t_moves *moves);

void	print(t_psdata stack);

/*
**	UTILS
*/
int		ps_max(t_stack *list, int *index);
int		ps_min(t_stack *list, int *index);
int		ps_islower(t_stack *list, int key);
int		ps_size(t_stack *a);
int		ps_npivots(int size);
int		ps_isdigit(int c);
int		ps_min_stack(t_stack *a);
int		ps_max_stack(t_stack *a);

/*
** CHECKS AND FREE
*/
void	ps_clear(t_psdata stack);
void	*ps_clear_stack(t_stack *stack);
int		ps_check_arg(char **args, int size);
int		ps_check(t_stack *stack);
int		ps_error(t_psdata stack);
/*
** PRE-SORT
*/

int		*ps_presort(t_stack *stack);
int		*ps_pivots(int *list, int size);
void	ps_set_index(int *list, t_stack *stack, int size);
/*
** DEBUG
*/
void	my_print(t_stack *list_a, t_stack *list_b);

#endif
