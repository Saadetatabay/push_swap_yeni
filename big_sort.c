/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:39:40 by satabay           #+#    #+#             */
/*   Updated: 2025/10/23 13:40:37 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_node **stack)
{
	int		index;
	t_node	*pt;
	t_node	*pt2;

	pt = *stack;
	while (pt)
	{
		index = 0;
		pt2 = *stack;
		while (pt2)
		{
			if (pt2->value < pt->value)
				index++;
			pt2 = pt2->next;
		}
		pt->index = index;
		pt = pt->next;
	}
}

int	ft_max_bits(int max)
{
	int	max_bit;

	max_bit = 0;
	while (max >> max_bit != 0)
		max_bit++;
	return (max_bit);
}

void	big_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = ft_max_bits(size - 1);
	index_stack(stack_a);
	while (i < max_bits)
	{
		j = 0;
		size = ft_stack_size(*stack_a);
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_atob(stack_a, stack_b);
			else
				add_head_to_tail(stack_a);
			j++;
		}
		while (*stack_b)
			push_btoa(stack_b, stack_a);
		i++;
	}
}
