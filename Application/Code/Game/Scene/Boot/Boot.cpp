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
	@detail	�������֐�
	@author	K.Oura
	@date	2017/10/07
*/
void Boot_Create( void )
{

	// �풓���\�[�X�̃��[�h�Ƃ�

}

/*
	@detail	�X�V�֐�
	@author	K.Oura
	@date	2017/10/07
*/
void Boot_Proc( void )
{

	// ���\�[�X���[�h�I�������
	// �f�o�b�O��
	Scene_ChangeScene( eSceneID_TestMenu );

	// �����[�X��
	Scene_ChangeScene( eSceneID_TestMenu );

}



