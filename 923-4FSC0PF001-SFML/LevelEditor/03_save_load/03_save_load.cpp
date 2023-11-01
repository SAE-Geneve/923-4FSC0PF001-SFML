#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

#define TILEMAP_WIDTH 16
#define TILEMAP_HEIGHT 12
#define TILE_SIZE_PX 50

// TODO: replace the bool array with a TileType array, and allow to place Start and End tiles.
// enum class TileType {
//     Empty = 0,
//     Wall,
//     Start,
//     End,
// };

static sf::Vector2i player_coords(2, 1);
static bool tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = {0}; // initialize a bool array with all zeroes (false).

bool in_bounds(sf::Vector2i coords)
{
    return coords.x >= 0
        && coords.x < TILEMAP_WIDTH
        && coords.y >= 0
        && coords.y < TILEMAP_HEIGHT
    ;
}

void save()
{
    FILE* f = fopen("level.data", "wb");
    fwrite(tilemap, sizeof(tilemap), 1, f);
    fclose(f);
}

void load()
{
    FILE* f = fopen("level.data", "rb");
    fread(tilemap, sizeof(tilemap), 1, f);
    fclose(f);
}

int main()
{
    // set some tiles for testing purposes
    tilemap[0] = true; // top left
    tilemap[TILEMAP_WIDTH-1] = true; // top right
    tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT-1] = true; // bottom right
    {
        int x = 3;
        int y = 2;
        tilemap[TILEMAP_WIDTH*y + x] = true;
    }

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // Create tile shape
    sf::RectangleShape tile_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
    tile_shape.setFillColor(sf::Color(209, 147, 67));
    tile_shape.setOutlineColor(sf::Color(245, 213, 127));
    tile_shape.setOutlineThickness(-2);

    // Create cursor shape
    sf::RectangleShape cursor_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
    cursor_shape.setFillColor(sf::Color(209, 147, 67, 0));
    cursor_shape.setOutlineColor(sf::Color(250, 250, 250));
    cursor_shape.setOutlineThickness(-3);

    // Create player shape
    sf::CircleShape player_shape(TILE_SIZE_PX / 4);
    player_shape.setFillColor(sf::Color(180, 30, 30));
    player_shape.setOutlineColor(sf::Color(252, 100, 100));
    player_shape.setOutlineThickness(-2);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                sf::Vector2i prev_player_coords = player_coords;
                if (event.key.code == sf::Keyboard::D) {
                    player_coords.x += 1;
                }
                if (event.key.code == sf::Keyboard::A) {
                    player_coords.x -= 1;
                }
                if (event.key.code == sf::Keyboard::S) {
                    player_coords.y += 1;
                }
                if (event.key.code == sf::Keyboard::W) {
                    player_coords.y -= 1;
                }
                // "Collision" test
                if (!in_bounds(player_coords) || tilemap[player_coords.x + player_coords.y * TILEMAP_WIDTH]) {
                    // if our new position is in a wall, we cancel the movement by teleporting
                    // back to our previous coordinates.
                    player_coords = prev_player_coords;
                }

                if (event.key.code == sf::Keyboard::F5) {
                    save();
                }
                if (event.key.code == sf::Keyboard::F9) {
                    load();
                }
            }
        }

        // Determine tile coordinates that the mouse is hovering
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2i mouse_tile_coord(mouse_pos.x / 50, mouse_pos.y / 50);
        //printf("%i,%i\n", mouse_tile_coord.x, mouse_tile_coord.y);

        // Editor interaction
        bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);
        if (mouse_left || mouse_right) {
            // Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
            if (in_bounds(mouse_tile_coord)) {
                // Set the hovered tile to true or false depending on the pressed mouse button.
                tilemap[mouse_tile_coord.y * TILEMAP_WIDTH + mouse_tile_coord.x] = mouse_left;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw the tilemap
        for (int y = 0; y < TILEMAP_HEIGHT; y++) {
            for (int x = 0; x < TILEMAP_WIDTH; x++) {
                if (tilemap[x+y*TILEMAP_WIDTH]) {
                    // draw tile shape at correct position
                    tile_shape.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
                    window.draw(tile_shape);
                } else {
                    // draw nothing                    
                }
            }
        }

        // draw selection cursor
        cursor_shape.setPosition(TILE_SIZE_PX * mouse_tile_coord.x, TILE_SIZE_PX * mouse_tile_coord.y);
        window.draw(cursor_shape);        

        // draw player
        player_shape.setPosition(player_coords.x * TILE_SIZE_PX + TILE_SIZE_PX/4, player_coords.y * TILE_SIZE_PX + TILE_SIZE_PX/4);
        window.draw(player_shape);
        
        // end the current frame
        window.display();
    }

    return 0;
}