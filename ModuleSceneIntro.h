#pragma once
#include "Module.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;
class SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void DrawPlayer(PhysBody* body, SDL_Texture* texture);
public:

	//Colliders
	PhysBody* ground;
	PhysBody* net;

	SDL_Texture* wall;
	SDL_Texture* player1text;
	SDL_Texture* player2text;

	//PhysBody* sensor;
	//bool sensed;
	//uint bonus_fx;
};
