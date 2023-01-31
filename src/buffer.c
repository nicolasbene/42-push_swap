/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:31:16 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/31 18:27:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_op(int a)
// {
// 	if (a == SA)
// 		ft_printf("sa\n");
// 	else if (a == SB)
// 		ft_printf("sb\n");
// }

// void	put_buff(int op)
// {
// 	static int	buffer[SWAP_BUFF_SIZE];
// 	int	i;

// 	if (op == FLUSH)
// 	{
// 		i = -1;
// 		while (buffer[++i])
// 			print_op(buffer[i]);
// 		return ;
// 	}
// 	i = 0;
// 	while (buffer[i])
// 		i++;
// 	buffer[i] = op;

// }