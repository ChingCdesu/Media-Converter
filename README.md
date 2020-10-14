# Media-Converter

Author: ChingCdesu(_ChingC)

## About

This is A simple media converter in browser.

Used packages: 

* C++ part: , [easylogging++](https://github.com/easylogging/easyloggingpp), [cpp-httplib](https://github.com/yhirose/cpp-httplib)
* HTML part: [bootstrap 4](https://github.com/twbs/bootstrap), [bootstrap-select](https://github.com/snapappointments/bootstrap-select)
* WASM part: [ffmpeg](https://ffmpeg.org), [emsdk](https://github.com/emscripten-core/emsdk)

## Build, Deploy

**Build Requirements:**

* CMake and Any C++ Compiler

```sh
mkdir build
cmake --build ./build --target media-converter -j6
```

**Config:**

Copy `config.default.ini` and rename to `config.ini`, to change your own config.

You can edit `config.ini` to change server actions.

```ini
# config.default.ini
[server]
bind=127.0.0.1              # server host, default is 127.0.0.1
port=3000                   # server port, default is 3000
static-folder=./public      # static folder path, default is ./public
```

## How this repository works?

1. Use [emsdk](https://github.com/emscripten-core/emsdk) to build [ffmpeg](https://ffmpeg.org) WASM file.
2. Embed WASM and Javascript to HTML file.
3. Browsers call the exported functions from WASM.
4. Make a fast server with C++ for HTML and other files.

## FAQ

* Q: Does it support any browser?

  A: No, only the browser with Chromium Core support WASM Module.
