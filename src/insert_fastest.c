/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fastest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:18 by nibenoit          #+#    #+#             */
/*   Updated: 2023/02/06 15:19:09 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_rot(t_rotbuf buffer)
{
	int	count;

	if (buffer.r_from > buffer.r_to)
		count = buffer.r_from;
	else
		count = buffer.r_to;
	if (buffer.rr_from > buffer.rr_to)
		count += buffer.rr_from;
	else
		count += buffer.rr_to;
	return (count);
}

//calcule la position actuelle d'un élément dans la liste et 
//détermine combien de rotations sont nécessaires pour le mettre 
//en haut de la liste
int	count_move_on_top(t_list *s, int n)
{
	t_list	*tmp;
	int		ind;
	int		len;
	int		mid;

	ind = 1;
	tmp = s;
	while (tmp->content != n)
	{
		tmp = tmp->next;
		ind++;
	}
	len = ft_lstsize(s);
	mid = (len / 2) + (len % 2);
	if (ind <= mid)
		return (ind - 1);
	else
		return (ind - len - 1);
}

//calcule le nombre de rotations nécessaires pour insérer un
//élément dans une autre liste et le classer.
t_rotbuf	insert_move_count(t_list **from, t_list **to, int val)
{
	t_rotbuf	buffer;
	int			count_from;
	int			count_to;

	buffer = (t_rotbuf){0, 0, 0, 0};
	count_from = count_move_on_top(*from, val);
	count_to = count_move_on_top(*to, get_next_greater_value(*to, val));
	if (count_from > 0)
		buffer.r_from = count_from;
	else
		buffer.rr_from = -count_from;
	if (count_to > 0)
		buffer.r_to = count_to;
	else
		buffer.rr_to = -count_to;
	return (buffer);
}

void	print_rotbuf(t_list **a, t_list **b, t_rotbuf buffer)
{
	while (buffer.r_from && buffer.r_to)
	{
		rotate(a, b, "rr");
		buffer.r_to--;
		buffer.r_from--;
	}
	while (buffer.r_from--)
		rotate(b, NULL, "rb");
	while (buffer.r_to--)
		rotate(a, NULL, "ra");
	while (buffer.rr_from && buffer.rr_to)
	{
		rev_rotate(a, b, "rrr");
		buffer.rr_from--;
		buffer.rr_to--;
	}
	while (buffer.rr_from--)
		rev_rotate(b, NULL, "rrb");
	while (buffer.rr_to--)
		rev_rotate(a, NULL, "rra");
}

void	insert_fastest_a(t_list **a, t_list **b)
{
	t_list		*tmp;
	t_rotbuf	buffer;
	t_rotbuf	tmp_buffer;
	int			min;

	tmp = *b;
	buffer = insert_move_count(b, a, tmp->content);
	min = nb_rot(buffer);
	while (tmp)
	{
		tmp_buffer = insert_move_count(b, a, tmp->content);
		if (nb_rot(tmp_buffer) < min)
		{
			min = nb_rot(tmp_buffer);
			buffer = tmp_buffer;
		}
		tmp = tmp->next;
	}
	print_rotbuf(a, b, buffer);
	push(b, a, "pa");
}
