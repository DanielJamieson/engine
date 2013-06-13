#pragma once

#include "..\Engine\Interfaces\Scene.h"
#include "..\Engine\Crosshair.h"
#include "..\Engine\Player.h"

namespace scenes {

class GameScene : public engine::Scene
{
public:
	typedef engine::Scene super;

	virtual int init();
	virtual int UpdateGame(float delta);

	virtual void pause();
	virtual void resume();

	GameScene(void);
	virtual ~GameScene(void);

protected:
	game::Crosshair*	crosshair;
	game::Player*		player;
};

};