#include <Config.h>
#include <fstream>

using namespace proxy;
using namespace web;

Config::Config(const std::string& fileName)
{
    std::fstream fstrm(fileName);
    json_ = json::value::parse(fstrm);

    if (json_.has_field(U("INCLUDE")))
    {
        int split = fileName.find_last_of("/\\");
        std::string incFilePath;
        if (split != -1 /*nop*/)
        {
            incFilePath = fileName.substr(split + 1) + json_[U("INCLUDE")].
                                                       as_string();
        }
        else
        {
            incFilePath = json_[U("INCLUDE")].as_string();
        }
        std::fstream incFstrm(incFilePath);
        include_ = json::value::parse(incFstrm);
        json_.erase("INCLUDE");
    }
}
