#include <loguru.hpp>
#include <Gemini.h>

#include <string>
#include <functional>
#include <vector>

// FIXME: remove this
#include <iostream>

using namespace proxy;
using namespace web;
using namespace web::websockets::client;

Gemini::Gemini(Config* config, args::ArgumentParser& /*argParser*/)
    : ProxyBase(config),
      exchangeConnected_(false),
      engineConnected_(false)
{
}

void Gemini::connectExch()
{
    for (auto& sym : config_->get<std::vector<std::string> >("Symbols"))
    {
        connectHelper_(sym);
    }

    // Note: make sure set message handler after everyone has connected

    using namespace std::placeholders;

    for (auto& sym : config_->get<std::vector<std::string> >("Symbols"))
    {
        clients_[sym].client_.set_message_handler(std::bind(&Gemini::onMessage_,
                                                           this,
                                                           _1,
                                                           sym));
    }
}

void Gemini::connectEngine()
{
}

bool Gemini::checkExchConnection()
{
    std::lock_guard<std::mutex> lock(mtx_);
    bool exchStatus = exchangeConnected_;
    return exchStatus;
}

bool Gemini::checkEngineConnection()
{
    return false;
}

void Gemini::onMessage_(web::websockets::client::websocket_incoming_message /*msg*/,
                        const std::string& symbol)
{
    // FIXME: write some real things
    LOG_F(2, "Got %s", symbol.c_str());
}

void Gemini::connectHelper_(const std::string& symbol)
{
    status& clientStatus = clients_[symbol];
    std::string wsAddr = config_->get<std::string>("WebSocketAddr");
    wsAddr += "/v1/marketdata/" + symbol;
    clientStatus.client_.connect(wsAddr).wait();
    clientStatus.exchangeConnected_ = true;
    LOG_F(INFO, "MD connection established to %s", wsAddr.c_str());
}
