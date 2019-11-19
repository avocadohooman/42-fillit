/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:41:37 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/19 12:50:31 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		xy_position_a(char *s, size_t i, size_t xy)
{
	i = i + 10;
	while (s[i - 1] != '.' && s[i - 1] != '\n' && s[i])
	{
		xy--;
		i--;
	}
	return (xy);
}

static int		xy_position_b(char *s, size_t i, size_t xy)
{
	i = i + 5;
	while (s[i - 1] != '.' && s[i - 1] != '\n' && s[i])
	{
		xy--;
		i--;
	}
	return (xy);
}

int				start(char *s)
{
	size_t i;
	size_t xy;

	i = 0;
	xy = 0;
	while (s[i] == '.' || s[i] == '\n')
		i++;
	xy = i;
	if (ft_isupper(s[i + 10]) && ft_isupper(s[i + 9]) && (i + 10) < 20)
		return (xy_position_a(s, i, xy));
	if (ft_isupper(s[i + 5]) && (i + 5) < 20)
		return (xy_position_b(s, i, xy));
	return (xy);
}

int				solve_mode(char *board, t_list *lst, size_t start, char *backup)
{
	if (!lst)
	{
		ft_putstr(board);
		ft_strdel(&backup);
		ft_strdel(&board);
		return (1);
	}
	while (board[start])
	{
		if (!slap(board, lst->content, start))
			start++;
		else if (!solve_mode(board, lst->next, 0, ft_strdup(board)))
		{
			board = ft_strdup(backup);
			start++;
		}
		else
		{
			ft_strdel(&backup);
			return (1);
		}
	}
	ft_strdel(&board);
	ft_strdel(&backup);
	return (0);
}
