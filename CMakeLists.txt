cmake_minimum_required(VERSION 3.10)
project(st_game_engine CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(st_game_engine
    main.cpp
    src/core/App.cpp
    src/core/Config.cpp
    src/core/ResourceManager.cpp
    src/core/DebugOverlay.cpp
    src/controllers/MenuController.cpp
    src/controllers/OptionsController.cpp      # ← nowy
    src/controllers/GameController.cpp
    src/views/MenuView.cpp
    src/views/OptionsView.cpp                  # ← nowy
    src/views/GameView.cpp
)

# ← to jest kluczowe: przypięte do st_game_engine
target_include_directories(st_game_engine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
)

target_link_libraries(st_game_engine raylib m dl pthread GL X11)
