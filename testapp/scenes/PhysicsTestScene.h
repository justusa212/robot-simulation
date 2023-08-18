#ifndef PHYSICS_TEST_SCENE_H_
#define PHYSICS_TEST_SCENE_H_

#include "Scene.h"

class RectObject;
class CircleObject;

class PhysicsTestScene : public Scene
{
public:
    PhysicsTestScene();

private:
    std::unique_ptr<RectObject> m_ground;
    std::unique_ptr<RectObject> m_fallingBox;
    std::unique_ptr<CircleObject> m_fallingBall;
};

#endif /* PHYSICS_TEST_SCENE_H_ */
