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
        // If only 1 cornerpoint present to avoid dividing by 0 specify a condition
        float deltaAngle = (m_cornerPointCount > 1) ? (90.f / (m_cornerPointCount - 1)) : 0.f;

        // Identifying which center (corner) the index belongs to
        std::size_t centerIndex = index / m_cornerPointCount;

        // The index of the point in the reference of that specific corner
        std::size_t localIndex = index % m_cornerPointCount;

        switch (centerIndex) {
            // The order of indeces has to go clockwise, because otherwise even if 
            // each corner is defined correctly, because of how sfml fills shapes
            // it will look twisted
            
            case 0: { // Top-Right, rounded
                // The coordinates grow from left to right and from top to bottom
                sf::Vector2f center = {m_size.x - m_radius, m_radius};
                // Choose angle references to account from clockwise order of indeces 
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

private:
    void update() { Shape::update(); }
    sf::Vector2f m_size;
    float m_radius;
    size_t m_cornerPointCount;
};