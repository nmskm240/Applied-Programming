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
		sprintf(buf, " 学籍番号:%d 名前: %s 学年: %d年 コメント: %s", this->id, this->name, this->rank, this->comment);
		return buf;
	}
};