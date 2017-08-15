#pragma once

#include <Config.h>

namespace proxy
{

template<>
std::string Config::get<std::string>(const std::string& key)
{

}

template<>
int Config::get<int>(const std::string& key)
{

}

template<>
double Config::get<double>(const std::string& key)
{

}

template<>
bool Config::get<bool>(const std::string& key)
{

}

template<>
std::vector<std::string> Config::get<std::vector<std::string> >(const std::string& key)
{

}

template<>
std::vector<int> Config::get<std::vector<int> >(const std::string& key)
{

}

} // end namespace proxy
