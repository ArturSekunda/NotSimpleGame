# NotSimpleGame 🎮

A 2D RPG game built from scratch in C++ as a learning project focused on game architecture and systems design.

## 🚀 About

NotSimpleGame is a from-scratch 2D RPG where I'm learning advanced C++ concepts, game architecture patterns, and project structure management. The project emphasizes clean code organization and scalable system design.

## ⚙️ Tech Stack

- **Language:** C++
- **Graphics:** SFML
- **GUI:** TGUI
- **Game language and translation:** JSON
- **Database:** SQLite (In the future)
- **Build System:** CMake
- **IDE:** JetBrains CLion

## 📁 Project Structure

```
NotSimpleGame/
├── src/
│   ├── core/          # Core game engine components
│   ├── entities/      # Game entities (Player, NPCs, etc.)
│   ├── inventory/     # Inventory system
│   ├── items/         # Item system
│   ├── handlers/      # Event and input handlers
│   ├── managers/      # Game state and resource managers
│   ├── UI/            # User interface components
│   └── main.cpp       # Entry point
└── CMakeLists.txt     # Build configuration
```

## 🎯 Current Status

**Phase:** Early Development
- ✅ Project architecture setup
- ✅ Basic systems framework
- ✅ Simple Debugging tools implementation
- ✅ Refactoring Main Game HUD
- 🔄 Inventory System & Item System Generation
- 📋 Next: Core mechanics (combat, AI behavior)

## 🛠️ Planned Features

- **Inventory System** - Item management and storage
- **Weapon System** - Combat mechanics and weapon handling
- **Entity System** - Player, NPCs, and enemy entities
- **UI System** - Menus, HUD, and interactive elements
- **Handler Systems** - Input and event management
- **Manager Systems** - Game state, resource, and scene management
- **Language System** - Localization and translation
- **Database System** - Save and load game data

## 📊 Code Analysis

Using **CodeScene** for code quality analysis and project insights.

[![CodeScene Average Code Health](https://codescene.io/projects/72111/status-badges/average-code-health)](https://codescene.io/projects/72111)
[![CodeScene Hotspot Code Health](https://codescene.io/projects/72111/status-badges/hotspot-code-health)](https://codescene.io/projects/72111)
[![CodeScene System Mastery](https://codescene.io/projects/72111/status-badges/system-mastery)](https://codescene.io/projects/72111)

## 📜 License

[![License: CC BY-NC-SA 4.0](https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg)](https://creativecommons.org/licenses/by-nc-sa/4.0/)

**Creative Commons Attribution-NonCommercial-ShareAlike 4.0**

### 🎮 What you can do:
- ✅ Play, modify, and create mods
- ✅ Share with others
- ✅ Accept donations (for mods/content)

### ❌ What you cannot do:
- ❌ Sell the game or mods
- ❌ Use commercially

📖 [Full License](LICENSE) | 🔗 [Easy Summary](https://creativecommons.org/licenses/by-nc-sa/4.0/)

### Third-party libraries:
- **SFML** - [zlib/png license](https://www.sfml-dev.org/license.php)
- **TGUI** - [zlib license](https://tgui.eu/license/)
- **nlohmann/json** - JSON for Modern C++ - [MIT license](https://github.com/nlohmann/json)
- **SQLite** - SQL database engine - [Public Domain](https://www.sqlite.org/copyright.html)