//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#ifndef _GAMEMAIN_
#define EXTERN extern
#else
#define EXTERN
#endif


#include <windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "..\DirectXTK.h"
#include "..\Texture.h"
#include "GameBase.h"


// �萔�̒�` ==============================================================

// �Q�[���^�C�g��
#define GAME_TITLE "Sokoban"

// �Q�[�����
#define SCREEN_WIDTH  640    // ��[pixel]
#define SCREEN_HEIGHT 480    // ����[pixel]

#define MAX_TIP 300

//�@�\���̐錾
typedef struct tag_object
{
	Texture *handle;		//�O���t�B�b�N�n���h�� 
	int grp_x;				//���摜�̂����W 
	int grp_y;				//���摜�̂����W 
	int grp_w;				//���摜�̕� 
	int grp_h;				//���摜�̍��� 
	float pos_x;			//���Wx 
	float pos_y;			//���Wy 
	float spd_x;			//���xx 
	float spd_y;			//���xy 
	int state;				//���

}OBJECT;					//�I�u�W�F�N�g�p

//�@�񋓌^�錾
enum SCENE
{
	BASE,
	LOGO,
	TITLE,
	PLAY,
	CLEAR,
	OVER
};

// �֐��̐錾 ==============================================================
// �Q�[���̏���������
void InitializeGame(void);

// �Q�[���̍X�V����
void UpdateGame(void);

// �Q�[���̕`�揈��
void RenderGame(void);

// �Q�[���̏I������
void FinalizeGame(void);

//�@���l�`�揈��
void DrawNum(int x, int y, int n);


// �O���[�o���ϐ��̒�` ====================================================
EXTERN Texture *g_grpHandle;		//�@�O���t�B�b�N
EXTERN Texture *g_PongImage;		//�@�|���摜

EXTERN int g_map[15][20];	//	�}�b�v�f�[�^
EXTERN OBJECT g_tip[MAX_TIP];		//�@�}�b�v�`�b�v

EXTERN OBJECT g_player;				//�@�v���C��
EXTERN int g_r;						//�@���ݍs
EXTERN int g_c;						//�@���ݗ�

EXTERN OBJECT g_box[10];			//�@��
EXTERN int g_boxCnt;				//�@���̐�

EXTERN int g_scene;					//�V�[���Ǘ�
EXTERN int g_NextScene;				//���̃V�[��

EXTERN int g_TimeCnt;				//���ԃJ�E���^
EXTERN int g_Time;					//�b��
