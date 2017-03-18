CFLAGS=-std=c++14 -g
CXX_FLAGS = $(CFLAGS)
CC=g++
LIBS = "C:\Program Files\mingw-w64\x86_64-6.2.0-win32-seh-rt_v5-rev1\mingw64\x86_64-w64-mingw32\lib\libgdi32.a"

BIN=maze

BUILD_DIR = ./build

CPP = main.cpp dfs.cpp gbfs.cpp common.cpp

OBJ = $(CPP:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

$(BIN) : $(OBJ)
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LIBS)

-include $(DEP)

$(BUILD_DIR)/%.o : %.cpp
	if not exist $(@D) mkdir $(@D)
	$(CXX) $(CXX_FLAGS) -MMD -c $< -o $@

.PHONY : clean
clean :
	-rm $(BIN) $(OBJ) $(DEP)

