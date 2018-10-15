/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:16:56 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/08 09:47:04 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_struct(void)
{
	t_stacks *s;

	s = (t_stacks *)malloc(sizeof(t_stacks));
	s->stack_a = NULL;
	s->stack_b = NULL;
	s->size = 0;
	s->len_a = 0;
	s->len_b = 0;
	return (s);
}

void		ft_viz_cool(t_stacks *s, int y, int x)
{
	int i;
	int j;

	i = 0;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	while (i <= s->len_a - 1)
	{
		j = 0;
		while (j <= (s->stack_a[s->len_a - i - 1] / 1))
			mvprintw(y + i, x + j++, "X");
		i++;
	}
	attron(COLOR_PAIR(2));
	while (i <= s->size - 1)
	{
		j = 0;
		while (j <= (s->stack_b[s->size - i - 1] / 1))
			mvprintw(y + i, x + j++, "X");
		i++;
	}
}
