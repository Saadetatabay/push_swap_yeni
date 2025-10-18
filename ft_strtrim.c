#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

static int	del_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	del_end(char const *s1, char const *set, int start)
{
	int	len;

	len = ft_strlen(s1);
	while (len > start && ft_strchr(set, s1[len - 1]))
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*ret;

	i = 0;
	if (!s1)
		return (0);
	start = del_start(s1, set);
	end = del_end(s1, set, start);
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	while (start < end)
		ret[i++] = s1[start++];
	ret[i] = '\0';
	return (ret);
}