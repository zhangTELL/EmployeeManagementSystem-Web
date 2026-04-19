#include "workerManager.h"

using namespace std;


WorkerManager::WorkerManager()  //worker manager的构造函数
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())  //文件是否存在
	{
		//cout << "文件不存在！" << endl;

		this->m_Num = 0;   //初始化

		this->m_Array = NULL;  //初始化

		this->m_FileIsEmpty = true;

		ifs.close();

	}

		
	else
	{
		char ch;
		ifs >> ch;

		if (ifs.eof())  //是否为空
		{

			//读一个字符
			cout << "已读取0名员工信息" << endl;

			this->m_Num = 0;

			this->m_Array = NULL;

			this->m_FileIsEmpty = true;
			ifs.close();

		}

		else
		{
			//文件存在且不为空
			int num = this->GetEmpNum();
			cout << "已读取" << num << "名员工信息" << endl;
			this->m_Num = num;

			this->m_Array = new Worker * [this->m_Num];

			this->InitEmp();
		}

	}
}


void WorkerManager::ShowMenu()
{
	cout << "**************************************" << endl;
	cout << "*******  欢迎使用职工管理系统  *******" << endl;
	cout << "**********  0.退出管理程序  **********" << endl;
	cout << "**********  1.增加职工信息  **********" << endl;
	cout << "**********  2.显示职工信息  **********" << endl;
	cout << "**********  3.删除职工信息  **********" << endl;
	cout << "**********  4.修改职工信息  **********" << endl;
	cout << "**********  5.查找职工信息  **********" << endl;
	cout << "**********  6.按照编号排序  **********" << endl;
	cout << "**********  7.清空所有信息  **********" << endl;
	cout << "**************************************" << endl;
	cout << endl;

}


void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}


void WorkerManager::AddEmp()
{
	cout << "请输入你要添加的数量：";
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_Num + addNum; //计算新空间大小
		Worker** newSpace = new Worker * [newSize];

		if (this->m_Array)
		{
			for (int i = 0; i < this->m_Num; ++i)   //读取文件中的数据
			{
				newSpace[i] = this->m_Array[i];
			}
		}

		for (int i = 0; i < addNum; ++i)  //读取添加的数据
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i+1 << "个新职工的编号：";
			cin >> id;

			cout << "           该职工的姓名：";
			cin >> name;

			cout << "           该职工的职位（1.员工 2.经理 3.老板）：";
			cin >> dSelect;

			while (dSelect > 3 || dSelect < 1)
			{
				cout << "输入错误！请重新输入：";
				cin >> dSelect;
			}

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			}

			newSpace[this->m_Num + i] = worker;

		}
		delete[] this->m_Array;

		this->m_Array = newSpace;

		this->m_Num = newSize;

		this->m_FileIsEmpty = false;

		cout << endl << "成功添加" << addNum << "名新职工！" << endl << endl;

		this->save();   //存入文件
	}
	else
	{
		cout << "输入错误！" << endl;
		system("pause");
		system("cls");
		return;
	}

	system("pause");
	system("cls");

}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //out写文件

	for (int i = 0; i < this->m_Num; ++i)
	{
		ofs << this->m_Array[i]->m_ID << " "
			<< this->m_Array[i]->m_Name << " "
			<< this->m_Array[i]->m_DeptID << endl;
	}

	ofs.close(); //关闭文件

}

int WorkerManager::GetEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}

	return num;
}

void WorkerManager::InitEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_Array[index] = worker;
		index++;
	}

	ifs.close();

}

void WorkerManager::ShowEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "未添加任何职工信息！请先添加！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Num; ++i)
		{
			this->m_Array[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_Num; ++i)
	{
		if (this->m_Array[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

void WorkerManager::DelEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入你要删除对象的ID：";
		cin >> id;

		int index = this->IsExist(id);


		while (index == -1)
		{
			cout << "不存在该职工！请重新输入：";
			cin >> id;
		}

		int select;
		cout << "编号：" << id << "  职工的姓名为：" << this->m_Array[index]->m_Name << endl;
		cout << "确认是否要删除？（1.确认 2.再想想）：";
		cin >> select;
		while (select != 1 && select != 2)
		{
			cout << "输入错误，请重新输入：";
			cin >> select;
		}

		if (select == 1)
		{
			for (int i = index; i < this->m_Num - 1; ++i)
			{
				this->m_Array[i] = this->m_Array[i + 1];
			}
			this->m_Num--;
			this->save();
		}

		
	}
	
	system("pause");
	system("cls");
}

void WorkerManager::MdfEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入你要修改职工的ID：";
		cin >> id;
		
		int index = this->IsExist(id);

		cout << "该职工姓名为：" << this->m_Array[index]->m_Name << endl;


		if (index != -1)
		{
			cout << "请输入你要修改的内容（1.ID 2.姓名 3.职位）：";
			int choice;
			cin >> choice;
			if (choice <= 3 && choice >= 1)
			{
				int fId = this->m_Array[index]->m_ID;
				string fName = this->m_Array[index]->m_Name;
				switch (choice)
				{
				case 1:
				{
					int nID;
					cout << "修改ID号为：";
					cin >> nID;
					this->m_Array[index]->m_ID = nID;
					break;
				}
				case 2:
				{
					string nName;
					cout << "修改姓名为：";
					cin >> nName;
					this->m_Array[index]->m_Name = nName;
					break;
				}
				case 3:
				{
					cout << "修改职位为（1.员工 2.经理 3.老板）：";
					int dSelect;
					cin >> dSelect;

					while (dSelect > 3 || dSelect < 1)
					{
						cout << "输入错误！请重新输入：";
						cin >> dSelect;
					}

					Worker* worker = NULL;
					switch (dSelect)
					{
					case 1:
						worker = new Employee(fId, fName, dSelect);
						break;
					case 2:
						worker = new Manager(fId, fName, dSelect);
						break;
					case 3:
						worker = new Boss(fId, fName, dSelect);
						break;
					}
					this->m_Array[index] = worker;
					break;
				}

				}
			cout << "修改成功！" << endl;

			this->save();

			}
			else
			{
				cout << "输入错误，已退出" << endl;
			}
		}
		else
		{
			cout << "未找到该职工信息！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::FindEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int id = 0;
		cout << "请输入你要查找的职工的ID：";
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			this->m_Array[index]->ShowInfo();
		}
		else
		{
			cout << "未找到该职工信息！" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		cout << "请选择排序方式（1.升序 2.降序）：" << endl;

		int select = 0;
		cin >> select;

		while (select != 1 && select != 2)
		{
			cout << "输入错误！请重新输入：";
			cin >> select;
		}

		sort(this->m_Array, this->m_Array + this->m_Num,
			[select](Worker* a, Worker* b)
			{
				if (select == 1)
					return a->m_ID < b->m_ID; 
				else
					return a->m_ID > b->m_ID; 
			}
		);
		cout << "排序成功！" << endl;
		this->save();
		
	}
	system("pause");
	system("cls");
}

void WorkerManager::ClenFile()
{
	cout << "是否清空？（1.确认 2.返回）" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_Array)
		{
			for (int i = 0; i < this->m_Num; ++i)
			{
				if (this->m_Array[i] != NULL)
				{
					delete this->m_Array[i];
				}
			}
			delete[]this->m_Array;
			this->m_Array = NULL;
			this->m_Num = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;

	}
	system("pause");
	system("cls");

}


WorkerManager::~WorkerManager()
{
	if (this->m_Array)
	{
		for (int i = 0; i < this->m_Num; ++i)
		{
			if (this->m_Array[i] != NULL)
			{
				delete this->m_Array[i];
			}
		}

		delete[]this->m_Array;
		this->m_Array = NULL;
	}
}
