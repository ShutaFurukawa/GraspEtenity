//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.cpp
//!
//! @brief  ゲームクリア処理のソースファイル
//!
//! @date   日付		2016/07/08
//!
//! @author 制作者名	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GameClear.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;


//----------------------------------------------------------------------
//! @brief コンストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GameClear::GameClear()
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
GameClear::~GameClear(void)
{

}


//----------------------------------------------------------------------
//! @brief ゲームクリア処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameClear::Update(void)
{
	cnt++;

	//スペースキー点滅用
	if (cnt > 120)
	{
		cnt = 0;
	}

	//スペースキーでタイトルに遷移
	if (g_keyTracker->pressed.Space)
	{
		g_NextScene = TITLE;

	}

}


//----------------------------------------------------------------------
//! @brief ゲームクリア描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GameClear::Render(void)
{
	//RECT rect;			// 絵の左上の座標と右下の座標編集用
	//wchar_t buf[256];	//文字列編集用

	//rect = { 64, 224, 160, 256 };
	//g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(265, 200),
	//	&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);

	////swprintf_s(buf, 256, L"SPACE");		//文字列編集
	//if (g_TimeCnt < 100)
	//{
	//	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(280, 380));
	//	rect = { 0, 224, 64, 256 };
	//	g_spriteBatch->Draw(g_PongImage->m_pTexture, Vector2(280, 380),
	//		&rect, Colors::White, 0.0f, Vector2(0, 0), 1.0f);
	//}

	//swprintf_s(buf, 256, L"CLEAR");		//文字列編集
	//g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(100, 0));


}


