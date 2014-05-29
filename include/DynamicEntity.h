#ifndef INCLUDE_DYNAMICENTITY_H
#define INCLUDE_DYNAMICENTITY_H

#include "Entity.h"
#include "Crosshair.h"
#include "BombPotion.h"
#include <vector>
#include <array>

enum CollisionSide : uint8_t {
	SOLID_TOP = 0,
	SOLID_BOTTOM,
	SOLID_RIGHT,
	SOLID_LEFT,
	SOLID_TOTAL
};

/**
* Subclass of Entity.
* The objects of this class are entities, but have physics applied to them (such as velocity).
*/
class DynamicEntity : public Entity {

	public:
		/**
		* The constructor.
		* Initializes all attributes.
		* @param x_ : position in x axis.
		* @param y_ : position in y axis.
		* @param sprite_ : which sprite to use.
		*/
		DynamicEntity(const double x_, const double y_, Sprite* const sprite_);

		/**
		* The destructor.
		*/
		virtual ~DynamicEntity();

		virtual void jump();
		virtual void applyGravity();
		virtual void move(const bool movingLeft_, const bool movingRight_);
		virtual void slowVx();
		virtual void roll();
		virtual void aim(Crosshair* const crosshair, double direction);
		virtual void useBombPotion(BombPotion* const bombPotion, const int strength, const int distance);

		/**
		* @param width_,height_ : Tells the player what the width and height of the level is.
		* @see Level::update()
		*/
		virtual void setLevelWH(const unsigned int width_, const unsigned int height_);

		virtual void setCollisionRects(const std::vector<SDL_Rect>& collisionRects_);

		double vx; /**< The dynamic entity's speed on the x axis. */
		double vy; /**< The dynamic entity's speed on the x axis. */
		double speed; /**< Speed that moves dynamic entity on input. */
		double maxSpeed; /**< Dynamic entity max speed. */		
		bool isGrounded; /**< Check for if the dynamic entity is on the ground. */

	protected:
		/**
		* Updates the position of the dynamic entity
		* Update is based on what input was recieved, and the players velocity.
		* @param dt_ : Delta time. Time elapsed between one frame and the other, independent
		* 	of processing speed.
		*/
		virtual void updatePosition(const double dt_);

		/**
		* @return A bool array with the sides the DynamicEntity collided.
		*/
		std::array<bool, CollisionSide::SOLID_TOTAL> detectCollision();

		/**
		* Handles the collision.
		*/
		virtual void handleCollision(std::array<bool, CollisionSide::SOLID_TOTAL> detections_) = 0;

		unsigned int levelW; /**< The width of the level. */
		unsigned int levelH; /**< The height of the level. */
		std::vector<SDL_Rect> collisionRects; /**< The SDL_Rects containing collidable tiles 
			positions. */

};

#endif // INCLUDE_DYNAMICENTITY_H