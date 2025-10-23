/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:40:44 by satabay           #+#    #+#             */
/*   Updated: 2025/10/23 12:21:09 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack)->value;
	mid = (*stack)->next->value;
	bottom = (*stack)->next->next->value;
	if (top < mid && mid > bottom)
	{
		add_tail_to_head(stack);
		if ((*stack)->value > (*stack)->next->value)
		{
			swap_firsttwo(stack);
		}
	}
	else if (top > mid && top > bottom && mid < bottom)
		add_head_to_tail(stack);
	else if (top > mid)
	{
		swap_firsttwo(stack);
		if ((*stack)->next->value > (*stack)->next->next->value)
			add_tail_to_head(stack);
	}
}

void	find_min_value(t_node	*stack_a, int *index)
{
	int		i;
	int		min;

	i = 0;
	min = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min)
		{
			min = stack_a->value;
			*index = i;
		}
		stack_a = stack_a->next;
		i++;
	}
}

void	push_min_value_to_b(t_node **stack_a, t_node **stack_b)
{
	int		indeks;
	int		size;

	indeks = 0;
	size = ft_stack_size(*stack_a);
	find_min_value(*stack_a, &indeks);
	if (indeks <= (size -1) / 2)
	{
		while (indeks--)
			add_head_to_tail(stack_a);
	}
	else
	{
		while (indeks < size)
		{
			add_tail_to_head(stack_a);
			indeks++;
		}
	}
	push_atob(stack_a, stack_b);
}

void	sort_four_five(t_node **stack_a, t_node **stack_b)
{
	if (ft_stack_size(*stack_a) == 4)
	{
		push_min_value_to_b(stack_a, stack_b);
		sort_three(stack_a);
		push_btoa(stack_b, stack_a);
	}
	else
	{
		push_min_value_to_b(stack_a, stack_b);
		push_min_value_to_b(stack_a, stack_b);
		sort_three(stack_a);
		push_btoa(stack_b, stack_a);
		push_btoa(stack_b, stack_a);
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int size_a)
{
	if (size_a <= 2)
		swap_firsttwo(stack_a);
	else if (size_a <= 3)
		sort_three(stack_a);
	else if (size_a <= 5)
		sort_four_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, size_a);
}
