#include "ofApp.h"
#include <iostream>

using namespace snakelinkedlist;

const int kLabel_screen_offset = 20;

// Setup method
void snakeGame::setup() {
	ofSetWindowTitle("Snake126");

	srand(static_cast<unsigned>(time(0))); // Seed random with current time

	initResources();
}

/*
Update function called before every draw
If the function should update when it is called it will:
1. Check to see if the game is in progress, if it is paused or over it should not update.
2. Check to see if the current head of the snake intersects the food pellet. If so:
* The snake should grow by length 1 in its current direction
* The food should be moved to a new random location
3. Update the snake in the current direction it is moving
4. Check to see if the snakes new position has resulted in its death and the end of the game
*/
void snakeGame::update() {
	if (should_update_) {
		if (current_state_ == IN_PROGRESS) {
			ofVec2f snake_body_size = game_snake_.getBodySize();
			ofVec2f head_pos = game_snake_.getHead()->position;
			ofRectangle snake_rect(head_pos.x, head_pos.y, snake_body_size.x, snake_body_size.y);

			if (snake_rect.intersects(game_food_.getFoodRect())) {
				game_snake_.eatFood(game_food_.getColor());
				levelup_sound.play();
				game_food_.rebase();
			}
			game_snake_.update();

			if (game_snake_.isDead()) {
				ofSoundStopAll();
				gameover_sound.play();
				current_state_ = FINISHED;
			}
		}
	}

	should_update_ = true;
}

/*
Draws the current state of the game with the following logic
1. If the game is paused draw the pause screen
2. If the game is finished draw the game over screen and final score
3. Draw the current position of the food and of the snake
*/
void snakeGame::draw() {
	drawBackground();
	drawGameData();
	if (current_state_ == PAUSED) {
		drawGamePaused();
	}
	else if (current_state_ == FINISHED) {
		drawGameOver();
	}
	drawFood();
	drawSnake();
}

/*
Function that handles actions based on user key presses
1. if key == F12, toggle fullscreen
2. if key == p and game is not over, toggle pause
3. if game is in progress handle WASD action
4. if key == r and game is over reset it

WASD logic:
Let dir be the direction that corresponds to a key
if current direction is not dir (Prevents key spamming to rapidly update the snake)
and current_direction is not opposite of dir (Prevents the snake turning and eating itself)
Update direction of snake and force a game update (see ofApp.h for why)
*/
void snakeGame::keyPressed(int key) {
	if (key == OF_KEY_F12) {
		ofToggleFullscreen();
		return;
	}

	int upper_key = toupper(key); // Standardize on upper case

	if (upper_key == 'P' && current_state_ != FINISHED) {
		// Pause or unpause
		current_state_ = (current_state_ == IN_PROGRESS) ? PAUSED : IN_PROGRESS;
	}
	else if (current_state_ == IN_PROGRESS)
	{
		SnakeDirection current_direction = game_snake_.getDirection();

		// If current direction has changed to a valid new one, force an immediate update and skip the next frame update
		if (upper_key == 'W' && current_direction != DOWN && current_direction != UP) {
			game_snake_.setDirection(UP);
			update();
			should_update_ = false;
		}
		else if (upper_key == 'A' && current_direction != RIGHT && current_direction != LEFT) {
			game_snake_.setDirection(LEFT);
			update();
			should_update_ = false;
		}
		else if ((upper_key == 'S') && current_direction != UP && current_direction != DOWN) {
			game_snake_.setDirection(DOWN);
			update();
			should_update_ = false;
		}
		else if (upper_key == 'D' && current_direction != LEFT && current_direction != RIGHT) {
			game_snake_.setDirection(RIGHT);
			update();
			should_update_ = false;
		}
	}
	else if (upper_key == 'R' && current_state_ == FINISHED) {
		reset();
	}
}

void snakeGame::reset() {
	game_snake_ = Snake();
	game_food_.rebase();
	current_state_ = IN_PROGRESS;

	initResources();
}

void snakeGame::windowResized(int w, int h) {
	game_food_.resize(w, h);
	game_snake_.resize(w, h);
}

void snakeGame::drawFood() {
	ofSetColor(255, 255, 255);
	mushroom_image.draw(game_food_.getFoodRect());
}

void snakeGame::drawSnake() {
	ofVec2f snake_body_size = game_snake_.getBodySize();
	ofVec2f head_pos = game_snake_.getHead()->position;

	for (SnakeBody* curr = game_snake_.getHead(); curr != NULL; curr = curr->next) {
		ofVec2f currPos = curr->position;
		if (currPos != head_pos) {
			ofSetColor(255, 255, 255);
			mario_body_image.draw(currPos.x, currPos.y, snake_body_size.x, snake_body_size.y);
		}
	}
	ofSetColor(255, 255, 255);
	mario_head_image.draw(head_pos.x, head_pos.y, snake_body_size.x, snake_body_size.y);
}

void snakeGame::drawBackground() {
	ofSetColor(255, 255, 255);
	background_image.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

void snakeGame::drawGameData() {
	float fps = ofGetFrameRate();
	string total_food = std::to_string(game_snake_.getFoodEaten());
	string lose_message = "Score: " + total_food + "\nFPS: " + std::to_string(fps).substr(0, 7);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(lose_message, kLabel_screen_offset, kLabel_screen_offset);
}

void snakeGame::drawGameOver() {
	string total_food = std::to_string(game_snake_.getFoodEaten());
	string lose_message = "Game Over!!!\nFinal Score: " + total_food;
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(lose_message, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

void snakeGame::drawGamePaused() {
	string pause_message = "P to Unpause!";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(pause_message, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
}

void snakeGame::initResources() {
	levelup_sound.load("levelup.mp3");

	background_sound.load("marioTheme.mp3");
	background_sound.setLoop(true);
	background_sound.play();

	gameover_sound.load("gameover.mp3");

	mushroom_image.load("mushroom.png");
	mario_head_image.load("marioHead.png");
	mario_body_image.load("marioBody.png");
	background_image.load("marioBackground.png");
}
