/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:12:59 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/11 19:22:46 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main()
{
	int k;
	k = 15;
	// test1 score 107/233 max ok
		// conv_d-i 20/40 max ok
		// conv_u 14/26 max ok
		// conv_x 20/39 max ok
		// conv_c 8/8 max ok
		// conv_s 14/15 max ok
		// conv_p 6/7 max ok
		// Percent 8/12 max ok
	// test  score 773/2070
	printf("ORDI: %d\n", printf("%d\n", -424));
	printf("MOI: %d\n", ft_printf("%d\n", -424));
}
