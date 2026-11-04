# T.R.A.G. - native recompilation (private)

A static recompilation of **T.R.A.G. - Tactical Rescue Assault Group** (PlayStation, NTSC-U,
`SLUS-00813`, Sunsoft, 1999) to native code, using the recompiler and runtime of the Muppet
Monster Adventure and Einhander ports. The MIPS executable `SLUS_008.13` is translated to C++
and runs on Windows (and Linux) with a runtime that replaces the PlayStation hardware and BIOS.
Graphics are re-rendered with OpenGL at higher resolution.

**No game data is included.** You need your own copy of the game as a disc image (`.chd`, or
`.cue` + `.bin`).

## Status

- Work in progress. The executable is recompiled; the code modules the game loads from its
  `PRG/PLAYER/*_PACK.BIN`, `SUB0D.BIN` and `SAVE.BIN` files (at 0x80143E08) still run in the
  runtime's interpreter until they are mapped.
- Boots through the logos and the intro movie into gameplay and the map screen.

## Running (Windows)

1. Download the `trag-win64` artifact from the latest **Build Windows** run (Actions tab).
2. First run only: put your disc image next to `trag.exe` or in a `game` folder beside it, then
   run `trag.exe` - or drag the image onto it.
3. The disc is imported once into **`assets.dat`** (about 460 MB) and checked sector by sector
   to be an exact copy. From then on the game runs from `assets.dat` and the disc image can be
   deleted.

### In-game settings (F1 or Esc, Start+Select on a controller)

| Setting | Options |
|---|---|
| Resolution | 1x (original) to 6x internal resolution (restart); the window follows it (240 lines x the setting, shrunk to fit the desktop) |
| Widescreen 16:9 | wider view of the 3D world |
| VSync, Fullscreen (F11 / Alt+Enter) | |
| Scaling | sharp or smooth |
| Texture filtering | off (original), smooth 3D (2D art and text stay sharp), smooth everything - bilinear on the palette-decoded texels, so transparent edges stay clean |
| Colour | true colour, or the original 15-bit colour with the PlayStation's dither pattern |
| Precise geometry | sub-pixel polygon positions and perspective-correct textures (no wobble or texture warping), PGXP-style |
| Screen filter | off, scanlines, CRT (scanlines + aperture grille + glow; needs a window 600+ pixels tall) |
| Audio resampling | standard, or high quality (windowed-sinc) for the streamed XA music and voices |
| Swap A/B and X/Y | face buttons by position |
| Fast CD loading | levels load faster; music and movies stay real-time |
| Game speed | 1x-8x fast-forward (hold Tab for a burst) |
| Frame rate display | game frames per second and emulation speed (100% = a real console) |
| Keyboard keys | rebind every PlayStation button (or reset to defaults) |
| Controller buttons | rebind every PlayStation button to controller buttons, triggers or stick directions |

### Controls

Any XInput/SDL gamepad works. Einhander reads only the d-pad and buttons, so the left stick also
drives the d-pad. The original game has no vibration (it never sends motor data, and a reference
emulator with a DualShock attached never rumbles either); this port adds it - see Vibration above.
Controllers SDL has no mapping for are used as generic joysticks (buttons, hats, axes), and a
`gamecontrollerdb.txt` next to the exe adds more mappings. Start+Select opens the settings menu.
Keyboard defaults: arrows = d-pad, X = Cross, Z = Circle, A = Square, S = Triangle, Q/W = L1/R1,
1/2 = L2/R2, Enter = Start, Backspace = Select, I/J/K/L = right stick, Tab = fast-forward (hold).
Change them in the F1 menu under **Keyboard keys** (saved in `trag.ini`).

## Regenerating the code

```sh
python3 tools/prepare_disc.py TRAG.cue game
python3 src/recomp.py game config src/gen 300
```

## Disclaimer

This is an unofficial fan project. It is **not affiliated with, endorsed by, or sponsored by**
Sunsoft, Sony Interactive Entertainment or any of their affiliates. *T.R.A.G.* and all related
names and marks belong to their respective owners. This repository contains no game data; you
need your own legally obtained copy of the game.

## License

The project's own code is released under the [MIT License](LICENSE). Third-party components keep
their own licenses; see [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).
