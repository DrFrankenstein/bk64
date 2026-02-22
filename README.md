bk64 - A Breakout clone for the Commodore 64
=====================================

Downloading
-----------
>[!NOTE]
>This is a very early work in progress. No builds are available as this isn't really a functioning game at the moment.

Building
--------
You will need [cc65] and a basic Make utility.
>[!NOTE]
>The Makefile currently only works with NMAKE (which ships with the Windows SDK and Visual Studio). It should be fairly easy to port to a GNUMakefile, but that's for another day.

To build a `.prg` file:
```sh
nmake
#or
nmake all
```

You should be able to drag that `.prg` file to an emulator like VICE.

To build a `.d64` disk image of the game, which you can then write to a physical floppy or mount in an emulator:
```sh
nmake dist
```

These instructions assume that your `cc65` install is in your `PATH` environment variable. If, for some reason, you need to specify a different path for your compiler and/or linker, you can specify that as part of your NMAKE command:
```sh
nmake CC=/path/to/cl65 all
```

[cc65]: https://cc65.github.io/
