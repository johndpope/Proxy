#include <Config.h>
#include <fstream>

using namespace proxy;
using namespace web;

Config::Config(const std::string& fileName)
{
    std::fstream fstrm(fileName);
    json_ = json::value::parse(fstrm);

    if (json_.has_field("include"))
    {
        int split = fileName.find_last_of("/\\");
        std::string incFilePath;
        if (split != -1 /*nop*/)
        {
            incFilePath = fileName.substr(0, split + 1) + json_["include"].
                                                       as_string();
        }
        else
        {
            incFilePath = json_["include"].as_string();
        }

        std::fstream incFstrm(incFilePath);
        include_ = json::value::parse(incFstrm);
        json_.erase("include");
    }
}

bool Config::hasKey(const std::string& key)
{
    return json_.has_field(key) || include_.has_field(key);
}
