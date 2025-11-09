````markdown
# st_game_engine

A small C++/CMake playground for building a simple game-style app on top of **raylib**.

Current features:

- window settings loaded from `config.ini`
- embedded Roboto font loaded from memory (`resources/fonts/roboto_font.h`)
- simple MVC-ish project layout (`core/`, `controllers/`, `views/`, `resources/`)
- main menu (Play Game, Options, Exit) controlled with arrow keys
- options screen with fullscreen toggle and “back”
- game screen with a basic 3D scene and FPS-like camera (WASD + mouse)
- in-game debug overlay toggled with `~` for quick on-screen logs
- ESC does **not** close the app (we handle it ourselves)

Tested on Ubuntu 24 with KDevelop.

## Project structure

```text
st_game_engine/
├── CMakeLists.txt
├── config.ini
├── main.cpp
├── resources/
│   └── fonts/
│       └── roboto_font.h
└── src/
    ├── core/
    │   ├── App.h / App.cpp
    │   ├── Config.h / Config.cpp
    │   ├── ResourceManager.h / ResourceManager.cpp
    │   └── DebugOverlay.h / DebugOverlay.cpp
    ├── controllers/
    │   ├── BaseController.h
    │   ├── MenuController.h / .cpp
    │   ├── OptionsController.h / .cpp
    │   └── GameController.h / .cpp
    └── views/
        ├── MenuView.h / .cpp
        ├── OptionsView.h / .cpp
        └── GameView.h / .cpp
````

## Build

Requirements:

* CMake
* C++17 compiler
* raylib (installed as a system library)

Example on Ubuntu:

```bash
sudo apt install cmake g++ libraylib-dev
```

Build:

```bash
mkdir -p build
cd build
cmake ..
make
./st_game_engine
```

## Config

`config.ini` (in repo root):

```ini
window_width=1280
window_height=720
window_title=st_game_engine
```

If the file is missing, defaults are used.

## Controls

**Menu:**

* ↑ / ↓ – navigate
* Enter – select

**Options:**

* ↑ / ↓ – select entry
* ← / → – change value (fullscreen)
* Enter on “Back” – return to menu

**Game:**

* Mouse – look
* W A S D – move
* Space / Left Ctrl – up / down
* Shift – faster
* ESC – back to menu

**Debug:**

* `~` (grave) – show/hide debug overlay

## License

MIT
````
