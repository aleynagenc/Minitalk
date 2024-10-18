/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:27:56 by agenc             #+#    #+#             */
/*   Updated: 2023/01/07 14:27:58 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sender(int sig)
{
	static int	i = 7;
	static char	c;

	c += sig << i;
	if (i == 0)
	{
		i = 7;
		ft_printf("%c", c);
		c = 0;
	}
	else
		i--;
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		sender(1);
	if (signal == SIGUSR2)
		sender(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("\nProcess ID: %d\n", pid);
	ft_printf("\e[90mWaiting for a message..\e[0m\n");
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
}
