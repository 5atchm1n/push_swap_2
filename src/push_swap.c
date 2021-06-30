/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:27:54 by sshakya           #+#    #+#             */
/*   Updated: 2021/06/30 01:36:56 by sshakya          ###   ########.fr       */
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
void	print(t_psdata stack)
{
	t_stack *temp;
	temp = stack.a;
	while (temp != NULL)
	{
		printf("n = %3d\t i = %3d\t p = %p\n", temp->n, temp->index, temp);
		temp = temp->next;
	}
	printf("STACK B\n");
	temp = stack.b;
	while (temp != NULL)
	{
		printf("n = %3d\t i = %3d\t p = %p\n", temp->n, temp->index, temp);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_psdata stack;

	ps_init(&stack);
	if (ps_check_arg(argv, argc) == 0)
		ps_error(stack);
	if (ps_set(argc, argv, &stack) == 0)
		return (ps_error(stack));
	//print(stack);
	ps_sort(&stack);
	//print(stack);
	ps_clear(stack);
	return (0);
}
