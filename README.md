# BI-PA2: Semestral work

Repository copy of my semestral work from "Programming and Algorithmics 2" course on Czech Technical University in Prague.

Goal: Create simple 2D strategy game. Detailed description in Slovak languge [here](https://github.com/Richardds/CTU_BI-PA2_SemestralWork/blob/master/zadani.txt).

### Build & Run:

`make all` - Compiles documentation and code

`make compile` - Compiles code only

`make doc` - Compiles documentation only

`make run` - Runs game

Binary is locates on root directory `./boldiric`

### Quick guide:

**Keys 1,2,3,4,5** - Select building you want to build.

**Left mouse button** - Place building

**Right mouse button** - Destroy building

**Middle mouse button** - Upgrade building

**S key** - save game state to `./savegame.bin`

**L key** - load game state from `./savegame.bin`

**N key** - reset game state

If you do not want to wait for resources gain, press **G key** for DEV mode.

I was unable to use any SDL2 font library so there is no text rendering. All information is unfortunately printed to console.
