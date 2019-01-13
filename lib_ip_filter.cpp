#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h> 
#include <regex>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

bool allow_print_ip(std::string rgxp, std::string ip)
{
    std::regex regular(rgxp);
    return std::regex_search(ip.c_str(), regular);
}

void print_ip_pool(const std::vector<std::vector<std::string>>& ip_pool, std::string rgxp = "")
{
    bool start;
    std::string out;
    for (auto& ip: ip_pool){
        start = false;
        out = "";
        for (auto& ip_part: ip){
            if (start){
                out += ".";
            } else {
                start = true;
            }
            out += ip_part;
        }
        if (allow_print_ip(rgxp, out))
            std::cout << out << std::endl;
    }
}