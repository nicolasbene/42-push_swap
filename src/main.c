/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:20:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/13 16:36:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (parse(&a, argc, argv) != 0)
		error_msg("Error", a, b);
	if (already_sort(a))
		error_msg(NULL, a, b);
	len = ft_lstsize(a);
	if (len == 2 && a->content > a->next->content)
		swap(a, NULL, "sa");
	else if (len >= 3 && len <= 5)
		sort_five(&a, &b, len);
	else if (len > 5 && len <= 100)
		sort_small(&a, &b);
	else if (len > 100)
		sort_big(&a, &b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
