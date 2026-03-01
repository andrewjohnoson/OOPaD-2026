cmake_minimum_required(VERSION 4.1)
project(OOPaD_2026)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOPaD_2026 src/main.cpp
        libs/Menu.cpp
        libs/Menu.h
        src/Controller/LabsMenu.cpp
        src/Controller/LabsMenu.h
        libs/CheckInput.cpp
        libs/CheckInput.h
        libs/TerminalController.cpp
        libs/TerminalController.h
)

add_executable(laba-1 labs/laba-1/src/laba-1.cpp
        libs/Menu.cpp
        libs/Menu.h
        libs/CheckInput.cpp
        libs/CheckInput.h
        libs/TerminalController.cpp
        libs/TerminalController.h
        labs/laba-1/src/Entities/LinkedListInt.cpp
        labs/laba-1/src/Entities/LinkedListInt.h
        labs/laba-1/src/Entities/LinkedListString.cpp
        labs/laba-1/src/Entities/LinkedListString.h
        labs/laba-1/src/Controller/FirstLabMenu.cpp
        labs/laba-1/src/Controller/FirstLabMenu.h
        labs/laba-1/src/Controller/ListMenu.cpp
        labs/laba-1/src/Controller/ListMenu.h
        labs/laba-1/src/Controller/ListIntController.cpp
        labs/laba-1/src/Controller/ListIntController.h
        labs/laba-1/src/Controller/ListStringController.cpp
        labs/laba-1/src/Controller/ListStringController.h
)