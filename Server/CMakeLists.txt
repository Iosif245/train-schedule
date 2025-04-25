cmake_minimum_required(VERSION 3.22)
project(Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Server
        tinyxml2/tinyxml2.h
        tinyxml2/tinyxml2.cpp
        XmlClass/Xml.h
        XmlClass/Xml.cpp
        main.cpp
        ToolkitClass/Toolkit.h
        ToolkitClass/Toolkit.cpp
        Types/Station/Station.h
        Types/Train/Train.h
        TimeClass/Time.h
        TimeClass/Time.cpp
        CommandClass/Command.h
        CommandClass/LoginCommandClass/Login.h
        Types/Command_Input/Command_input.h
        CommandClass/LoginCommandClass/Login.cpp
        CommandClass/LogoutCommandClass/Logout.h
        CommandClass/LogoutCommandClass/Logout.cpp
        CommandClass/GetTrainsInfoCommandClass/GetTrainsInfo.h
        CommandClass/GetTrainsInfoCommandClass/GetTrainsInfo.cpp
        CommandClass/AddArrivalDelayCommandClass/AddArrivalDelay.h
        CommandClass/AddArrivalDelayCommandClass/AddArrivalDelay.cpp
        CommandClass/GetArrivalInfoCommandClass/GetArrivalInfo.cpp
        CommandClass/GetDepartureInfoCommandClass/GetDepartureInfo.h
        CommandClass/GetDepartureInfoCommandClass/GetDepartureInfo.cpp
        CommandClass/AddDepartureDelayCommandClass/AddDepartureDelay.h
        CommandClass/AddDepartureDelayCommandClass/AddDepartureDelay.cpp
        CommandClass/CallCommandClass/CallCommand.h
        CommandClass/CallCommandClass/CallCommand.cpp
        Types/CommandQueue/CommandQueue.h
        Types/CommandQueue/CommandQueue.cpp
        Types/ThreadStruct/ThreadStruct.h
        SocketClass/Socket.h
        SocketClass/Socket.cpp
)
