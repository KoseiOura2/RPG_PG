/*---------------------------------------------------------
	@file	Boot.cpp
			
	@author	K.Oura
	@date	2017/10/07
----------------------------------------------------------*/

//-------------------------------------------- include
#include "Boot.h"

#include "Game/Scene/Scene.h"

//-------------------------------------------- function

/*
	@detail	初期化関数
	@author	K.Oura
	@date	2017/10/07
*/
void Boot_Create( void )
{

	// 常駐リソースのロードとか

}

/*
	@detail	更新関数
	@author	K.Oura
	@date	2017/10/07
*/
void Boot_Proc( void )
{

	// リソースロード終わったら
	// デバッグ時
	Scene_ChangeScene( eSceneID_TestMenu );

	// リリース時
	Scene_ChangeScene( eSceneID_TestMenu );

}



