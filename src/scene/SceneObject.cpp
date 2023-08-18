#include "SceneObject.h"
#include "Scene.h"
#include "components/RenderableComponent.h"
#include "components/PhysicsComponent.h"
#include "components/ControllerComponent.h"
#include "components/Transforms.h"

#include <cassert>

SceneObject::SceneObject(Scene *scene)
{
    assert(scene != nullptr);
    scene->addObject(this);
    m_scene = scene;
    m_physicsWorld = scene->getPhysicsWorld();
}

SceneObject::~SceneObject()
{
    m_scene->removeObject(this);
}

void SceneObject::setController(ControllerComponent *controller)
{
    assert(controller != nullptr);
    m_controllerComponent = controller;
}

void SceneObject::updateRenderable()
{
    if (m_renderableComponent) {
        m_renderableComponent->onFixedUpdate();
    }
}

void SceneObject::updatePhysics(float stepTime)
{
    if (m_physicsComponent) {
        m_physicsComponent->onFixedUpdate(stepTime);
    }
}

void SceneObject::updateController(float stepTime)
{
    if (m_controllerComponent) {
        m_controllerComponent->onFixedUpdate(stepTime);
    }
}

void SceneObject::onKeyEvent(const Event::Key &keyEvent)
{
    if (m_controllerComponent) {
        m_controllerComponent->onKeyEvent(keyEvent);
    }
}

void SceneObject::onFixedUpdate()
{
    /* Do nothing */
}
