project(youtube-viewer)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_definitions(-Wall)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Network WebEngine WebEngineWidgets)

set(SRCS
    main.cpp
    window.cpp
)

# Static builds on Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(Qt5_USE_STATIC_LIBS ON)
	set(Qt5_USE_STATIC_RUNTIME ON)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif ()

add_executable(youtube-viewer ${SRCS} ${MOCS})
target_link_libraries(youtube-viewer Qt5::Core Qt5::Gui Qt5::Network Qt5::WebEngine Qt5::WebEngineWidgets)
