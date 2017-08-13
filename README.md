# Proxy
Responsible for communication with exchange.

# Required libraries

## Websocket and REST library

[cpprestsdk](https://github.com/Microsoft/cpprestsdk)

## Logging library

[loguru](https://github.com/emilk/loguru): Headers only. Default location is the
same level as Proxy directory. Override with `make LOGLIBDIR=<library directory> [other options]`
when building

## Commandline argument parser library

[args](https://github.com/Taywee/args/blob/master/args.hxx): Headers only. Default location is the
same level as Proxy directory. Override with `make ARGSLIBDIR=<library directory> [other options]`
when building
