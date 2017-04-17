//*--------------------------------------------------------------*//
//= @file   ���O:Player.h
//=
//= @brief  �T�v:�v���C���[�N���X
//=
//= @date   ���t:2016/1/26
//=
//= @author �����:�Ð�A��
//*--------------------------------------------------------------*//

//�w�b�_�t�@�C���̑��d�C���N���[�h�h�~
#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include "..\Texture.h"
#include "..\DirectXTK.h"

//�N���X�̒�`
class ObjectBase
{
	//������J�����o
protected:
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

	//���J�����o
public:
	//�R���X�g���N�^
	ObjectBase();
	//�f�X�g���N�^
	~ObjectBase();

	//�����o�֐�
	Texture* GetHandle();
	void SetHandle(Texture* h);
	int GetGrpX();
	void SetGrpX(int x);
	int GetGrpY();
	void SetGrpY(int y);
	int GetGrpW();
	void SetGrpW(int w);
	int GetGrpH();
	void SetGrpH(int h);
	float GetPosX();
	void SetPosX(float x);
	float GetPosY();
	void SetPosY(float y);
	float GetSpdX();
	void SetSpdX(float sx);
	float GetSpdY();
	void SetSpdY(float sy);
	int GetState();
	void SetState(int state);

	void Update();
	void Render();
};