//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.h
//!
//! @brief  ゲームプレイのヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include "Player.h"
#include "Enemy.h"

#define ENEMY_MAX 20

class GamePlay :public GameBase
{
private:
	//マウス座標
	int mx;
	int my;

	Player* player;
	Enemy* enemy[ENEMY_MAX];

public:

	GamePlay();
	~GamePlay();

	void Update();
	void Render();
	
};

