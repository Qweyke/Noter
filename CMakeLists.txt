cmake_minimum_required(VERSION 4.1.2)

project(Noter
    VERSION 0.1
    LANGUAGES C CXX
)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Always export compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Qt (Widgets + Gui + Core)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Qt  autogen (MOC, UIC, RCC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Include fetch module
include(FetchContent)

# spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.3
)
FetchContent_MakeAvailable(spdlog)

# Include
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# Sources
file(GLOB_RECURSE CPP_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE CPP_HEADERS CONFIGURE_DEPENDS include/*.hpp)
file(GLOB_RECURSE QT_UI_FILES CONFIGURE_DEPENDS src/*.ui)

# Executable
add_executable(${PROJECT_NAME}
    ${CPP_SOURCES}
    ${CPP_HEADERS}
    ${QT_UI_FILES}
)

# Linking
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    spdlog::spdlog
)

# Output binaries to build/bin/
set_target_properties(Noter PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
