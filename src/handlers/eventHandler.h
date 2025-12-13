#ifndef NOTSIMPLEGAME_EVENTHANDLER_H
#define NOTSIMPLEGAME_EVENTHANDLER_H
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"

class eventHandler {

    sf::Event event;
    sf::RenderWindow* window;
public:
    explicit eventHandler() : window(nullptr) {};
    ~eventHandler() = default;

    // singleton
    static eventHandler& getInstance() {
        static eventHandler instance;
        return instance;
    }

    void ListenEvents(sf::Event& ev,sf::RenderWindow& RenderWindow);

    bool getWhenMouseClicked() const;

    sf::Vector2i getMousePosition() const;

    sf::Vector2f getMouseWorldPosition(const sf::View& view) const;




};


#endif //NOTSIMPLEGAME_EVENTHANDLER_H