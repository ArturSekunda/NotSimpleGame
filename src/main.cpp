#include "core/game.h"
#include "managers/UIManager.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "managers/inputManager.h"

int main() {
    sf::Clock DeltaTimeClock;
    int frameCount = 0;
    sf::Clock FPSClock;


    game::getInstance().initializeEntities();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Test", sf::Style::Default, settings);
    tgui::Gui gui{window};

    game::getInstance().renderUI(gui);

    game::getInstance().getUIManager()->UpdateTextSizes(window.getSize().x, window.getSize().y);


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
            game::getInstance().isLMBPressed = event.type == sf::Event::MouseButtonPressed;

            if (event.type == sf::Event::Resized){
                CameraView.setSize(event.size.width, event.size.height);
                window.setView(CameraView);
                game::getInstance().getUIManager()->UpdateTextSizes(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
            }
        }

        // FPS Calculation
        frameCount++;
        if (FPSClock.getElapsedTime().asSeconds() >= 1.0f) {
            window.setTitle("SFML Test - FPS: " + std::to_string(frameCount));
            frameCount = 0;
            FPSClock.restart();
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
    std::cout << "DEBUG: Cleaning UI before main() ends\n";
    game::getInstance().getUIManager()->CleanAllUI();
    return 0;
}
