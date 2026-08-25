#pragma once 

class RoundedRectangleShape : public sf::Shape {
public:
    RoundedRectangleShape(const sf::Vector2f& size, float radius, size_t cornerPointCount = 20)
        : m_size(size), m_radius(radius), m_cornerPointCount(cornerPointCount) {
        update();
    }

    void setSize(const sf::Vector2f& size) { m_size = size; update(); }
    void setRadius(float radius) { m_radius = radius; update(); }

    virtual std::size_t getPointCount() const override {
        return m_cornerPointCount * 4;
    }

    virtual sf::Vector2f getPoint(std::size_t index) const override {
        if (index >= getPointCount()) return {};

        static const float pi = 3.141592654f;
        float deltaAngle = (m_cornerPointCount > 1) ? (90.f / (m_cornerPointCount - 1)) : 0.f;

        std::size_t centerIndex = index / m_cornerPointCount;
        std::size_t localIndex = index % m_cornerPointCount;

        switch (centerIndex) {
            case 0: { // Top-Right, rounded
                sf::Vector2f center = {m_size.x - m_radius, m_radius};
                float angleRad = (270.f + localIndex * deltaAngle) * pi / 180.f;
                return {center.x + m_radius * std::cos(angleRad), center.y + m_radius * std::sin(angleRad)};
            }
            case 1: // Bottom-Right, sharp
                return {m_size.x, m_size.y};

            case 2: // Bottom-Left, sharp
                return {0.f, m_size.y};

            case 3: { // Top-Left, rounded
                sf::Vector2f center = {m_radius, m_radius};
                float angleRad = (180.f + localIndex * deltaAngle) * pi / 180.f;
                return {center.x + m_radius * std::cos(angleRad), center.y + m_radius * std::sin(angleRad)};
            }
        }
        return {};
    }
    // virtual sf::Vector2f getPoint(std::size_t index) const override {
        // if (index >= getPointCount()) return {};

        // float deltaAngle = 90.f / (m_cornerPointCount - 1);
        // sf::Vector2f center;
        // float angle_x, angle_y;
        // unsigned int centerIndex = index / m_cornerPointCount;
        // static const float pi = 3.141592654f;
        // sf::Vector2f position;

        // switch (centerIndex) {
        //     case 0: {
        //         // top right
        //         center = {m_size.x - m_radius, m_radius};
        //         break;
        //     }
        //     case 1: {
        //         // top left
        //         center = {m_radius, m_radius};
        //         break;
        //     }
        //     case 2:
        //         // bottom left
        //         center = {m_radius, m_size.y - m_radius};
        //         break;
        //     case 3:
        //         // bottom right
        //         center = {m_size.x - m_radius, m_size.y - m_radius};
        //         break;
        //     }
        //     float angle = (index % m_cornerPointCount) * deltaAngle * pi / 180.f + centerIndex * pi / 2.f;
            
        // return {center.x + m_radius * cos(angle), center.y - m_radius * sin(angle)};
    // }

private:
    void update() { Shape::update(); }
    sf::Vector2f m_size;
    float m_radius;
    size_t m_cornerPointCount;
};