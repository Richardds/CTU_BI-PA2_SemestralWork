cmake_minimum_required(VERSION 3.13)
project(SemestralWork)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_LIBRARY_PATH "C:/MinGW/lib/libSDL2.dll.a")
set(SDL2_INCLUDE_PATH "C:/MinGW/include/SDL2")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_INCLUDE_PATH})

add_executable(${PROJECT_NAME} src/main.cpp src/SemestralWork.cpp src/SemestralWork.h src/Core/Window.cpp src/Core/Window.h src/Core/Renderer.cpp src/Core/Renderer.h src/Graphics/Renderable.cpp src/Graphics/Renderable.h src/Graphics/Rectangle.cpp src/Graphics/Rectangle.h src/Game/GameLogic.cpp src/Game/GameLogic.h src/Core/core.h src/Graphics/Moveable.cpp src/Graphics/Moveable.h src/System/Logger.cpp src/System/Logger.h src/System/Trace.cpp src/System/Trace.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_LIBRARY_PATH})