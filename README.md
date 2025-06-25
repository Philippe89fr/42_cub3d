## Cub3D - 42

# Description:
cub3D is a 3D graphics project inspired by the world-famous Wolfenstein 3D game. The project implements a ray-casting engine to create a "realistic" 3D of the inside of a maze. The project uses the miniLibX graphics library to display wall textures, floor, colors, and allow smooth window management. The program takes a scene description file (.cub format) that defines the maze layout, textures, and colors, parsing this information to create the map and launch the game.

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
  - `N/S/E/W` represents the character. (depend on the orientation the player start with)

# Main Technologies / Skills Used:

- **Programming Languages:** C
- **Graphics Programming:** miniLibX library for window management, image displayment, and event handling
- **Ray-Casting Algorithm:** Mathematical implementation of ray-casting principles to give a 3D impression
- **Computer Graphics & Mathematical Concepts:** 3D perspective projection, texture mapping, Trigonometry, and pixel manipulation
- **Algorithm Optimization:** Efficient ray-casting implementation for real-time performance
- **File Parsing:** Custom .cub file format parsing for scene description
- **Memory Management:** Dynamic allocation for image data, textures, and scene information
- **Error Handling:** Comprehensive validation for file formats, map validity, and system resources
- **Makefile Management:** For automating compilation with graphics library linking

# Installation and compilation
1. Clone this repository into your project:
```bash
git clone git@github.com:Philippe89fr/42_cub3d.git
```
2. Run the following command:
```bash
make
```
3. Launch Game:
```bash
./so_long maps/valide_grande.ber
```
