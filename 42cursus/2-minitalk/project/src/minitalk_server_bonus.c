/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichkiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:22:50 by kichkiro          #+#    #+#             */
/*   Updated: 2023/04/06 22:52:37 by kichkiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile char	*g_received_bits = 0;

/**
 * @brief 
	Decodes 8 bits into a character.
 * @details 
	The function takes a global char array containing 8 bits, and decodes the 
	bits into a character using bitwise operators.
 * @param bits 
	The 8 bits to be decoded.
 * @return 
	The decoded character.
 */
static char	decode_bits(volatile char *bits)
{
	char	c;
	size_t	i;

	c = 0;
	i = 0;
	while (i < 8)
	{
		if (bits[i] == '1')
			c |= (1 << i);
		else
			c |= 0;
		i++;
	}
	return (c);
}

/**
 * @brief 
	Signal handler for incoming signals.
 * @details 
	The function takes a signal, signal information and a context; 
	It reads the signal and appends '1' or '0' to a global char array depending 
	on the signal received; 
	If the length of the array is equal to 8, the 8 bits are decoded into a 
	character and printed to the standard output using the write function; 
	The global char array is then freed.
 * @param sig 
	The signal received.
 * @param info 
	Information about the signal.
 * @param context 
	Context of the signal.
 */
static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	char	c;

	(void)context;
	if (sig == SIGUSR1)
		g_received_bits = ft_char_append((char *)g_received_bits, '1', 1);
	else if (sig == SIGUSR2)
		g_received_bits = ft_char_append((char *)g_received_bits, '0', 1);
	else
		exit(1);
	if (ft_strlen((char *)g_received_bits) == 8)
	{
		c = decode_bits(g_received_bits);
		write(1, &c, 1);
		ft_free((void **)&g_received_bits);
	}
	kill(info->si_pid, SIGUSR1);
}

/**
 * @brief 
	Main function for the server process.
 * @details 
	The function initializes a signal handler for SIGUSR1 and SIGUSR2 and waits 
	for incoming signals; 
	Once a signal is received, the signal handler function is called and the 
	corresponding bit is appended to a global char array; 
	Once 8 bits are received, they are decoded into a character and printed to 
	the standard output using the write function; 
	The server process then sends a signal back to the client process to 
	indicate that the character has been received.
 * @param argc 
	The number of arguments passed to the function.
 * @param argv 
	The arguments passed to the function.
 * @return 
	The exit status of the function.
 */
int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		ft_exit("Too many arguments...\n", RED_B, 2, 1);
	ft_printf("%sServer PID ->%s %i%s\n", WHITE_B, MAGENTA_B, getpid(), RESET);
	while (true)
	{
		ft_bzero(&act, sizeof(act));
		act.sa_sigaction = &sig_handler;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}
