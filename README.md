# Crusher

A modern port of the MS-DOS game Crusher developed by Soleau Software.

## About the game

Crusher is an action puzzle game where you must complete multiple tasks in order to win. You are in a dungeon and must collect 10,000 points before receiving your first objective. To collect points, you must collect diamonds and crush your enemies. While doing so, you must avoid running out of oxygen by collecting oxygen tanks, and you must break through walls using TNT that you find along the way.

The game is played in a 25 room map. Once you get the 10,000 points and receive your first objective, you learn why you are really here: a maiden in distress named Eve. But there is more - play the game to find out all the various objectives you must complete to win it.

## Project requirements

- Linux.
- SFML version 2.5 installed in the system.
- A C++ compiler (I have used g++).

## Build

The steps for building the game are:

1. Go to the root of the project and execute `make BUILD=release` for the release version or `make` / `make BUILD=develop` for the development version.
2. after compiling the game, execute it with `./crusher`
3. Enjoy! 

The development version has output to the console, shows the FPS in the window and the code does not have the compiler optimizations of the release version.

## How to Play

- You start with 5 lifes, 4 bombs and X oxigen.
- You move trought a map of 25 rooms and each room is 19x16 dimensions.
- You can move blocks if their path are free from other blocks, enemies, items or ways, except of grey blocks, they can't be moved.
- You can use bombs to destroy any block.
- Enemies are defeat when they can't move, surrounded by blocks, items, ways or another enemy.
- Each room has 3 enemies. If you stand by the side of one you lose one life.
- Each move consumes oxygen. If you run out of it you lose a life.
- The oxygen tank has 10 steps.
- After killing an enemy, an oxygen pickup will appear in a free random place of the current room.

Points:
- Diamonds give 150 points.
- Killing an enemy gives 125 points.
- Oxigen gives 15 points.
- Bombs gives 20 points and 3 bombs.

Controls:

- Arrows: moves the character.
- Spacebar: activate bomb. After then you chose an adjacent block with an arrow key.
- Escape: pause the game.


## Screenshoots
