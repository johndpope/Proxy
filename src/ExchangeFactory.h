#pragma once

#include <string>

#include <Config.h>

namespace proxy
{

class ProxyBase
{
public:
    ProxyBase(const Config* );

    /**
     * Make connection to the exchange
     * Returns true if success; false otherwise.
     * Should be non-blocking
     */
    virtual bool connectExch() = 0;

    /**
     * Make connection to the engine
     * Returns true if success, false otherwise.
     * Should be non-blocking
     */
    virtual bool connectEngine() = 0;

    /**
     * Checks connection with exchange.
     */
    virtual bool checkExchConnection() = 0;

    /**
     * Checks connection with engine.
     */
    virtual bool checkEngineConnection() = 0;

protected:
    const Config* config_;
};

ProxyBase* createProxy(const std::string& exchName , const Config* );

} // end namespace proxy
