#pragma once

#include <mutex>
#include <unordered_map>

#include <ProxyFactory.h>
#include <cpprest/ws_client.h>
#include <args.hxx>

namespace proxy
{

struct status
{
public:
    web::websockets::client::websocket_callback_client client_;
    bool exchangeConnected_;

    status() : exchangeConnected_(false) {}
};

class Gemini : public ProxyBase
{
public:
    Gemini(Config*, args::ArgumentParser& argParser);

    void connectExch() override;

    void connectEngine() override;

    bool checkExchConnection() override;

    bool checkEngineConnection() override;

private:
    void onMessage_(web::websockets::client::websocket_incoming_message msg,
                    const std::string& symbol);
    void connectHelper_(const std::string& symbol);

    std::mutex mtx_;
    bool exchangeConnected_;
    bool engineConnected_;
    std::unordered_map<std::string, status> clients_;

};

} // end namespace proxy
