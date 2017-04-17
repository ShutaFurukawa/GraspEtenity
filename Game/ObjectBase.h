//*--------------------------------------------------------------*//
//= @file   名前:Player.h
//=
//= @brief  概要:プレイヤークラス
//=
//= @date   日付:2016/1/26
//=
//= @author 製作者:古川柊太
//*--------------------------------------------------------------*//

//ヘッダファイルの多重インクルード防止
#pragma once

//ヘッダファイルのインクルード
#include "..\Texture.h"
#include "..\DirectXTK.h"

//クラスの定義
class ObjectBase
{
	//限定公開メンバ
protected:
	Texture *handle;		//グラフィックハンドル 
	int grp_x;				//元画像のｘ座標 
	int grp_y;				//元画像のｙ座標 
	int grp_w;				//元画像の幅 
	int grp_h;				//元画像の高さ 
	float pos_x;			//座標x 
	float pos_y;			//座標y 
	float spd_x;			//速度x 
	float spd_y;			//速度y 
	int state;				//状態

	//公開メンバ
public:
	//コンストラクタ
	ObjectBase();
	//デストラクタ
	~ObjectBase();

	//メンバ関数
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