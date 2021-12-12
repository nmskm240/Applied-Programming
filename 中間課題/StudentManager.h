#include "StudentList.h"
#include <iostream>
using namespace std;

struct StudentManager
{
	private:
		StudentList _list;

	public:
		void createAndAddData()
		{
			int id, rank;
			char* name = new char, *comment = new char;
			try
			{
				cout << "登録するデータ情報を入力してください\n";
				cout << "学籍番号を入力してください\n";
				cin >> id;
				cout << "名前を入力してください\n";
				cin >> name;
				cout << "学年を入力してください\n";
				cin >> rank;
				cout << "コメントを入力してください\n";
				cin >> comment;
			}
			catch (...)
			{
				cout << "入力されたデータが正常ではありませんでした\n";
				cin.clear();
				cin.seekg(0);
				return;
			}
			this->_list.add(Student(id, name, rank, comment));
		}

		void deleteData()
		{
			int index;
			this->_list.out();
			cout << "削除するデータの番号を入力してください\n";
			try
			{
				cin >> index;
			}
			catch (...)
			{
				cout << "正の整数を入力してください\n";
				cin.clear();
				cin.seekg(0);
				return;
			}
			this->_list.removeAt(index);
		}

		void showData()
		{
			this->_list.out();
		}
};