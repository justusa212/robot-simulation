#ifndef LINE_COMPONENT_H_
#define LINE_COMPONENT_H_

#include "Renderer.h"
#include "components/RenderableComponent.h"
#include "components/Transforms.h"

#include <cassert>

/**
 * Renders a line from a start to an end position with a specified width.
 *
 * It can't used directly in a Scene, instead it must be assigned to
 * a Scene object to be updated each simulation iteration.
 */
class LineComponent : public RenderableComponent
{
public:
    LineComponent(const LineTransform *transform, const glm::vec4& color) :
        m_transform(transform),
        m_color(color) {}
    /**
     * Called every simulation iteration (if assigned to a Scene Object).
     */
    void onFixedUpdate() override {
        if (m_enabled == false) {
            return;
        }
        assert(m_transform != nullptr);
        Renderer::drawLine(m_transform->start, m_transform->end, m_transform->width, m_color);
    }
private:
    const LineTransform *const m_transform = nullptr;
    glm::vec4 m_color;
};

#endif /* LINE_COMPONENT_H_ */
