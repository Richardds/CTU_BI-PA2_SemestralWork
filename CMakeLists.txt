cmake_minimum_required(VERSION 3.13)
project(SemestralWork)

set(CMAKE_CXX_STANDARD 11)

set(SDL2_LIBRARY_PATH "C:/MinGW/lib/libSDL2.dll.a")
set(SDL2_INCLUDE_PATH "C:/MinGW/include/SDL2")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_INCLUDE_PATH})

add_executable(SemestralWork src/main.cpp src/SemestralWork.cpp src/SemestralWork.h src/Core/Window.cpp src/Core/Window.h src/Core/Renderer.cpp src/Core/Renderer.h src/System/Logger.cpp src/System/Logger.h src/System/Trace.cpp src/System/Trace.h src/System/BinaryReader.cpp src/System/BinaryReader.h src/System/BinaryWriter.cpp src/System/BinaryWriter.h src/Game/WorldStats.cpp src/Game/WorldStats.h src/Graphics/Entity.cpp src/Graphics/Entity.h src/Graphics/Rectangle.cpp src/Graphics/Rectangle.h src/Game/Objects/Building.cpp src/Game/Objects/Building.h src/Game/GameLogic.cpp src/Game/GameLogic.h src/Core/core.h src/Graphics/HasPosition.cpp src/Graphics/HasPosition.h src/Game/Objects/BuildingConfig.cpp src/Game/Objects/BuildingConfig.h src/Tools/BuildingConfigGenerator.cpp src/Tools/BuildingConfigGenerator.h src/Graphics/Text.cpp src/Graphics/Text.h)

target_link_libraries(SemestralWork ${SDL2_LIBRARY} ${SDL2_LIBRARY_PATH})
