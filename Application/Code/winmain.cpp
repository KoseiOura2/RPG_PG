/*---------------------------------------------------------
	@file	winmain.cpp
			
	@author	K.Oura
	@date	2017/9/08
----------------------------------------------------------*/

//-------------------------------------------- include
#include <Windows.h>
#include "Core.h"
#include "Game/GameMain.h"


//-------------------------------------------- prototype
int Initialize( );


//-------------------------------------------- function
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) 
{

	if ( Initialize( ) == -1 ) {
		return -1;
	}

	Framework::GetInstance( )->Run( );

	Framework::Finalize( );

	return 0 ;				// �\�t�g�̏I�� 

}

int Initialize( ) 
{

	// FrameWork�̏�����
	Framework::Initialize( );

	// �֐��̓o�^
	Framework::GetInstance( )->SetProcFunc( &GameMain_ProcFunc );
	Framework::GetInstance( )->SetDrawFunc( &GameMain_DrawFunc );

	return 0;

}
