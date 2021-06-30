/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:51:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/30 01:37:14 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_issorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ps_pivot_next(t_stack *stack_a, int pivot)
{
	int		i;
	int		j;
	t_stack	*temp;

	i = 0;
	j = 0;
	temp = stack_a->head;
	while (temp != NULL)
	{
		if (temp->n < pivot)
			break ;
		i++;
		temp = temp->next;
	}
	temp = stack_a->tail;
	while (temp != NULL)
	{
		if (temp->n < pivot)
			break ;
		j++;
		temp = temp->prev;
	}
	if (i < j)
		return (1);
	return (0);
}

void	ps_sort_large(t_psdata *stack)
{
	int i;

	i = 0;
	while (i < ps_npivots(stack->size))
	{
		if (stack->a->head->n < stack->pivots[i])
			stack->b = ps_push(&stack->a, stack->b, 'b');
		else if (ps_pivot_next(stack->a, stack->pivots[i]))
			ps_rotate(stack->a, 'a');
		else
			ps_reverse(stack->a, 'a');
		if (ps_islower(stack->a, stack->pivots[i]) == 0)
			i++;
	}
}

void	ps_sort(t_psdata *stack)
{
	t_moves	moves;

	while(ps_size(stack->a) != 1 && ps_issorted(stack->a) == 0)
	{
		if (stack->a->index > stack->a->tail->index)
			ps_rotate(stack->a, 'a');
		stack->b = ps_push(&stack->a, stack->b, 'b');
	//	print(*stack);
	}
	while (stack->b != NULL)
	{
		ps_set_moves(stack, &moves);
		while (moves.rr > 0)
		{
			ps_rotate(stack->a, 'c');
			ps_rotate(stack->b, 'c');
			moves.rr -= 1;
			write(1, "rr\n", 3);
		}
		while (moves.rrr > 0)
		{
			ps_reverse(stack->a, 'c');
			ps_reverse(stack->b, 'c');
			moves.rrr -= 1;
			write(1, "rrr\n", 4);
		}
		while (moves.rb-- > 0)
			ps_rotate(stack->a, 'a');
		while (moves.ra-- > 0)
			ps_rotate(stack->b, 'b');
		while (moves.rrb-- > 0)
			ps_reverse(stack->a, 'a');
		while (moves.rra-- > 0)
			ps_reverse(stack->b, 'b');
		stack->a = ps_push(&stack->b, stack->a, 'a'); 
	}
}
