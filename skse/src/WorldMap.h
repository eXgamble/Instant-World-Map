#pragma once

// The world map opens outdoors the way it does indoors: already at map height, without the camera flying up from the
// player first. The map's camera runs a Transition state that zooms from near the player to map height; when it begins,
// its start is set to its end, so it has nothing to do.
namespace WorldMap
{
	// At plugin load: the zoom hook. False if it couldn't be installed (the map then zooms as vanilla).
	bool Install();
}
