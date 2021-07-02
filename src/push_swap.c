/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/07/02 02:16:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_init(t_psdata *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->list = NULL;
	stack->pivots = NULL;
	stack->size = 0;
}

int	main(int argc, char **argv)
{
	t_psdata	stack;

	ps_init(&stack);
	if (ps_check_arg(argv, argc) == 0)
		return (ps_error(stack));
	if (ps_set(argc, argv, &stack) == 0)
		return (ps_error(stack));
	if (!ps_sort(&stack))
		return (ps_error(stack));
	ps_clear(stack);
	return (0);
}
