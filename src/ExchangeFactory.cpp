#include <ExchangeFactory.h>

#include <string>

using namespace proxy;

ProxyBase* createProxy(const std::string& exchName, const Config* )
{
    if (exchName == "Gemini" || exchName == "Gemini-Sandbox")
    {
    }

    return NULL;
}
