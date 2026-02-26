bk64 - A Breakout clone for the Commodore 64
=====================================

Downloading
-----------
>[!NOTE]
>This is a very early work in progress. No builds are available as this isn't really a functioning game at the moment.

Building
--------
You will need [cc65] and a Make utility.

To build a `.prg` file:

on Windows:
```bat
nmake
: or
nmake all
```
on *nix:
```sh
make
# or
make all
```

You should be able to drag that `.prg` file to an emulator like VICE.

To build a `.d64` disk image of the game, which you can then write to a physical floppy or mount in an emulator:
```bat
: on Windows
nmake dist
```

```sh
# on *nix
nmake dist
```

These instructions assume that your `cc65` install is in your `PATH` environment variable. If, for some reason, you need to specify a different path for your compiler and/or linker, you can specify that as part of your NMAKE command:
```bat
: Windows
nmake CC=\path\to\cl65 all
```
```sh
# *nix
make CC=/path/to/cl65 all
```

Developing
----------
If you use VS Code, a project file for the VS64 extension is included.

[cc65]: https://cc65.github.io/
