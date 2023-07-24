# CPMK - C/C++ Project Maker
But this time in C++

## Generate a simple C/C++ project structure with CMake.

## Usage
Simply open a terminal and type: cpmk <language> <project_name>

### Examples:
```sh
cpmk c c_proj
```

```sh
cpmk cpp cpp_proj
```

# Installation
## Requirements
Requires CMake

Follow these steps:
```sh
git clone https://github.com/Sampie159/cpmkcpp.git
cd cpmkcpp
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
sudo cmake --install build
```
