/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:08:19 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/06 18:08:19 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	toUpper(std::string str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = std::toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		i = 0;
		while (argv[++i])
		{
			std::string str = argv[i];
			std::cout << toUpper(str);
			if (argv[i + 1])
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
