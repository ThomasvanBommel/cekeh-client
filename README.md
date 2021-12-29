# cekeh-client
OpenGL client for cekeh game

<br />

## Requirements
cmake 
```bash
sudo apt-get install cmake
```

<!-- cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev libxi-dev -->

Use the `--recurse-submodules` tag when cloning this repository:
```bash
git clone --recurse-submodules https://github.com/ThomasvanBommel/cekeh-client.git

# ... or this if you've already cloned it
git submodule init
```

<br />

## Running the application
```bash
# configure, build, and execute
./run

# force re-configuration, re-build, and execute
./run -f # or
./run --force
```

<br />