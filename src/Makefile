CXX := g++
LOGLIBDIR ?=../../loguru
ARGSLIBDIR ?= ../../args
CFLAGS := -g -std=c++11 -Wall
LFLAGS := $(CFLAGS)

INCLUDES := -I$(LOGLIBDIR) -I$(ARGSLIBDIR) -I.
LIBRARIES := -lcpprest

CFLAGS += $(INCLUDES)
LFLAGS += $(INCLUDES) $(LIBRARIES)

CPPFILES := $(wildcard *.cpp)
OBJFILES := $(addprefix obj/,$(notdir $(CPPFILES:.cpp=.o)))

TARGET := Proxy # Executable name

$(TARGET): directory $(OBJFILES)
	$(CXX) $(LFLAGS) -o $@ $(OBJFILES)

obj/%.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,obj/\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

obj/%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

directory:
	mkdir -p obj

clean:
	rm -f $(TARGET)
	rm -rf obj

-include $(OBJFILES:.o=.d)
