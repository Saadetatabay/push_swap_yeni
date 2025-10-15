#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define INT_MIN -2147483648
#define INT_MAX 2147483647

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	int index;
	int value;
	struct s_node *next;
} t_node;

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_error();
int		ft_dup(int indis, int num, char **argv);
int		ft_check_sorted(t_node *stack);
int		ft_stack_size(t_node *stack);
void	sort_stack(t_node **stack_a, t_node **stack_b, int size_a);
void	sort_three(t_node **stack);
void add_head_to_tail(t_node **a);
void swap_firsttwo(t_node **stack);
void push_atob(t_node **a, t_node **b);
void push_btoa(t_node **b, t_node **a);
void add_tail_to_head(t_node **a);
void big_sort(t_node **stack_a, t_node **stack_b, int size);
int ft_max_bits(int max);
void index_stack(t_node **stack);
void print_stack(t_node *stack);
#endif