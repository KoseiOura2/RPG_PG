/*---------------------------------------------------------
	@file	DebugPrint.h
			
	@author	K.Oura
	@date	2017/9/08
----------------------------------------------------------*/

#ifndef __DEBUG_PRINT_H__
#define __DEBUG_PRINT_H__


//-------------------------------------------- include
#include "CoreCommon.h"


//-------------------------------------------- function

/*
	@detail	デバッグ文字描画
	@author	K.Oura
	@date	2017/10/07
*/
s32 DebugPrint_Draw( s32 x, s32 y, s32 r, s32 g, s32 b, char* pFormat, ... );

#endif // __DEBUG_PRINT_H__
