/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:34:46 by mel-gand          #+#    #+#             */
/*   Updated: 2023/02/23 19:34:48 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_size;

void	invalid_pid(int pid)
{
	write(2, "Invalid PID", 11);
	exit(1);
}

void	sighand(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR2)
		g_size++;
}

void	ft_sbit(int pid, char c)
{
	int					i;
	int					len;
	struct sigaction	sigc;

	sigc.sa_sigaction = sighand;
	sigc.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sigc, 0);
	i = 0;
	while (i <= 7)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	len;

	len = ft_strlen(argv[2]);
	i = 0;
	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1 || pid == 0 || pid == 1)
			invalid_pid(pid);
		else
		{
			while (argv[2][i] != '\0')
			{
				ft_sbit(pid, argv[2][i]);
				i++;
			}
			if (len == g_size)
				write(1, "message received a rajol\n", 25);
		}
	}
}
