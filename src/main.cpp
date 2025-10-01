#include "core/game.h"
#include "managers/UIManager.h"
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

    game::getInstance().renderUI(gui);

    UIManager::getInstance().UpdateTextSizes(window.getSize().x, window.getSize().y);


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
                UIManager::getInstance().UpdateTextSizes(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
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

        gui.draw();


        window.display();
    }
    UIManager::getInstance().CleanAllUI();
    return 0;
}

