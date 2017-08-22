#include <Config.h>
#include <fstream>
#include <loguru.hpp>

using namespace proxy;
using namespace web;

Config::Config(args::ArgumentParser& argParser)
    : fileName_(argParser, "filepath", "config file path", {'f', "filepath"}),
      loaded_(false)
{
}

bool Config::hasKey(const std::string& key)
{
    checkLoad_();
    return json_.has_field(key) || include_.has_field(key);
}

//FIXME: Might slowdown get functions
void Config::checkLoad_()
{
    if (loaded_)
        return;

    std::string fileName;
    if (fileName_)
        fileName = args::get(fileName_);
    else
    {
        LOG_F(ERROR, "Config file path not specified");
        exit(1);
    }

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
    loaded_ = true;
}
