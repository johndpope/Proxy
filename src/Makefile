CXX := g++
PROTOC := protoc
LOGLIBDIR ?= ../../loguru
ARGSLIBDIR ?= ../../args
CFLAGS := -g -std=c++14 -Wall -Wextra
LFLAGS := $(CFLAGS)

INCLUDES := -I$(LOGLIBDIR) -I$(ARGSLIBDIR) -I.
LIBRARIES := -lcpprest -lpthread -ldl -lprotobuf

CFLAGS += $(INCLUDES)
LFLAGS += $(INCLUDES) $(LIBRARIES)

CPPFILES := $(wildcard *.cpp)
PROTOFILES := $(wildcard *.proto)
OBJFILES := $(addprefix obj/,$(notdir $(CPPFILES:.cpp=.o))) $(addprefix obj/,$(notdir $(PROTOFILES:.proto=.obj)))

TARGET := Proxy # Executable name

$(TARGET): directory $(OBJFILES)
	$(CXX) $(LFLAGS) -o $@ $(OBJFILES)

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $^ -o $@

obj/%.obj: gen/%.pb.cc
	$(CXX) -c $(CFLAGS) $^ -o $@

gen/%.pb.cc: %.proto
	$(PROTOC) -I=. --cpp_out=gen/ $^

directory:
	mkdir -p obj
	mkdir -p gen

clean:
	rm -f $(TARGET)
	rm -rf obj
	rm -rf gen

