#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
float xVel = 3;
float yVel = 3;
float* xVell = &xVel;

void CheckIfHit(sf::RectangleShape& player, sf::RectangleShape& ball);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

    sf::RectangleShape playerRight(sf::Vector2f(10, 100));
    playerRight.setPosition(sf::Vector2f(750, 250));
    playerRight.setFillColor(sf::Color::Green);

    sf::RectangleShape playerLeft(sf::Vector2f(10, 100));
    playerLeft.setPosition(sf::Vector2f(50, 250));
    playerLeft.setFillColor(sf::Color::Green);
    sf::Vector2f playerLeftPos(50, 250);

    sf::RectangleShape ball(sf::Vector2f(20, 20));
    ball.setPosition(sf::Vector2f(400, 300));
    ball.setFillColor(sf::Color::White);
    sf::Vector2f ballPosition(400, 300);

    window.setFramerateLimit(60);
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        float deltaTime = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerRight.move(0.f, -450 * deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerRight.move(0.f, 450 * deltaTime);
        }
        if (ballPosition.x < 400)
            if (playerLeftPos.y < ballPosition.y)
                playerLeftPos.y += 3;
            else
            {
                playerLeftPos.y -= 3;
            }
        playerLeft.setPosition(playerLeftPos);
        CheckIfHit(playerLeft, ball);
        CheckIfHit(playerRight, ball);

        ballPosition.x += xVel;
        ballPosition.y += yVel;

        ball.setPosition(ballPosition);
        //ballPosition.y += yVel;

        if (ballPosition.x > 760)
            xVel = xVel * (-1);

        if (ballPosition.x < 40)
            xVel = xVel * (-1);

        if (ballPosition.y > 580)
            yVel = yVel * (-1);

        if (ballPosition.y < 0)
            yVel = yVel * (-1);

        window.clear();
        window.draw(playerRight);
        window.draw(ball);
        window.draw(playerLeft);
        window.display();
    }

    return 0;
}
    void CheckIfHit(sf::RectangleShape& player, sf::RectangleShape& ball)
    {
        
        sf::FloatRect playerBounds = player.getGlobalBounds();
        sf::FloatRect ballBounds = ball.getGlobalBounds();
 
        if (playerBounds.intersects(ballBounds))
        {
            int a = rand() % 2;
            if (a == 0)
                yVel = yVel * (-1);
            xVel = xVel * (-1);
        }
    }

    void Movement()
    {

    }