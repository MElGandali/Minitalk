/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:30:32 by mel-gand          #+#    #+#             */
/*   Updated: 2023/02/04 19:30:34 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handsig(int signum, siginfo_t *info, void *context)
{
	t_serv	serv;

	if (serv.id != info->si_pid)
	{
		serv.i = 0;
		serv.character = 0;
	}
	serv.id = info->si_pid;
	if (signum == SIGUSR1)
		serv.character ^= 1 << serv.i;
	serv.i++;
	if (serv.i == 8)
	{
		write(1, &serv.character, 1);
		serv.i = 0;
		serv.character = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	siga;

	siga.sa_sigaction = handsig;
	siga.sa_flags = SA_SIGINFO;
	printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while (1)
		pause();
	return (0);
}
