Breakout-Clone
==============
A breakout clone for Twitch!  Written in C++ to show simple game development using object oriented programming using SFML!

Requirements
============
This project uses the following IDE's and libraries when compiling:

+ Microsoft Visual Studio 2013
+ SFML (Simple Fast Media Library)
+ a header.ttf font to be placed in the "Breakout Clone" directory.

Microsoft Visual Studio 2013 is the main IDE used in order to quickly setup the project.  SFML is used for graphics rendering and keyboard input, and header.ttf is the font file used to render text in the game.  Please make sure that you find a font that you can use, as it will not be distributed within this in order to prevent potential copyright issues.

Project Structure
==================
After opening the Visual Studio Project, you will see a variety of filters in the "Solution Explorer" panel.  Under "Header Files" and "Source Files" you have the following filters:

+ Core
+ Entities
+ States

These filters contain the following information:

###Core
Contains core classes for the project.  These classes manage essential things related to any game.  The main parts in this breakout clone are entities (the paddle, the ball, walls, etc.), the game state (main menus', the game, etc.), and the scoring system.  The following classes are in available as headers only:

+ entity.h
+ game_state.h

These files are completely self contained and do not require a .cpp counterpart.  The last file that can be found is:

+ score_system.h

Which does have a .cpp counterpart.  This is because of the fact that it is referencing the player's paddle, which also referenced it, and will created a circular reference if not split correctly.

###Entities
This filter is used for managing the game's entities.  In this, we have three files that have headers in the "Header Files" filter, and .cpp counterparts in the "Source Files" filter.  The files are:

+ ball.h/ball.cpp
+ paddle.h/paddle.cpp
+ wall.h/wall.cpp

The ball files manage the ball that moves around the game, and handles its collisions with the paddle and resulting actions.  The paddle file manages the player's movement of the paddle using the keyboard.  The wall files manage the walls and their collisions with the ball and resulting actions.  These again are split into header and .cpp files in order to prevent circular reference issues.

###States
This filter is used for managing the game's states.  In this filter, we have two main files in both the "Header Files" filter and the "Source Files" filter:

+ main_game.h/main_game.cpp
+ main_menu.h/main_menu.cpp

main_game handles the game's state, and uses the paddle, ball, and wall entities to allow the player to play the game.  main_menu manages the main menu's state, with things like rendering the game's title, drawing a "flashy" background using the ball and wall entities, and handling user input on the menu.

If you have further questions, you can contact me via my personal website and I will try to get back to you about them.  I hope this small doucmentation is useful to those who read it!
