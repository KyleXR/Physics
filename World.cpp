#include "World.h"
#include "Body.h"
#include "ForceGenerator.h"
#include "Joint.h"
#include "Collisions/Collision.h"
#include <vector>

glm::vec2 World::gravity{ 0, -9.8f };

World::~World()
{
	for (Body* body : m_bodies)
	{
		delete body;
	}
	m_bodies.clear();
}

void World::Step(float dt)
{
	// apply force generator force
	std::vector<Body*> bodies(m_bodies.begin(), m_bodies.end());
	if (!m_bodies.empty() && !m_forceGenerators.empty())
	{
		for (auto forceGenerator : m_forceGenerators)
		{
			forceGenerator->Apply(bodies);
		}

	}

	for (auto joint : m_joints) joint->Step(dt);

	for (Body* body : m_bodies)
	{
		body->Step(dt);
	}

	// Collision
	std::vector<Contact> contacts;
	Collision::CreateContacts(bodies, contacts);
	Collision::SeperateContacts(contacts);
	Collision::ResolveContacts(contacts);
}

void World::Draw(Graphics* m_graphics)
{
	for (auto joint : m_joints) joint->Draw(m_graphics);
	for (auto forceGenerator : m_forceGenerators) forceGenerator->Draw(m_graphics);
	for (Body* body : m_bodies) body->Draw(m_graphics);
}

void World::AddBody(Body* body)
{
	m_bodies.push_back(body);
}

void World::RemoveBody(Body* body)
{
	m_bodies.remove(body);
}

void World::AddJoint(Joint* joint)
{
	m_joints.push_back(joint);
}

void World::RemoveJoint(Joint* joint)
{
	m_joints.remove(joint);
}

void World::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_forceGenerators.push_back(forceGenerator);
}

