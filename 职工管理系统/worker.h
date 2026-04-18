#pragma once
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>

using namespace std;

class Worker
{
public:

	virtual void ShowInfo() = 0;

	virtual string GetDeptID() = 0;

	int m_ID = 0;
	string m_Name;
	int m_DeptID = 0;
};
