#include "core/game.h"
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "handlers/eventHandler.h"
#include "managers/inputManager.h"

int main() {
    sf::Clock DeltaTimeClock;
    int frameCount = 0;
    sf::Clock FPSClock;
    std::unique_ptr<game> gameInstance  = std::make_unique<game>();


    gameInstance->initializeEntities();

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    // Create a Window and render it
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Test", sf::Style::Default, settings);
    tgui::Gui gui{window};

    gameInstance->renderUI(gui);

    gameInstance->getUIManager()->UpdateTextSizes(window.getSize().x, window.getSize().y);


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
            eventHandler::getInstance().ListenEvents(event, window);

            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
                std::cout << "DEBUG: Inventory printed to console\n";
                gameInstance->getPlayerPtr().getInventory().printInventory();

            }

            if (event.type == sf::Event::Resized){
                CameraView.setSize(event.size.width, event.size.height);
                window.setView(CameraView);
                gameInstance->getUIManager()->UpdateTextSizes(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
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
        gameInstance->setDeltaTime(DeltaTimeClock.restart().asSeconds());

        // Update Game Logic
        gameInstance->Updater();

        window.clear();

        gameInstance->render(window, CameraView);

        gui.draw();


        window.display();
    }
    std::cout << "DEBUG: Cleaning UI before main() ends\n";
    gameInstance->getUIManager()->CleanAllUI();
    return 0;
}
