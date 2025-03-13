# Pathfinder
# Map Setup using SFML

## Compilation Instructions

1. Install SFML (`sudo apt-get install libsfml-dev` on Linux or use vcpkg/homebrew on Windows/macOS).
2. Run the following commands:

```
mkdir build
cd build
cmake ..
make
./MapSetup
```

## Usage
- Left-click to add destinations.
- Destinations will be marked in red on the grid.
- The program prints destination coordinates in the console.
- Close the window to exit the program.
