# Makefile

# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -Wall -std=c++11 

# 目标可执行文件名
TARGET = test

# 源文件
SOURCES = test.cpp player.cpp game.cpp

# 对象文件
OBJECTS = $(SOURCES:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# 编译
%.o: %.cpp card.h player.h game.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(TARGET) $(OBJECTS)