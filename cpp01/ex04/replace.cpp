/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

static bool openFiles(std::string file_name_read, std::fstream &source, std::fstream &destiny)
{
    std::string file_name_write;
    int delimiter;
    std::string sufixo;

    if ((int)(file_name_read.find('.')) != -1)
    {
        delimiter = file_name_read.find('.') + 1;
        sufixo = "replace";
    }
    else
    {
        delimiter = file_name_read.length();
        sufixo = ".replace";
    }
    source.open(file_name_read.c_str(), std::fstream::in);
    if (!source.is_open())
    {
        std::cout << "Unable to open the following file: " << file_name_read << "\n";
        return false;
    }
    file_name_write = file_name_read.substr(0, delimiter) + sufixo;
    destiny.open(file_name_write.c_str(), std::fstream::out|std::fstream::app);
    if (!destiny.is_open())
    {
        source.close();
        std::cout << "Unable to open the following file: " << file_name_write << "\n";
        return false;
    }
    return true;
}

static void foundS1Line(std::fstream &destiny, std::string line, std::string s1, std::string s2, size_t &index_start, int &index_end)
{
    bool foundS1;

    foundS1 = true;
    while (foundS1)
    {
        destiny << line.substr(index_start, index_end - index_start);
        destiny << s2;
        index_start = index_end + s1.length();
        index_end = line.find(s1, index_start);
        if (index_end == -1)
            foundS1 = false;
    }
}

static void replaceSourceToDestiny(std::fstream &source, std::fstream &destiny, std::string s1, std::string s2)
{
    int index_end;
    size_t index_start;
    std::string line;

    while(std::getline(source, line))
    {
        index_start = 0;
        index_end = line.find(s1);
        if (index_end != -1)
            foundS1Line(destiny, line, s1, s2, index_start, index_end);
        if (index_start < line.length())
            destiny << line.substr(index_start, line.length());
        if (source.peek() != EOF)
            destiny << "\n";
    }
    source.close();
    destiny.close();
}

int replace(std::string file_name_read, std::string s1, std::string s2)
{
    std::fstream file_read;
    std::fstream file_write;
    std::string file_name_write;

    if (!(openFiles(file_name_read, file_read, file_write)))
        return 2;
    replaceSourceToDestiny(file_read, file_write, s1, s2);
    return 0;
}