/*---------------------------------------------------------
	@file	Scene.cpp
			
	@author	K.Oura
	@date	2017/10/07
----------------------------------------------------------*/

//-------------------------------------------- include
#include "Scene.h"

// 各シーン
#include "Boot/Boot.h"
#include "Test/TestMenu.h"

//-------------------------------------------- struct
typedef struct {
	char*	SceneName;						// シーン名
	void	( *CreateFunc )( void );		// 生成関数
	void	( *ProcFunc )( void );			// 更新関数
	void	( *DrawFunc )( void );			// 描画関数
	void	( *EndFunc )( void );			// 終了関数
	BOOL	( *IsEndFunc )( void );			// 終了取得関数

} SCENE_ITEM_MENU;

//-------------------------------------------- macro
#define SCENE_ITEM_MENU_NUM			( eSceneID_Num )

//-------------------------------------------- table
static SCENE_ITEM_MENU	s_SceneItemMenuTbl[ SCENE_ITEM_MENU_NUM ] = {
	//	シーン名		生成関数				更新関数			描画関数			終了関数	終了取得関数
	{	"Boot",			Boot_Create,			Boot_Proc,			NULL,				NULL,		NULL			 },

#ifdef DEBUG
	{	"TestMenu",		TestMenu_Create,		TestMenu_Proc,		TestMenu_Draw,		NULL,		NULL			 },
#endif // DEBUG
};

//-------------------------------------------- function
static eSceneID s_NowScene	= eSceneID_None;
static eSceneID s_NextScene	= eSceneID_None;
static eSceneID s_PrevScene	= eSceneID_None;

//-------------------------------------------- function

/*
	@detail	シーンの初期化関数
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_InitFunc( void )
{

	s_NowScene = eSceneID_Boot;

	// シーンの生成
	if ( s_SceneItemMenuTbl[ s_NowScene ].CreateFunc ) {
		s_SceneItemMenuTbl[ s_NowScene ].CreateFunc( );
	}

}

/*
	@detail	シーンの更新関数
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_ProcFunc( void )
{

	if ( s_NextScene == eSceneID_None ) {
		// 更新処理
		if ( s_SceneItemMenuTbl[ s_NowScene ].ProcFunc ) {
			s_SceneItemMenuTbl[ s_NowScene ].ProcFunc( );
		}
	} else {
		// シーン切り替え処理
		if ( s_NowScene != s_PrevScene ) {
			// フェードアウト入れたい

			s_PrevScene = s_NowScene;

			// シーンの削除
			if ( s_SceneItemMenuTbl[ s_NowScene ].EndFunc ) {
				s_SceneItemMenuTbl[ s_NowScene ].EndFunc( );
			}

		} else {
			// シーンの削除が完了したら
			if ( s_SceneItemMenuTbl[ s_NowScene ].IsEndFunc ) {
				if ( s_SceneItemMenuTbl[ s_NowScene ].IsEndFunc( ) ) {
					// フェードイン入れたい

					s_NowScene	= s_NextScene;
					s_NextScene = eSceneID_None;
				}
			} else {
				s_NowScene	= s_NextScene;
				s_NextScene = eSceneID_None;
			}
		}
	}

}

/*
	@detail	シーンの描画関数
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_DrawFunc( void )
{

	if ( s_NextScene == eSceneID_None ) {
		// 更新処理
		if ( s_SceneItemMenuTbl[ s_NowScene ].DrawFunc ) {
			s_SceneItemMenuTbl[ s_NowScene ].DrawFunc( );
		}
	}


	DebugPrint_Draw( 0, 0, 255, 255, 255, s_SceneItemMenuTbl[ s_NowScene ].SceneName );

}



//-------------------------------------------------------------------------------

/*
	@detail	シーンの切り替え
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_ChangeScene( eSceneID NextScene )
{
	s_NextScene = NextScene;
}

/*
	@detail	現在のシーンを取得
	@author	K.Oura
	@date	2017/10/07
*/
eSceneID Scene_GetNowScene( void )
{
	return s_NowScene;
}

/*
	@detail	前のシーンを取得
	@author	K.Oura
	@date	2017/10/07
*/
eSceneID Scene_GetPrevScene( void )
{
	return s_PrevScene;
}

