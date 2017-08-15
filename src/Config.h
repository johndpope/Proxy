#pragma once

#include <fstream>
#include <string>
#include <vector>

#include <cpprest/json.h>

namespace proxy
{

class Config
{
public:
    Config();
    Config(const std::string& fileName);

    template<typename T>
    T get(const std::string& key);

    bool hasKey(const std::string& key);

private:
    web::json::value json_;
};

} // end namespace proxy

#include <Config.inl>
