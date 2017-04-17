//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.h
//!
//! @brief  �Q�[���v���C�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "Player.h"
#include "Enemy.h"

#define ENEMY_MAX 20

class GamePlay :public GameBase
{
private:
	//�}�E�X���W
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

