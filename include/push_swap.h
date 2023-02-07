/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:57 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/07 12:12:39 by nibenoit         ###   ########.fr       */
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

//ADV_OPERATIONS
int		find_min_value(t_list *s);
void	move_nb_top_a(t_list **a, int ng);
int		get_next_greater_value(t_list *s, int n);

int		parse(t_list **a, int argc, char *argv[]);
void	sort_five(t_list **a, t_list **b, size_t len);
void	sort_small(t_list **a, t_list **b);
void	sort_big(t_list **a, t_list **b);
void	insert_fastest_a(t_list **a, t_list **b);
int		count_move_on_top(t_list *s, int n);

//MEDIAN
int		def_median(t_list *a, int len);
void	push_median_b(int min, int max, t_list **a, t_list **b);

//ERROR
void	error_msg(char *msg, t_list *a, t_list *b);

#endif
