#pragma once

#include <string>
#include <vector>

#include <cpprest/json.h>
#include <args.hxx>

namespace proxy
{

class Config
{
public:

    Config(args::ArgumentParser& argParser);

    template<typename T>
    T get(const std::string& key);

    bool hasKey(const std::string& key);

private:
    web::json::value json_;
    web::json::value include_;
    args::ValueFlag<std::string> fileName_;
    bool loaded_;

    void checkLoad_();
};

} // end namespace proxy

#include <Config.inl>
