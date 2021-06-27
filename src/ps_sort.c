/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:51:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/27 11:33:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_issorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next != NULL)
	{
		if (temp->n > temp->next->n)
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

t_stack		*ps_copy_stack(t_stack *src)
{
	t_stack *copy;

	copy = malloc(sizeof(t_stack));
	copy->next = NULL;
	copy->prev = NULL;
	copy->n = src->n;
	copy->index = src->index;
	copy->head = copy;
	while (src->next != NULL)
	{
		copy->next = malloc(sizeof(t_stack));
		copy->next->head = copy->head;
		copy->next->index = src->next->index;
		copy->next->n = src->next->n;
		copy->next->next = NULL;
		copy->next->prev = copy;
		src = src->next;
		copy = copy->next;
	}
	ps_set_tail(copy->head);
	return (copy->head);
}




t_psdata	ps_copy(t_psdata *stack)
{
	t_psdata	copy;

	copy.a = ps_copy_stack(stack->a);
	copy.b = ps_copy_stack(stack->a);

	return (copy);
}

/*
   int	ps_next(t_psdata *stack)
   {
   int	i;
   int	count;
   int	*moves;
   t_psdata	copy;

   moves = malloc(sizeof(int) * ps_size(stack->b));
   copy = ps_copy(stack);
   i = 0;
   while (i < ps_size(stack->b))
   {
   count = 0;
   while (copy.a->index < copy.b->index)
   {
   ps_rotate(copy.a, 'c');
   count++;
   }
   moves[i] = count + i;
   if (copy.a->tail->index > copy.b->index)
   {
   while (count > 0)
   {
   ps_reverse(copy.a, 'c');
   moves[i] = moves[i] + 1;
   count--;
   }
   }
   ps_rotate(copy.b, 'c');
   i++;
   }
   int min;
   int	index;
   i = 0;
   min = 0;
   index = 0;
   while (i < ps_size(stack->b))
   {
   if (moves[i] < min)
   {
   min = moves[i];
   index = i;
   }
   i++;
   }
   ps_clear_stack(copy.a);
   ps_clear_stack(copy.b);
   free(moves);
   return (index);
   }
 */
void	ps_sort(t_psdata *stack)
{
	while(ps_size(stack->a) != 1 && ps_issorted(stack->a) == 0)
	{
		if (stack->a->index > stack->a->tail->index)
			ps_rotate(stack->a, 'a');
		stack->b = ps_push(&stack->a, stack->b, 'b');
	}
	int index;
	int i;
	int dir;
	i = -1;
	while (stack->b != NULL)
	{
		if (stack->a->index > stack->b->index 
				&& (stack->a->tail->index < stack->b->index || ps_issorted(stack->a)))
			stack->a = ps_push(&stack->b, stack->a, 'a');
		index = ps_next(stack, &dir);
	//	if (index == 0)
	//		stack->a = ps_push(&stack->b, stack->a, 'a');
		while (dir == 0 && stack->b && stack->b->index != index)
			ps_rotate(stack->b, 'b');
		while (dir == 1 && stack->b && stack->b->index != index)
			ps_reverse(stack->b, 'b');
		while (stack->b && stack->a->index < stack->b->index)
		{
			ps_rotate(stack->a, 'a');
			i++;
		}
		if (stack->b && stack->a->tail->index > stack->b->index)
			while (i > -1)
			{
				ps_reverse(stack->a, 'a');
				i--;
			}
		if (stack->b == NULL)
			while (ps_issorted(stack->a) == 0)
				ps_reverse(stack->a, 'a');
	}
}
