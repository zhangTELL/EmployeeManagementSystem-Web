#include "boss.h"

Boss::Boss(int id, string name, int dID)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = dID;
}

void Boss::ShowInfo()
{
	printf("职工编号：%04d", this->m_ID);
	cout <<("\t职工姓名：") << left << setw(30) << this->m_Name
		<< "\t职务：" << this->GetDeptID()
		<< "\t岗位职责：管理公司所有事务"
		<< endl;
}

string Boss::GetDeptID()
{
	return "总裁";
}