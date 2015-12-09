#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	//Players collider
	player1 = App->physics->CreateCircle(200, 420, 21, 0.0f);
	player2 = App->physics->CreateCircle(602, 420, 21, 0.0f);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}


// Update: draw background
update_status ModulePlayer::Update()
{

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT){
		App->physics->MovePlayer(player1, -0.1f, 0.0f);
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT){
		App->physics->MovePlayer(player1, 0.1f, 0.0f);
	}
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT){
		App->physics->MovePlayer(player2, -0.1f, 0.0f);
	}
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT){
		App->physics->MovePlayer(player2, 0.1f, 0.0f);
	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT){
		App->physics->MovePlayer(player1, 0.0f, -0.1f);
	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN || App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT){
		App->physics->MovePlayer(player2, 0.0f, -0.1f);
	}

	player1->body->ApplyForce(b2Vec2(0, 3), player1->body->GetWorldCenter(), true);
	player2->body->ApplyForce(b2Vec2(0, 4), player2->body->GetWorldCenter(), true);

	return UPDATE_CONTINUE;
}



