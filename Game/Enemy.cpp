//*--------------------------------------------------------------*//
//= @file   ���O:Enemy.cpp
//=
//= @brief  �T�v:�G�l�~�[�\�[�X
//=
//= @date   ���t:2016/2/5
//=
//= @author �����:�Ð�A��
//*--------------------------------------------------------------*//

//�w�b�_�t�@�C���̃C���N���[�h
#include "Enemy.h"
#include "GameMain.h"
#include <d3d11.h>
#include <SimpleMath.h>

//���O���
using namespace DirectX::SimpleMath;
using namespace DirectX;

//�����o�֐��̒�`
//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Enemy::Enemy()
{
	Texture* PongImage = new Texture(L"Resources\\Images\\PongImage.png");

	handle = PongImage;

	grp_x = 32;
	grp_y = 0;
	grp_w = 32;
	grp_h = 32;
	pos_x = 640;
	pos_y = (rand() % 15 + 1) * 32;
	spd_x = 0.0f;
	spd_y = 0.0f;
	state = 1;

}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Enemy::~Enemy()
{

}
