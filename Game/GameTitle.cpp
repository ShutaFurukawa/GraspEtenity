//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.cpp
//!
//! @brief  タイトル処理のソースファイル
//!
//! @date   日付		2016/07/08
//!
//! @author 制作者名	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameTitle.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameTitle::GameTitle()
{
	cnt = 0;

}

//----------------------------------------------------------------------
//! @brie　デストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameTitle::~GameTitle(void)
{

}


//----------------------------------------------------------------------
//! @brief タイトル処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameTitle::Update(void)
{

	cnt++;

	//スペースキー点滅用
	if (cnt > 120)
	{
		g_NextScene = PLAY;

	}

	//スペースキーでプレイに遷移
	if (g_keyTracker->pressed.Space)
	{
		g_NextScene = PLAY;

	}
}

//----------------------------------------------------------------------
//! @brief タイトル描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameTitle::Render(void)
{
	//RECT rect;			// 絵の左上の座標と右下の座標編集用
	//wchar_t buf[256];	//文字列編集用

	//rect = { 0, 160, 256, 224 };
	//g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(0, 192),
	//	&rect, Colors::White, 0.0f, Vector2(0, 0), Vector2(2.5, 2.5));

	////swprintf_s(buf, 256, L"SPACE");		//文字列編集
	//if (g_TimeCnt < 100)
	//{
	//	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(280, 380));
	//	rect = { 0, 224, 64, 256 };
	//	g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(280, 380),
	//		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
	//}

}


