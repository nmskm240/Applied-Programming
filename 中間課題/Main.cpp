#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StudentManager.h"
using namespace std;

int main()
{
	int num = 0;
	StudentManager manager;
	cin.exceptions(ios::failbit);
	while (true)
	{
		cout << "操作内容を選択してください\n";
		cout << " 1:新規データの登録\n 2:登録データの削除\n 3:登録データの出力\n 0:終了\n";
		try
		{
			cin >> num;
		}
		catch (...)
		{
			cout << "無効な入力です\n";
			cin.clear();
			cin.seekg(0);
		}
		switch (num)
		{
			case 0:
				return 0;
			case 1:
				manager.createAndAddData();
				break;
			case 2:
				manager.deleteData();
				break;
			case 3:
				manager.showData();
				break;
			default:
				cout << "無効な操作です\n";
				break;
		}
	}
}