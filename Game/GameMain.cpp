//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付		2016/07/08
//!
//! @author 制作者名	T.Hasegawa
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
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

// プロトタイプ宣言 ====================================================
void importData(string filename);


// グローバル変数の定義 ====================================================
GameBase *base;


// 関数の定義 ==============================================================

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializeGame(void)
{
	int i;			//カウンタ

	importData("map.csv");
	//　画像の読み込み 
	g_grpHandle = new Texture(L"Resources\\Images\\TridentLogo.png");
	g_PongImage = new Texture(L"Resources\\Images\\PongImage.png");

	//音の読み込み
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
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateGame(void)
{
	ADX2Le::Update();

	//シーン管理
	if (g_scene != g_NextScene)
	{
		g_scene = g_NextScene;

		//シーン削除
		//delete base;
		//シーン生成
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
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderGame(void)
{
	base->Render();
}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	ADX2Le::Finalize();
	//delete base;
}


//----------------------------------------------------------------------
//! @brief 数値描画処理
//!
//! @param[in] xy座標，数値w
//!
//! @return なし
//----------------------------------------------------------------------
void DrawNum(int x, int y, int n)
{
	int w = n;		//計算用
	int i = 0;		//文字数

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
//! @brief CSVファイルの読み込み
//!
//! @param[in] ファイル名
//!
//! @return なし
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

		//1行のうち、文字列とコンマを分割する
		while (getline(stream, token, ',')){
			//すべて文字列として読み込まれるため
			//数値は変換が必要
			g_map[i / 20][i % 20] = atoi(token.c_str());
			i++;
		}
		g_map[i / 20][i % 20] = atoi(token.c_str());
	}
}



