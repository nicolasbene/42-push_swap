/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/06 15:41:20 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(int a)
{
	ft_printf("%d ", a);
}

void	print_st(t_list *a, t_list *b)
{
	ft_printf("a : ");
	ft_lstiter(a, print);
	ft_printf("\n");
	ft_printf("b : ");
	ft_lstiter(b, print);
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) == -1)
		error_msg("Error", a, b);
	len = ft_lstsize(a);
	// print_st(a, b);
	if (len == 2 && a->content > a->next->content)
		swap(a, NULL, "sa");
	else if (len >= 3 && len <= 5)
		sort_five(&a, &b, len);
	else if (len > 5 && len <= 100)
		sort_small(&a, &b);
	else if (len > 100)
		sort_big(&a, &b);
	move_nb_top_a(&a, find_min_value(a));
	// print_st(a, b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
