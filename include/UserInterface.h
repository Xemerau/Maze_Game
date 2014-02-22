/// The User Interface class is responsible for displaying information to the
/// user by utiliizing sf::Text objects. In addition, it is also responsible
/// for tracking the current game state and chainging screens accordingly.
#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <SFML/Graphics.hpp>
#include "ImageManager.h"
#include <list>
#include <string>

class UserInterface
{
    public:
        enum ScreenState {Title, Game, LevelComplete, GameOver, HighScores, None};

        UserInterface(ImageManager &imageManager);
        virtual ~UserInterface();
        void updateTitle();
        void updateGame(int p_lives, int l_score, bool l_complete);
        void updateLevelComplete(int l_score, bool l_stealth, bool l_pacifist, int s_totalScore);
        void updateGameOver();
        void updateHighscores(std::list<std::string> names, std::list<int> scores);
        void updatePreviousState();
        ScreenState getState();
    private:
        std::list<sf::Text> textObjects;
        ScreenState state;
        ScreenState previousState;
        sf::Font font;
        sf::Sprite titleImage;
};

#endif // USERINTERFACE_H
