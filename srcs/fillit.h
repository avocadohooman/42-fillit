/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:11:15 by gmolin            #+#    #+#             */
/*   Updated: 2019/11/19 14:09:27 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 1

int			create_mode(char *file);
char		*board_mode(size_t len);
int			solve_mode(char *board, t_list *lst, size_t start, char *backup);
int			slap(char *board, char *tblock, size_t start);
int			start(char *s);
int			board_size(size_t len);
void		increase_block(t_list **alst, size_t len);

#endif
