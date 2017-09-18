/*---------------------------------------------------------
	@file	Framework.h
			
	@author	K.Oura
	@date	2017/9/08
----------------------------------------------------------*/

//-------------------------------------------- include

#include "Framework.h"
#include "CoreCommon.h"
//#include <time.h>
//#include "Task.h"
//#include <typeinfo>

//-------------------------------------------- prototype

//-------------------------------------------- include
// シングルトン
Framework* Framework::_instance;

//-------------------------------------------- class

/*
	@detail	コンストラクタ
	@author	K.Oura
	@date	2017/09/08
*/
Framework::Framework( ) {

}

/*
	@detail	デストラクタ
	@author	K.Oura
	@date	2017/09/08
*/
Framework::~Framework( ) {
}

/*
	@detail	初期化
	@author	K.Oura
	@date	2017/09/08
*/
void Framework::Initialize( ) {
	if ( !_instance ) {
		_instance = new Framework;
	}

	// 乱数
	//srand( ( unsigned int ) time ( NULL ) );

	//画面サイズ設定 640 * 480固定で
	SetGraphMode( 640, 480, 32 );
	SetMouseDispFlag( TRUE );
	/*if ( SetGraphMode( 1920, 1080, 32 ) != DX_CHANGESCREEN_OK ) {
		 return -1;
	}*/
	
	//ウィンドウモード
	ChangeWindowMode( TRUE );
	// DxLibの2重起動確認:: TRUE:2重起動可能 FALSE:不可能
	SetDoubleStartValidFlag( FALSE ); 
	// メインウィンドウのアクティブ確認
	SetAlwaysRunFlag( TRUE );

	if ( DxLib_Init( ) == -1 ) {		// ＤＸライブラリ初期化処理
		return;			// エラーが起きたら直ちに終了
	}

	//SetDrawArea( 0, 0, 1920 / 2, 1080 / 2 );
	SetDrawScreen( DX_SCREEN_BACK );
	SetUseBackCulling( TRUE );

	SetChangeScreenModeGraphicsSystemResetFlag( FALSE );
}

/*
	@detail	末期化
	@author	K.Oura
	@date	2017/09/08
*/
void Framework::Finalize( ) {

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理
	if ( _instance ) {
		//_instance.reset( );
	}
}

/*
	@detail	インスタンスの取得
	@author	K.Oura
	@date	2017/09/08
*/
Framework* Framework::GetInstance( ) {
	return _instance;
}

/*
	@detail	メインループ
	@author	K.Oura
	@date	2017/09/08
*/
void Framework::Run( ) {
	
	// メインループ
	while ( true ) {
		// エラー
		if ( ProcessMessage( ) == -1 ) {
			break;
		}
		// ESCで終了
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
			break;
		}

		// 更新
		_ProcFunc( );

		// 描画
		_DrawFunc( );

	}
}

/*
	@detail	更新関数を登録
	@author	K.Oura
	@date	2017/09/18
*/
void Framework::SetProcFunc( void ( *Func )( void ) )
{
	_ProcFunc = Func;
}

/*
	@detail	描画関数を登録
	@author	K.Oura
	@date	2017/09/18
*/
void Framework::SetDrawFunc( void ( *Func )( void ) )
{
	_DrawFunc = Func;
}

//void Framework::initializeAllTask( ) {
//	std::map< std::string, TaskPtr >::iterator it = _task_map.begin( );
//	while ( it != _task_map.end( ) ) {
//		TaskPtr task = it->second;
//		task->initialize( );
//		it++;
//	}
//}
//
//void Framework::finalizeAllTask( ) {
//	std::map< std::string, TaskPtr >::iterator it = _task_map.begin( );
//	while ( it != _task_map.end( ) ) {
//		TaskPtr task = it->second;
//		task->finalize( );
//		it++;
//	}
//}
//
//void Framework::loopAllTask( ) {
//	while ( true ) {
//		if ( ProcessMessage( ) == -1 ) {
//			break;
//		}
//		if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
//			break;
//		}
//		//タスクを回す
//		std::map< std::string, TaskPtr >::iterator it = _task_map.begin( );
//		while ( it != _task_map.end( ) ) {
//			TaskPtr task = it->second;
//			task->update( );
//			it++;
//		}
//		if ( _end ) {
//			break;
//		}
//	}
//}
//
//void Framework::addTask( TaskPtr task ) {
//	if ( task ) {
//		_task_map[ typeid( *task ).name( ) ] = task;
//	}
//}
//
//TaskPtr Framework::getTask( std::string type ) {
//    if ( _task_map.find( type ) == _task_map.end( ) ) {
//        return TaskPtr( );
//    }
//	return _task_map[ type ];
//}
