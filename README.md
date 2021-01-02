<div id="header">
    <p align="center">
      <img width="64px" height="64px" style="border-radius: 6px;" src="examples/resources/textures/icon.png"/><br>
      <b>astera</b><br>
  	  <span font-size="16px">a cross platform game library</span><br>
      <span font-size="12px">Made by <a href="http://tek256.com">Devon</a> with love.</span><br><br>
      <span><a href="https://github.com/tek256/astera/wiki/Build-Guide">Setup</a> | <a href="https://github.com/tek256/astera/tree/master/examples/">Examples</a> | <a href="https://discordapp.com/invite/63GvpMh">Discord</a> | <a href="https://github.com/sponsors/tek256">Support</a></span><br><br>
      <span><img src="https://github.com/tek256/astera/workflows/Build%20Astera/badge.svg"></span>
    </p>
</div>

### About
Astera is a 2D game library written in C99 focused on performance, portability, and maintainability. Astera aims to rely on as few dependencies as possible. 

### Features
```
- Deferred & Forward Rendering
- Collision Dection + Resolution
- 3D Audio + basic Audio Effects & Filters
- Asset Management
- UI System
- Input System
```

### Target Platforms
Here are the target platforms for this library:  
```
- Windows
- Linux
- Mac OSX 
- BSD
``` 

_NOTE: I'm always open to adding more target platforms!_

### Building
Astera and it's dependencies are built using CMake. You can run your own CMake command or try using one of the automated build scripts (they're located in the `tools/` folder).

```
Usage build_unix.sh && build_win.bat [-hrcxqq]
-h  Show this info
-r  Build release (optimizations, -O2)
-c  Build clean (remove previous build generated by this script)
-x  Don't build examples
-q  Quiet output
-qq Silence all output
Windows Only:
-m  Force use MinGW (gcc/g++)
-l  Force use LLVM (clang/clang++)
```

Example script usage (generate a release candidate):

```
./build_unix.sh -r
```

Example CMake usage:

```
cmake -Bbuild -S. 
cmake --build build
```

NOTE: Once the build files are generated (first line) you only have to call `cmake --build build` to rebuild the source.

For more information see the relevant [wiki page](https://github.com/tek256/astera/wiki/Build-Guide).

### Special Thanks
[Isabella Muerte](https://github.com/slurps-mad-rips) for being a patient friend and helping create the build system.  
[Sharlock93](https://github.com/sharlock93) for helping diagnose issues.  
[Dan Bechard](https://github.com/dbechrd) for helping test on Windows & discuss ideas with.  

