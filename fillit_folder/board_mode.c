/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:03:34 by gmolin            #+#    #+#             */
/*   Updated: 2019/11/12 16:34:19 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // delete before submission

static int		board_size(size_t len)
{
	float		temp;
	float		sqrt;
	int			base;

	//printf("This is len %zu\n", len);
	base = len * 4;
	//printf("This is base %d\n", base);
    sqrt = base / 2;
    temp = 0;
	//printf("%d\n", base);
	while(sqrt != temp)
	{
		temp = sqrt;
	    sqrt = (base / temp + temp) / 2;
	}
	//printf("This is sqrt%f\n", sqrt);
	return (sqrt);
}

char	*board_mode(size_t len)
{
	size_t		i;
	char		*board;
	size_t		size;
	//ft_putstr("start");
	
	i = 0;
	//printf("This is len before board size %zu\n", len);
	size = (board_size(len) + 1) * (board_size(len));
	//printf("%zu\n", size);
	if (!(board = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (i < size)
	{
		board[i] = '.';
		if (i % (board_size(len) + 1) == 0)
			board[i] = '\n';
		i++;
	}
	board[i] = '\0';
	return (board);
}
