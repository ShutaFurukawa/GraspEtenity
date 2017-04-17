//*--------------------------------------------------------------*//
//= @file   ���O:Player.cpp
//=
//= @brief  �T�v:�v���C���[�\�[�X
//=
//= @date   ���t:2016/1/26
//=
//= @author �����:�Ð�A��
//*--------------------------------------------------------------*//

//�w�b�_�t�@�C���̃C���N���[�h
#include "Player.h"
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
Player::Player()
{
	Texture* PongImage = new Texture(L"Resources\\Images\\PongImage.png");

	handle = PongImage;

	grp_x = 0;
	grp_y = 0;
	grp_w = 32;
	grp_h = 32;
	pos_x = 0;
	pos_y = 0;
	spd_x = 0.0f;
	spd_y = 0.0f;
	state = 1;

}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
Player::~Player()
{

}
