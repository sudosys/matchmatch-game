# Match Match Game ![matchmatch_icon](https://user-images.githubusercontent.com/67098654/151411987-4b1feb09-e4c2-42e6-ade0-d2f4cb2e4a9f.png)

## About the Game

Match Match Game is a card matching game that gives you customizability and joy. Players can customize card backs as they wish. Also there are card front themes for players to choose from!

## Installation

Latest version of the game can be downloaded from the [releases](https://github.com/sudosys/matchmatch-game/releases) tab.

## Build Steps

> qmake.exe src.pro

Then, create a folder in the project directory and cd into it

Using __MinGW__:

> mingw32-make.exe -j8

Using __MSVC__ (Microsoft Visual C++ Compiler):

> jom.exe

## Game Settings

Settings are pretty straight-forward.

Players can select,

* Card Back Texture
* Card Front Texture
* Background

and

* Music
* Sound effects (card flip sound and end game sound)

can be toggled.

![settings_window](https://user-images.githubusercontent.com/67098654/155855769-b7dc4e38-e284-4d8b-a3eb-6f481fd0ba60.png)

## Player Statistics

Match Match Game also keeps statistics about your game.

The things that the game keeps track of are,

* Difficulty level of the game
* Date & Time that the game started
* Time elapsed
* Erroneous flips occured in the game
* Score of the game

![player_statistics_window](https://user-images.githubusercontent.com/67098654/155857650-0dc2c080-eef0-4bb1-b08c-bfdd94d065c0.png)

## Contributing

Contributions are welcomed. If you have ideas about the game please contact via Twitter (link can be found in the profile page).

## License

This game is licensed under [GNU GPLv3.0](https://github.com/sudosys/matchmatch-game/blob/master/COPYING)
