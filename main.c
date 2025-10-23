/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:40:12 by satabay           #+#    #+#             */
/*   Updated: 2025/10/23 12:30:57 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_arg_two(char	**num, int argc)
{
	int				i;
	long long int	temp;

	i = 0;
	while (num[i])
	{
		if (!ft_isnum(num[i]))
			ft_error(num, argc);
		temp = ft_atoi(num[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			ft_error(num, argc);
		temp = (int)temp;
		if (!ft_dup(i, temp, num))
			ft_error(num, argc);
		i++;
	}
}

char	**ft_check_arg(int argc, char **argv)
{
	int				j;
	int				i;
	char			**num;

	j = 0;
	i = 0;
	if (argc == 2)
	{
		num = ft_split(argv[1], ' ');
		if (!num || !*num)
			ft_error(num, argc);
	}
	else
	{	
		num = argv + 1;
		while (num[j])
		{
			num[j] = ft_strtrim(num[j], " ");
			j++;
		}
	}
	ft_check_arg_two(num, argc);
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

void	free_splitt(char	**splitted, int argc)
{
	int	i;

	i = 0;
	if (!splitted)
		return ;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	if (argc == 2)
		free(splitted);
}

int	main(int argc, char **argv)
{
	char	**num;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(1);
	if (argc == 2 && !*argv[1])
		ft_error(NULL, argc);
	num = ft_check_arg(argc, argv);
	stack_init(num, &stack_a);
	free_splitt(num, argc);
	if (!ft_check_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, ft_stack_size(stack_a));
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
