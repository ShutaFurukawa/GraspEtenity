//*--------------------------------------------------------------*//
//= @file   名前:Player.h
//=
//= @brief  概要:プレイヤークラス
//=
//= @date   日付:2016/1/26
//=
//= @author 製作者:古川柊太
//*--------------------------------------------------------------*//

//ヘッダファイルのインクルード
#include "ObjectBase.h"
#include <d3d11.h>
#include <SimpleMath.h>

//名前空間
using namespace DirectX::SimpleMath;
using namespace DirectX;

//メンバ関数の定義
//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//----------------------------------------------------------------------
ObjectBase::ObjectBase()
{

}

//----------------------------------------------------------------------
//! @brief デストラクタ
//----------------------------------------------------------------------
ObjectBase::~ObjectBase()
{

}

Texture* ObjectBase::GetHandle()
{
	return handle;
}

void ObjectBase::SetHandle(Texture* h)
{
	handle = h;
}

//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
//= @brief ステータスを決める
//=
//= @param[in] 各能力
//=
//= @return ステータス値
//__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|
int ObjectBase::GetGrpX()
{
	return grp_x;
}

void ObjectBase::SetGrpX(int x)
{
	grp_x = x;
}

int ObjectBase::GetGrpY()
{
	return grp_y;
}

void ObjectBase::SetGrpY(int y)
{
	grp_y = y;
}

int ObjectBase::GetGrpW()
{
	return grp_w;
}

void ObjectBase::SetGrpW(int w)
{
	grp_w = w;
}

int ObjectBase::GetGrpH()
{
	return grp_h;
}

void ObjectBase::SetGrpH(int h)
{
	grp_h = h;
}

float ObjectBase::GetPosX()
{
	return pos_x;
}

void ObjectBase::SetPosX(float x)
{
	pos_x = x;
}

float ObjectBase::GetPosY()
{
	return pos_y;
}

void ObjectBase::SetPosY(float y)
{
	pos_y = y;
}

float ObjectBase::GetSpdX()
{
	return spd_x;
}

void ObjectBase::SetSpdX(float x)
{
	spd_x = x;
}

float ObjectBase::GetSpdY()
{
	return spd_y;
}

void ObjectBase::SetSpdY(float y)
{
	spd_y = y;
}

int ObjectBase::GetState()
{
	return state;
}

void ObjectBase::SetState(int s)
{
	state = s;
}


void ObjectBase::Update()
{
	pos_x += spd_x;
	pos_y += spd_y;
}

void ObjectBase::Render()
{
	RECT rect;
	rect = { grp_x, grp_y, grp_x + grp_w, grp_y + grp_h };

	g_spriteBatch->Draw(handle->m_pTexture, Vector2(pos_x, pos_y), &rect, Colors::White, 0.0f, Vector2(grp_w / 2, grp_h / 2), 1.0f);

}