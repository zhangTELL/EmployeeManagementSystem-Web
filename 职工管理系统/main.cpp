#include <iostream>
#include <string>

#include "workerManager.h"

using namespace std;

int main()
{

	WorkerManager wm;
	system("pause");
	system("cls");

	int choice = 0;

	do
	{
		wm.ShowMenu();
		cout << "请输入你的选择：";
		cin >> choice;
		if (choice != 0)
		{
			switch (choice)
			{
			case 1: //add
				wm.AddEmp();
				break;
			case 2: //show
				wm.ShowEmp();
				break;
			case 3: //delete
				wm.DelEmp();
				break;
			case 4: //modify
				wm.MdfEmp();
				break;
			case 5: //find
				wm.FindEmp();
				break;
			case 6: //sort
				wm.SortEmp();
				break;
			case 7: //zero
				wm.ClenFile();
				break;
			default:
				system("cls");
				break;
			}
		}

	} while (choice != 0);

	wm.ExitSystem();


	return 0;
}