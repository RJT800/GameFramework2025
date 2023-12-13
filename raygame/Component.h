#pragma once
class Actor;

class Component
{
public:

	Component();
	Component(Actor* owner, const char* name);
	virtual ~Component();
	/// <summary>
	/// called before the first update.
	/// </summary>
	virtual void start() {};

	/// <summary>
	/// called every time the game update.
	/// </summary>
	/// <param name="deltaTime">the amount of time that has 
	/// passed between the current frame and last frame.</param>
	virtual void update(float deltaTime) {};

	/// <summary>
	/// called after update in order to update visuals.
	/// </summary>
	virtual void draw() {};

	/// <summary>
	/// called at the end of a scene or when an actor is removed from the scene.
	/// </summary>
	virtual void end() {};

	/// <summary>
	/// called when the owner overlaps with another actor.
	/// </summary>
	/// <param name="other">the actor the onwer overlapped.</param>
	virtual void onCollision(Actor* other) {};

	/// <summary>
	/// called when the actor is going to be destroyed.
	/// </summary>
	virtual void onDestroy() {};


	/// <returns>the name of the component.</returns>
	const char* getName() { return  m_name; }


	/// <returns>the actor the component is tied to.</returns>
	Actor* getOwner() { return m_owner;  }
private:
	const char* m_name;
	Actor* m_owner;

};

