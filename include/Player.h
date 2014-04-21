#ifndef INCLUDE_PLAYER_H
#define INCLUDE_PLAYER_H

#include "Entity.h"
#include "Sprite.h"
#include "InputKeys.h"

#include <array>
using std::array;

/**
* The player entity class.
* Contains all the relevant implementation relative to the player.
*/
class Player : public Entity {

	public:
		/**
		* The constructor.
		* Creates the player by setting the position and sprite.
		* @param x_ : position in x axis.
		* @param y_ : position in y axis.
		* @param sprite_ : which sprite to use.
		*/
		Player(double x_, double y_, Sprite *sprite_);

		/**
		* The destructor.
		* Resets the attributes.
		*/
		virtual ~Player();

		/**
		* Updates the player.
		* Modifies whatever is necessary, relative to the player.
		* @param dt_ : Delta time. Time elapsed between one frame and the other, independent of processing speed.
		*/
		virtual void update(double dt_);

		/**
		* Renders the player.
		* Uses the player's sprite render method.
		* @see Sprite::render()
		*/
		virtual void render();

		/**
		* Updates the player depending on recieved input.
		* Modifies whatever is necessary, relative to the player.
		* @param keyStates_ : The input handled boolean array that says which keys are pressed.
		*/
		void updateInput(array<bool, GameKeys::MAX> keyStates_);

		/**
		* @param x_,y_ : Sets the players knowledge of the cameras x,y position.
		* @see Level::update()
		*/
		void setCameraXY(double x_, double y_);

		/**
		* @param width_,height_ : Sets the players knowledge of the level width,height.
		* @see Level::update()
		*/
		void setLevelWH(unsigned int width_, unsigned int height_);

		enum State
		{
			STATE_STANDING,
			STATE_WALKING,
			STATE_JUMPING,
			STATE_CROUCHING,
			STATE_ROLLING
		};

		State state;

	private:
		double vx; /**< The player's speed on the x axis. */
		double vy; /**< The player's speed on the x axis. */
		double speed; /**< Speed that moves player on input. */
		double maxSpeed; /**< Player max speed. */

		double cameraX;
		double cameraY;
		unsigned int levelW;
		unsigned int levelH;
		bool canJump;

};

#endif //INCLUDE_PLAYER_H
