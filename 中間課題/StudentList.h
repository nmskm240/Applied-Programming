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
			ListNode* pNode = new ListNode;
			if (pNode == NULL)
			{
				cout << "ƒƒ‚ƒŠ‚ÌŠm•Û‚ÉŽ¸”s‚µ‚Ü‚µ‚½\n";
				return;
			}
			pNode->pData = student.clone();
			if (pNode->pData == NULL)
			{
				cout << "ƒƒ‚ƒŠ‚ÌŠm•Û‚ÉŽ¸”s‚µ‚Ü‚µ‚½\n";
				delete pNode;
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
				cout << "ƒf[ƒ^‚ª“o˜^‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ\n";
				return;
			}
			if (this->length == 1)
			{
				this->_listTop = NULL;
			}
			else
			{
				if (pwNode->pBack == NULL)
				{
					//æ“ª
					this->_listTop = this->_listTop->pNext;
					this->_listTop->pBack = NULL;
				}
				else if (pwNode->pNext == NULL)
				{
					//––”ö
					pwNode->pBack->pNext = NULL;
				}
				else
				{
					pwNode->pNext->pBack = pwNode->pBack;
					pwNode->pBack->pNext = pwNode->pNext;
				}
			}
			delete pwNode->pData;
			delete pwNode;
			this->length--;
		}

		void out()
		{
			if (this->length == 0)
			{
				cout << "ƒf[ƒ^‚ª“o˜^‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ\n";
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