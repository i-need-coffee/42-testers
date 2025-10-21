/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:47:20 by sjolliet          #+#    #+#             */
/*   Updated: 2025/10/21 15:21:44 by sjolliet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	test: $(NAME)
		@$(CC) $(CFLAGS) main.c $(NAME) -o $@
		@make -s clean
		@echo "🧪 Test created."
*/

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		count;

	count = printf("%s", (char *)NULL);
	printf("\n(og) count: %d\n", count);
	count = 0;
	count = ft_printf("%s", (char *)NULL);
	ft_printf("\n(ft) count: %d\n", count);
}
