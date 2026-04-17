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
add_executable(laba-2 labs/laba-2/src/laba-2.cpp
        labs/laba-2/src/Controller/SecondLabMenu.cpp
        labs/laba-2/src/Controller/SecondLabMenu.h
        labs/laba-2/src/Entities/Array.cpp
        labs/laba-2/src/Entities/Array.h
        labs/laba-2/src/Controller/Manipulator.cpp
        labs/laba-2/src/Controller/Manipulator.h
        libs/CheckInput.cpp
        libs/CheckInput.h
        libs/TerminalController.cpp
        libs/TerminalController.h
        libs/Menu.cpp
        libs/Menu.h
)
add_executable(laba-3 labs/laba-3/src/laba-3.cpp
        labs/laba-3/src/Controller/ThirdLabMenu.cpp
        labs/laba-3/src/Controller/ThirdLabMenu.h
        labs/laba-3/src/Entity/Distance.cpp
        labs/laba-3/src/Entity/Distance.h
        labs/laba-3/src/Controller/CheckInputThirdLab.cpp
        labs/laba-3/src/Controller/CheckInputThirdLab.h
        libs/TerminalController.cpp
        libs/TerminalController.h
        libs/Menu.cpp
        libs/Menu.h
)
add_executable(laba-4 labs/laba-4/src/laba-4.cpp
        labs/laba-4/src/Controller/FourthLabMenu.cpp
        labs/laba-4/src/Controller/FourthLabMenu.h
        libs/TerminalController.cpp
        libs/TerminalController.h
        libs/Menu.cpp
        libs/Menu.h
        labs/laba-4/src/Entity/LocalDateTime.cpp
        labs/laba-4/src/Entity/LocalDateTime.h
        labs/laba-4/src/Entity/LocalDate.cpp
        labs/laba-4/src/Entity/LocalDate.h
        labs/laba-4/src/Entity/LocalTime.cpp
        labs/laba-4/src/Entity/LocalTime.h
        labs/laba-4/src/Entity/DateTimeBase.cpp
        labs/laba-4/src/Entity/DateTimeBase.h
        labs/laba-4/src/Entity/Route.cpp
        labs/laba-4/src/Entity/Route.h
)
