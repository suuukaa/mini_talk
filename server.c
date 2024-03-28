/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:33:56 by sel-bouy          #+#    #+#             */
/*   Updated: 2024/03/25 11:26:52 by sel-bouy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	server_receive(int receive, siginfo_t *info, void *context)
{
	static int	bit;
	static int	n;
	static int	processid;

	(void)context;
	if (processid != info->si_pid)
	{
		processid = info->si_pid;
		n = 0;
		bit = 0;
	}
	if (receive == SIGUSR1)
		n += 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &n, 1);
		bit = 0;
		n = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	write(1, "🤩ooooh are you ready let's go🤩\n", 38);
	write(1, "the process id is : 🥳🥳🥳 ", 34);
	ft_print_numbers(getpid());
	write(1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = server_receive;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
}
