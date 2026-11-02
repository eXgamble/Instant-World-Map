# Instant World Map

The world map opens outdoors the way it already does indoors: it fades in at map height, without the camera flying up
from your character first.

Indoors, Skyrim's map camera starts its zoom right next to where it ends, so the map simply fades in. Outdoors it starts
at your character and flies up to map height. This SKSE plugin sets the zoom's start to its end the moment it begins,
so it has nothing to do. The map ends on exactly the same view as before. Closing the map, zooming, panning and fast
travel are untouched.

No settings, no plugin file, and nothing runs while the map is closed.

## Requirements

- Skyrim Special Edition 1.5.97 or Anniversary Edition 1.6.1170 / 1.7.x (one DLL for both)
- SKSE64
- Address Library for SKSE Plugins

## Compatibility

It changes only where the map camera's opening zoom starts. Mods that change the map's look (map textures, weather,
markers) work alongside it. A mod that hooks the same opening zoom may conflict.

## Building

`skse\build.bat` (VS Build Tools with CMake, Ninja and vcpkg; see `skse\CMakePresets.json`). The DLL is copied to
`mod\SKSE\Plugins`.

## License

GPL-3.0 (`skse/LICENSE`): CommonLibSSE-NG is GPL-3.0-or-later and statically linked.
