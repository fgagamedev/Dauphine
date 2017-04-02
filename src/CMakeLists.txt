# Directories
include_directories(${Dauphine_SOURCE_DIR}/include ${SYSTEM_LIB_DIR}/SDL2/include)
link_directories(${SYSTEM_LIB_DIR}/SDL2/lib)

# Game library and executable
add_library(DauphineLib Animation.cpp AudioHandler.cpp Boss.cpp BStateAttack.cpp BStateIcePrision.cpp BStateIdle.cpp BStateMagicProjectile.cpp BStateShield.cpp BStateTeleport.cpp Camera.cpp Collision.cpp CollisionRect.cpp Configuration.cpp ControllerHandler.cpp Crosshair.cpp Document.cpp DynamicEntity.cpp Enemy.cpp Entity.cpp EStateAerial.cpp EStateAlert.cpp EStateAttack.cpp EStateCurious.cpp EStateDead.cpp EStateIdle.cpp EStatePatrolling.cpp FadeHandler.cpp FadeScreen.cpp FPSWrapper.cpp Game.cpp GameSave.cpp GStateContinue.cpp GStateCredits.cpp GStateGameOver.cpp GStateMenu.cpp GStateNewGame.cpp GStateOptions.cpp GStateSplash.cpp GStateTransition.cpp GStateVictory.cpp InputHandler.cpp LevelBoss.cpp Level.cpp LevelFive.cpp LevelFour.cpp LevelOne.cpp LevelThree.cpp LevelTwo.cpp Logger.cpp LuaScript.cpp Math.cpp Player.cpp PlayerHUD.cpp Potion.cpp PStateAerial.cpp PStateAiming.cpp PStateAttack.cpp PStateAttackJumping.cpp PStateAttackMoving.cpp PStateClimbing.cpp PStateCrouching.cpp PStateDead.cpp PStateHit.cpp PStateIdle.cpp PStateMoving.cpp PStateMovingCrouch.cpp PStateRolling.cpp QuadTree.cpp ResourceManager.cpp SDLWrapper.cpp Sprite.cpp StateBoss.cpp StateEnemy.cpp StateGame.cpp StatePlayer.cpp Text.cpp TileMap.cpp Util.cpp Window.cpp)
add_executable(Dauphine main.cpp)
target_link_libraries(Dauphine DauphineLib ${SYSTEM_LIBRARIES})

# Install files and directories
#install(TARGETS Jack_the_Janitor DESTINATION jtj/bin)
#install(PROGRAMS ${SYSTEM_DIR}/JackTheJanitor DESTINATION .)
#install(DIRECTORY ${SYSTEM_BIN_DIR}/lib/ DESTINATION jtj/lib)
#install(DIRECTORY ${ROOT_DIR}/resources DESTINATION jtj/)
