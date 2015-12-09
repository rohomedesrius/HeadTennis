#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{

}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	//TEXTURES
	wall = App->textures->Load("HeadTennis/ProvaFons.png");

	//Player textures
	player1text = App->textures->Load("HeadTennis/Player1Head.png");
	player2text = App->textures->Load("HeadTennis/Player2Head.png");

	//COLLIDERS
	int Map[30] = {
		6, 442,
		6, 267,
		28, 110,
		116, 27,
		278, 5,
		524, 6,
		686, 28,
		772, 111,
		796, 266,
		796, 447,
		411, 447,
		411, 331,
		392, 331,
		392, 447,
		6, 447
	};

	App->physics->CreateChain(0, 0, Map, 30);



	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

void  ModuleSceneIntro::DrawPlayer(PhysBody* body, SDL_Texture* texture){

	int player_x, player_y;
	body->GetPosition(player_x, player_y);
	
	App->renderer->Blit(texture, player_x - 3, player_y, NULL, 1.0f);
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	App->renderer->Blit(wall, 0, 0);
	DrawPlayer(App->player->player1, player1text);
	DrawPlayer(App->player->player2, player2text);

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 16, 1.5f);
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	int x, y;

}
