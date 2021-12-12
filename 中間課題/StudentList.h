#include <stdio.h>
#include "Student.h"
#include "ListNode.h"
using namespace std;

struct StudentList
{
	private: 
		ListNode* _listTop = NULL;

	public:
		int length = 0;

		ListNode* last()
		{
			ListNode* tmp;
			ListNode* pwNode = this->_listTop;
			do
			{
				tmp = pwNode;
				pwNode = pwNode->pNext;
			} while (tmp->pNext != NULL);
			return tmp;
		}

		ListNode* getAt(int index)
		{
			ListNode* pwNode = this->_listTop;
			if (this->length < index)
			{
				return NULL;
			}
			for (int i = 0; i < index; i++)
			{
				pwNode = pwNode->pNext;
			}
			return pwNode;
		}

		void add(Student student)
		{
			ListNode* pNode = new ListNode(student.clone());
			if (pNode == NULL)
			{
				cout << "�������̊m�ۂɎ��s���܂���\n";
				return;
			}
			if (this->_listTop == NULL)
			{
				this->_listTop = pNode;
			}
			else
			{
				ListNode* last = this->last();
				last->pNext = pNode;
				pNode->pBack = last;
			}
			this->length++;
		}

		void removeAt(int index)
		{
			ListNode* pwNode = this->getAt(index);
			if (pwNode == NULL) 
			{
				cout << "�f�[�^���o�^����Ă��܂���\n";
				return;
			}
			if (pwNode->isFirst())
			{
				this->_listTop = pwNode->pNext;
			}
			delete pwNode;
			this->length--;
		}

		void out()
		{
			if (this->length == 0)
			{
				cout << "�f�[�^���o�^����Ă��܂���\n";
				return;
			}
			ListNode* pwNode = this->_listTop;
			int counter = 0;
			while (pwNode != NULL)
			{
				Student* student = pwNode->pData;
				printf("No.%d%s\n", counter++, student->toString());
				pwNode = pwNode->pNext;
			}
		}
};