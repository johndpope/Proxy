#pragma once

#include <Config.h>

namespace proxy
{

template<>
inline std::string Config::get<std::string>(const std::string& key)
{
    checkLoad_();
    if (json_.has_field(key))
    {
        return json_.at(key).as_string();
    }
    return include_.at(key).as_string();
}

template<>
inline int Config::get<int>(const std::string& key)
{
    checkLoad_();
    if (json_.has_field(key))
    {
        return json_.at(key).as_integer();
    }
    return include_.at(key).as_integer();
}

template<>
inline double Config::get<double>(const std::string& key)
{
    checkLoad_();
    if (json_.has_field(key))
    {
        return json_.at(key).as_double();
    }
    return include_.at(key).as_double();
}

template<>
inline bool Config::get<bool>(const std::string& key)
{
    checkLoad_();
    if (json_.has_field(key))
    {
        return json_.at(key).as_bool();
    }
    return include_.at(key).as_bool();
}

template<>
inline std::vector<std::string>
Config::get<std::vector<std::string> >(const std::string& key)
{
    checkLoad_();
    const web::json::array* array; // since there is no default constructor
    if (json_.has_field(key))
    {
        array = &json_.at(key).as_array();
    }
    else
    {
        array = &include_.at(key).as_array();
    }

    std::vector<std::string> ret;
    for (auto val : *array)
    {
        ret.push_back(val.as_string());
    }
    return ret;
}

template<>
inline std::vector<int>
Config::get<std::vector<int> >(const std::string& key)
{
    checkLoad_();
    const web::json::array* array;
    if (json_.has_field(key))
    {
        array = &json_.at(key).as_array();
    }
    else
    {
        array = &include_.at(key).as_array();
    }

    std::vector<int> ret;
    for (auto val : *array)
    {
        ret.push_back(val.as_integer());
    }
    return ret;
}

} // end namespace proxy
