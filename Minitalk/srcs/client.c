/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:53:43 by afontan           #+#    #+#             */
/*   Updated: 2025/01/15 11:45:23 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi_minitalk(const char *str)
{
	int	x;
	int	i;
	int	sign;

	i = 0;
	x = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = x * 10;
		x = x + str[i] - 48;
		i++;
	}
	return (x * sign);
}

void	confirm(int signal)
{
	if (signal == SIGUSR2)
		return ;
	else if (signal == SIGUSR1)
		ft_printf("Message Received");
}

void	send_mess(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;
	int		i;

	i = 0;
	g_current_char = 0;
	if (ac != 3)
	{
		ft_printf("Erreur");
		return (1);
	}
	pid = ft_atoi_minitalk(av[1]);
	message = av[2];
	signal(SIGUSR1, confirm);
	signal(SIGUSR2, confirm);
	while (message[i])
	{
		send_mess(pid, message[i]);
		i++;
	}
	send_mess(pid, '\0');
	usleep(500);
}
