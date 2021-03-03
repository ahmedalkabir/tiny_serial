CXX = g++
TARGET = tiny_serial_output
BUILD_DIR ?= build
# CPPFLAGS += 

vpath %.cpp src


OBJS += tiny_serial_linux.o \
		tiny_serial_win.o \
		tiny_serial.o \
		main.o \
	

%.o: %.cpp
	$(CXX) -c -I./include $^ -o $(BUILD_DIR)/$@
	
build: $(OBJS)
	$(CXX) -I./include  $(addprefix $(BUILD_DIR)/, $^) -o $(BUILD_DIR)/$(TARGET)


clean:
	rm -f $(BUILD_DIR)/*.o