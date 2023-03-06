/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:30:16 by mel-gand          #+#    #+#             */
/*   Updated: 2023/02/04 19:30:19 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sbit(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1 || pid == 0 || pid == 1)
		{
			write(2, "Invalid PID", 11);
			exit(1);
		}
		else
		{
			while (argv[2][i] != '\0')
			{
				ft_sbit(pid, argv[2][i]);
				i++;
			}
			ft_sbit(pid, '\n');
		}
	}
}
