

#include<iostream>
#include<string>
using namespace std;

class trip
{
public:
	int yosan;
	void yosan_setting(int a);
	virtual void hikaku() = 0;
	trip(int a) { yosan = a; }
};

class airline :public trip
{
public:
	string basho;
	int nissuu;
	int shukuhakuhi;
	int koutuuhi;

	int goukei;
	string joukyou;

	void hikaku()
	{
		goukei = (shukuhakuhi + koutuuhi) * nissuu;
		if (yosan >= (shukuhakuhi + koutuuhi) * nissuu)
		{
			joukyou = "予算内";
		}
		if (yosan < (shukuhakuhi + koutuuhi) * nissuu)
		{
			joukyou = "予算オーバー";
		}
		cout << "予算:" << yosan << "費用合計:" << goukei << "差額:" << (yosan - goukei) << "予算状況:" << joukyou << endl;
	}

	airline(int a, string b, int c, int d, int e) :trip(a) { basho = b; nissuu = c; shukuhakuhi = d; koutuuhi = e; }
};

class sinkansen :public trip
{
public:
	string basho;
	int nissuu;
	int shukuhakuhi;
	int koutuuhi;

	int goukei;
	string joukyou;

	void hikaku()
	{
		goukei = (shukuhakuhi + koutuuhi) * nissuu;
		if (yosan >= (shukuhakuhi + koutuuhi) * nissuu)
		{
			joukyou = "予算内";
		}
		if (yosan < (shukuhakuhi + koutuuhi) * nissuu)
		{
			joukyou = "予算オーバー";
		}
		cout << "予算:" << yosan << "費用合計:" << goukei << "差額:" << (yosan - goukei) << "予算状況:" << joukyou << endl;
	}
	sinkansen(int a, string b, int c, int d, int e) :trip(a) {basho = b; nissuu = c; shukuhakuhi = d; koutuuhi = e;}
};

class bus :public trip
{
public:
	string basho;
	int nissuu;
	int shukuhakuhi;
	int koutuuhi;

	int goukei;
	string joukyou;

	void hikaku()
	{
		goukei = ((shukuhakuhi + koutuuhi) * nissuu);
		if (yosan >= (shukuhakuhi + koutuuhi) * nissuu)
		{
			joukyou = "予算内";
		}
		if (yosan <(shukuhakuhi + koutuuhi) * nissuu)
		{
			joukyou = "予算オーバー";
		}
		cout << "予算:" << yosan << "費用合計:" << goukei << "差額:" << (yosan - goukei) << "予算状況:" << joukyou << endl;
	}
	bus(int a, string b, int c, int d, int e) :trip(a) {basho = b; nissuu = c; shukuhakuhi = d; koutuuhi = e;}
};

void trip::yosan_setting(int a)
{
	yosan = a;
}

int main()
{
	int yosan;

	cout << "予算:" ;
	cin >> yosan;

	airline a(yosan, "沖縄", 3, 8000, 6000);
	sinkansen s(yosan, "京都", 2, 6000, 5000);
	bus b(yosan, "箱根", 2, 4000, 3000);

	a.hikaku();
	s.hikaku();
	b.hikaku();

	return 0;

}
