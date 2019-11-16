/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:48:52 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/15 11:23:26 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // remove

static int	check_blocks(char *new, char *board)
{
	size_t		let_a;
	size_t		let_b;
	size_t		i;

	let_a = 0;
	i = 0;
	while (new[i])
	{
		if (ft_isupper(new[i]))
			let_a++;
		i++;
	}
	let_b = 0;
	i = 0;
	while (board[i])
	{
		if (ft_isupper(board[i]))
			let_b++;
		i++;
	}
	if (let_a - let_b == 4)
		return (1);
	//printf("\033[0;31mPlacing Error\033[0m\t\n");
	return (0);
}

int				slap(char *board, char *tblock, size_t start)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = start;
	j = 0;
	//printf("A BOARD:\n%s", board);
	//printf("A TBLOCK:\n%s", tblock);
	new = NULL;
	new = ft_strdup(board);
	//printf("A NEW COPY:\n%s", new);
	//return (0);
	//printf("STRLEN OF NEW BEFORE: %zu\n", ft_strlen(new));
	//printf("J BEFORE: %zu\n", j);
	//I printf("I BEFORE: %zu\n", i);
	while (i < ft_strlen(new) - 1 && new[i] && tblock[j])
	{
		(tblock[j] == '\n') ? j++ : 0;
		(new[i] == '\n') ? i++ : 0;
		if (!(ft_isupper(new[i])))
		{
			if (new[i + 1] == '\n' && ft_isupper(tblock[j + 1]))
				break ;
			new[i] = tblock[j];
		}
		i++;
		j++;
	}
	//printf("J AFTER: %zu\n", j);
	//printf("I AFTER: %zu\n", i);
	//printf("AFTER PLACING\n%s", new);
	//printf("STRLEN OF NEW: %zu\n", ft_strlen(new));
	//printf("STRLEN OF TBLOCK: %zu\n", ft_strlen(tblock));
	//return (0);
	if (!check_blocks(new, board))
	{
		ft_strdel(&new);
		return (0);
	}
	ft_memmove(board, new, ft_strlen(new));
	ft_strdel(&new);
	//ft_putendl(board);
	return (1);
}
