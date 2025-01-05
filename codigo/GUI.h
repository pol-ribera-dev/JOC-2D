#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Sprite.h"

#define TILE_SIZE 32
#define HEIGHT 3
#define LETTER_GAP 7
#define HEART_GAP 16

class GUI {

private:
	GUI() {}

public:

	static GUI& instance()
	{
		static GUI GUI;

		return GUI;
	}

	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram, int amp);
	void render();
	void update(const glm::vec2 &newPos, int deltaTime);

	int getLives();
	int getScore();
	int getTries();
	int getTimeLeft();

	void setLives(int liv);
	void setTries(int tri);
	void setScore(int scr);
	void setTimeLeft(int time);
	bool isInitialized();
	void restart();

private:

	int lives;
	int score;
	int timeLeft;
	int tries;
	Sprite* background;
	vector<Sprite*> livesSprites, triesSprites, scoreSprites, timeSprites;
	Texture backgroundColor, font, heart;
	int amplitude;
	float tileGap;
	float timeTimer;

	Sprite* createLetter(char letter, const glm::vec2 &pos, ShaderProgram & shaderProgram);
	void createWord(string word, vector<Sprite*> &res, const glm::vec2 &pos, ShaderProgram & shaderProgram);
	void createHearts(const glm::vec2 &pos, ShaderProgram & shaderProgram);
	void createNumber(int num, int digitNumber, vector<Sprite*> &res, const glm::vec2 &pos, ShaderProgram & shaderProgram);
	bool initialized = false;
};