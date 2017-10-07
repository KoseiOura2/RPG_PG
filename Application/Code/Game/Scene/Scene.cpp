/*---------------------------------------------------------
	@file	Scene.cpp
			
	@author	K.Oura
	@date	2017/10/07
----------------------------------------------------------*/

//-------------------------------------------- include
#include "Scene.h"

// �e�V�[��
#include "Boot/Boot.h"
#include "Test/TestMenu.h"

//-------------------------------------------- struct
typedef struct {
	char*	SceneName;						// �V�[����
	void	( *CreateFunc )( void );		// �����֐�
	void	( *ProcFunc )( void );			// �X�V�֐�
	void	( *DrawFunc )( void );			// �`��֐�
	void	( *EndFunc )( void );			// �I���֐�
	BOOL	( *IsEndFunc )( void );			// �I���擾�֐�

} SCENE_ITEM_MENU;

//-------------------------------------------- macro
#define SCENE_ITEM_MENU_NUM			( eSceneID_Num )

//-------------------------------------------- table
static SCENE_ITEM_MENU	s_SceneItemMenuTbl[ SCENE_ITEM_MENU_NUM ] = {
	//	�V�[����		�����֐�				�X�V�֐�			�`��֐�			�I���֐�	�I���擾�֐�
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
	@detail	�V�[���̏������֐�
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_InitFunc( void )
{

	s_NowScene = eSceneID_Boot;

	// �V�[���̐���
	if ( s_SceneItemMenuTbl[ s_NowScene ].CreateFunc ) {
		s_SceneItemMenuTbl[ s_NowScene ].CreateFunc( );
	}

}

/*
	@detail	�V�[���̍X�V�֐�
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_ProcFunc( void )
{

	if ( s_NextScene == eSceneID_None ) {
		// �X�V����
		if ( s_SceneItemMenuTbl[ s_NowScene ].ProcFunc ) {
			s_SceneItemMenuTbl[ s_NowScene ].ProcFunc( );
		}
	} else {
		// �V�[���؂�ւ�����
		if ( s_NowScene != s_PrevScene ) {
			// �t�F�[�h�A�E�g���ꂽ��

			s_PrevScene = s_NowScene;

			// �V�[���̍폜
			if ( s_SceneItemMenuTbl[ s_NowScene ].EndFunc ) {
				s_SceneItemMenuTbl[ s_NowScene ].EndFunc( );
			}

		} else {
			// �V�[���̍폜������������
			if ( s_SceneItemMenuTbl[ s_NowScene ].IsEndFunc ) {
				if ( s_SceneItemMenuTbl[ s_NowScene ].IsEndFunc( ) ) {
					// �t�F�[�h�C�����ꂽ��

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
	@detail	�V�[���̕`��֐�
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_DrawFunc( void )
{

	if ( s_NextScene == eSceneID_None ) {
		// �X�V����
		if ( s_SceneItemMenuTbl[ s_NowScene ].DrawFunc ) {
			s_SceneItemMenuTbl[ s_NowScene ].DrawFunc( );
		}
	}


	DebugPrint_Draw( 0, 0, 255, 255, 255, s_SceneItemMenuTbl[ s_NowScene ].SceneName );

}



//-------------------------------------------------------------------------------

/*
	@detail	�V�[���̐؂�ւ�
	@author	K.Oura
	@date	2017/10/07
*/
void Scene_ChangeScene( eSceneID NextScene )
{
	s_NextScene = NextScene;
}

/*
	@detail	���݂̃V�[�����擾
	@author	K.Oura
	@date	2017/10/07
*/
eSceneID Scene_GetNowScene( void )
{
	return s_NowScene;
}

/*
	@detail	�O�̃V�[�����擾
	@author	K.Oura
	@date	2017/10/07
*/
eSceneID Scene_GetPrevScene( void )
{
	return s_PrevScene;
}

