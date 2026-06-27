
#include <iostream>
#include <string>
using namespace std;

class univercity
{
 protected:
	string name, gakka, class1;
public:
	univercity();
	univercity(string a, string b, string c) { name = a; gakka = b; class1 = c; }
	void data_show();
};

class circle
{
 protected:
	string name,activetime;
	int number;
public:
	circle();
	circle(string d, int e, string f){ name = d; number = e; activetime = f; }
	void data_show();
};

class student:public univercity,public circle
{
 protected:
	string name,shumi;
	int age;
public:
	student();
	student(string a, string b, string c, string d, int e, string f, string i, int g, string h) :univercity(a, b, c), circle(d, e, f) { student::name = i; shumi = h; age = g; }
	void data_show();
};

univercity::univercity()
{
	univercity::name = "未入力";
	gakka = "未入力";
	class1 = "未入力";
}

void univercity::data_show()
{
	cout << "大学名:" << univercity::name << "学科:" << gakka << "クラス:" << class1<<endl;
}

circle::circle()
{
	number = 0;
	activetime = "";
}

void circle::data_show()
{
	cout <<"サークル名:" << circle::name << "人数:" << number << "活動日:" << activetime << endl;
}

student::student()
{
	age = 0;
	shumi = "";
}

void student::data_show()
{
	univercity::data_show();
	circle::data_show();
	cout<<"氏名:"<< student::name << "age:" << age << "趣味:" << shumi << endl;
}

int main()
{
	student stu("日本","情報","A","テニス",13,"火曜日","木村一平", 20, "家");
	stu.data_show();
	system("pause");
	return 0;
}
