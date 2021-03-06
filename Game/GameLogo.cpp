//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.cpp
//!
//! @brief  ロゴ処理のソースファイル
//!
//! @date   日付		2016/07/08
//!
//! @author 制作者名	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameLogo.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameLogo::GameLogo()
{
	cnt = 0;
	p = new int[5];				//メモリーリーク検証用
}

//----------------------------------------------------------------------
//! @brie　デストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameLogo::~GameLogo(void)
{
	delete p;					//メモリーリーク検証用
}

//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameLogo::Update(void)
{
	cnt++;

	//トライデントロゴを６０フレーム
	if (cnt > 180)
	{
		g_NextScene = TITLE;
	}
}

//----------------------------------------------------------------------
//! @brief 描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameLogo::Render(void)
{
	RECT rect;	// 絵の左上の座標と右下の座標編集用
	//　ロゴを描画する 
	rect = { 0,0,256,256 };
	g_spriteBatch->Draw(g_grpHandle->m_pTexture, Vector2(60, 16),
						&rect,Colors::White,0.0f,Vector2(0,0),Vector2(2.0f,2.0f));
	//else
	//{
	//	rect = { 0, 96, 256, 160 };
	//	g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(0, 100),
	//		&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(6.0, 6.0));
	//}
}

