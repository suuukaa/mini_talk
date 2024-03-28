/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:31:41 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/03/24 22:27:21 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H
# include <signal.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_print_numbers(int n);
void	server_receive(int receive, siginfo_t *info, void *context);

#endif
