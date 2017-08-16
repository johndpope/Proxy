#pragma once

#include <Config.h>

namespace proxy
{

template<>
inline std::string Config::get<std::string>(const std::string& key)
{

}

template<>
inline int Config::get<int>(const std::string& key)
{

}

template<>
inline double Config::get<double>(const std::string& key)
{

}

template<>
inline bool Config::get<bool>(const std::string& key)
{

}

template<>
inline std::vector<std::string> Config::get<std::vector<std::string> >(const std::string& key)
{

}

template<>
inline std::vector<int> Config::get<std::vector<int> >(const std::string& key)
{

}

} // end namespace proxy
