//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.h
//!
//! @brief  �Q�[���N���A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once


class GameClear :public GameBase
{
private:
	int cnt;

public:

	GameClear();
	~GameClear();

	void Update();
	void Render();
	
};

