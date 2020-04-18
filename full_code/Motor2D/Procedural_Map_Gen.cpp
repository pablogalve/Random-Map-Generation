#include "Procedural_Map_Gen.h"
#include "j1App.h"
#include "j1Map.h"
#include "p2Log.h"

Procedural_Map_Gen::Procedural_Map_Gen()
{
	
}

Procedural_Map_Gen::~Procedural_Map_Gen()
{
}

int Procedural_Map_Gen::generateSeed() {
	//Returns current time in milliseconds
	//We'll use that as a seed
	msec = time(NULL) * 1000;

	return msec;
}

void Procedural_Map_Gen::generatePerlinNoise() {
	//We use always the same seed
	generatePerlinNoise(1);
}

void Procedural_Map_Gen::generatePerlinNoise(unsigned int seed)
{


	fillMap();
}

void Procedural_Map_Gen::fillMap()
{

	//Fills the map with data extracted from perlin noise
	for (int x = 0; x < 100; x++) {
		for (int y = 0; y < 100; y++) {
			if(x < 50 && y < 50)
				App->map->height_map[x][y] = 0;
			else if (x >= 50 && y < 50)
				App->map->height_map[x][y] = 1;
			else if (x < 50 && y >= 50)
				App->map->height_map[x][y] = 2;
			else if (x >= 50 && y >= 50)
				App->map->height_map[x][y] = 3;
			else 
				App->map->height_map[x][y] = 0;
		}
	}
}