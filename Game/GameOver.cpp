//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.cpp
//!
//! @brief  �Q�[���I�[�o�[�����̃\�[�X�t�@�C��
//!
//! @date   ���t		2016/07/08
//!
//! @author ����Җ�	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "GameOver.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
GameOver::GameOver()
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
GameOver::~GameOver(void)
{

}


void GameOver::Update(void)
{

	//cnt++;

	////�X�y�[�X�L�[�_�ŗp
	//if (cnt > 120)
	//{
	//	g_NextScene = TITLE;
	//}

	//�X�y�[�X�L�[�Ń^�C�g���ɑJ��
	if (g_mouseTracker->leftButton)
	{
		g_NextScene = PLAY;

	}

}


//----------------------------------------------------------------------
//! @brief �Q�[���I�[�o�[�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void GameOver::Render(void)
{
	//RECT rect;			// �G�̍���̍��W�ƉE���̍��W�ҏW�p
	//wchar_t buf[256];	//������ҏW�p

	//rect = { 64, 224, 160, 256 };
	//g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(265, 200),
	//	&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);

	////swprintf_s(buf, 256, L"SPACE");		//������ҏW
	//if (g_TimeCnt < 100)
	//{
	//	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(280, 380));
	//	rect = { 0, 224, 64, 256 };
	//	g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(280, 380),
	//		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
	//}

	//swprintf_s(buf, 256, L"OVER");		//������ҏW
	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(100, 0));

}

