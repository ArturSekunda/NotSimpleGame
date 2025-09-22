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
        src/core/darkMath.cpp
        src/core/darkMath.h
        src/handlers/debugHandler.cpp
        src/handlers/debugHandler.h
        src/entities/baseEntity.cpp
        src/entities/baseEntity.h
        src/entities/player/player.cpp
        src/entities/player/player.h
        src/handlers/collisionHandler.cpp
        src/handlers/collisionHandler.h
        src/entities/enemies/basicEnemy.cpp
        src/entities/enemies/basicEnemy.h)

# Link SFML libraries
target_link_libraries(main PRIVATE sfml-graphics sfml-audio sfml-window sfml-system sfml-network)

include_directories(${CMAKE_SOURCE_DIR}/src)
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