#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h> 

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

std::vector<int> split_to_int(const std::string &str, char d)
{
    std::vector<int> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(atoi(str.substr(start, stop - start).c_str()));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(atoi(str.substr(start).c_str()));

    return r;
}

void print_ip(const std::vector<int>& ip)
{
    bool start = false;
    for (auto& ip_part: ip){
        if (start){
            std::cout << ".";
        } else {
            start = true;
        }
            std::cout << ip_part;
    }
    std::cout << std::endl;
}

void filter(const std::vector<std::vector<int>>& ip_pool, int  a = -1, int b = -1, int c = -1, int d = -1)
{
    unsigned i = ip_pool.size();
    std::vector<int> param = {a, b, c, d};
    for (int j = 0; j < 4; ++j){
        if (param[j] > -1) while (ip_pool[i-1][j] <= param[j] && i > 0) --i;
    }
    if (a == -1 && b == -1 && c == -1 && d == -1) i = 0;
        while (i < ip_pool.size()){
            if((a == ip_pool[i][0] || a < 0) && (b == ip_pool[i][1] || b < 0)
            && (c == ip_pool[i][2] || c < 0) && (d == ip_pool[i][d] || d < 0))
                print_ip(ip_pool[i]);
            ++i;
        }
    
}

void filter_any(const std::vector<std::vector<int>>& ip_pool, int  a)
{
    for (const auto& ip: ip_pool)
        if (ip[0] == a || ip[1] == a || ip[2] == a || ip[3] == a)
            print_ip(ip);
}
