CXX := g++
LOGLIBDIR ?=../../loguru
ARGSLIBDIR ?= ../../args
CFLAGS := -g -std=c++14 -Wall -Wextra
LFLAGS := $(CFLAGS)

INCLUDES := -I$(LOGLIBDIR) -I$(ARGSLIBDIR) -I.
LIBRARIES := -lcpprest -lpthread -ldl

CFLAGS += $(INCLUDES)
LFLAGS += $(INCLUDES) $(LIBRARIES)

CPPFILES := $(wildcard *.cpp)
OBJFILES := $(addprefix obj/,$(notdir $(CPPFILES:.cpp=.o)))

TARGET := Proxy # Executable name

$(TARGET): directory $(OBJFILES)
	$(CXX) $(LFLAGS) -o $@ $(OBJFILES)

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

directory:
	mkdir -p obj

clean:
	rm -f $(TARGET)
	rm -rf obj

