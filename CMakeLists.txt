cmake_minimum_required(VERSION 3.16)

project(chessify)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Sources availableactionsfinder.cpp  boardwidget.cpp  core.cpp  Definitions.cpp  main.cpp  mainwindow.cpp  player.cpp)
set(Headers availableactionsfinder.h  boardwidget.h  core.h  Definitions.h  mainwindow.h  player.h)



add_executable( chessify ${Sources} ${Headers} )

target_link_libraries(chessify Qt5::Core Qt5::Widgets)
