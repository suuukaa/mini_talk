/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:21:58 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/03/26 11:09:26 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	send(int i)
{
	(void)i;
	write(1, "🥰 WE WIN YEEEEEE 🥰", 25);
}

void	client_send(int p, char c)
{
	int	bits;
	int	i;

	i = 1;
	bits = -1;
	while (++bits < 8)
	{
		if (c & i)
			kill(p, SIGUSR1);
		else
			kill(p, SIGUSR2);
		i = i << 1;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int	id;
	int	i;

	i = -1;
	if (ac != 3)
		return (write(1, "we wanna 2 parameters ✌️ 👻.\n", 36), 1);
	else
	{
		id = ft_atoi(av[1]);
		if (id <= 1)
			return (write(1, "😅 Illegal pid 😅", 22), 1);
		if (av[2][0])
		{
			while (av[2][++i])
				client_send(id, av[2][i]);
		}
		else
			write(1, "😫 Empty string 😫", 23);
	}
	signal(SIGUSR1, send);
	client_send(id, '\0');
	return (0);
}
