project(citadel-gui)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_definitions(-Wall)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)

set(SRCS
    main.cpp
    window.cpp
)

QT5_ADD_RESOURCES(RSCS kant-loader.qrc)

add_executable(kant-loader ${SRCS} ${RSCS} ${MOCS})
target_link_libraries(kant-loader Qt5::Core Qt5::Gui Qt5::Svg Qt5::Network Qt5::WebEngine Qt5::WebEngineWidgets)
