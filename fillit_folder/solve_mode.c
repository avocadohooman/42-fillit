/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:41:37 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/14 13:34:18 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // remove

static int start(char *s)
{
	size_t i;
	size_t xy;

	i = 0;
	xy = 0;
	while (s[i] == '.' || s[i] == '\n')
		i++;
	xy = i;
	if (ft_isupper(s[i + 10]) && ft_isupper(s[i + 9]) && (i + 10) < 20)
	{
		i = i + 10;
		while (s[i - 1] != '.' && s[i - 1] != '\n' && s[i])
		{
			xy--;
			i--;
		}
		return (xy);
	}
	if (ft_isupper(s[i + 5]) && (i + 5) < 20)
	{
		i = i + 5;
		while (s[i - 1] != '.' && s[i - 1] != '\n' && s[i])
		{
			xy--;
			i--;
		}
		return (xy);
	}
	return (xy);
}


static char *position_swap(char *s)
{
	size_t i;
	size_t begin;
	size_t j;
	size_t row;

	i = 0;
	row = 0;
	begin = start(s);
	j = begin;
	while (s[j] && s[i] && begin != 0)
	{
		if (s[j] == '\n')
		{
			j = begin + 5;
			begin = begin + 5;
			row++;
			i = row * 5;
			continue;
		}
		if (j > 20 || i > 20)
			break;
		s[i] = s[j];
		s[j] = '.';
		i++;
		j++;
	}
	return (s);
}

int solve_mode(char *board, t_list *lst, size_t start, char *backup)
{
	char 		*tmp;
	static int	b;
	t_list 		*begin_list;

	b = 1;
	tmp = NULL;
	begin_list = lst;
	printf("Number of elements in the list %zu\n", ft_lstlen(&lst));
	printf("Empty starting board: %s\n", board);
	if (!lst)
	{
		ft_putendl(board);
		return (1);
	}
	while (board[start])
	{
		if (!slap(board, position_swap(lst->content), start))
			start++;
		else if (!solve_mode(board, lst->next, 1, ft_strdup(board)))
		{
				board = ft_strdup(backup);
				start++;
		}
		else
			return (1);	
	}
	if (board[start] == '\0')
	{
		b++;
		printf("INCREASE BORD SIZE BY %d\n", b + 1);
		solve_mode(board_mode(ft_lstlen(&lst) + b + 1), begin_list, 1, board_mode(ft_lstlen(&lst) + b + 1));
	}
	return (0);
}
