#include<iostream>

class RpcGAME
{
private:
	int end;
	int inputPL, inputPC, countwin = 0, countlose = 0, countdraw = 0;
public:
	int kaisuu(void);//回数
	void seiseki(void);//戦績表示
	void InputFunc(void);//じゃんけんの手入力処理
	void InputPC(void);//コンピュータ側の出す手に関する処理
	void ResultDisp(void);//じゃんけん勝負の結果処理
	void setEND(int n);//じゃんけんを続けるか否か
	int ENDJudge(void);//終了判定setENDに送る値を受けとる
};

int RpcGAME::kaisuu(void)
{
	int num;
	num = countwin + countlose + countdraw+1;
	return num;
}

void RpcGAME::seiseki(void)
{
	std::cout << countwin << "勝" << countlose << "敗" << countdraw << "分け" << std::endl;
}

void RpcGAME::InputFunc()
{
	std::cout << "あなたの手を入力してください（１：グー、２：チョキ、パー：３）" << std::endl;
	std::cin >> inputPL;
	if (inputPL == 1)
		std::cout << "PL:グー" << std::endl;
	if (inputPL == 2)
		std::cout << "PL:チョキ" << std::endl;
	if (inputPL == 3)
		std::cout << "PL:パー" << std::endl;
}

void RpcGAME::InputPC()
{
	inputPC = (rand() % 3 + 1);
	if (inputPC == 1)
		std::cout << "PC:グー" << std::endl;
	if(inputPC==2)
		std::cout << "PC:チョキ" << std::endl;
	if (inputPC == 3)
		std::cout << "PC:パー" << std::endl;
	else std::cout << "error" << std:: endl;
}

void RpcGAME::ResultDisp(void)
{
	if (inputPL == inputPC)
	{
		std::cout << "引き分け" << std::endl;
		countdraw++;
	}
	else if (inputPL == 1 && inputPC == 2)
	{
		std::cout << "you win" << std::endl;
		countwin++;
	}
	else if (inputPL == 2 && inputPC == 3)
	{
		std::cout << "you win" << std::endl;
		countwin++;
	}
	else if (inputPL == 3 && inputPC == 1)
	{
		std::cout << "you win" << std::endl;
		countwin++;
	}
	else
	{
		std::cout << "you lose" << std::endl;
		countlose++;
	}

}

void RpcGAME::setEND(int n)
{
	if (n != 0 && n != 1)//1:終了,0:継続
		end = 1;
	else end = n;
}

int RpcGAME::ENDJudge()
{
	int num;
	std::cout << "ゲームを終了しますか？（はい：１、いいえ：０）" << std::endl;
	std::cin >> num;
	RpcGAME::setEND(num);
	return end;
}

int main(void)
{
	RpcGAME RpcGAMe;
	int endFlag = 0;
	do
	{
			std::cout << "じゃんけんゲーム(" << RpcGAMe.kaisuu() << "回戦目)" << std::endl;
			RpcGAMe.InputFunc();
			RpcGAMe.InputPC();
			RpcGAMe.ResultDisp();
			RpcGAMe.seiseki();
			endFlag = RpcGAMe.ENDJudge();
	} while (endFlag == 0);
	return 0;
}