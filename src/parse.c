/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:55:41 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/09 15:03:48 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char *s)
{
	int		i;
	size_t	len;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			if (i != 0 || (s[i] != '+' && s[i] != '-'))
				return (0);
		i++;
	}
	len = ft_strlen(s);
	if (len > MAX_LEN)
		return (0);
	if (ft_atol(s) > INT_MAX)
		return (0);
	if (ft_atol(s) < INT_MIN)
		return (0);
	return (1);
}

static int	check_double(int argc, char *argv[])
{
	int	ret;

	ret = ft_atoi(argv[argc]);
	argc++;
	while (argv[argc])
	{
		if (ft_atoi(argv[argc]) == ret)
			return (0);
		argc++;
	}
	return (1);
}

int	parse(t_list **a, int argc, char *argv[])
{
	t_list	*elem;

	argc--;
	while (argc > 0)
	{
		if (!is_valid(argv[argc]))
			return (-1);
		if (!check_double(argc, argv))
			return (-1);
		elem = ft_lstnew(ft_atoi(argv[argc]));
		if (!elem)
			return (-1);
		ft_lstadd_front(a, elem);
		argc--;
	}
	return (0);
}

int	already_sort(t_list *s)
{
	while (s->next)
	{
		if (s->content > s->next->content)
			return (0);
		s = s->next;
	}
	return (-1);
}
