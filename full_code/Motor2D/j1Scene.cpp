#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "Procedural_Map_Gen.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
	going_up = true;
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	//App->map->Load("iso_walk.tmx");

	debug_tex = App->tex->Load("maps/path.png");
	water_tex = App->tex->Load("maps/water.png");
	sand_tex = App->tex->Load("maps/sand.png");
	grass_tex = App->tex->Load("maps/grass.png");
	forest_tex = App->tex->Load("maps/forest.png");

	//TODO
	/*Default seed is 1337
	But we need a different seed on each game
	There's a function that generates a new seed,
	use that to pass as an argument to our "generatePerlinNoise" function
	*/
	App->procedural_map->generatePerlinNoise(App->procedural_map->generateSeed());

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	// debug pathfing ------------------
	static iPoint origin;
	static bool origin_selected = false;

	int x, y;
	App->input->GetMousePosition(x, y);

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += floor(200.0f * dt);

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= floor(200.0f * dt);

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += floor(200.0f * dt);

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= floor(200.0f * dt);

	//TODO
	//Same as before. The other one was executed at start and this one when you press F1	
	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		App->procedural_map->generatePerlinNoise(App->procedural_map->generateSeed());

	//We print the generated map on screen
	App->map->DrawProceduralMap(App->map->height_map, { 100, 100 });

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);
	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%d,%d",
		App->map->data.width, App->map->data.height,
		App->map->data.tile_width, App->map->data.tile_height,
		App->map->data.tilesets.count(),
		map_coordinates.x, map_coordinates.y);

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;
	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	static char title[256];
	sprintf_s(title, 256, "Procedural Map Generation");
	App->win->SetTitle(title);

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}
