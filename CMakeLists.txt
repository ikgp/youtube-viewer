project(citadel-gui)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_definitions(-Wall)

find_package(Qt5 REQUIRED COMPONENTS Core Gui WebEngine WebEngineWidgets)

set(SRCS
    main.cpp
    window.cpp
)

QT_ADD_RESOURCES(RSCS kant-loader.qrc)

# Static builds on Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(Qt5_USE_STATIC_LIBS ON)
	set(Qt5_USE_STATIC_RUNTIME ON)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif ()

add_executable(kant-loader ${SRCS} ${RSCS} ${MOCS})
target_link_libraries(kant-loader Qt5::Core Qt5::Gui Qt5::WebEngine Qt5::WebEngineWidgets)
qt_generate_deploy_app_script(
    TARGET kant-loader
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
add_custom_command(TARGET kant-loader POST_BUILD COMMAND ${deploy_script})
