#define LOGURU_IMPLEMENTATION 1
#include <Config.h>
#include <Gemini.h>
#include <loguru.hpp>
#include <args.hxx>
#include <ProxyFactory.h>

#include <iostream>
#include <string>
#include <unistd.h>

using namespace proxy;

void parseHelper(args::ArgumentParser& parser, int argc, char** argv)
{
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        exit(0);
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        exit(1);
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        exit(1);
    }
}

int main(int argc, char** argv)
{
    loguru::init(argc, argv);
    args::ArgumentParser parser(argv[0]);
    Config config(parser);

    parseHelper(parser, argc, argv); // first time only for config loader

    std::string name = config.get<std::string>("Name");

    ProxyBase* proxy = createProxy(name, &config, parser);

    proxy->connectEngine();
    proxy->connectExch();

    while (proxy->checkExchConnection() &&
           proxy->checkEngineConnection())
    {
        sleep(10);
    }
}
