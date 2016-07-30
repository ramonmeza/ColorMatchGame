# C++ compiler
CXX = g++
# C++ compiler flags
CXXFLAGS = -std=c++11 -c -Werror -g
# Linker flags (like -L)
LDFLAGS =
# Libraries to link (usually starts with -l)
LDLIBS = -lwiringPi -lpthread
# Remove command
RM = rm -f

# Dependencies
DEPS = Button.hpp LED.hpp Sensor.hpp
OBJS = Button.o LED.o Sensor.o 

# Target to build
TARGET = ColorMatchGame

all: $(TARGET)

# Just compile, don't link
# g++ -c file.cpp -o output_file.o
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -o $@

# Just link
# g++ -o output_file file.o OBJS_NEEDED.o -llibs
#%: %.o $(OBJS)
#	$(CXX) -o $@ $^ $(LDFLAGS) $(LDLIBS)
$(TARGET): $(TARGET).o $(OBJS)
	$(CXX) -o $@ $^ $(LDLIBS) $(LDFLAGS)
	
# make clean
clean: 
	$(RM) *~ $(OBJS) *.o $(TARGET) 