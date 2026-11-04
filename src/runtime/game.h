// T.R.A.G. - Tactical Rescue Assault Group (NTSC-U, SLUS-00813) - game-specific constants.
#pragma once
#define GAME_NAME "T.R.A.G."           // window title, message boxes
#define GAME_INI "trag.ini"
#define GAME_BIN "trag.exe"
#define GAME_EXE_NAME "SLUS_008.13"
#define GAME_SERIAL "SLUS-00813"
static const unsigned GAME_EXE_SIZE = 561152u;
static const unsigned GAME_EXE_PC = 0x80063bf4u;

// SYSTEM.CNF: TCB = 4, EVENT = 10, STACK = 801fff00
static const int SYS_TCBS = 4;
static const int SYS_EVENTS = 10;
static const unsigned SYS_STACK = 0x801FFF00u;
