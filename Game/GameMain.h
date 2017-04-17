//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
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


// 定数の定義 ==============================================================

// ゲームタイトル
#define GAME_TITLE "Sokoban"

// ゲーム画面
#define SCREEN_WIDTH  640    // 幅[pixel]
#define SCREEN_HEIGHT 480    // 高さ[pixel]

#define MAX_TIP 300

//　構造体宣言
typedef struct tag_object
{
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

}OBJECT;					//オブジェクト用

//　列挙型宣言
enum SCENE
{
	BASE,
	LOGO,
	TITLE,
	PLAY,
	CLEAR,
	OVER
};

// 関数の宣言 ==============================================================
// ゲームの初期化処理
void InitializeGame(void);

// ゲームの更新処理
void UpdateGame(void);

// ゲームの描画処理
void RenderGame(void);

// ゲームの終了処理
void FinalizeGame(void);

//　数値描画処理
void DrawNum(int x, int y, int n);


// グローバル変数の定義 ====================================================
EXTERN Texture *g_grpHandle;		//　グラフィック
EXTERN Texture *g_PongImage;		//　ポン画像

EXTERN int g_map[15][20];	//	マップデータ
EXTERN OBJECT g_tip[MAX_TIP];		//　マップチップ

EXTERN OBJECT g_player;				//　プレイヤ
EXTERN int g_r;						//　現在行
EXTERN int g_c;						//　現在列

EXTERN OBJECT g_box[10];			//　箱
EXTERN int g_boxCnt;				//　箱の数

EXTERN int g_scene;					//シーン管理
EXTERN int g_NextScene;				//次のシーン

EXTERN int g_TimeCnt;				//時間カウンタ
EXTERN int g_Time;					//秒数
