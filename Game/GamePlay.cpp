//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   ���t		2016/07/08
//!
//! @author ����Җ�	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GamePlay.h"
#include "ObjectBase.h"
#include "Player.h"

#include <time.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::GamePlay()
{
	srand((unsigned int)time(NULL));

	//�v���C���[�̓I�u�W�F�N�g�N���X�̔h���N���X�ł���
	player = new Player();
	//�G�l�~�[�|�C���^����邱�ƂŔz�񉻂����Ă���
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i] = new Enemy();
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i]->GetState() == 1)
		{
			enemy[i]->SetSpdX((rand() % 5 + 1)*-1);
		}
	}

}

//----------------------------------------------------------------------
//! @brie�@�f�X�g���N�^����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GamePlay::~GamePlay(void)
{
	delete player;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		delete enemy[i];
	}
}


//----------------------------------------------------------------------
//! @brief �Q�[���v���C����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GamePlay::Update(void)
{
	//int i;					//�J�E���^

	//�����Őݒ肷��̂͑��x

	//�L�[���͊֌W
	//�}�E�X
	player->SetSpdX(g_mouse.x - mx);
	mx = g_mouse.x;
	player->SetSpdY(g_mouse.y - my);
	my = g_mouse.y;

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i]->GetState() == 0)
		{
			enemy[i]->SetPosX(640);
			enemy[i]->SetPosY((rand() % 15 + 1) * 32);
			enemy[i]->SetState(1);
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i]->GetState() == 1)
		{
			if (enemy[i]->GetPosX() <= -32)
			{
				enemy[i]->SetState(0);
			}
		}
	}

	//�v���C���[�̍��W�ύX
	player->Update();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i]->Update();
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if ((enemy[i]->GetPosX() <= player->GetPosX() + player->GetGrpW()) &&
			(enemy[i]->GetPosX() + enemy[i]->GetGrpW() >= player->GetPosX()) &&
			(enemy[i]->GetPosY() <= player->GetPosY() + player->GetGrpH()) &&
			(enemy[i]->GetPosY() + enemy[i]->GetGrpH() >= player->GetPosY()))
		{
			g_NextScene = OVER;
		}
	}
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GamePlay::Render(void)
{
	//�v���C���[�̕`�揈��
	player->Render();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i]->Render();
	}
}
