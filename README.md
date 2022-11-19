# malom

## How to build

This project best built with the provided conan and cmake utilities like so:

`mkdir build-debug && cd build-debug`

`conan install -s build_type=Debug --build=missing ..`

`cmake -G Ninja -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug ..`

`cmake --build .`
