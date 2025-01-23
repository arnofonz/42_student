/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:52:30 by afontan           #+#    #+#             */
/*   Updated: 2025/01/15 12:53:10 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*my_realloc(char *ptr, int new_size)
{
	char	*new_str;
	int		i;

	new_str = malloc(new_size);
	if (!new_str)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < new_size)
		new_str[i++] = '\0';
	i = 0;
	if (ptr)
	{
		while (i < (int)ft_strlen(ptr))
		{
			new_str[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (new_str);
}

char	*malloc_mess(char *message, int *i)
{
	static int	mess_size = 10000;
	char		*mess_malloc;

	mess_malloc = NULL;
	if (message == NULL)
	{
		mess_size = 10000;
		message = malloc(mess_size * sizeof(char));
		if (!message)
			exit (1);
	}
	if (*i >= mess_size - 1)
	{
		mess_size += mess_size;
		mess_malloc = my_realloc(mess_malloc, mess_size * sizeof(char));
		if (!message)
			exit(1);
		ft_strlcpy(mess_malloc, message, mess_size);
		free (message);
		return (mess_malloc);
	}
	else
		return (message);
}

char	receipt_signal(int sig, unsigned char g_current_char, void *s)
{
	(void)s;
	if (sig == SIGUSR1)
		g_current_char = (g_current_char << 1);
	else if (sig == SIGUSR2)
		g_current_char = (g_current_char << 1) | 1;
	return (g_current_char);
}

void	handler(int sig, siginfo_t *info, void *s)
{
	static char	*message = NULL;
	static int	count = 0;
	static int	i = 0;

	message = malloc_mess(message, &i);
	g_current_char = receipt_signal(sig, g_current_char, s);
	count++;
	if (count == 8)
	{
		if (g_current_char == '\0')
		{
			message[i] = '\0';
			ft_printf("message recu :%s\n", message);
			i = 0;
			free(message);
			message = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		else
			message[i++] = g_current_char;
		g_current_char = 0;
		count = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sig;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Trop s'arguments.\n");
		return (1);
	}
	pid = getpid();
	ft_printf("le PID du serveur est : %d\nWaiting for a message...\n", pid);
	sig.sa_sigaction = handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (ac == 1)
	{
		pause();
	}
	return (0);
}
