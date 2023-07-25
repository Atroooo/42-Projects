/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:01:03 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 18:01:03 by marvin           ###   ########.fr       */
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

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
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
