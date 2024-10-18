/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:17:56 by agenc             #+#    #+#             */
/*   Updated: 2023/01/11 16:21:00 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
		if (res * sign < -2147483648)
			return (0);
		if (res * sign > 2147483647)
			return (-1);
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(ft_isdigit(s[i])))
		{
			ft_printf ("\e[31musage: ./client <server_pid> <text to send>\e[0m\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_shiftoperation(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3 && argv[2] != 0)
	{
		while (argv[2][i])
		{
			if (!check_pid(argv[1]))
				return (0);
			ft_shiftoperation(ft_atoi(argv[1]), argv[2][i++]);
		}
		ft_shiftoperation (ft_atoi(argv[1]), '\n');
	}
	else
		ft_printf("\e[31musage: ./client <server_pid> <text to send>\e[0m\n");
}
