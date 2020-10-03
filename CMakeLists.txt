cmake_minimum_required(VERSION 3.10)

project(Battleship)

set(ScriptPath src/)

add_executable(Battleship ${ScriptPath}main.cpp ${ScriptPath}BotMap.cpp ${ScriptPath}Ai.cpp)

add_library(Ai ${ScriptPath}Ai.h ${ScriptPath}Ai.cpp)
add_library(Map ${ScriptPath}Map.h ${ScriptPath}Map.cpp)
add_library(BotMap ${ScriptPath}BotMap.h ${ScriptPath}BotMap.cpp)
add_library(PlayerMap ${ScriptPath}PlayerMap.h ${ScriptPath}PlayerMap.cpp)
add_library(GameManager ${ScriptPath}GameManager.h ${ScriptPath}GameManager.cpp)
add_library(Ship ${ScriptPath}Ship.h ${ScriptPath}Ship.cpp)
add_library(systemClear ${ScriptPath}systemClear.h ${ScriptPath}systemClear.cpp)

target_link_libraries(Battleship PUBLIC Ai)
target_link_libraries(Battleship PUBLIC Map)
target_link_libraries(Battleship PUBLIC BotMap)
target_link_libraries(Battleship PUBLIC GameManager)
target_link_libraries(Battleship PUBLIC PlayerMap)
target_link_libraries(Battleship PUBLIC Ship)
target_link_libraries(Battleship PUBLIC systemClear)
