/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:25:15 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/09 16:12:27 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int checkParam(int argc, char **argv) {
    if (argc != 4)
    {
        std::cout << "Usage: ./sed file str str" << std::endl;
        return (0);
    }
    if (!argv[1])
    {
        std::cout << "Usage: ./sed file str str" << std::endl;
        return (0);
    }
    return (1);
}

std::string replaceLine(std::string line, char *str, char *replace)
{
    std::string start;
    std::string end;
    size_t i = 0;
    
    if ((std::string) str == (std::string) replace)
        return (line);
    while (line[i])
    {
        i = line.find(str);
        if (i > line.length())
            break;
        if (line[i])
        {
            start = line.substr(0, i);
            end = line.substr(i + std::string(str).length(), line.length());
            line = start + replace + end;
        }
        i += std::string(str).length();
    }
    return (line);
}

int fillAndReplace(char **argv)
{
    std::ifstream file(argv[1]);
    std::string line;
    
    if (!file.is_open())
    {
        std::cout << "Error: file not found" << std::endl;
        return (0);
    }
    std::ofstream newFile((std::string(argv[1]) + ".replace").c_str());
    if (!newFile.is_open())
    {
        std::cout << "Error while creating file" << std::endl;
        return (0);
    }
    while (std::getline(file, line))
    {
        newFile << replaceLine(line, argv[2], argv[3]);
        if (file.eof())
            break;
        newFile << std::endl;
    }
    file.close();
    newFile.close();
    return (1);
}

int main(int argc, char **argv) {
    if (!checkParam(argc, argv))
        return (-1);
    if (!argv[2] || !argv[3])
    {
        std::cout << "String is NULL" << std::endl;
        return (0);
    }
    if (!fillAndReplace(argv))
        return (-1);
    return (0);
}
