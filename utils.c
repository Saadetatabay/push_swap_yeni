/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:40:32 by satabay           #+#    #+#             */
/*   Updated: 2025/10/12 15:30:52 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

int	ft_isdigit(int c)
{
	if (c < 58 && c > 47)
		return (1);
	return (0);
}

int	ft_isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	ft_dup(int indis, int num, char **argv)
{
	int	i;

	i = 0;
	while (i < indis)
	{
		if (ft_atoi(argv[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_error(void)
{
	write(1, "geeçrli değil error\n", 23);
	exit (1);
}
