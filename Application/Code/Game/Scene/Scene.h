/*---------------------------------------------------------
	@file	Scene.h
			
	@author	K.Oura
	@date	2017/10/07
----------------------------------------------------------*/

#ifndef __SCENE_H__
#define __SCENE_H__


//-------------------------------------------- include
#include "Game/Common/GameCommon.h"

//-------------------------------------------- enum

enum eSceneID {
	eSceneID_None = -1,

	eSceneID_Boot,

	
#ifdef DEBUG
	eSceneID_TestMenu,
#endif // DEBUG

	eSceneID_Num
};

//-------------------------------------------- function

/*
	@detail	シーンの初期化関数
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_InitFunc( void );

/*
	@detail	シーンの更新関数
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_ProcFunc( void );

/*
	@detail	シーンの描画関数
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_DrawFunc( void );



//-------------------------------------------------------------------------------

/*
	@detail	シーンの切り替え
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_ChangeScene( eSceneID NextScene );

/*
	@detail	現在のシーンを取得
	@author	K.Oura
	@date	2017/10/07
*/
eSceneID Scene_GetNowScene( void );

/*
	@detail	前のシーンを取得
	@author	K.Oura
	@date	2017/10/07
*/
eSceneID Scene_GetPrevScene( void );

#endif // __SCENE_H__

