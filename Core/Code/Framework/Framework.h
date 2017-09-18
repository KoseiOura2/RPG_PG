/*---------------------------------------------------------
	@file	Framework.h
			
	@author	K.Oura
	@date	2017/9/08
----------------------------------------------------------*/

#ifndef __FRAME_WORK_H__
#define __FRAME_WORK_H__

//#include <string>
//#include <map>

//-------------------------------------------- class
class Framework {
public:
	static Framework* GetInstance( );
	static void Initialize( );
	static void Finalize( );
	virtual ~Framework( );
	void Run( );
	void SetProcFunc( void ( *Func )( void ) );
	void SetDrawFunc( void ( *Func )( void ) );
	//void addTask( TaskPtr task );
	//TaskPtr getTask( std::string type );
private:
	Framework( );
	//void initializeAllTask( );
	//void loopAllTask( );
	//void finalizeAllTask( );
private:
	static Framework* _instance;
	void ( *_ProcFunc )( void );
	void ( *_DrawFunc )( void );
	//std::map< std::string, TaskPtr > _task_map;
	//bool _end;
};

#endif // __FRAME_WORK_H__
