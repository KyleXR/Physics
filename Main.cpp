//#include <iostream>
//#include "Random.h"
//#include "Graphics.h"
//#include <SDL.h>
//#include <glm/glm.hpp>
//#include "ParticleTest.h"
//#include "ForceTest.h"
//#include "JointTest.h"
#include "Tests/CollisionTest.h"


int main(int argc, char* argv[]) 
{
    Test* test = new CollisionTest();
    test->Initialize();
    while (!test->IsQuit()) { test->Run(); }
    delete test;

    return 0;
}