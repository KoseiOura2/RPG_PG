/*---------------------------------------------------------
	@file	DebugPrint.cpp
			
	@author	K.Oura
	@date	2017/10/07
----------------------------------------------------------*/

//-------------------------------------------- include
#include "DebugPrint.h"

//-------------------------------------------- function


/*
	@detail	デバッグ文字描画
	@author	K.Oura
	@date	2017/10/07
*/
s32 DebugPrint_Draw( s32 x, s32 y, s32 r, s32 g, s32 b, char* pFormat, ... )
{

	// 描画テスト
	//DrawBox( 0 , 0 , 100, 100, GetColor( 255,0,0 ) , TRUE ) ;

	va_list list;
	va_start( list, pFormat );

	s32 success = DrawFormatString( x, y, GetColor( r, g, b ), pFormat, list );

	va_end( list );

	return 0;
}



