cmake_minimum_required(VERSION 3.16)
project(NotSimpleGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TGUI_BACKEND SFML_GRAPHICS)

# Fetch SFML
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.2
        GIT_SHALLOW ON
)

FetchContent_Declare(TGUI
        GIT_REPOSITORY https://github.com/texus/TGUI.git
        GIT_TAG v1.6.1
        GIT_SHALLOW ON
)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(SFML TGUI json)

# Create your executable
add_executable(main src/main.cpp
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
        src/entities/enemies/basicEnemy.h
        src/core/game.cpp
        src/core/game.h
        src/UI/menuHUD.cpp
        src/UI/menuHUD.h
        src/core/gameMenu.cpp
        src/core/gameMenu.h
        src/UI/mainGameHUD.cpp
        src/UI/mainGameHUD.h
        src/managers/UIManager.cpp
        src/managers/UIManager.h
        src/UI/debugWindow.cpp
        src/UI/debugWindow.h
        src/UI/DebugWidgets/panelInsideDebugWindow.cpp
        src/UI/DebugWidgets/panelInsideDebugWindow.h
        src/UI/DebugWidgets/optionWidgetsDebugWindow.cpp
        src/UI/DebugWidgets/optionWidgetsDebugWindow.h
        src/UI/DebugWidgets/playerInfoLabelsDebugWindow.cpp
        src/UI/DebugWidgets/playerInfoLabelsDebugWindow.h
        src/UI/DebugWidgets/collisionButtonDebugWindow.cpp
        src/UI/DebugWidgets/collisionButtonDebugWindow.h
        src/UI/DebugWidgets/playerChangeStatsDebugWindow.cpp
        src/UI/DebugWidgets/playerChangeStatsDebugWindow.h
        src/UI/DebugWidgets/playerChangeNormalStatsDebugWindow.cpp
        src/UI/DebugWidgets/playerChangeNormalStatsDebugWindow.h
        src/UI/MainGameHUDWidgets/panelsWithLayouts.cpp
        src/UI/MainGameHUDWidgets/panelsWithLayouts.h
        src/UI/MainGameHUDWidgets/playerProgressBars.cpp
        src/UI/MainGameHUDWidgets/playerProgressBars.h
        src/UI/MainGameHUDWidgets/playerNameAndLevel.cpp
        src/UI/MainGameHUDWidgets/playerNameAndLevel.h
        src/UI/MainGameHUDWidgets/playerStats.cpp
        src/UI/MainGameHUDWidgets/playerStats.h
        src/items/itemBase.cpp
        src/items/itemBase.h
        src/items/helpers/itemStructs.h
        src/items/helpers/itemEnums.h
        src/items/weapon.cpp
        src/items/weapon.h
        src/managers/itemManager.cpp
        src/managers/itemManager.h
        src/items/helpers/enumConversion.cpp
        src/items/helpers/enumConversion.h
        src/items/armor.cpp
        src/items/armor.h
        src/inventory/Inventory.cpp
        src/inventory/Inventory.h
        src/inventory/baseEquipment.cpp
        src/inventory/baseEquipment.h
        src/inventory/playerEquipment.cpp
        src/inventory/playerEquipment.h
        src/entities/helpers/entityEnums.h
        src/entities/helpers/entityStructs.h
        src/UI/MainGameHUDWidgets/playerEquipmentWidget.cpp
        src/UI/MainGameHUDWidgets/playerEquipmentWidget.h
        src/items/helpers/enumConversionTextures.cpp
        src/items/helpers/enumConversionTextures.h
        src/UI/MainGameHUDWidgets/playerInventoryWidget.cpp
        src/UI/MainGameHUDWidgets/playerInventoryWidget.h
        src/inventory/enemyEquipment.cpp
        src/inventory/enemyEquipment.h
        src/entities/projectile/projectileEntity.cpp
        src/entities/projectile/projectileEntity.h
        src/handlers/eventHandler.cpp
        src/handlers/eventHandler.h
)

# Link SFML libraries
target_link_libraries(main PRIVATE
        nlohmann_json::nlohmann_json
        tgui
        sfml-graphics
        sfml-audio
        sfml-window
        sfml-system
        sfml-network
)

include_directories(${CMAKE_SOURCE_DIR}/src)

# Copy DLLs to output directory (Windows)
if(WIN32)
    add_custom_command(TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-network>
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE:tgui>
            $<TARGET_FILE_DIR:main>)
endif()