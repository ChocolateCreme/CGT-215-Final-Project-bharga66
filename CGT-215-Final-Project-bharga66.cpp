#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

using namespace sf;
using namespace std;
using namespace sfp;

int main()
{
    // Create the window
    RenderWindow window(VideoMode(965, 620), "Angry Birds");
    window.setFramerateLimit(60);

    // Create the physics world
    World world(Vector2f(0, 9.8f));

    // Load background image
    Texture backgroundTexture;

    if (!backgroundTexture.loadFromFile("AngryBirds.png"))
    {
        cout << "Failed to load background image!" << endl;
        return -1;
    }

    Sprite backgroundSprite(backgroundTexture);

    // Create ceiling
    PhysicsRectangle ceiling;
    ceiling.setSize(Vector2f(965, 10));
    ceiling.setCenter(Vector2f(482.5f, 0));
    ceiling.setStatic(true);
    world.AddPhysicsBody(ceiling);

    // Create floor
    PhysicsRectangle floor;
    floor.setSize(Vector2f(965, 10));
    floor.setCenter(Vector2f(482.5f, 615));
    floor.setStatic(true);
    world.AddPhysicsBody(floor);

    // Load pig texture
    Texture pigTexture;

    if (!pigTexture.loadFromFile("Pig.png"))
    {
        cout << "Failed to load pig image!" << endl;
        return -1;
    }

    // Create pigs
    PhysicsSprite pig1;
    pig1.setTexture(pigTexture);
    pig1.setCenter(Vector2f(900, 40));
    world.AddPhysicsBody(pig1);

    PhysicsSprite pig2;
    pig2.setTexture(pigTexture);
    pig2.setCenter(Vector2f(850, 60));
    world.AddPhysicsBody(pig2);

    PhysicsSprite pig3;
    pig3.setTexture(pigTexture);
    pig3.setCenter(Vector2f(800, 80));
    world.AddPhysicsBody(pig3);

    PhysicsSprite pig4;
    pig4.setTexture(pigTexture);
    pig4.setCenter(Vector2f(750, 100));
    world.AddPhysicsBody(pig4);

    PhysicsSprite pig5;
    pig5.setTexture(pigTexture);
    pig5.setCenter(Vector2f(700, 120));
    world.AddPhysicsBody(pig5);

    // Game loop
    Clock clock;

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

        // Draw everything
        window.clear();

        window.draw(backgroundSprite);
        window.draw(floor);
        window.draw(ceiling);

        window.draw(pig1);
        window.draw(pig2);
        window.draw(pig3);
        window.draw(pig4);
        window.draw(pig5);

        window.display();
    }

    return 0;
}
