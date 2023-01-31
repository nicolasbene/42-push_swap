/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/31 19:21:34 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define SWAP_BUFF_SIZE 30	

# define MAX_LEN	11

# define FLUSH -2
# define SA		1
# define SB		2

//OPERATIONS
void		swap(t_list *s1, t_list *s2, char *msg);
void		push(t_list **from, t_list **to, char *msg);
void		rotate(t_list **s1, t_list **s2, char *msg);


int			parse(t_list **a, int argc, char *argv[]);
void		error_msg(char *msg, t_list *a, t_list *b);
// void		put_buff(int op);
// static void	print_op(int a);

#endif
