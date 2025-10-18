/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:22:35 by satabay           #+#    #+#             */
/*   Updated: 2025/10/18 18:17:19 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				index;
	int				value;
	struct s_node	*next;
}	t_node;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
long long int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_error(char **n, int arg);
int		ft_dup(int indis, int num, char **argv);
int		ft_check_sorted(t_node *stack);
int		ft_stack_size(t_node *stack);
void	sort_stack(t_node **stack_a, t_node **stack_b, int size_a);
void	sort_three(t_node **stack);
void	add_head_to_tail(t_node **a);
void	swap_firsttwo(t_node **stack);
void	push_atob(t_node **a, t_node **b);
void	push_btoa(t_node **b, t_node **a);
void	add_tail_to_head(t_node **a);
void	big_sort(t_node **stack_a, t_node **stack_b, int size);
int		ft_max_bits(int max);
void	index_stack(t_node **stack);
void	print_stack(t_node *stack);
void	free_splitt(char	**splitted, int argc);
void	ft_lstclear(t_node **lst);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif