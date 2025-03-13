cmake_minimum_required(VERSION 3.10)
project(MapNavigation)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)  # ✅ Enable Qt's MOC system

add_executable(MapNavigation main.cpp MapWidget.cpp)
target_link_libraries(MapNavigation Qt6::Widgets)
