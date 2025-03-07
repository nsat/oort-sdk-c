# C API client for oort_agent_sdk_interface

## Overview

- API version: 1.5
- Package version: 
For more information, please visit [https://developers.spire.com/oort-docs/index.html](https://developers.spire.com/oort-docs/index.html)

## Installation
You'll need the `curl 7.40.0` package (or newer) in order to build the API. To have code formatted nicely, you also need to have uncrustify version 0.67 or later.

# Prerequisites

## Install the `curl 7.40.0` package with the following command on Linux.
```bash
sudo apt remove curl
wget http://curl.haxx.se/download/curl-7.40.0.tar.gz
tar -xvf curl-7.40.0.tar.gz
cd curl-7.40.0/
./configure
make
sudo make install
```
## Install the `uncrustify 0.67` package with the following command on Linux.
```bash
git clone https://github.com/uncrustify/uncrustify.git
cd uncrustify
mkdir build
cd build
cmake ..
make
sudo make install
```

## Compile the sample:
This will compile the generated code and create a library in the build folder which has to be linked to the codes where API will be used.
```bash
mkdir build
cd build
// To install library to specific location, use following commands
cmake -DCMAKE_INSTALL_PREFIX=/pathtolocaiton ..
// for normal install use following command
cmake ..
make
sudo make install
```
## How to use compiled library
Given the test/source code which uses the API is written in main.c
(and the required api include is written and all objects necessary are defined and created)

To compile main.c (given the file is present in build folder) use following command
```bash
gcc main.c -L. -loort_agent_sdk_interface -o main
```
If using the supplied CMake config, this should be set up automatically.


Once compiled, you can run it with ``` ./main ```

Note: You don't need to specify includes for models and include folder 
seperately as they are included from the main include file. You just 
have to import the api.h file in your code, the models will be loaded automatically.
