/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:11:15 by gmolin            #+#    #+#             */
/*   Updated: 2019/11/15 11:15:50 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft_folder/includes/libft.h"
# define BUFF_SIZE 1

int			create_mode(char *file);
void		ft_putlst(t_list **alst); //delete after!
char		*board_mode(size_t len);
int			solve_mode(char *board, t_list *lst, size_t start, char *backup);
int			slap(char *board, char *tblock, size_t start);
int 		start(char *s);
int			board_size(size_t len);

 #endif