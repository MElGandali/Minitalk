/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:35:00 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/06 20:41:25 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	fill_str(t_serv *serv)
{
	if (serv->i == 8 && serv->j == 8)
		unibit(&serv->byte, serv->character);
	if (serv->j == 8 || serv->j == 16 || serv->j == 24 || serv->j == 32)
	{
		while (serv->k < serv->j / 8)
		{
			serv->str[serv->k++] = serv->character;
			serv->character = 0;
		}
		if (serv->k == serv->byte)
			serv->k = 0;
		serv->i = 0;
	}
}

void	check_size(t_serv *serv, siginfo_t *info)
{
	if (serv->j == 8 && serv->byte == 1)
		write_reset(serv, info);
	else if (serv->j == 16 && serv->byte == 2)
		write_reset(serv, info);
	else if (serv->j == 24 && serv->byte == 3)
		write_reset(serv, info);
	else if (serv->j == 32 && serv->byte == 4)
		write_reset(serv, info);
	else
		return ;
}

void	handsig(int signum, siginfo_t *info, void *context)
{
	t_serv	serv;

	if (serv.id != info->si_pid)
	{
		serv.str[0] = 0;
		serv.str[1] = 0;
		serv.str[2] = 0;
		serv.str[3] = 0;
		serv.j = 0;
		serv.k = 0;
		serv.character = 0;
		serv.i = 0;
	}
	if (signum == SIGUSR1)
		serv.character ^= 1 << serv.i;
	serv.i++;
	serv.j++;
	fill_str(&serv);
	if (serv.j == 7 || serv.j == 15 || serv.j == 23 || serv.j == 31)
		kill(info->si_pid, SIGUSR2);
	check_size(&serv, info);
	serv.id = info->si_pid;
}

int	main(int argc, char **argv)
{
	struct sigaction	sigv;

	sigv.sa_sigaction = handsig;
	sigv.sa_flags = SA_SIGINFO;
	printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &sigv, 0);
	sigaction(SIGUSR2, &sigv, 0);
	while (1)
		pause();
	return (0);
}
