#pragma once

#include <ExchangeFactory.h>

namespace proxy
{

class Gemini : public ProxyBase
{
public:
    Gemini(const Config* );

    bool connectExch() override;

    bool connectEngine() override;

    bool checkExchConnection() override;

    bool checkEngineConnection() override;
};

} // end namespace proxy
