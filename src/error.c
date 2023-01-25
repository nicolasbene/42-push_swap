/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:07:31 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/25 18:23:32 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char	*msg, t_list *a, t_list *b)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	if (a)
		ft_lstclear(&a, NULL);
	if (b)
		ft_lstclear(&b, NULL);
	exit(-1);
}
