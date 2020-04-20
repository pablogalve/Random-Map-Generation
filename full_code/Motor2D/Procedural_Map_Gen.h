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

	bool Awake(pugi::xml_node& config);

	int generateSeed();

	void generatePerlinNoise();
	void generatePerlinNoise(unsigned int seed);

public:
	

	
private:	
	time_t				msec;	
	float				frequency;
	float				default_seed;
};

#endif // !__Procedural_Map_Gen__
