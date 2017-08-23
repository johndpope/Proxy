#define LOGURU_IMPLEMENTATION 1
#include <Config.h>
#include <Gemini.h>
#include <loguru.hpp>
#include <args.hxx>

#include <iostream>
#include <string>
#include <unistd.h>

using namespace proxy;

int main(int argc, char** argv)
{
    loguru::init(argc, argv);
    args::ArgumentParser parser(argv[0]);
    Config config(parser);
    Gemini gemini(&config, parser);
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (args::Help)
    {
        std::cout << parser;
        return 0;
    }
    catch (args::ParseError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    gemini.connectExch();
    while (gemini.checkExchConnection())
    {
        sleep(10);
    }
}
