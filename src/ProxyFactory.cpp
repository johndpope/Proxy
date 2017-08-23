#include <ProxyFactory.h>
#include <Gemini.h>
#include <args.hxx>

#include <string>

using namespace proxy;

ProxyBase* proxy::createProxy(const std::string& exchName,
                       Config* config,
                       args::ArgumentParser& argParser)
{
    if (exchName == "Gemini" || exchName == "Gemini-Sandbox")
    {
        return new Gemini(config, argParser);
    }

    return NULL;
}
