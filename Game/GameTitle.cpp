//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  �^�C�g�������̃\�[�X�t�@�C��
//!
//! @date   ���t		2016/07/08
//!
//! @author ����Җ�	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameTitle.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameTitle::GameTitle()
{
	cnt = 0;

}

//----------------------------------------------------------------------
//! @brie�@�f�X�g���N�^����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameTitle::~GameTitle(void)
{

}


//----------------------------------------------------------------------
//! @brief �^�C�g������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameTitle::Update(void)
{

	cnt++;

	//�X�y�[�X�L�[�_�ŗp
	if (cnt > 120)
	{
		g_NextScene = PLAY;

	}

	//�X�y�[�X�L�[�Ńv���C�ɑJ��
	if (g_keyTracker->pressed.Space)
	{
		g_NextScene = PLAY;

	}
}

//----------------------------------------------------------------------
//! @brief �^�C�g���`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameTitle::Render(void)
{
	//RECT rect;			// �G�̍���̍��W�ƉE���̍��W�ҏW�p
	//wchar_t buf[256];	//������ҏW�p

	//rect = { 0, 160, 256, 224 };
	//g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(0, 192),
	//	&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(2.5, 2.5));

	////swprintf_s(buf, 256, L"SPACE");		//������ҏW
	//if (g_TimeCnt < 100)
	//{
	//	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(280, 380));
	//	rect = { 0, 224, 64, 256 };
	//	g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(280, 380),
	//		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
	//}

}


