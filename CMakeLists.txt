cmake_minimum_required(VERSION 3.16)
project(NotSimpleGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
        GIT_SHALLOW ON
)
FetchContent_MakeAvailable(SFML)

# Create your executable
add_executable(main src/main.cpp
        src/managers/assetsManager.cpp
        src/managers/assetsManager.h
        src/managers/inputManager.cpp
        src/managers/inputManager.h
        src/math/darkMath.cpp
        src/math/darkMath.h
        src/entity/player.cpp
        src/entity/player.h)

# Link SFML libraries
target_link_libraries(main PRIVATE sfml-graphics sfml-audio sfml-window sfml-system sfml-network)

# Copy SFML DLLs to output directory (Windows)
if(WIN32)
    add_custom_command(TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-network>
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE_DIR:main>)
endif()