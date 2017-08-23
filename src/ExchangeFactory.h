#pragma once

#include <string>

#include <Config.h>

namespace proxy
{

class ProxyBase
{
public:
    ProxyBase(Config* config) : config_(config) {}

    /**
     * Make connection to the exchange
     * Should be non-blocking
     */
    virtual void connectExch() = 0;

    /**
     * Make connection to the engine
     * Should be non-blocking
     */
    virtual void connectEngine() = 0;

    /**
     * Checks connection with exchange.
     */
    virtual bool checkExchConnection() = 0;

    /**
     * Checks connection with engine.
     */
    virtual bool checkEngineConnection() = 0;

protected:
    Config* config_;
};

ProxyBase* createProxy(const std::string& exchName , Config* );

} // end namespace proxy
