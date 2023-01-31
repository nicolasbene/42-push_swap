/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/31 19:24:48 by nibenoit         ###   ########.fr       */
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
	print_st(a, b);
	if (len == 2 && a->content > a->next->content)
		swap(a, NULL, "sa");
	// else if (len >= 3 && len <= 5)
	// 	sort_five(a, b);
	print_st(a, b);

	push(&a, &b, "pb");
	print_st(a, b);
	push(&a, &b, "pb");
	print_st(a, b);
	push(&a, &b, "pb");
	print_st(a, b);
	push(&a, &b, "pb");
	print_st(a, b);

	swap(b, NULL, "sb");
	print_st(a, b);

	swap(a, b, "ss");
	print_st(a, b);



	swap(a, NULL, "sa");
	print_st(a, b);

	rotate(&a, NULL, "ra");
	print_st(a, b);

	rotate(&b, NULL, "rb");
	print_st(a, b);

	rotate(&a, &b, "rr");
	print_st(a, b);

 	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
