/*
** Basic project
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#include "../includes/macros.hpp"
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
    std::string str;
    std::ifstream in(fileName.c_str());

    if(!in)
        return false;
    while (std::getline(in, str)) {
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }
    in.close();
    return true;
}


int main (int ac, char **av)
{
    std::vector <std::string> file;
    size_t lines;
    size_t  i = 1;
    std::string err_msg = "USAGE: ./test filepath";

    if (ac != 2) {
        std::cout << err_msg << std::endl;
        return 84;
    }
    if (getFileContent(av[1], file) == false) {
        std::cout << err_msg + ": File error" << std::endl;
        return 84;
    }
    lines = file.size();
    for (auto &str : file) {
        std::replace(str.begin(), str.end(), ',', ' ');
        str = str.substr (str.find("|") + 1, str.length());
        if (i != lines)
            str = str.substr (0, str.length() - 1);
        str.erase(str.begin() + str.find(' '));
        std::cout << str << std::endl;
        i++;
    }
    return SUCCES;
}