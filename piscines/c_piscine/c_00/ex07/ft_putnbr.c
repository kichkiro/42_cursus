/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:22:42 by kichkiro          #+#    #+#             */
/*   Updated: 2022/07/17 15:02:10 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		i;
	int		cifra;
	char	nc;

	i = 0;
	while (nb != 0 && i == 0)
	{
		cifra = nb % 10;
		nb /= 10;
		i++;
		nc = cifra + '0';
		ft_putnbr (nb);
	}
	write (1, &nc, 1);
}