//*--------------------------------------------------------------*//
//= @file   名前:Player.cpp
//=
//= @brief  概要:プレイヤーソース
//=
//= @date   日付:2016/1/26
//=
//= @author 製作者:古川柊太
//*--------------------------------------------------------------*//

//ヘッダファイルのインクルード
#include "Player.h"
#include "GameMain.h"
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
//! @brief デストラクタ
//----------------------------------------------------------------------
Player::~Player()
{

}
