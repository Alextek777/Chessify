cmake_minimum_required(VERSION 3.16)

project(chessify)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(Sources src/availableactionsfinder.cpp  src/boardwidget.cpp  src/core.cpp  src/Definitions.cpp  src/main.cpp  src/mainwindow.cpp  src/player.cpp)
set(Headers src/availableactionsfinder.h  src/boardwidget.h  src/core.h  src/Definitions.h  src/mainwindow.h  src/player.h)


add_executable( chessify ${Sources} ${Headers} )

target_link_libraries(chessify Qt5::Core Qt5::Widgets)
