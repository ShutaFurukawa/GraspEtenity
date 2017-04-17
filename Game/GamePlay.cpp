//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  ゲームプレイ処理のソースファイル
//!
//! @date   日付		2016/07/08
//!
//! @author 制作者名	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "GamePlay.h"
#include "ObjectBase.h"
#include "Player.h"

#include <time.h>

using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief コンストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::GamePlay()
{
	srand((unsigned int)time(NULL));

	//プレイヤーはオブジェクトクラスの派生クラスである
	player = new Player();
	//エネミーポインタを作ることで配列化をしている
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i] = new Enemy();
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i]->GetState() == 1)
		{
			enemy[i]->SetSpdX((rand() % 5 + 1)*-1);
		}
	}

}

//----------------------------------------------------------------------
//! @brie　デストラクタ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
GamePlay::~GamePlay(void)
{
	delete player;
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		delete enemy[i];
	}
}


//----------------------------------------------------------------------
//! @brief ゲームプレイ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GamePlay::Update(void)
{
	//int i;					//カウンタ

	//ここで設定するのは速度

	//キー入力関係
	//マウス
	player->SetSpdX(g_mouse.x - mx);
	mx = g_mouse.x;
	player->SetSpdY(g_mouse.y - my);
	my = g_mouse.y;

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i]->GetState() == 0)
		{
			enemy[i]->SetPosX(640);
			enemy[i]->SetPosY((rand() % 15 + 1) * 32);
			enemy[i]->SetState(1);
		}
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (enemy[i]->GetState() == 1)
		{
			if (enemy[i]->GetPosX() <= -32)
			{
				enemy[i]->SetState(0);
			}
		}
	}

	//プレイヤーの座標変更
	player->Update();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i]->Update();
	}
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if ((enemy[i]->GetPosX() <= player->GetPosX() + player->GetGrpW()) &&
			(enemy[i]->GetPosX() + enemy[i]->GetGrpW() >= player->GetPosX()) &&
			(enemy[i]->GetPosY() <= player->GetPosY() + player->GetGrpH()) &&
			(enemy[i]->GetPosY() + enemy[i]->GetGrpH() >= player->GetPosY()))
		{
			g_NextScene = OVER;
		}
	}
}

//----------------------------------------------------------------------
//! @brief ゲームプレイ描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void GamePlay::Render(void)
{
	//プレイヤーの描画処理
	player->Render();
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i]->Render();
	}
}
