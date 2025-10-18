cmake_minimum_required(VERSION 3.21)

project(Noter
    VERSION 0.1
    LANGUAGES C CXX
)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Qt ---
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Qt Autogen
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# # --- Dependencies ---
# include(FetchContent)
# FetchContent_Declare(
#     spdlog
#     GIT_REPOSITORY https://github.com/gabime/spdlog.git
#     GIT_TAG v1.15.3
# )
# FetchContent_MakeAvailable(spdlog)

# --- Headers ---
file(GLOB_RECURSE CPP_HEADERS CONFIGURE_DEPENDS include/*.hpp)

# --- Sources ---
file(GLOB_RECURSE CPP_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE QT_UI_FILES CONFIGURE_DEPENDS src/*.ui)

# --- Executable ---
add_executable(${PROJECT_NAME}
    ${CPP_SOURCES}
    ${CPP_HEADERS}
    ${QT_UI_FILES}
)

# --- Include dirs ---
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# --- Link libraries ---
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    # spdlog::spdlog
)

# # --- Output binaries ---
# set_target_properties(${PROJECT_NAME} PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
# )
