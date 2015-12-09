#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

class PhysBody;
class SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	PhysBody* player1;
	PhysBody* player2;

};