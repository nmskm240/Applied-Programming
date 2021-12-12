struct ListNode
{
	Student* pData = NULL;
	ListNode* pNext = NULL;
	ListNode* pBack = NULL;

	ListNode(Student* data)
	{
		this->pData = data;
		if (this->pData == NULL)
		{
			cout << "ƒƒ‚ƒŠ‚ÌŠm•Û‚ÉŽ¸”s‚µ‚Ü‚µ‚½\n";
			delete this;
			return;
		}
	}

	~ListNode()
	{
		if (!this->isSingle())
		{
			if (this->isFirst())
			{
				this->pNext->pBack = NULL;
			}
			else if (this->isLast())
			{
				this->pBack->pNext = NULL;
			}
			else
			{
				this->pNext->pBack = this->pBack;
				this->pBack->pNext = this->pNext;
			}
		}
		delete pData;
	}

	bool isFirst()
	{
		return pBack == NULL;
	}

	bool isLast()
	{
		return pNext == NULL;
	}

	bool isSingle()
	{
		return isFirst() && isLast();
	}
};