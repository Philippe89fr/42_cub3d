## Cub3D - 42

# Description:
So Long is a 2D game project that introduces fundamental game programming concepts using the MiniLibX graphics library. The player controls a character that must collect all items on a map and reach the exit using the shortest path possible. This project focuses on working with textures, sprites, window management, and event handling. The game features a top-down view with tile-based movement, where players navigate through maps defined by .ber files containing walls, collectibles, empty spaces, player starting position, and exit points. 

<img src="./image.png" alt="Screenshot du jeu" width="500">

# Context:
Part of 42 Common Core.

## Map Example
```bash
1111111111111
1000001000001
10P0000000001
1000000100001
1000000000001
10000001M0C01
1000000000001
1000000000001
1000000000001
1000M00000001
100C00000E001
1000000000001
1111111111111
```
  - `1` represents a wall.
  - `0` represents an empty space.
  - `P` represents the character.
  - `C` represents a collectible
  - `M` represents a monster.


# Main Technologies / Skills Used:

- **Programming Languages:** C
- **Graphics Programming:** Working with the MiniLibX library for window and image creation  
- **2D Game Management:** Managing player position and map grid navigation
- **Event Handling:** Managing keyboard inputs and window events
- **Texture Management:** Loading, displaying, and manipulating sprites and textures
- **Map Parsing:** Reading and validating .ber map files with specific formatting requirements
- **Memory Management:** Proper allocation and cleanup of graphics resources
- **File I/O Operations:** Reading map files and handling file errors
- **Error Handling:** Comprehensive validation of map structure and game states
- **Makefile Management:** Building projects with graphics library dependencies

# Installation and compilation
1. Clone this repository into your project:
```bash
git clone git@github.com:Philippe89fr/42_soLong.git
```
2. Run the following command:
```bash
make
```
3. Launch Game:
```bash
./so_long maps/valide_grande.ber
```
