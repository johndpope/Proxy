#include <Gemini.h>

#include <string>
#include <functional>

// FIXME: remove this
#include <iostream>

using namespace proxy;
using namespace web;
using namespace web::websockets::client;

Gemini::Gemini(const Config* config) : ProxyBase(config),
                                       exchangeConnected_(false),
                                       engineConnected_(false)
{
    // TODO: Log exchange name here
    // And provide warning as well if
    // connecting to real exchange
}

bool Gemini::connectExch()
{
    // TODO: Log wsAddr.
    std::string wsAddr = config_->get<std::string>("WebSocketAddr");
    wsAddr += "/v1/marketdata/BTCUSD";
    client_.connect(wsAddr).then([&](){
        {
            std::lock_guard<std::mutex> lock(mtx_);
            exchangeConnected_ = true;
        }
        // TODO: log when success
    });
    using namespace std::placeholders;
    client_.set_message_handler(std::bind(&Gemini::onMessage_, this, _1));
}

bool Gemini::connectEngine()
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

}

void Gemini::onMessage_(web::websockets::client::websocket_incoming_message msg)
{
    // FIXME: write some real things
    std::cout << msg.extract_string().get() << std::endl;
}
