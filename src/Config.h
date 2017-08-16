#pragma once

#include <string>
#include <vector>

#include <cpprest/json.h>

namespace proxy
{

class Config
{
public:

    Config(const std::string& fileName);

    template<typename T>
    T get(const std::string& key);

    bool hasKey(const std::string& key);

private:
    web::json::value json_;
    web::json::value include_;
};

} // end namespace proxy

#include <Config.inl>
