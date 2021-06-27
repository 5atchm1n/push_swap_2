/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:04:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/26 12:39:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_stack *list, char stack)
{
	int	n;
	int	i;

	n = list->n;
	i = list->index;
	if (list->next != NULL)
	{
		list->n = list->next->n;
		list->index = list->next->index;
		list->next->n = n;
		list->next->index = i;
	}
	list = list->head;
	if (stack == 'a')
		write(1, "sa\n", 3);
	if (stack == 'b')
		write(1, "sb\n", 3);
}

void	ps_rotate(t_stack *list, char stack)
{
	int	n;
	int	i;

	n = list->n;
	i = list->index;
	if (list->next != NULL)
	{
		while (list->next != NULL)
		{
			list->n = list->next->n;
			list->index = list->next->index;
			list = list->next;
		}
		list->n = n;
		list->index = i;
	}
	list = list->head;
	if (stack == 'a')
		write(1, "ra\n", 3);
	if (stack == 'b')
		write(1, "rb\n", 3);
}

void	ps_reverse(t_stack *list, char stack)
{
	int		n;
	int		i;
	t_stack	*tail;

	n = list->tail->n;
	i = list->tail->index;
	tail = list->tail;
	while (tail->prev != NULL)
	{
		tail->n = tail->prev->n;
		tail->index = tail->prev->index;
		tail = tail->prev;
	}
	list->n = n;
	list->index = i;
	list = list->head;
	if (stack == 'a')
		write(1, "rra\n", 4);
	if (stack == 'b')
		write(1, "rrb\n", 4);
}
