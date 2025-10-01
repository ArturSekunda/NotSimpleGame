#include "core/game.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

int main() {
    sf::Clock DeltaTimeClock;

    bool DeveloperMode = true;

    game::getInstance().initializeEntities();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test", sf::Style::Default, settings);
    tgui::Gui gui{window};


    window.setFramerateLimit(60);

    // Camera
    sf::View CameraView = window.getDefaultView();

    // Game Loop
    while (window.isOpen()) {

        // Create an event
        sf::Event event;

        // Event Handler
        while (window.pollEvent(event)) {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }

            if (event.type == sf::Event::Resized){
                CameraView.setSize(event.size.width, event.size.height);
                window.setView(CameraView);
            }

            if (event.type == sf::Event::KeyPressed && DeveloperMode) {
                inputManager::getInstance().debugInput(event);
            }
        }


        // Delta Time Calculation
        game::getInstance().setDeltaTime(DeltaTimeClock.restart().asSeconds());

        // Update Game Logic
        game::getInstance().Updater();

        window.clear();

        game::getInstance().render(window, CameraView);
        game::getInstance().renderUI(gui);

        gui.draw();


        window.display();
    }
    return 0;
}

