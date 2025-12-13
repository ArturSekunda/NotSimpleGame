#include "eventHandler.h"


void eventHandler::ListenEvents(sf::Event &ev,sf::RenderWindow& RenderWindow) {
    event = ev;
    window = &RenderWindow;
}

bool eventHandler::getWhenMouseClicked() const {
    return event.type == sf::Event::MouseButtonPressed;
}

sf::Vector2i eventHandler::getMousePosition() const {
    return sf::Mouse::getPosition(*window);
}

sf::Vector2f eventHandler::getMouseWorldPosition(const sf::View& view) const {
    if (! window) {
        return sf::Vector2f(0.f, 0.f);
    }
    return window->mapPixelToCoords(sf::Mouse::getPosition(*window), view);
}
