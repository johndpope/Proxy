#pragma once

#include <mutex>

#include <ExchangeFactory.h>
#include <cpprest/ws_client.h>
#include <args.hxx>

namespace proxy
{

class Gemini : public ProxyBase
{
public:
    Gemini(Config*, args::ArgumentParser& argParser);

    bool connectExch() override;

    bool connectEngine() override;

    bool checkExchConnection() override;

    bool checkEngineConnection() override;

private:
    void onMessage_(web::websockets::client::websocket_incoming_message msg);

    std::mutex mtx_;
    bool exchangeConnected_;
    bool engineConnected_;
    web::websockets::client::websocket_callback_client client_;
};

} // end namespace proxy
