/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:30:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/13 17:12:43 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quit(char *op, t_list **a, t_list **b, char *msg)
{	
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	free(op);
	if (msg)
		ft_printf("%s", msg);
	exit(-1);
}

void	operation(char	*op, t_list **a, t_list **b, int i)
{
	if (!ft_strncmp(op, "rrr", 4))
		rev_rotate(a, b, "rrr");
	else if (!ft_strncmp(op, "rra", 4))
		rev_rotate(a, NULL, "rra");
	else if (!ft_strncmp(op, "rrb", 4))
		rev_rotate(b, NULL, "rrb");
	else if (!ft_strncmp(op, "rr", 4))
		rotate(a, b, "rr");
	else if (!ft_strncmp(op, "ra", 3))
		rotate(a, NULL, "ra");
	else if (!ft_strncmp(op, "rb", 3))
		rotate(b, NULL, "rb");
	else if (!ft_strncmp(op, "sa", 3))
		swap(*a, NULL, "sa");
	else if (!ft_strncmp(op, "sb", 3))
		swap(*b, NULL, "sb");
	else if (!ft_strncmp(op, "ss", 3))
		swap(*b, *a, "ss");
	else if (!ft_strncmp(op, "pa", 3))
		push(b, a, "pa");
	else if (!ft_strncmp(op, "pb", 3))
		push(a, b, "pb");
	else
	{
		printf("%d\n", i);
		quit(op, a, b, "Errortarace\n");
	}
}

void	verdict(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) != 0)
		error_msg("Error", a, b);
	line = get_next_line(0);
	int i = 0;
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		i++;
		operation(line, &a, &b, i);
		free(line);
		line = get_next_line(0);
	}
	verdict(&a, &b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
}
