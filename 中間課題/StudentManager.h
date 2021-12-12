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
				cout << "�o�^����f�[�^������͂��Ă�������\n";
				cout << "�w�Дԍ�����͂��Ă�������\n";
				cin >> id;
				cout << "���O����͂��Ă�������\n";
				cin >> name;
				cout << "�w�N����͂��Ă�������\n";
				cin >> rank;
				cout << "�R�����g����͂��Ă�������\n";
				cin >> comment;
			}
			catch (...)
			{
				cout << "���͂��ꂽ�f�[�^������ł͂���܂���ł���\n";
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
			cout << "�폜����f�[�^�̔ԍ�����͂��Ă�������\n";
			try
			{
				cin >> index;
			}
			catch (...)
			{
				cout << "���̐�������͂��Ă�������\n";
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