#include <loguru.hpp>
#include <Gemini.h>

#include <string>
#include <functional>

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
    // TODO: Log exchange name here
    // And provide warning as well if
    // connecting to real exchange
}

bool Gemini::connectExch()
{
    std::string wsAddr = config_->get<std::string>("WebSocketAddr");
    wsAddr += "/v1/marketdata/BTCUSD"; // TODO: use commandline to specify
    LOG_F(INFO, wsAddr.c_str());
    client_.connect(wsAddr).then([&](){
        {
            std::lock_guard<std::mutex> lock(mtx_);
            exchangeConnected_ = true;
        }
        LOG_F(INFO, "MD connection established");
    });
    using namespace std::placeholders;
    client_.set_message_handler(std::bind(&Gemini::onMessage_, this, _1));
    return exchangeConnected_;
}

bool Gemini::connectEngine()
{
    return false;
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

void Gemini::onMessage_(web::websockets::client::websocket_incoming_message msg)
{
    // FIXME: write some real things
    std::cout << msg.extract_string().get() << std::endl;
}
