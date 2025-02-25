/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:44:59 by agenc             #+#    #+#             */
/*   Updated: 2022/11/14 14:17:22 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_p(unsigned long p)
{
	int	i;

	i = 0;
	if (p >= 16)
		i += ft_p(p / 16);
	if ((p % 16) < 10)
		i += ft_putchar((p % 16) + 48);
	else
		i += ft_putchar((p % 16) + 87);
	return (i);
}
