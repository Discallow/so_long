/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 18:55:12 by discallow         #+#    #+#             */
/*   Updated: 2024/06/11 17:47:38 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strcmp2(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] != '.')
		i++;
	if (str1[i] == '.')
	{
		i++;
		while ((str1[i] || str2[i]) && str1[i] == str2[i])
			i++;
		if (str1[1])
			return (INT_MAX);
		else
			return (0);
	}
	return (INT_MAX);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
