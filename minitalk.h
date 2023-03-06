/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:30:51 by mel-gand          #+#    #+#             */
/*   Updated: 2023/02/04 19:30:54 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct server
{
	int		i;
	char	character;
	int		byte;
	char	str[4];
	int		j;
	int		k;
	int		id;
}			t_serv;

void		handsig(int signum, siginfo_t *info, void *context);
void		ft_sbit(int pid, char c);
int			ft_atoi(const char *str);
void		write_reset(t_serv *serv, siginfo_t *info);
void		unibit(int *byte, unsigned char c);
void		fill_str(t_serv *serv);
void		check_size(t_serv *serv, siginfo_t *info);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const char *str);
void		invalid_pid(int pid);

#endif