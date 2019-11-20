/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:48:52 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/20 17:03:27 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_board(char *new, char *board)
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
	return (0);
}

static char			*downsize(char *tblock, size_t len)
{
	size_t	i;
	size_t	j;
	char	*new;
	size_t	len2;

	new = ft_strnew((len + 1) * len);
	i = 0;
	j = 0;
	len2 = 0;
	while (i < 13)
	{
		if (len2 == 3)
		{
			new[j] = '\n';
			i = i + 2;
			j++;
			len2 = 0;
		}
		new[j] = tblock[i];
		j++;
		i++;
		len2++;
	}
	new[j] = '\n';
	return (new);
}

static void			placing(char *new, char *tblock, size_t i, size_t j)
{
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
}

int					slap(char *board, char *tblock, size_t start)
{
	size_t		j;
	char		*new;
	char		*tmp;

	j = 0;
	new = ft_strdup(board);
	if (ft_strclen(new, '\n') == 3)
	{
		tmp = downsize(tblock, 3);
		placing(new, tmp, start, j);
		ft_strdel(&tmp);
	}
	else
		placing(new, tblock, start, j);
	if (!check_board(new, board))
	{
		ft_strdel(&new);
		return (0);
	}
	ft_memmove(board, new, ft_strlen(new));
	ft_strdel(&new);
	return (1);
}
