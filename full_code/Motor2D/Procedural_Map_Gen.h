#ifndef __Procedural_Map_Gen__
#define __Procedural_Map_Gen__

#include "j1Module.h"
#include <time.h>
#include "FastNoise.h"

class Procedural_Map_Gen : public j1Module
{
public:
	Procedural_Map_Gen();
	~Procedural_Map_Gen();

	int generateSeed();

	void generatePerlinNoise();
	void generatePerlinNoise(unsigned int seed);
	
	
	void fillMap();
private:
	time_t msec;
	
};

#endif // !__Procedural_Map_Gen__
