/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:09 by agenc             #+#    #+#             */
/*   Updated: 2023/01/11 16:36:34 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <stdio.h>

void	ft_shiftoperation(int pid, char c);
void	signal_handler(int signal);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		check_pid(char *s);

#endif
