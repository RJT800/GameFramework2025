#include "TestScene.h"
#include "Player.h"
#include "Transform2D.h"
#include "MoveComponent.h"

void TestScene::start()
{
	Scene::start();

	Player* player = new Player();
	
	MoveComponent* playerMove = (MoveComponent*)player->addComponent(new MoveComponent(50, player));

	player->addComponent(playerMove);
	playerMove->setVelocity({ 50,20 });

	MathLibrary::Vector2 scale = MathLibrary::Vector2(50, 50);
	player->getTransform()->setScale(scale);
	addActor(player);
}