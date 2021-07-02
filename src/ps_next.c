/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:23:51 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/02 02:20:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_pos(t_stack *a, t_stack *b)
{
	t_stack	*head;
	int		pos;
	int		lim[2];
	int		index[2];

	lim[1] = ps_max(a, &index[1]);
	lim[0] = ps_min(a, &index[0]);
	head = a;
	while (b)
	{
		pos = 1;
		a = head;
		while (a != NULL)
		{
			if (b->index > lim[1])
				b->in_a = index[1] + 1;
			if (b->index < lim[0])
				b->in_a = index[0];
			if (a->next && b->index > a->index && b->index < a->next->index)
				b->in_a = pos;
			if (!a->next && b->index > a->index && b->index < a->head->index)
				b->in_a = 0;
			pos++;
			a = a->next;
		}
		b = b->next;
	}
}

static void	ps_count_moves(t_stack *b, t_stack *a)
{
	int	size_a;
	int	size_b;

	size_a = ps_size(a);
	size_b = ps_size(b);
	while (b)
	{
		if (b->n <= size_b / 2)
		{
			b->moves.rb = b->n;
			b->moves.rrb = 0;
		}
		else
		{
			b->moves.rrb = size_b % b->n;
			b->moves.rb = 0;
		}
		if (b->in_a <= size_a / 2)
		{
			b->moves.ra = b->in_a;
			b->moves.rra = 0;
		}
		else
		{
			b->moves.rra = size_a % b->in_a;
			b->moves.ra = 0;
		}
		b->moves.rr = 0;
		b->moves.rrr = 0;
		b = b->next;
	}
}

static void	ps_optimize(t_stack *b)
{
	while (b)
	{
		if (b->moves.ra > 0 && b->moves.rb > 0)
			b->moves.rr = ps_lower(b->moves.ra, b->moves.rb);
		if (b->moves.rra > 0 && b->moves.rrb > 0)
			b->moves.rrr = ps_lower(b->moves.rra, b->moves.rrb);
		if (b->moves.rr > 0)
		{
			b->moves.ra = b->moves.ra - b->moves.rr;
			b->moves.rb = b->moves.rb - b->moves.rr;
		}
		if (b->moves.rrr > 0)
		{
			b->moves.rra = b->moves.rra - b->moves.rrr;
			b->moves.rrb = b->moves.rrb - b->moves.rrr;
		}
		b->tot = b->moves.rr + b->moves.rrr + b->moves.ra
			+ b->moves.rb + b->moves.rra + b->moves.rrb;
		b = b->next;
	}
}

static int	ps_find_best(t_stack *stack)
{
	int		n;
	int		tot;

	n = stack->index;
	tot = stack->tot;
	while (stack)
	{
		if (tot > stack->tot)
		{
			n = stack->index;
			tot = stack->tot;
		}
		stack = stack->next;
	}
	return (n);
}

void	ps_set_moves(t_psdata *stack, t_moves *moves)
{
	t_stack	*temp;
	int		index;

	temp = stack->b;
	ps_pos(stack->a, stack->b);
	ps_count_moves(stack->b, stack->a);
	ps_optimize(stack->b);
	index = ps_find_best(stack->b);
	while (temp)
	{
		if (temp->index == index)
		{
			moves->rr = temp->moves.rr;
			moves->rrr = temp->moves.rrr;
			moves->rra = temp->moves.rra;
			moves->rrb = temp->moves.rrb;
			moves->ra = temp->moves.ra;
			moves->rb = temp->moves.rb;
		}
		temp = temp->next;
	}
}
