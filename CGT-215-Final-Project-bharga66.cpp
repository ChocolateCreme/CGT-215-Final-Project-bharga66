#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

using namespace sf;
using namespace std;
using namespace sfp;

int main()
{
    // Create the window
    RenderWindow window(VideoMode(965, 621), "Angry Birds");

    // Load the background image
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("AngryBirds.png"))
    {
        cout << "Failed to load background image!" << endl;
        return -1;
    }

    // Create the background sprite
    Sprite backgroundSprite(backgroundTexture);

    // Game loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        // Draw the background
        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }

    return 0;
}
