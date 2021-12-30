# cekeh-client
OpenGL client for cekeh game

Be sure to initialize the required submodules with one of these options:
```bash
# clone using the --resurse-submodules tag
git clone --recurse-submodules https://github.com/ThomasvanBommel/cekeh-client.git

# ... or this if you've already cloned it
git submodule init
```

<br />

## Requirements
 - cmake
 - g++
```bash
sudo apt-get install cmake g++
```

<!-- cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev libxi-dev -->

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