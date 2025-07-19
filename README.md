# so_long-42

A simple 2D graphical game developed in C using the MiniLibX (MLX) library, as part of the 42 school curriculum. The objective is to collect all collectibles and reach the exit while avoiding enemies.

## Features
- 2D tile-based map rendering using MLX
- Player movement with keyboard controls
- Collectibles and exit logic
- Moving enemy with basic AI
- Multiple sample maps
- Custom XPM graphics for all game elements

## Requirements
- macOS (uses OpenGL and AppKit frameworks)
- [MiniLibX (MLX)](https://harm-smits.github.io/42docs/libs/minilibx)
- GCC or Clang

## Build Instructions
1. Clone the repository:
   ```sh
git clone <your-repo-url>
cd so_long-42
```
2. Build the project:
   ```sh
make
```

## Run Instructions
Run the game with a map file (in `.ber` format):
```sh
./so_long maps/map0.ber
```

## Controls
- **W / Up Arrow**: Move up
- **A / Left Arrow**: Move left
- **S / Down Arrow**: Move down
- **D / Right Arrow**: Move right
- **ESC**: Exit the game

## Game Rules
- The player (`P`) must collect all collectibles (`C`) to open the exit (`E`).
- The map is surrounded by walls (`1`).
- The player must avoid the enemy, which moves automatically.
- The game ends if the player reaches the exit after collecting all collectibles, or if caught by the enemy.

## Map Format
- Maps are plain text files with the `.ber` extension.
- Allowed characters:
  - `1`: Wall
  - `0`: Floor
  - `P`: Player start position (only one)
  - `C`: Collectible
  - `E`: Exit
  - Enemy is placed automatically in open space

### Example Map
```
1111111
1P0C0E1
1111111
```

## Assets
All game graphics are in the `imgs/` directory as XPM files:
- `p_r.xpm`: Player
- `c.xpm`: Collectible
- `close_door.xpm`: Closed exit
- `open_door.xpm`: Open exit
- `enemyf1.xpm` to `enemyf4.xpm`: Enemy animation frames
- `floor.xpm`: Floor
- `wall1.xpm`: Wall

## Sample Maps
Several sample maps are provided in the `maps/` directory:
- `map0.ber`, `map1.ber`, `map2.ber`, ...

## Author
- amel-has@student.42.fr

---

*This project is part of the 42 school curriculum.* 