/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuokka <vkuokka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:33:33 by vkuokka           #+#    #+#             */
/*   Updated: 2019/11/22 12:32:46 by vkuokka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*read_file(int fd)
{
	char		rline[BUFF_SIZE + 1];
	char		*file;
	char		*tmp;
	int			count;
	size_t		i;

	i = 0;
	if (!(file = ft_strnew(0)))
		return (NULL);
	while ((count = read(fd, rline, BUFF_SIZE)) > 0)
	{
		rline[count] = '\0';
		i += count;
		tmp = file;
		file = ft_strjoin(file, rline);
		free(tmp);
	}
	if (count < 0)
		return (NULL);
	if (file[i - 2] == '\n')
		return (NULL);
	return (file);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		*file;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(file = read_file(fd)) || !create_mode(file))
			ft_putendl("error");
		ft_strdel(&file);
		close(fd);
	}
	else
		ft_putendl("usage: ./fillit [] source_file");
	return (0);
}
