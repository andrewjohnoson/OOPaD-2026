cmake_minimum_required(VERSION 4.0)
project(laba-1)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba-1 src/laba-1.cpp
    ../../libs/Menu.cpp
    ../../libs/Menu.h
    ../../libs/CheckInput.cpp
    ../../libs/CheckInput.h
    ../../libs/TerminalController.cpp
    ../../libs/TerminalController.h
    src/Entities/LinkedListInt.cpp
    src/Entities/LinkedListInt.h
    src/Entities/LinkedListString.cpp
    src/Entities/LinkedListString.h
    src/Controller/FirstLabMenu.cpp
    src/Controller/FirstLabMenu.h
    src/Controller/ListMenu.cpp
    src/Controller/ListMenu.h
    src/Controller/ListIntController.cpp
    src/Controller/ListIntController.h
)