/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:40:53 by satabay           #+#    #+#             */
/*   Updated: 2025/10/18 17:58:30 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_firsttwo(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*(stack) = temp2;
	write(1, "sa\n", 3);
}

void	push_atob(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

void	push_btoa(t_node **b, t_node **a)
{
	t_node	*temp;

	if (!(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	add_head_to_tail(t_node **a)
{
	t_node	*temp;
	t_node	*iter;

	temp = *a;
	iter = *a;
	*a = (*a)->next;
	while (iter->next)
		iter = iter->next;
	iter->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	add_tail_to_head(t_node **a)
{
	t_node	*lst;
	t_node	*temp;
	//burayı sor
	
	if (!*a || !(*a)->next)
		return ;
	lst = NULL;
	temp = NULL;
	temp = *a;
	while (temp->next)
	{
		if (!temp->next->next)
		{
			lst = temp->next;
			lst->next = *a;
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	*a = lst;
	write(1, "rra\n", 4);
}
