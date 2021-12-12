using namespace std;

struct Student
{
	int id;
	char* name;
	int rank;
	char* comment;

	Student(int id, char* name, int rank, char* comment)
	{
		this->id = id;
		this->name = name;
		this->rank = rank;
		this->comment = comment;
	}

	Student* clone()
	{
		return new Student(*this);
	}

	char* toString()
	{
		char* buf = new char;
		sprintf(buf, " �w�Дԍ�:%d ���O: %s �w�N: %d�N �R�����g: %s", this->id, this->name, this->rank, this->comment);
		return buf;
	}
};