#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME  "empFile.txt"



class WorkerManager
{
public:
	WorkerManager();

	void ShowMenu();

	void ExitSystem();

	void AddEmp();
	void ShowEmp();
	void DelEmp();
	void MdfEmp();
	void FindEmp();
	void SortEmp();
	void ClenFile(); 

	void save(); //存入文件

	void InitEmp();  //初始化

	int GetEmpNum();

	int IsExist(int id);

	bool m_FileIsEmpty;

	int m_Num;

	Worker ** m_Array;    //职工指针数组


	~WorkerManager();

};


