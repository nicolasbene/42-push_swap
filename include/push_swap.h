/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/03 17:31:00 by nibenoit         ###   ########.fr       */
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

// # define FLUSH -2
// # define SA		1
// # define SB		2

typedef struct s_rotbuf
{
	int	r_from;
	int	r_to;
	int	rr_from;
	int	rr_to; 
}	t_rotbuf;


//OPERATIONS
void	swap(t_list *s1, t_list *s2, char *msg);
void	push(t_list **from, t_list **to, char *msg);
void	rotate(t_list **s1, t_list **s2, char *msg);
void	rev_rotate(t_list **s1, t_list **s2, char *msg);


int		parse(t_list **a, int argc, char *argv[]);
void	error_msg(char *msg, t_list *a, t_list *b);
void	sort_five(t_list **a, t_list **b, size_t len);
void	sort_small(t_list **a, t_list **b);
int		get_next_greater_value(t_list *s, int n);
void	move_nb_top_a(t_list **a, int ng);
int		find_min_value(t_list *s);


#endif
