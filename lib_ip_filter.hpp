#pragma once

#include "lib_ip_filter.cpp"

std::vector<std::string> split(const std::string &, char);
bool allow_print_ip(std::string, std::string);
void print_ip_pool(const std::vector<std::vector<std::string>>&, std::string);