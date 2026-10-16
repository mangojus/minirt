_This project has been created as part of the 42 curriculum by rshin, cafabre._

# miniRT

A ray tracer written in **C** on top of MiniLibX. It reads a scene description file (`.rt`), casts one ray per pixel from a configurable camera, and shades each hit with ambient light, diffuse (Lambertian) lighting and hard shadows.

## Features

- **Primitives**: spheres, planes, and finite cylinders with capped ends (tube plus two discs).
- **Camera**: position, view direction, and horizontal field of view from 0 to 180°.
- **Lighting**: ambient light, one point light with brightness, and colored lights and objects.
- **Shading**: diffuse lighting from `N·L`, plus shadow rays that check for occluders between each hit point and the light.
- **Math**: a small homogeneous `vec4`/matrix library (points vs vectors, dot/cross product, normalization, matrix × vector).
- **Strict scene parsing**: unknown identifiers, missing or duplicated `A`/`C`/`L`, wrong argument counts, out-of-range values (including direction vectors outside [-1, 1]), empty files and bad file extensions are all rejected with an error message.
- **Window**: 1600×900. Close it with `Esc` or the window's close button, which frees all resources.

## Build & run

Requirements: `cc`, `make`, and the X11 development libraries (`libx11-dev libxext-dev zlib1g-dev`). MiniLibX is bundled in [`minilibx-linux/`](minilibx-linux) and libft in [`libft/`](libft). Both are built automatically.

```bash
make
./miniRT scenes/1_basic/all.rt
```

## Scene format

One element per line, with fields separated by spaces. Vectors are `x,y,z` and colors are `R,G,B` in the 0–255 range.

| ID | Element | Fields |
|---|---|---|
| `A` | ambient light (exactly once) | ratio `[0,1]` · color |
| `C` | camera (exactly once) | position · direction (normalized) · FOV `[0,180]` |
| `L` | point light (exactly once) | position · brightness `[0,1]` · color |
| `sp` | sphere | center · diameter · color |
| `pl` | plane | point · normal (normalized) · color |
| `cy` | cylinder | center · axis (normalized) · diameter · height · color |

```
A   0.1                     255,255,255
C   0,1,-10    0,0,1        60
L   5,5,-5     1.0          255,255,255

sp  3,1,0      2                          255,255,255
pl  0,0,0      0,1,0                      255,255,255
cy  -3,1,0     -0.5,0,0.5   2     3       255,255,255
```

## Example scenes

[`scenes/`](scenes) has more than 40 scenes, grouped to exercise one feature at a time:

| Folder | Shows |
|---|---|
| `0_bad/` | invalid files that must be rejected (bad values, missing elements, wrong extension, empty file) |
| `1_basic/` | each primitive on its own, including horizontal and tilted cylinders |
| `2_light/` | light from front, back, side, top and quarter angles |
| `3_ambient/` | ambient and light intensity at 0 versus 1, with colored light |
| `4_multi/` | several objects, multiple cylinders, colored ambient light |
| `5_perspective/` | FOV changes, camera rotation, moving lights |
| `6_intersect/` | intersecting objects and closed rooms |
| `7_fun/` | composed scenes: `atoms`, `monster`, `scifi`, `western` |

```bash
for f in scenes/7_fun/*.rt; do ./miniRT "$f"; done    # press Esc to go to the next one
```

## How it works

```
.rt file ─▶ parsing ─▶ scene (A, C, L, objects) ─▶ for each pixel:
              │                                        primary ray from the camera
              └─ validation & errors                   nearest intersection (sp / pl / cy)
                                                       ambient + diffuse · shadow ray
                                                       ─▶ image buffer ─▶ MiniLibX window
```

| Directory | Role |
|---|---|
| `src/parsing/` | reads the file, dispatches lines by identifier, validates values and coordinates, builds the scene |
| `src/exec/` | rendering loop, ray generation, intersections, shading, window controls |
| `src/vec4/` | vector and matrix math |

## Team

- **rshin**: rendering (rays, intersections, shading), vector math, window/controls
- **cafabre**: scene parsing and validation, advanced math.
