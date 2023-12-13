#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

MoveComponent::MoveComponent(float maxSpeed, Actor* owner) : Component(owner,"MoveComponent")
{
	m_maxSpeed = maxSpeed;
	
}

void MoveComponent::update(float deltaTime)
{
	//store the currentposition.
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();

	//if velocityu is over  the maximum speed...
	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		//normalize the velocity and scale it by the max speed to clamp it.
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}
	
	//increase the current position by the velocity to get the new position.
	position = position + getVelocity() * deltaTime;
	
	//and set the transform's position to be the new position.
	getOwner()->getTransform()->setLocalPosition(position);
}