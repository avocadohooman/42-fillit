/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:03:34 by gmolin            #+#    #+#             */
/*   Updated: 2019/11/19 13:06:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		board_size(size_t len)
{
	float		temp;
	float		sqrt;
	int			base;

	base = len * 4;
	sqrt = base / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (base / temp + temp) / 2;
	}
	return (sqrt);
}

char	*board_mode(size_t len)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*board;
	char		*a_board;

	i = 0;
	size = (board_size(len) + 1) * (board_size(len));
	board = ft_strnew(size);
	while (i < size + 1)
	{
		board[i] = '.';
		if (i % (board_size(len) + 1) == 0 && i != 0)
			board[i] = '\n';
		i++;
	}
	board[i] = '\0';
	i = 1;
	j = 0;
	a_board = (char*)malloc(sizeof(char) * (size + 1));
	while (board[i])
		a_board[j++] = board[i++];
	ft_strdel(&board);
	a_board[j] = '\0';
	return (a_board);
}
