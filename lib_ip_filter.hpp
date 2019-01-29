#pragma once

#include "lib_ip_filter.cpp"

std::vector<std::string> split(const std::string &, char);
std::vector<int> split_to_int(const std::string &, char);
void filter(const std::vector<std::vector<int>>& ip_pool, int , int, int, int);
void filter_any(const std::vector<std::vector<int>>&, int);
