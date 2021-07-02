/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:18:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/02 02:15:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_set_index(int *list, t_stack *stack, int size)
{
	int	n;

	while (stack != NULL)
	{
		n = size;
		while (n > -1)
		{
			if (list[n] == stack->n)
				stack->index = n;
			n--;
		}
		stack = stack->next;
	}
}

static t_stack	*ps_head(char *head)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = stack;
	stack->index = 0;
	stack->n = (int)ps_atoi(head);
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

void	ps_set_tail(t_stack *head)
{
	t_stack	*temp;
	t_stack	*tail;
	int		i;

	i = 1;
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	tail = temp;
	temp = head;
	while (temp != NULL)
	{
		temp->tail = tail;
		temp = temp->next;
		i++;
	}
}

static t_stack	*ps_set_stack(int n, char **args)
{
	t_stack	*stack;
	int		i;

	stack = ps_head(args[1]);
	if (stack == NULL)
		return (NULL);
	i = 2;
	while (i < n)
	{
		stack->next = malloc(sizeof(t_stack));
		if (stack->next == NULL)
			return (ps_clear_stack(stack->head));
		stack->next->index = 0;
		stack->next->in_a = 0;
		stack->next->head = stack->head;
		stack->next->n = (int)ps_atoi(args[i]);
		stack->next->next = NULL;
		stack->next->prev = stack;
		stack = stack->next;
		i++;
	}
	ps_set_tail(stack->head);
	return (stack->head);
}

int	ps_set(int argc, char **args, t_psdata *stack)
{
	stack->a = ps_set_stack(argc, args);
	if (stack->a == NULL)
		return (0);
	if (!ps_check(stack->a))
		return (0);
	stack->size = ps_size(stack->a);
	stack->list = ps_presort(stack->a);
	if (stack->list == NULL)
		return (0);
	stack->pivots = ps_pivots(stack->list, stack->size);
	if (stack->list == NULL)
		return (0);
	ps_set_index(stack->list, stack->a, stack->size);
	return (1);
}
