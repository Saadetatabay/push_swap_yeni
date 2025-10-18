/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:40:12 by satabay           #+#    #+#             */
/*   Updated: 2025/10/18 13:33:22 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_check_arg(int argc, char **argv)
{
	int				i;
	long long int	temp;
	char			**num;

	i = 0;
	if (argc == 2)
		num = ft_split(argv[1], ' ');
	else
		num = argv + 1;
	while (num[i])
	{
		if (!ft_isnum(num[i]))
			ft_error();
		temp = ft_atoi(num[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			ft_error();
		temp = (int)temp;
		if (!ft_dup(i, temp, num))
			ft_error();
		i++;
	}
	return (num);
}

void	stack_init(char **num, t_node **my_stack)
{
	int		i;
	t_node	*current;

	*my_stack = malloc(sizeof(t_node));
	current = *my_stack;
	i = 0;
	while (num[i])
	{
		current->value = ft_atoi(num[i]);
		if (num[i + 1])
		{
			current->next = malloc(sizeof(t_node));
			current = current->next;
		}
		else
			current->next = NULL;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**num;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		ft_error();
	if (argc == 2 && !*argv[1])
		ft_error();
	num = ft_check_arg(argc, argv);
	stack_init(num, &stack_a);
	if (!ft_check_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, ft_stack_size(stack_a));
}
