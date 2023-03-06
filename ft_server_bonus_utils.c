/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:53:03 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/06 19:53:06 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_reset(t_serv *serv, siginfo_t *info)
{
	static int	k;

	while (k < serv->j / 8)
	{
		write(1, &serv->str[k], 1);
		k++;
	}
	if (k == serv->j / 8)
		k = 0;
	serv->i = 0;
	serv->character = 0;
	serv->j = 0;
	ft_memset(serv->str, 0, sizeof(*serv->str));
}

void	unibit(int *byte, unsigned char c)
{
	int	i;

	*byte = 0;
	i = 7;
	if ((c & 1 << i) == 0)
		(*byte)++;
	else
	{
		while (i >= 4)
		{
			if (c & 1 << i)
				(*byte)++;
			i--;
		}
	}
}
