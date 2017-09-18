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
// �V���O���g��
Framework* Framework::_instance;

//-------------------------------------------- class

/*
	@detail	�R���X�g���N�^
	@author	K.Oura
	@date	2017/09/08
*/
Framework::Framework( ) {

}

/*
	@detail	�f�X�g���N�^
	@author	K.Oura
	@date	2017/09/08
*/
Framework::~Framework( ) {
}

/*
	@detail	������
	@author	K.Oura
	@date	2017/09/08
*/
void Framework::Initialize( ) {
	if ( !_instance ) {
		_instance = new Framework;
	}

	// ����
	//srand( ( unsigned int ) time ( NULL ) );

	//��ʃT�C�Y�ݒ� 640 * 480�Œ��
	SetGraphMode( 640, 480, 32 );
	SetMouseDispFlag( TRUE );
	/*if ( SetGraphMode( 1920, 1080, 32 ) != DX_CHANGESCREEN_OK ) {
		 return -1;
	}*/
	
	//�E�B���h�E���[�h
	ChangeWindowMode( TRUE );
	// DxLib��2�d�N���m�F:: TRUE:2�d�N���\ FALSE:�s�\
	SetDoubleStartValidFlag( FALSE ); 
	// ���C���E�B���h�E�̃A�N�e�B�u�m�F
	SetAlwaysRunFlag( TRUE );

	if ( DxLib_Init( ) == -1 ) {		// �c�w���C�u��������������
		return;			// �G���[���N�����璼���ɏI��
	}

	//SetDrawArea( 0, 0, 1920 / 2, 1080 / 2 );
	SetDrawScreen( DX_SCREEN_BACK );
	SetUseBackCulling( TRUE );

	SetChangeScreenModeGraphicsSystemResetFlag( FALSE );
}

/*
	@detail	������
	@author	K.Oura
	@date	2017/09/08
*/
void Framework::Finalize( ) {

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������
	if ( _instance ) {
		//_instance.reset( );
	}
}

/*
	@detail	�C���X�^���X�̎擾
	@author	K.Oura
	@date	2017/09/08
*/
Framework* Framework::GetInstance( ) {
	return _instance;
}

/*
	@detail	���C�����[�v
	@author	K.Oura
	@date	2017/09/08
*/
void Framework::Run( ) {
	
	// ���C�����[�v
	while ( true ) {
		// �G���[
		if ( ProcessMessage( ) == -1 ) {
			break;
		}
		// ESC�ŏI��
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
			break;
		}

		// �X�V
		_ProcFunc( );

		// �`��
		_DrawFunc( );

	}
}

/*
	@detail	�X�V�֐���o�^
	@author	K.Oura
	@date	2017/09/18
*/
void Framework::SetProcFunc( void ( *Func )( void ) )
{
	_ProcFunc = Func;
}

/*
	@detail	�`��֐���o�^
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
//		//�^�X�N����
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
