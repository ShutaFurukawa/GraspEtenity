//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t		2016/07/08
//!
//! @author ����Җ�	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#define _GAMEMAIN_
#include "GameMain.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

#include "..\ADX2Le.h"
#include "CueSheet_0.h"

#include "GameLogo.h"
#include "GameTitle.h"
#include "GamePlay.h"
#include "GameClear.h"
#include "GameOver.h"

#pragma comment(lib,"cri_ware_pcx86_LE_import.lib")

using namespace DirectX::SimpleMath;
using namespace DirectX;
using namespace std;

// �v���g�^�C�v�錾 ====================================================
void importData(string filename);


// �O���[�o���ϐ��̒�` ====================================================
GameBase *base;


// �֐��̒�` ==============================================================

//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializeGame(void)
{
	int i;			//�J�E���^

	importData("map.csv");
	//�@�摜�̓ǂݍ��� 
	g_grpHandle = new Texture(L"Resources\\Images\\TridentLogo.png");
	g_PongImage = new Texture(L"Resources\\Images\\PongImage.png");

	//���̓ǂݍ���
	//g_se = LoadSoundMem("Resources\\Sounds\\SE00.ogg");
	ADX2Le::Initialize("Resources\\Sounds\\NewProject.acf");
	ADX2Le::LoadAcb("Resources\\Sounds\\CueSheet_0.acb");
	ADX2Le::Play(CRI_CUESHEET_0__CUE_ID_0);

	g_scene = PLAY;
	g_NextScene = g_scene;
	//g_init = 0;

	base = new GamePlay();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	ADX2Le::Update();

	//�V�[���Ǘ�
	if (g_scene != g_NextScene)
	{
		g_scene = g_NextScene;

		//�V�[���폜
		//delete base;
		//�V�[������
		switch (g_scene)
		{
		case LOGO:
			base = new GameLogo();
			break;
		case TITLE:
			base = new GameTitle();
			break;
		case PLAY:
			base = new GamePlay();
			break;
		case CLEAR:
			base = new GameClear();
			break;
		case OVER:
			base = new GameOver();
			break;

		}

	}


	base->Update();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{
	base->Render();
}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	ADX2Le::Finalize();
	//delete base;
}


//----------------------------------------------------------------------
//! @brief ���l�`�揈��
//!
//! @param[in] xy���W�C���lw
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void DrawNum(int x, int y, int n)
{
	int w = n;		//�v�Z�p
	int i = 0;		//������

	if (w == 0)
	{
	//	//DrawRectGraph(x, y, 0, 48, 25, 32, g_PongImage, TRUE, FALSE);
	}
	else
	{
		while (w)
		{
	//		//DrawRectGraph(x - i * 25, y,
	//		//	(w % 10) * 25, 48, 25, 32, g_PongImage, TRUE, FALSE);
			w = w / 10;
			i++;
		}
	}

}

//----------------------------------------------------------------------
//! @brief CSV�t�@�C���̓ǂݍ���
//!
//! @param[in] �t�@�C����
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void importData(string filename)
{
	ifstream ifs(filename);
	string str;
	int i;

	if (!ifs) {
		for (i = 0; i < MAX_TIP; i++)
		{
			g_map[i / 20][i % 20] = 4;
		}
		return;
	}

	i = 0;
	while (getline(ifs, str)){
		string token;
		istringstream stream(str);

		//1�s�̂����A������ƃR���}�𕪊�����
		while (getline(stream, token, ',')){
			//���ׂĕ�����Ƃ��ēǂݍ��܂�邽��
			//���l�͕ϊ����K�v
			g_map[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		g_map[i / 20][i % 20] = atoi(token.c_str());
	}
}



