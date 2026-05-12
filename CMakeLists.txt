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
        libs/CheckInput.cpp
        libs/CheckInput.h
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
        labs/laba-4/src/Controller/RouteController.cpp
        labs/laba-4/src/Controller/RouteController.h
)
add_executable(laba-5 labs/laba-5/laba-5.cpp
        labs/laba-5/Entities/Circle.cpp
        labs/laba-5/Entities/Circle.h
        labs/laba-5/Entities/Square.cpp
        labs/laba-5/Entities/Square.h
        labs/laba-5/Entities/Triangle.cpp
        labs/laba-5/Entities/Triangle.h
        labs/laba-5/Entities/Shape.cpp
        labs/laba-5/Entities/Shape.h
        labs/laba-5/Entities/Pyramid.cpp
        labs/laba-5/Entities/Pyramid.h
        labs/laba-5/Controller/FifthLabMenu.cpp
        labs/laba-5/Controller/FifthLabMenu.h
        labs/laba-5/Controller/ShapesController.cpp
        labs/laba-5/Controller/ShapesController.h
        libs/TerminalController.cpp
        libs/TerminalController.h
        libs/Menu.cpp
        libs/Menu.h
        libs/CheckInput.cpp
        libs/CheckInput.h
)
add_executable(laba-6 labs/laba-6/laba-6.cpp
        labs/laba-6/Entities/Process.cpp
        labs/laba-6/Entities/Process.h
        labs/laba-6/Entities/HumanActivity.cpp
        labs/laba-6/Entities/HumanActivity.h
        labs/laba-6/Entities/Game.cpp
        labs/laba-6/Entities/Game.h
        labs/laba-6/Entities/Esports.cpp
        labs/laba-6/Entities/Esports.h
        labs/laba-6/Entities/CompetitiveSport.cpp
        labs/laba-6/Entities/CompetitiveSport.h
        libs/TerminalController.h
        libs/TerminalController.cpp
        libs/CheckInput.h
        libs/CheckInput.cpp
        libs/Menu.h
        libs/Menu.cpp
        libs/Date.h
        libs/Date.cpp
        labs/laba-6/Controller/SixthLabMenu.cpp
        labs/laba-6/Controller/SixthLabMenu.h
        labs/laba-6/Controller/EntitiesManager.cpp
        labs/laba-6/Controller/EntitiesManager.h

)
