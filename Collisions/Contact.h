#pragma once

#include <glm/glm.hpp>

struct Contact
{
	class Body* bodyA{ nullptr };
	class Body* bodyB{ nullptr };

	float resitution{ 0 };
	float depth{ 0 };
	glm::vec2 normal{ 0, 0 };
};