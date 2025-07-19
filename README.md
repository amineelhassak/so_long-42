# 🎯 So_Long - 2D Pathfinding Game

[![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Complete-brightgreen.svg)]()
[![Build](https://img.shields.io/badge/Build-Passing-success.svg)]()
[![Version](https://img.shields.io/badge/Version-1.0.0-blue.svg)]()

<div align="center">

# 🎯 So_Long Game

> A 2D pathfinding game with graphical interface using MLX library.

**Navigate through mazes, collect items, and reach the exit in this engaging 2D adventure!**

[![GitHub stars](https://img.shields.io/github/stars/yourusername/so_long-42?style=social)](https://github.com/yourusername/so_long-42/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/so_long-42?style=social)](https://github.com/yourusername/so_long-42/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/so_long-42)](https://github.com/yourusername/so_long-42/issues)

</div>

---

## 📚 Table of Contents

- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [🛠️ Installation](#️-installation)
- [🎮 Usage](#-usage)
- [🗺️ Map Format](#️-map-format)
- [📁 Project Structure](#-project-structure)
- [🛠️ Technologies Used](#️-technologies-used)
- [🎨 Screenshots](#-screenshots)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)

## 🎯 Overview

So_Long is a **2D pathfinding game** that challenges players to navigate through mazes, collect items, and reach the exit. Built with the MLX graphics library, it features smooth animations, enemy movement patterns, and an intuitive graphical interface.

### 🎓 What You'll Experience

- **2D maze navigation** with smooth movement controls
- **Item collection** mechanics with visual feedback
- **Enemy AI** with movement patterns
- **Pathfinding validation** to ensure solvable maps
- **Graphical rendering** with sprites and animations
- **Map parsing** and validation system

## ✨ Features

### 🎮 Core Gameplay
- 🎯 **2D maze navigation** with WASD controls
- 🎁 **Item collection** system with counter display
- 🚪 **Exit mechanism** requiring all items
- 🎨 **Graphical interface** with MLX library
- 🎵 **Smooth animations** and visual effects

### 🗺️ Map System
- 📝 **Map parsing** from `.ber` files
- ✅ **Validation system** for map integrity
- 🔍 **Pathfinding algorithm** to ensure solvability
- 🎨 **Visual map representation** with sprites

### 👾 Enemy System
- 🤖 **Enemy AI** with movement patterns
- ⚡ **Collision detection** with enemies
- 🎭 **Animated sprites** for enemies
- 🎯 **Game over** on enemy contact

### 🎨 Graphics & UI
- 🖼️ **Sprite rendering** for all game elements
- 🎨 **Color-coded elements** for easy identification
- 📊 **Move counter** display
- 🎵 **Visual feedback** for actions

## 🛠️ Installation

### Prerequisites

- **macOS** (tested on macOS 22.1.0)
- **GCC compiler** (latest version recommended)
- **Make** (GNU Make 4.0+)
- **MLX library** (for graphics)

### 🏗️ Building the Project

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/so_long-42.git
   cd so_long-42
   ```

2. **Build the project**
   ```bash
   make
   ```

3. **Build with bonus features**
   ```bash
   make bonus
   ```

### 🔧 Available Make Commands

| Command | Description |
|---------|-------------|
| `make` | Builds the main version |
| `make bonus` | Builds with bonus features |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and executables |
| `make re` | Rebuilds the project from scratch |

## 🎮 Usage

### 🚀 Running the Game

1. **Basic version:**
   ```bash
   ./so_long maps/map1.ber
   ```

2. **Bonus version:**
   ```bash
   ./so_long_bonus maps/map1.ber
   ```

### 📁 Example Maps

The project includes example map files:
- `maps/map0.ber` - Simple tutorial map
- `maps/map1.ber` - Basic gameplay map
- `maps/map2.ber` - Advanced challenge map

### 🧪 Testing Different Maps

```bash
# Test with different maps
./so_long maps/map0.ber
./so_long maps/map1.ber
./so_long maps/map2.ber

# Test with custom map
./so_long path/to/your/map.ber
```

## 🗺️ Map Format

The game uses `.ber` files to define maps. Here's the complete format:

### 📝 Map File Structure

```
1111111111111111111111
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1000000000000000000001
1111111111111111111111
```

### 🧱 Map Elements

| Symbol | Description |
|--------|-------------|
| `1` | Wall (impassable) |
| `0` | Empty space (walkable) |
| `P` | Player spawn position |
| `C` | Collectible item |
| `E` | Exit |
| `N` | Enemy (bonus version) |

### ✅ Map Validation Rules

- **Must be rectangular** with consistent width
- **Must be surrounded by walls** (no gaps)
- **Must have exactly one player spawn point** (`P`)
- **Must have at least one collectible** (`C`)
- **Must have exactly one exit** (`E`)
- **Must be properly closed** (no open areas)
- **Must be solvable** (pathfinding validation)

## 📁 Project Structure

```
so_long-42/
├── 📁 srcs/
│   ├── 📄 main.c              # Main program
│   ├── 📁 allocation/
│   │   ├── 📄 allocation.c    # Memory allocation
│   │   └── 📄 init.c          # Initialization
│   ├── 📁 free/
│   │   ├── 📄 free.c          # Memory cleanup
│   │   └── 📄 exit.c          # Exit handling
│   ├── 📁 parsing/
│   │   ├── 📄 parsing.c       # Map parsing
│   │   ├── 📄 validation.c    # Map validation
│   │   └── 📄 pathfinding.c   # Pathfinding algorithm
│   ├── 📁 algo_mlx/
│   │   ├── 📄 draw_window.c   # Window rendering
│   │   ├── 📄 enemy.c         # Enemy AI
│   │   ├── 📄 hook_mlx.c      # Input handling
│   │   ├── 📄 movement.c      # Player movement
│   │   └── 📄 rendering.c     # Graphics rendering
│   ├── 📁 mylib/
│   │   ├── 📄 ft_itoa.c       # Integer to string
│   │   ├── 📄 ft_strlen.c     # String length
│   │   └── 📄 ft_putstr.c     # String output
│   └── 📁 get_next_line/
│       └── 📄 get_next_line.c # File reading
├── 📁 includes/
│   ├── 📄 headers.h           # Main header
│   ├── 📄 get_next_line.h     # GNL header
│   └── 📄 structs.h           # Data structures
├── 📁 maps/
│   ├── 📄 map0.ber            # Tutorial map
│   ├── 📄 map1.ber            # Basic map
│   └── 📄 map2.ber            # Advanced map
├── 📁 imgs/
│   ├── 📄 player.xpm          # Player sprite
│   ├── 📄 wall.xpm            # Wall sprite
│   ├── 📄 collect.xpm         # Collectible sprite
│   ├── 📄 exit.xpm            # Exit sprite
│   ├── 📄 enemy.xpm           # Enemy sprite
│   └── 📄 background.xpm      # Background sprite
├── 📄 Makefile                # Build configuration
└── 📄 README.md               # This file
```

## 🛠️ Technologies Used

### Programming Languages
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

### Graphics & Libraries
![MLX](https://img.shields.io/badge/MLX-000000?style=for-the-badge&logo=opengl&logoColor=white)
![OpenGL](https://img.shields.io/badge/OpenGL-5586A4?style=for-the-badge&logo=opengl&logoColor=white)

### Build Tools
![Make](https://img.shields.io/badge/Make-000000?style=for-the-badge&logo=gnu&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-000000?style=for-the-badge&logo=gnu&logoColor=white)

### Development Tools
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)
![VS Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)

### Algorithms
![Pathfinding](https://img.shields.io/badge/Pathfinding-000000?style=for-the-badge&logo=algorithm&logoColor=white)
![Graph Theory](https://img.shields.io/badge/Graph_Theory-000000?style=for-the-badge&logo=graph&logoColor=white)

## 🎨 Screenshots

*[Add screenshots of your game here]*

### 🎮 Gameplay Screenshots
- **Main Menu**: Game start screen
- **Gameplay**: Player navigating the maze
- **Item Collection**: Collecting items with counter
- **Victory Screen**: Reaching the exit
- **Game Over**: Enemy collision

## 🤝 Contributing

This is a 42 School project, but if you have suggestions or find bugs, feel free to contribute:

### How to Contribute

1. **Fork the repository**
   ```bash
   git clone https://github.com/yourusername/so_long-42.git
   ```

2. **Create a feature branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

3. **Make your changes**
   - Follow the existing code style
   - Add comments for complex logic
   - Test thoroughly with different maps

4. **Commit your changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```

5. **Push to the branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

6. **Open a Pull Request**

### Contribution Guidelines

- Follow the existing code style and conventions
- Add tests for new features
- Update documentation as needed
- Ensure the game compiles without warnings
- Test on different map configurations

## 📄 License

This project is part of the 42 School curriculum. The code is written for educational purposes.

---

<div align="center">

**Made with ❤️ and lots of ☕**

*Navigate through mazes, collect items, and reach the exit in this engaging 2D adventure!*

[![GitHub stars](https://img.shields.io/github/stars/yourusername/so_long-42?style=social)](https://github.com/yourusername/so_long-42/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/so_long-42?style=social)](https://github.com/yourusername/so_long-42/network)
[![GitHub issues](https://img.shields.io/github/issues/yourusername/so_long-42)](https://github.com/yourusername/so_long-42/issues)

**Author**: [Your Name]  
**School**: 42 School  
**Project**: So_Long  
**Last updated**: December 2024

</div> 