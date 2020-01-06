#include <iostream>
#include<fstream>
#define x 9                                      //如果用for迴圈 用變數j當x 變數i當y
#define y 10
using namespace std;
int chesstable[x][y] = { {0} };
struct tablechess                                //用sturct 存每一個棋子
{
	int chess = 0;        //旗子編號
	int chess_x = 0;      //棋子位址
	int chess_y = 0;
	int chess_x_eat = 0;  //到時候吃別人旗子的位址
	int chess_y_eat = 0;
}f_5, f_7, f_3, f_4, f_6, f_8, f_11, f_12, f_14, f_15, f_13, f_9, f_10, f_0, f_1, f_2, s_105, s_107, s_103, s_104, s_106, s_108, s_111, s_112, s_114, s_115, s_113, s_109, s_110, s_101, s_102, s_100;  /*    棋子取名的地方 */        //我想說取名就 先後 號碼
int first(int chesstable[x][y]);
int second(int chesstable[x][y]);
int f_5_defend(int chesstable[x][y], tablechess);
int f_7_defend(int chesstable[x][y], tablechess);
int f_3_defend(int chesstable[x][y], tablechess);
int f_4_defend(int chesstable[x][y], tablechess);
int f_6_1(int chesstable[x][y], tablechess);
int f_8_1(int chesstable[x][y], tablechess);
int f_11_1(int chesstable[x][y], tablechess);
int f_12_1(int chesstable[x][y], tablechess);
int f_14_1(int chesstable[x][y], tablechess);
int f_15_1(int chesstable[x][y], tablechess);
int f_13_attack(int chesstable[x][y], tablechess);
int f_9_attack(int chesstable[x][y], tablechess);
int f_10_attack(int chesstable[x][y], tablechess);
int f_0_defend(int chesstable[x][y], tablechess);
int f_1_defend(int chesstable[x][y], tablechess);
int f_2_defend(int chesstable[x][y], tablechess);
int f_5_attack(int chesstable[x][y], tablechess);
int f_6_attack(int chesstable[x][y], tablechess);
int s_105_defend(int chesstable[x][y], tablechess);
int s_107_defend(int chesstable[x][y], tablechess);
int s_103_defend(int chesstable[x][y], tablechess);
int s_104_defend(int chesstable[x][y], tablechess);
int s_106_1(int chesstable[x][y], tablechess);
int s_108_1(int chesstable[x][y], tablechess);
int s_111_1(int chesstable[x][y], tablechess);
int s_112_1(int chesstable[x][y], tablechess);
int s_114_1(int chesstable[x][y], tablechess);
int s_115_1(int chesstable[x][y], tablechess);
int s_109_attack(int chesstable[x][y], tablechess);
int s_110_attack(int chesstable[x][y], tablechess);
int s_101_defend(int chesstable[x][y], tablechess);
int s_102_defend(int chesstable[x][y], tablechess);
int s_100_defend(int chesstable[x][y], tablechess);
int s_113_attack(int chesstable[x][y], tablechess);
int s_105_attack(int chesstable[x][y], tablechess);
int s_106_attack(int chesstable[x][y], tablechess);
int order;

int main(int argc, char* argv[])
{
	ifstream infile("table.txt", ios::in);
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			infile >> chesstable[j][i];              //讀棋盤
		}
	}
	infile.close();
	order = atoi(argv[1]);                           //先後手數值轉整數
	if (order == 0)
	{
		if (first(chesstable) == 100)
		{
			return 1;
		}
		else if (chesstable[2][9] != 12 && f_12.chess != 0)            //如果裡面函數都沒有照著預期走 就寫防止犯規跟程式跑不動的情況
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0" << " " << "12" << " " << f_12.chess_x << " " << f_12.chess_y + 1 << endl;
			outfile.close();
			return 1;
		}
		else if (chesstable[2][9] == 12 || chesstable[3][9] == 12 || chesstable[4][9] == 12 || chesstable[5][9] == 12 || chesstable[6][9] == 12 || chesstable[7][9] == 12 && f_12.chess != 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0" << " " << "12" << " " << f_12.chess_x + 1 << " " << f_12.chess_y << endl;
			outfile.close();
			return 1;
		}
		else if (chesstable[8][9] == 12 && f_12.chess != 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0" << " " << "12" << " " << f_12.chess_x - 1 << " " << f_12.chess_y << endl;
			outfile.close();
			return 1;
		}
		else if (f_3.chess_x == 2 && f_3.chess_y == 0 && f_3.chess != 0)
		{
			if (chesstable[1][1] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 3 0 2" << endl;
				outfile.close();
				return 1;
			}
		}
		else if (f_4.chess_x == 6 && f_4.chess_y == 0 && f_4.chess != 0)                  //用象拖時間(最後手段)
		{
			if (chesstable[7][1] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 4 8 2" << endl;
				outfile.close();
				return 1;
			}
		}
		else if (f_3.chess_x == 0 && f_3.chess_y == 2 && f_3.chess != 0)
		{
			if (chesstable[1][1] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 3 2 0" << endl;
				outfile.close();
				return 1;
			}
		}
		else if (f_4.chess_x == 8 && f_4.chess_y == 2 && f_4.chess != 0)
		{
			if (chesstable[7][1] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 4 6 0" << endl;
				outfile.close();
				return 1;
			}
		}
	}                                                //決定先後手
	if (order == 1)
	{
		if (second(chesstable) == 100)
		{
			return 1;
		}
		else if (chesstable[2][0] != 112 && s_112.chess != 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1" << " " << "112" << " " << s_112.chess_x << " " << s_112.chess_y + 1 << endl;
			outfile.close();
			return 1;
		}
		else if (chesstable[2][0] == 112 || chesstable[3][0] == 112 || chesstable[4][0] == 112 || chesstable[5][0] == 112 || chesstable[6][0] == 112 || chesstable[7][0] == 112 && s_112.chess != 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1" << " " << "112" << " " << s_112.chess_x + 1 << " " << s_112.chess_y << endl;
			outfile.close();
			return 1;
		}
		else if (chesstable[8][0] == 112 && s_112.chess != 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1" << " " << "112" << " " << s_112.chess_x - 1 << " " << s_112.chess_y << endl;
			outfile.close();
			return 1;
		}
		else if (s_103.chess_x == 2 && s_103.chess_y == 9 && s_103.chess != 0)
		{
			if (chesstable[1][8] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 103 0 7" << endl;
				outfile.close();
				return 1;
			}
		}
		else if (s_104.chess_x == 6 && s_104.chess_y == 9 && s_104.chess != 0)                  //用象拖時間(最後手段)
		{
			if (chesstable[7][8] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 104 8 7" << endl;
				outfile.close();
				return 1;
			}
		}
		else if (s_103.chess_x == 0 && s_103.chess_y == 7 && s_103.chess != 0)
		{
			if (chesstable[1][8] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 103 2 9" << endl;
				outfile.close();
				return 1;
			}
		}
		else if (s_104.chess_x == 8 && s_104.chess_y == 7 && s_104.chess != 0)
		{
			if (chesstable[7][8] == -1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 104 6 9" << endl;
				outfile.close();
				return 1;
			}
		}
	}
}
int first(int chesstable[x][y])
{
	int f__5 = 10;
	int f__0 = 10;
	int f__6 = 10;
	int f__3 = 10;
	int f__4 = 10;
	int f__7 = 10;
	int f__8 = 10;
	int f__9 = 10;
	int f__10 = 10;
	int f__11 = 10;
	int f__12 = 10;
	int f__13 = 10;
	int f__14 = 10;
	int f__15 = 10;
	f__0 = f_0_defend(chesstable, f_0);
	if (f__0 == 100)
	{
		return 100;
	}
	f__3 = f_3_defend(chesstable, f_3);
	if (f__3 == 100)
	{
		return 100;
	}
	f__4 = f_4_defend(chesstable, f_4);
	if (f__4 == 100)
	{
		return 100;
	}
	f__5 = f_5_defend(chesstable, f_5);
	if (f__5 == 100)
	{
		return 100;
	}
	else if (f__5 == 1)
	{
		if (chesstable[f_5.chess_x_eat][f_5.chess_y_eat] == 105 || chesstable[f_5.chess_x_eat][f_5.chess_y_eat] == 106 || chesstable[f_5.chess_x_eat][f_5.chess_y_eat] == 107 || chesstable[f_5.chess_x_eat][f_5.chess_y_eat] == 108 || chesstable[f_5.chess_x_eat][f_5.chess_y_eat] == 109 || chesstable[f_5.chess_x_eat][f_5.chess_y_eat] == 110)  //這邊就可以挑想要吃的東西了 但我就寫我覺得比較可以吃的 看你要不要改
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5" << " " << f_5.chess_x_eat << " " << f_5.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__6 = f_6_1(chesstable, f_6);
	if (f__6 == 100)
	{
		return 100;
	}
	else if (f__6 == 1)
	{
		if (chesstable[f_6.chess_x_eat][f_6.chess_y_eat] == 105 || chesstable[f_6.chess_x_eat][f_6.chess_y_eat] == 106 || chesstable[f_6.chess_x_eat][f_6.chess_y_eat] == 107 || chesstable[f_6.chess_x_eat][f_6.chess_y_eat] == 108 || chesstable[f_6.chess_x_eat][f_6.chess_y_eat] == 109 || chesstable[f_6.chess_x_eat][f_6.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6" << " " << f_6.chess_x_eat << " " << f_6.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__7 = f_7_defend(chesstable, f_7);
	if (f__7 == 100)
	{
		return 100;
	}
	else if (f__7 == 1)
	{
		if (chesstable[f_7.chess_x_eat][f_7.chess_y_eat] == 105 || chesstable[f_7.chess_x_eat][f_7.chess_y_eat] == 106 || chesstable[f_7.chess_x_eat][f_7.chess_y_eat] == 107 || chesstable[f_7.chess_x_eat][f_7.chess_y_eat] == 108 || chesstable[f_7.chess_x_eat][f_7.chess_y_eat] == 109 || chesstable[f_7.chess_x_eat][f_7.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 7" << " " << f_7.chess_x_eat << " " << f_7.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__8 = f_8_1(chesstable, f_8);
	if (f__8 == 100)
	{
		return 100;
	}
	else if (f__8 == 1)
	{
		if (chesstable[f_8.chess_x_eat][f_8.chess_y_eat] == 105 || chesstable[f_8.chess_x_eat][f_8.chess_y_eat] == 106 || chesstable[f_8.chess_x_eat][f_8.chess_y_eat] == 107 || chesstable[f_8.chess_x_eat][f_8.chess_y_eat] == 108 || chesstable[f_8.chess_x_eat][f_8.chess_y_eat] == 109 || chesstable[f_8.chess_x_eat][f_8.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 8" << " " << f_8.chess_x_eat << " " << f_8.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__11 = f_11_1(chesstable, f_11);
	if (f__11 == 1)
	{
		if (chesstable[f_11.chess_x_eat][f_11.chess_y_eat] == 105 || chesstable[f_11.chess_x_eat][f_11.chess_y_eat] == 106 || chesstable[f_11.chess_x_eat][f_11.chess_y_eat] == 107 || chesstable[f_11.chess_x_eat][f_11.chess_y_eat] == 108 || chesstable[f_11.chess_x_eat][f_11.chess_y_eat] == 109 || chesstable[f_11.chess_x_eat][f_11.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 11" << " " << f_11.chess_x_eat << " " << f_11.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__12 = f_12_1(chesstable, f_12);
	if (f__12 == 1)
	{
		if (chesstable[f_12.chess_x_eat][f_12.chess_y_eat] == 105 || chesstable[f_12.chess_x_eat][f_12.chess_y_eat] == 106 || chesstable[f_12.chess_x_eat][f_12.chess_y_eat] == 107 || chesstable[f_12.chess_x_eat][f_12.chess_y_eat] == 108 || chesstable[f_12.chess_x_eat][f_12.chess_y_eat] == 109 || chesstable[f_12.chess_x_eat][f_12.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 12" << " " << f_12.chess_x_eat << " " << f_12.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__14 = f_14_1(chesstable, f_14);
	if (f__14 == 1)
	{
		if (chesstable[f_14.chess_x_eat][f_14.chess_y_eat] == 105 || chesstable[f_14.chess_x_eat][f_14.chess_y_eat] == 106 || chesstable[f_14.chess_x_eat][f_14.chess_y_eat] == 107 || chesstable[f_14.chess_x_eat][f_14.chess_y_eat] == 108 || chesstable[f_14.chess_x_eat][f_14.chess_y_eat] == 109 || chesstable[f_14.chess_x_eat][f_14.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 14" << " " << f_14.chess_x_eat << " " << f_14.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__15 = f_15_1(chesstable, f_15);
	if (f__15 == 1)
	{
		if (chesstable[f_15.chess_x_eat][f_15.chess_y_eat] == 105 || chesstable[f_15.chess_x_eat][f_15.chess_y_eat] == 106 || chesstable[f_15.chess_x_eat][f_15.chess_y_eat] == 107 || chesstable[f_15.chess_x_eat][f_15.chess_y_eat] == 108 || chesstable[f_15.chess_x_eat][f_15.chess_y_eat] == 109 || chesstable[f_15.chess_x_eat][f_15.chess_y_eat] == 110)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 15" << " " << f_15.chess_x_eat << " " << f_15.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	f__13 = f_13_attack(chesstable, f_13);
	if (f__13 == 2 || f__13 == 3)
	{
		return 100;
	}
	f__9 = f_9_attack(chesstable, f_9);
	if (f__9 == 100)
	{
		return 100;
	}
	f__10 = f_10_attack(chesstable, f_10);
	if (f__10 == 2 || f__10 == 3 || f__10 == 100)
	{
		return 100;
	}
	f__6 = f_6_attack(chesstable, f_6);
	if (f__6 == 100)
	{
		return 100;
	}
	f__5 = f_5_attack(chesstable, f_5);
	if (f__5 == 100)
	{
		return 100;
	}
	return 0;
}
int second(int chesstable[x][y])
{
	int s__105 = 10;
	int s__100 = 10;
	int s__106 = 10;
	int s__103 = 10;
	int s__104 = 10;
	int s__107 = 10;
	int s__108 = 10;
	int s__109 = 10;
	int s__111 = 10;
	int s__110 = 10;
	int s__112 = 10;
	int s__113 = 10;
	int s__114 = 10;
	int s__115 = 10;
	s__100 = s_100_defend(chesstable, s_100);
	if (s__100 == 100)
	{
		return 100;
	}
	s__103 = s_103_defend(chesstable, s_103);
	if (s__103 == 100)
	{
		return 100;
	}
	s__104 = s_104_defend(chesstable, s_104);
	if (s__104 == 100)
	{
		return 100;
	}
	s__105 = s_105_defend(chesstable, s_105);
	if (s__105 == 100)
	{
		return 100;
	}
	else if (s__105 == 1)
	{
		if (chesstable[s_105.chess_x_eat][s_105.chess_y_eat] == 5 || chesstable[s_105.chess_x_eat][s_105.chess_y_eat] == 6 || chesstable[s_105.chess_x_eat][s_105.chess_y_eat] == 7 || chesstable[s_105.chess_x_eat][s_105.chess_y_eat] == 8 || chesstable[s_105.chess_x_eat][s_105.chess_y_eat] == 9 || chesstable[s_105.chess_x_eat][s_105.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105" << " " << s_105.chess_x_eat << " " << s_105.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__106 = s_106_1(chesstable, s_106);
	if (s__106 == 100)
	{
		return 100;
	}
	else if (s__106 == 1)
	{
		if (chesstable[s_106.chess_x_eat][s_106.chess_y_eat] == 5 || chesstable[s_106.chess_x_eat][s_106.chess_y_eat] == 6 || chesstable[s_106.chess_x_eat][s_106.chess_y_eat] == 7 || chesstable[s_106.chess_x_eat][s_106.chess_y_eat] == 8 || chesstable[s_106.chess_x_eat][s_106.chess_y_eat] == 9 || chesstable[s_106.chess_x_eat][s_106.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106" << " " << s_106.chess_x_eat << " " << s_106.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__107 = s_107_defend(chesstable, s_107);
	if (s__107 == 100)
	{
		return 100;
	}
	else if (s__107 == 1)
	{
		if (chesstable[s_107.chess_x_eat][s_107.chess_y_eat] == 5 || chesstable[s_107.chess_x_eat][s_107.chess_y_eat] == 6 || chesstable[s_107.chess_x_eat][s_107.chess_y_eat] == 7 || chesstable[s_107.chess_x_eat][s_107.chess_y_eat] == 8 || chesstable[s_107.chess_x_eat][s_107.chess_y_eat] == 9 || chesstable[s_107.chess_x_eat][s_107.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 107" << " " << s_107.chess_x_eat << " " << s_107.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__108 = s_108_1(chesstable, s_108);
	if (s__108 == 100)
	{
		return 100;
	}
	else if (s__108 == 1)
	{
		if (chesstable[s_108.chess_x_eat][s_108.chess_y_eat] == 5 || chesstable[s_108.chess_x_eat][s_108.chess_y_eat] == 6 || chesstable[s_108.chess_x_eat][s_108.chess_y_eat] == 7 || chesstable[s_108.chess_x_eat][s_108.chess_y_eat] == 8 || chesstable[s_108.chess_x_eat][s_108.chess_y_eat] == 9 || chesstable[s_108.chess_x_eat][s_108.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 108" << " " << s_108.chess_x_eat << " " << s_108.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__111 = s_111_1(chesstable, s_111);
	if (s__111 == 1)
	{
		if (chesstable[s_111.chess_x_eat][s_111.chess_y_eat] == 5 || chesstable[s_111.chess_x_eat][s_111.chess_y_eat] == 6 || chesstable[s_111.chess_x_eat][s_111.chess_y_eat] == 7 || chesstable[s_111.chess_x_eat][s_111.chess_y_eat] == 8 || chesstable[s_111.chess_x_eat][s_111.chess_y_eat] == 9 || chesstable[s_111.chess_x_eat][s_111.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 111" << " " << s_111.chess_x_eat << " " << s_111.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__112 = s_112_1(chesstable, s_112);
	if (s__112 == 1)
	{
		if (chesstable[s_112.chess_x_eat][s_112.chess_y_eat] == 5 || chesstable[s_112.chess_x_eat][s_112.chess_y_eat] == 6 || chesstable[s_112.chess_x_eat][s_112.chess_y_eat] == 7 || chesstable[s_112.chess_x_eat][s_112.chess_y_eat] == 8 || chesstable[s_112.chess_x_eat][s_112.chess_y_eat] == 9 || chesstable[s_112.chess_x_eat][s_112.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 112" << " " << s_112.chess_x_eat << " " << s_112.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__114 = s_114_1(chesstable, s_114);
	if (s__114 == 1)
	{
		if (chesstable[s_114.chess_x_eat][s_114.chess_y_eat] == 5 || chesstable[s_114.chess_x_eat][s_114.chess_y_eat] == 6 || chesstable[s_114.chess_x_eat][s_114.chess_y_eat] == 7 || chesstable[s_114.chess_x_eat][s_114.chess_y_eat] == 8 || chesstable[s_114.chess_x_eat][s_114.chess_y_eat] == 9 || chesstable[s_114.chess_x_eat][s_114.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 114" << " " << s_114.chess_x_eat << " " << s_114.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__115 = s_115_1(chesstable, s_115);
	if (s__115 == 1)
	{
		if (chesstable[s_115.chess_x_eat][s_115.chess_y_eat] == 5 || chesstable[s_115.chess_x_eat][s_115.chess_y_eat] == 6 || chesstable[s_115.chess_x_eat][s_115.chess_y_eat] == 7 || chesstable[s_115.chess_x_eat][s_115.chess_y_eat] == 8 || chesstable[s_115.chess_x_eat][s_115.chess_y_eat] == 9 || chesstable[s_115.chess_x_eat][s_115.chess_y_eat] == 10)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 115" << " " << s_115.chess_x_eat << " " << s_115.chess_y_eat << endl;
			outfile.close();
			return 100;
		}
	}
	s__113 = s_113_attack(chesstable, s_113);
	if (s__113 == 2 || s__113 == 3 || s__113 == 4)
	{
		return 100;
	}
	s__109 = s_109_attack(chesstable, s_109);
	if (s__109 == 100)
	{
		return 100;
	}
	s__110 = s_110_attack(chesstable, s_110);
	if (s__110 == 2 || s__110 == 3 || s__110 == 100)
	{
		return 100;
	}
	s__106 = s_106_attack(chesstable, s_106);
	if (s__106 == 100)
	{
		return 100;
	}
	s__105 = s_105_attack(chesstable, s_105);
	if (s__105 == 100)
	{
		return 100;
	}
	return 0;
}
int f_5_defend(int chesstable[x][y], tablechess)                     //左車 能走x++,--,y++,--
{
	f_5.chess = 0;
	f_5.chess_x = 0;
	f_5.chess_y = 0;                               //每一次都要歸零 重新抓棋子位址
	f_5.chess_x_eat = 0;
	f_5.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 5)                 //找出車的位址
			{
				f_5.chess = chesstable[j][i];
				f_5.chess_x = j;
				f_5.chess_y = i;
			}
		}
	}
	if (f_5.chess == 0)                                  //車被吃掉傳出-1值
	{
		return -1;
	}
	for (int j = f_5.chess_x + 1; j < x; j++)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][f_5.chess_y] == 100) {
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5" << " " << j << " " << f_5.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][f_5.chess_y] == -1)
		{
			if (chesstable[j + 1][f_5.chess_y] == 100)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 5" << " " << j + 1 << " " << f_5.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = f_5.chess_x - 1; j >= 0; j--)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][f_5.chess_y] == 100)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5" << " " << j << " " << f_5.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][f_5.chess_y] == -1)
		{
			if (chesstable[j - 1][f_5.chess_y] == 100)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 5" << " " << j - 1 << " " << f_5.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_5.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[f_5.chess_x][i] == 100) {
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5" << " " << f_5.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_5.chess_x][i] == -1)
		{
			if (chesstable[f_5.chess_x][i + 1] == 100)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 5" << " " << f_5.chess_x << " " << i + 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_5.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[f_5.chess_x][i] == 100) {
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5" << " " << f_5.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_5.chess_x][i] == -1)
		{
			if (chesstable[f_5.chess_x][i - 1] == 100)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 5" << " " << f_5.chess_x << " " << i - 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_5.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[f_5.chess_x][i] == 101 || chesstable[f_5.chess_x][i] == 102 || chesstable[f_5.chess_x][i] == 103 || chesstable[f_5.chess_x][i] == 104 || chesstable[f_5.chess_x][i] == 105 || chesstable[f_5.chess_x][i] == 106 || chesstable[f_5.chess_x][i] == 107 || chesstable[f_5.chess_x][i] == 108 || chesstable[f_5.chess_x][i] == 109 || chesstable[f_5.chess_x][i] == 110 || chesstable[f_5.chess_x][i] == 111 || chesstable[f_5.chess_x][i] == 112 || chesstable[f_5.chess_x][i] == 113 || chesstable[f_5.chess_x][i] == 114 || chesstable[f_5.chess_x][i] == 115)
		{
			f_5.chess_x_eat = f_5.chess_x;
			f_5.chess_y_eat = i;
			return 1;
		}
		if (chesstable[f_5.chess_x][i] == -1)
		{
			if (chesstable[f_5.chess_x][i + 1] == 101 || chesstable[f_5.chess_x][i + 1] == 102 || chesstable[f_5.chess_x][i + 1] == 103 || chesstable[f_5.chess_x][i + 1] == 104 || chesstable[f_5.chess_x][i + 1] == 105 || chesstable[f_5.chess_x][i + 1] == 106 || chesstable[f_5.chess_x][i + 1] == 107 || chesstable[f_5.chess_x][i + 1] == 108 || chesstable[f_5.chess_x][i + 1] == 109 || chesstable[f_5.chess_x][i + 1] == 110 || chesstable[f_5.chess_x][i + 1] == 111 || chesstable[f_5.chess_x][i + 1] == 112 || chesstable[f_5.chess_x][i + 1] == 113 || chesstable[f_5.chess_x][i + 1] == 114 || chesstable[f_5.chess_x][i + 1] == 115)
			{
				f_5.chess_x_eat = f_5.chess_x;
				f_5.chess_y_eat = i + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_5.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[f_5.chess_x][i] == 101 || chesstable[f_5.chess_x][i] == 102 || chesstable[f_5.chess_x][i] == 103 || chesstable[f_5.chess_x][i] == 104 || chesstable[f_5.chess_x][i] == 105 || chesstable[f_5.chess_x][i] == 106 || chesstable[f_5.chess_x][i] == 107 || chesstable[f_5.chess_x][i] == 108 || chesstable[f_5.chess_x][i] == 109 || chesstable[f_5.chess_x][i] == 110 || chesstable[f_5.chess_x][i] == 111 || chesstable[f_5.chess_x][i] == 112 || chesstable[f_5.chess_x][i] == 113 || chesstable[f_5.chess_x][i] == 114 || chesstable[f_5.chess_x][i] == 115)
		{
			f_5.chess_x_eat = f_5.chess_x;
			f_5.chess_y_eat = i;
			return 1;
		}
		else if (chesstable[f_5.chess_x][i] == -1)
		{
			if (chesstable[f_5.chess_x][i - 1] == 101 || chesstable[f_5.chess_x][i - 1] == 102 || chesstable[f_5.chess_x][i - 1] == 103 || chesstable[f_5.chess_x][i - 1] == 104 || chesstable[f_5.chess_x][i - 1] == 105 || chesstable[f_5.chess_x][i - 1] == 106 || chesstable[f_5.chess_x][i - 1] == 107 || chesstable[f_5.chess_x][i - 1] == 108 || chesstable[f_5.chess_x][i - 1] == 109 || chesstable[f_5.chess_x][i - 1] == 110 || chesstable[f_5.chess_x][i - 1] == 111 || chesstable[f_5.chess_x][i - 1] == 112 || chesstable[f_5.chess_x][i - 1] == 113 || chesstable[f_5.chess_x][i - 1] == 114 || chesstable[f_5.chess_x][i - 1] == 115)
			{
				f_5.chess_x_eat = f_5.chess_x;
				f_5.chess_y_eat = i - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = f_5.chess_x + 1; j < x; j++)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][f_5.chess_y] == 101 || chesstable[j][f_5.chess_y] == 102 || chesstable[j][f_5.chess_y] == 103 || chesstable[j][f_5.chess_y] == 104 || chesstable[j][f_5.chess_y] == 105 || chesstable[j][f_5.chess_y] == 106 || chesstable[j][f_5.chess_y] == 107 || chesstable[j][f_5.chess_y] == 108 || chesstable[j][f_5.chess_y] == 109 || chesstable[j][f_5.chess_y] == 110 || chesstable[j][f_5.chess_y] == 111 || chesstable[j][f_5.chess_y] == 112 || chesstable[j][f_5.chess_y] == 113 || chesstable[j][f_5.chess_y] == 114 || chesstable[j][f_5.chess_y] == 115)
		{
			f_5.chess_y_eat = f_5.chess_y;
			f_5.chess_x_eat = j;
			return 1;
		}
		else if (chesstable[j][f_5.chess_y] == -1)
		{
			if (chesstable[j + 1][f_5.chess_y] == 101 || chesstable[j + 1][f_5.chess_y] == 102 || chesstable[j + 1][f_5.chess_y] == 103 || chesstable[j + 1][f_5.chess_y] == 104 || chesstable[j + 1][f_5.chess_y] == 105 || chesstable[j + 1][f_5.chess_y] == 106 || chesstable[j + 1][f_5.chess_y] == 107 || chesstable[j + 1][f_5.chess_y] == 108 || chesstable[j + 1][f_5.chess_y] == 109 || chesstable[j + 1][f_5.chess_y] == 110 || chesstable[j + 1][f_5.chess_y] == 111 || chesstable[j + 1][f_5.chess_y] == 112 || chesstable[j + 1][f_5.chess_y] == 113 || chesstable[j + 1][f_5.chess_y] == 114 || chesstable[j + 1][f_5.chess_y] == 115)
			{
				f_5.chess_y_eat = f_5.chess_y;
				f_5.chess_x_eat = j + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = f_5.chess_x - 1; j >= 0; j--)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][f_5.chess_y] == 101 || chesstable[j][f_5.chess_y] == 102 || chesstable[j][f_5.chess_y] == 103 || chesstable[j][f_5.chess_y] == 104 || chesstable[j][f_5.chess_y] == 105 || chesstable[j][f_5.chess_y] == 106 || chesstable[j][f_5.chess_y] == 107 || chesstable[j][f_5.chess_y] == 108 || chesstable[j][f_5.chess_y] == 109 || chesstable[j][f_5.chess_y] == 110 || chesstable[j][f_5.chess_y] == 111 || chesstable[j][f_5.chess_y] == 112 || chesstable[j][f_5.chess_y] == 113 || chesstable[j][f_5.chess_y] == 114 || chesstable[j][f_5.chess_y] == 115)
		{
			f_5.chess_y_eat = f_5.chess_y;
			f_5.chess_x_eat = j;
			return 1;
		}
		else if (chesstable[j][f_5.chess_y] == -1)
		{
			if (chesstable[j - 1][f_5.chess_y] == 101 || chesstable[j - 1][f_5.chess_y] == 102 || chesstable[j - 1][f_5.chess_y] == 103 || chesstable[j - 1][f_5.chess_y] == 104 || chesstable[j - 1][f_5.chess_y] == 105 || chesstable[j - 1][f_5.chess_y] == 106 || chesstable[j - 1][f_5.chess_y] == 107 || chesstable[j - 1][f_5.chess_y] == 108 || chesstable[j - 1][f_5.chess_y] == 109 || chesstable[j - 1][f_5.chess_y] == 110 || chesstable[j - 1][f_5.chess_y] == 111 || chesstable[j - 1][f_5.chess_y] == 112 || chesstable[j - 1][f_5.chess_y] == 113 || chesstable[j - 1][f_5.chess_y] == 114 || chesstable[j - 1][f_5.chess_y] == 115)
			{
				f_5.chess_y_eat = f_5.chess_y;
				f_5.chess_x_eat = j - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	if (chesstable[3][0] == 109 || chesstable[3][0] == 110)
	{
		if (chesstable[0][0] == 5)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5 0 1" << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int f_7_defend(int chesstable[x][y], tablechess)   //左馬 能走x+2 y+1
{
	f_7.chess = 0;
	f_7.chess_x = 0;
	f_7.chess_y = 0;
	f_7.chess_x_eat = 0;
	f_7.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 7)
			{
				f_7.chess = chesstable[j][i];
				f_7.chess_x = j;
				f_7.chess_y = i;
			}
		}
	}
	if (f_7.chess == 0)
	{
		return -1;
	}
	if (chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 100 && chesstable[f_7.chess_x][f_7.chess_y + 1] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 7" << " " << f_7.chess_x + 1 << " " << f_7.chess_y + 2 << endl;                                     //如果會吃到帥的情況
		outfile.close();
		return 100;
	}
	if (chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 100 && chesstable[f_7.chess_x][f_7.chess_y + 1] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 7" << " " << f_7.chess_x - 1 << " " << f_7.chess_y + 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 101 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 102 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 103 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 104 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 105 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 106 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 107 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 108 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 109 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 110 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 111 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 112 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 113 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 114 || chesstable[f_7.chess_x + 1][f_7.chess_y + 2] == 115) && (chesstable[f_7.chess_x][f_7.chess_y + 1] == -1))    //如果能吃的位置有就輸出位置
	{
		f_7.chess_x_eat = f_7.chess_x + 1;
		f_7.chess_y_eat = f_7.chess_y + 2;
		return 1;
	}
	if ((chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 101 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 102 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 103 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 104 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 105 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 106 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 107 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 108 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 109 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 110 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 111 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 112 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 113 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 114 || chesstable[f_7.chess_x - 1][f_7.chess_y + 2] == 115) && (chesstable[f_7.chess_x][f_7.chess_y + 1] == -1))
	{
		f_7.chess_x_eat = f_7.chess_x - 1;
		f_7.chess_y_eat = f_7.chess_y + 2;
		return 1;
	}
	return 0;
}
int f_3_defend(int chesstable[x][y], tablechess) //左象 走x+2 y+2 ,x+1 y+1不能有東西,只在車或馬或砲靠近最左側才行動,要不然默認不動
{
	f_3.chess = 0;
	f_3.chess_x = 0;
	f_3.chess_y = 0;
	f_3.chess_x_eat = 0;
	f_3.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 3)
			{
				f_3.chess = chesstable[j][i];
				f_3.chess_x = j;
				f_3.chess_y = i;

			}
		}
	}
	if (f_3.chess == 0)
	{
		return -1;
	}
	if ((chesstable[f_3.chess_x - 2][f_3.chess_y + 2] == 105 || chesstable[f_3.chess_x - 2][f_3.chess_y + 2] == 106 || chesstable[f_3.chess_x - 2][f_3.chess_y + 2] == 107 || chesstable[f_3.chess_x - 2][f_3.chess_y + 2] == 108 || chesstable[f_3.chess_x - 2][f_3.chess_y + 2] == 109 || chesstable[f_3.chess_x - 2][f_3.chess_y + 2] == 110) && (chesstable[f_3.chess_x - 1][f_3.chess_y + 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 3" << " " << f_3.chess_x - 2 << " " << f_3.chess_y + 2 << endl;
		outfile.close();
		return 100;
	}
	if (f_3.chess_x == 2 && f_3.chess_y == 0 && chesstable[3][1] == -1)
	{
		if (chesstable[4][2] == 113)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 3 4 2" << endl;                 //防兵直衝的情況
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int f_4_defend(int chesstable[x][y], tablechess)
{
	f_4.chess = 0;
	f_4.chess_x = 0;
	f_4.chess_y = 0;
	f_4.chess_x_eat = 0;
	f_4.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 4)
			{
				f_4.chess = chesstable[j][i];
				f_4.chess_x = j;
				f_4.chess_y = i;

			}
		}
	}
	if (f_4.chess == 0)
	{
		return -1;
	}
	if ((chesstable[f_4.chess_x + 2][f_4.chess_y + 2] == 105 || chesstable[f_4.chess_x + 2][f_4.chess_y + 2] == 106 || chesstable[f_4.chess_x + 2][f_4.chess_y + 2] == 107 || chesstable[f_4.chess_x + 2][f_4.chess_y + 2] == 108 || chesstable[f_4.chess_x + 2][f_4.chess_y + 2] == 109 || chesstable[f_4.chess_x + 2][f_4.chess_y + 2] == 110) && (chesstable[f_4.chess_x + 1][f_4.chess_y + 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 4" << " " << f_4.chess_x + 2 << " " << f_4.chess_y + 2 << endl;
		outfile.close();
		return 100;
	}
	if (f_4.chess_x == 7 && f_4.chess_y == 0 && chesstable[5][1] == -1)
	{
		if (chesstable[4][2] == 113)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 4 4 2" << endl;                 //防兵直衝的情況
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int f_6_1(int chesstable[x][y], tablechess)
{
	f_6.chess = 0;
	f_6.chess_x = 0;
	f_6.chess_y = 0;                               //每一次都要歸零 重新抓棋子位址
	f_6.chess_x_eat = 0;
	f_6.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 6)                 //找出車的位址
			{
				f_6.chess = chesstable[j][i];
				f_6.chess_x = j;
				f_6.chess_y = i;
			}
		}
	}
	if (f_6.chess == 0)                                  //車被吃掉傳出-1值
	{
		return -1;
	}
	for (int j = f_6.chess_x + 1; j < x; j++)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][f_6.chess_y] == 100)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6" << " " << j << " " << f_6.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][f_6.chess_y] == -1)
		{
			if (chesstable[j + 1][f_6.chess_y] == 100)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 6" << " " << j + 1 << " " << f_6.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = f_6.chess_x - 1; j >= 0; j--)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][f_6.chess_y] == 100)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6" << " " << j << " " << f_6.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][f_6.chess_y] == -1)
		{
			if (chesstable[j - 1][f_6.chess_y] == 100)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 6" << " " << j - 1 << " " << f_6.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_6.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[f_6.chess_x][i] == 100)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6" << " " << f_6.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_6.chess_x][i] == -1)
		{
			if (chesstable[f_6.chess_x][i + 1] == 100)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 6" << " " << f_6.chess_x << " " << i + 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_6.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[f_6.chess_x][i] == 100)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6" << " " << f_6.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_6.chess_x][i] == -1)
		{
			if (chesstable[f_6.chess_x][i - 1] == 100)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 6" << " " << f_6.chess_x << " " << i - 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_6.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[f_6.chess_x][i] == 101 || chesstable[f_6.chess_x][i] == 102 || chesstable[f_6.chess_x][i] == 103 || chesstable[f_6.chess_x][i] == 104 || chesstable[f_6.chess_x][i] == 105 || chesstable[f_6.chess_x][i] == 106 || chesstable[f_6.chess_x][i] == 107 || chesstable[f_6.chess_x][i] == 108 || chesstable[f_6.chess_x][i] == 109 || chesstable[f_6.chess_x][i] == 110 || chesstable[f_6.chess_x][i] == 111 || chesstable[f_6.chess_x][i] == 112 || chesstable[f_6.chess_x][i] == 113 || chesstable[f_6.chess_x][i] == 114 || chesstable[f_6.chess_x][i] == 115)
		{
			f_6.chess_x_eat = f_6.chess_x;
			f_6.chess_y_eat = i;
			return 1;
		}
		else if (chesstable[f_6.chess_x][i] == -1)
		{
			if (chesstable[f_6.chess_x][i + 1] == 101 || chesstable[f_6.chess_x][i + 1] == 102 || chesstable[f_6.chess_x][i + 1] == 103 || chesstable[f_6.chess_x][i + 1] == 104 || chesstable[f_6.chess_x][i + 1] == 105 || chesstable[f_6.chess_x][i + 1] == 106 || chesstable[f_6.chess_x][i + 1] == 107 || chesstable[f_6.chess_x][i + 1] == 108 || chesstable[f_6.chess_x][i + 1] == 109 || chesstable[f_6.chess_x][i + 1] == 110 || chesstable[f_6.chess_x][i + 1] == 111 || chesstable[f_6.chess_x][i + 1] == 112 || chesstable[f_6.chess_x][i + 1] == 113 || chesstable[f_6.chess_x][i + 1] == 114 || chesstable[f_6.chess_x][i + 1] == 115)
			{
				f_6.chess_x_eat = f_6.chess_x;
				f_6.chess_y_eat = i + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = f_6.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[f_6.chess_x][i] == 101 || chesstable[f_6.chess_x][i] == 102 || chesstable[f_6.chess_x][i] == 103 || chesstable[f_6.chess_x][i] == 104 || chesstable[f_6.chess_x][i] == 105 || chesstable[f_6.chess_x][i] == 106 || chesstable[f_6.chess_x][i] == 107 || chesstable[f_6.chess_x][i] == 108 || chesstable[f_6.chess_x][i] == 109 || chesstable[f_6.chess_x][i] == 110 || chesstable[f_6.chess_x][i] == 111 || chesstable[f_6.chess_x][i] == 112 || chesstable[f_6.chess_x][i] == 113 || chesstable[f_6.chess_x][i] == 114 || chesstable[f_6.chess_x][i] == 115)
		{
			f_6.chess_x_eat = f_6.chess_x;
			f_6.chess_y_eat = i;
			return 1;
		}
		else if (chesstable[f_6.chess_x][i] == -1)
		{
			if (chesstable[f_6.chess_x][i - 1] == 101 || chesstable[f_6.chess_x][i - 1] == 102 || chesstable[f_6.chess_x][i - 1] == 103 || chesstable[f_6.chess_x][i - 1] == 104 || chesstable[f_6.chess_x][i - 1] == 105 || chesstable[f_6.chess_x][i - 1] == 106 || chesstable[f_6.chess_x][i - 1] == 107 || chesstable[f_6.chess_x][i - 1] == 108 || chesstable[f_6.chess_x][i - 1] == 109 || chesstable[f_6.chess_x][i - 1] == 110 || chesstable[f_6.chess_x][i - 1] == 111 || chesstable[f_6.chess_x][i - 1] == 112 || chesstable[f_6.chess_x][i - 1] == 113 || chesstable[f_6.chess_x][i - 1] == 114 || chesstable[f_6.chess_x][i - 1] == 115)
			{
				f_6.chess_x_eat = f_6.chess_x;
				f_6.chess_y_eat = i - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = f_6.chess_x + 1; j < x; j++)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][f_6.chess_y] == 101 || chesstable[j][j] == 102 || chesstable[j][f_6.chess_y] == 103 || chesstable[j][f_6.chess_y] == 104 || chesstable[j][f_6.chess_y] == 105 || chesstable[j][f_6.chess_y] == 106 || chesstable[j][f_6.chess_y] == 107 || chesstable[j][f_6.chess_y] == 108 || chesstable[j][f_6.chess_y] == 109 || chesstable[j][f_6.chess_y] == 110 || chesstable[j][f_6.chess_y] == 111 || chesstable[j][f_6.chess_y] == 112 || chesstable[j][f_6.chess_y] == 113 || chesstable[j][f_6.chess_y] == 114 || chesstable[j][f_6.chess_y] == 115)
		{
			f_6.chess_y_eat = f_6.chess_y;
			f_6.chess_x_eat = j;
			return 1;
		}
		if (chesstable[j][f_6.chess_y] == -1)
		{
			if (chesstable[j + 1][f_6.chess_y] == 101 || chesstable[j + 1][f_6.chess_y] == 102 || chesstable[j + 1][f_6.chess_y] == 103 || chesstable[j + 1][f_6.chess_y] == 104 || chesstable[j + 1][f_6.chess_y] == 105 || chesstable[j + 1][f_6.chess_y] == 106 || chesstable[j + 1][f_6.chess_y] == 107 || chesstable[j + 1][f_6.chess_y] == 108 || chesstable[j + 1][f_6.chess_y] == 109 || chesstable[j + 1][f_6.chess_y] == 110 || chesstable[j + 1][f_6.chess_y] == 111 || chesstable[j + 1][f_6.chess_y] == 112 || chesstable[j + 1][f_6.chess_y] == 113 || chesstable[j + 1][f_6.chess_y] == 114 || chesstable[j + 1][f_6.chess_y] == 115)
			{
				f_6.chess_y_eat = f_6.chess_y;
				f_6.chess_x_eat = j + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = f_6.chess_x - 1; j >= 0; j--)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][f_6.chess_y] == 101 || chesstable[j][f_6.chess_y] == 102 || chesstable[j][f_6.chess_y] == 103 || chesstable[j][f_6.chess_y] == 104 || chesstable[j][f_6.chess_y] == 105 || chesstable[j][f_6.chess_y] == 106 || chesstable[j][f_6.chess_y] == 107 || chesstable[j][f_6.chess_y] == 108 || chesstable[j][f_6.chess_y] == 109 || chesstable[j][f_6.chess_y] == 110 || chesstable[j][f_6.chess_y] == 111 || chesstable[j][f_6.chess_y] == 112 || chesstable[j][f_6.chess_y] == 113 || chesstable[j][f_6.chess_y] == 114 || chesstable[j][f_6.chess_y] == 115)
		{
			f_6.chess_y_eat = f_6.chess_y;
			f_6.chess_x_eat = j;
			return 1;
		}
		if (chesstable[j][f_6.chess_y] == -1)
		{
			if (chesstable[j - 1][f_6.chess_y] == 101 || chesstable[j - 1][f_6.chess_y] == 102 || chesstable[j - 1][f_6.chess_y] == 103 || chesstable[j - 1][f_6.chess_y] == 104 || chesstable[j - 1][f_6.chess_y] == 105 || chesstable[j - 1][f_6.chess_y] == 106 || chesstable[j - 1][f_6.chess_y] == 107 || chesstable[j - 1][f_6.chess_y] == 108 || chesstable[j - 1][f_6.chess_y] == 109 || chesstable[j - 1][f_6.chess_y] == 110 || chesstable[j - 1][f_6.chess_y] == 111 || chesstable[j - 1][f_6.chess_y] == 112 || chesstable[j - 1][f_6.chess_y] == 113 || chesstable[j - 1][f_6.chess_y] == 114 || chesstable[j - 1][f_6.chess_y] == 115)
			{
				f_6.chess_y_eat = f_6.chess_y;
				f_6.chess_x_eat = j - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	if (chesstable[5][0] == 109 || chesstable[5][0] == 110)
	{
		if (chesstable[8][0] == 6)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 8 1" << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int f_8_1(int chesstable[x][y], tablechess)
{
	f_8.chess = 0;
	f_8.chess_x = 0;
	f_8.chess_y = 0;
	f_8.chess_x_eat = 0;
	f_8.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 8)
			{
				f_8.chess = chesstable[j][i];
				f_8.chess_x = j;
				f_8.chess_y = i;
			}
		}
	}
	if (f_8.chess == 0)
	{
		return -1;
	}
	if ((chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 100) && (chesstable[f_8.chess_x][f_8.chess_y + 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 8" << f_8.chess_x + 1 << " " << f_8.chess_y + 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 100) && (chesstable[f_8.chess_x][f_8.chess_y + 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 8" << f_8.chess_x - 1 << " " << f_8.chess_y + 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 101 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 102 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 103 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 104 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 105 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 106 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 107 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 108 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 109 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 110 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 111 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 112 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 113 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 114 || chesstable[f_8.chess_x + 1][f_8.chess_y + 2] == 115) && (chesstable[f_8.chess_x][f_8.chess_y + 1] == -1))
	{
		f_8.chess_x_eat = f_8.chess_x + 1;
		f_8.chess_y_eat = f_8.chess_y + 2;
		return 1;
	}
	if ((chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 101 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 102 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 103 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 104 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 105 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 106 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 107 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 108 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 109 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 110 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 111 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 112 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 113 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 114 || chesstable[f_8.chess_x - 1][f_8.chess_y + 2] == 115) && (chesstable[f_8.chess_x][f_8.chess_y + 1] == -1))
	{
		f_8.chess_x_eat = f_8.chess_x - 1;
		f_8.chess_y_eat = f_8.chess_y + 2;
		return 1;
	}
	return 0;
}
int f_11_1(int chesstable[x][y], tablechess)//前方有敵人才動作
{
	f_11.chess = 0;
	f_11.chess_x = 0;
	f_11.chess_y = 0;
	f_11.chess_x_eat = 0;
	f_11.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 11)
			{
				f_11.chess = chesstable[j][i];
				f_11.chess_x = j;
				f_11.chess_y = i;
			}
		}
	}
	if (f_11.chess == 0)
	{
		return -1;
	}
	if (chesstable[f_11.chess_x][f_11.chess_y + 1] == 105 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 106 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 107 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 108 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 109 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 110 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 111 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 112 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 113 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 114 || chesstable[f_11.chess_x][f_11.chess_y + 1] == 115)
	{
		f_11.chess_x_eat = f_11.chess_x;
		f_11.chess_y_eat = f_11.chess_y + 1;
		return 1;
	}
	return 0;
}
int f_12_1(int chesstable[x][y], tablechess)//前方有敵人才動作
{
	f_12.chess = 0;
	f_12.chess_x = 0;
	f_12.chess_y = 0;
	f_12.chess_x_eat = 0;
	f_12.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 12)
			{
				f_12.chess = chesstable[j][i];
				f_12.chess_x = j;
				f_12.chess_y = i;
			}
		}
	}
	if (f_12.chess == 0)
	{
		return -1;
	}
	if (chesstable[f_12.chess_x][f_12.chess_y + 1] == 105 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 106 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 107 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 108 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 109 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 110 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 111 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 112 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 113 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 114 || chesstable[f_12.chess_x][f_12.chess_y + 1] == 115)
	{
		f_12.chess_x_eat = f_12.chess_x;
		f_12.chess_y_eat = f_12.chess_y + 1;
		return 1;
	}
	return 0;
}
int f_14_1(int chesstable[x][y], tablechess)//前方有敵人才動作
{
	f_14.chess = 0;
	f_14.chess_x = 0;
	f_14.chess_y = 0;
	f_14.chess_x_eat = 0;
	f_14.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 14)
			{
				f_14.chess = chesstable[j][i];
				f_14.chess_x = j;
				f_14.chess_y = i;
			}
		}
	}
	if (f_14.chess == 0)
	{
		return -1;
	}
	if (chesstable[f_14.chess_x][f_14.chess_y + 1] == 105 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 106 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 107 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 108 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 109 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 110 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 111 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 112 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 113 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 114 || chesstable[f_14.chess_x][f_14.chess_y + 1] == 115)
	{
		f_14.chess_x_eat = f_14.chess_x;
		f_14.chess_y_eat = f_14.chess_y + 1;
		return 1;
	}
	return 0;
}
int f_15_1(int chesstable[x][y], tablechess)//前方有敵人才動作
{
	f_15.chess = 0;
	f_15.chess_x = 0;
	f_15.chess_y = 0;
	f_15.chess_x_eat = 0;
	f_15.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 15)
			{
				f_15.chess = chesstable[j][i];
				f_15.chess_x = j;
				f_15.chess_y = i;
			}
		}
	}
	if (f_15.chess == 0)
	{
		return -1;
	}
	if (chesstable[f_15.chess_x][f_15.chess_y + 1] == 105 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 106 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 107 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 108 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 109 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 110 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 111 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 112 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 113 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 114 || chesstable[f_15.chess_x][f_15.chess_y + 1] == 115)
	{
		f_15.chess_x_eat = f_15.chess_x;
		f_15.chess_y_eat = f_15.chess_y + 1;
		return 1;
	}
	return 0;
}
int f_13_attack(int chesstable[x][y], tablechess) //一開始就會往前衝 砲發現吃不到後往右移
{
	f_13.chess = 0;
	f_13.chess_x = 0;
	f_13.chess_y = 0;
	f_13.chess_x_eat = 0;
	f_13.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 13)
			{
				f_13.chess = chesstable[j][i];
				f_13.chess_x = j;
				f_13.chess_y = i;
			}
		}
	}
	if (f_13.chess == 0)
	{
		return -1;
	}
	if (f_13.chess_y < 4 || f_13.chess_y == 4)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 13" << " " << f_13.chess_x << " " << f_13.chess_y + 1 << endl;
		outfile.close();
		return 2;
	}
	if (f_13.chess_y == 5 && f_13.chess_x == 4)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 13" << " " << f_13.chess_x + 1 << " " << f_13.chess_y << endl;
		outfile.close();
		return 3;
	}
	return 0;
}
int f_9_attack(int chesstable[x][y], tablechess)
{
	f_9.chess = 0;
	f_9.chess_x = 0;
	f_9.chess_y = 0;
	f_9.chess_x_eat = 0;
	f_9.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 9)
			{
				f_9.chess = chesstable[j][i];
				f_9.chess_x = j;
				f_9.chess_y = i;
			}
		}
	}
	if (f_9.chess == 0)
	{
		return -1;
	}
	if (chesstable[4][2] == -1 && chesstable[3][2] == -1 && chesstable[2][2] == -1)
	{
		if (f_9.chess_x == 1 && f_9.chess_y == 2)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 9 4 2" << endl;        //移到中間
			outfile.close();
			return 100;
		}
	}
	else if (f_9.chess_x == 1 && f_9.chess_y == 2)
	{
		if (chesstable[1][1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 9 1 1" << endl;        //移到中間
			outfile.close();
			return 100;
		}
	}
	if (f_9.chess_x == 1 && f_9.chess_y == 2)
	{
		if (chesstable[2][1] == -1 && chesstable[3][1] == -1 && chesstable[4][1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 9 4 1" << endl;        //移到中間
			outfile.close();
			return 100;
		}
	}
	for (int i = f_9.chess_y + 1; i < y; i++)                     //砲往下抓旗子跳(砲要吃中間必須要有旗子跳)
	{
		if (chesstable[f_9.chess_x][i] != -1)
		{
			for (int j = i + 1; j < y; j++)              //抓到棋子可以跳後 找下一個棋子是不是將軍
			{
				if (chesstable[f_9.chess_x][j] == 100)
				{
					ofstream outfile;
					outfile.open("play.txt");
					outfile << "0 9" << " " << f_9.chess_x << " " << j << endl;   //如果能打到將
					outfile.close();
					return 100;
				}
				else if (chesstable[f_9.chess_x][j] != -1)
				{
					return 0;                               //我直接傳出0 反正是最後一行比較保險
				}
			}
		}
	}
	return 0;
}
int f_10_attack(int chesstable[x][y], tablechess)
{
	f_10.chess = 0;
	f_10.chess_x = 0;
	f_10.chess_y = 0;
	f_10.chess_x_eat = 0;
	f_10.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 10)
			{
				f_10.chess = chesstable[j][i];
				f_10.chess_x = j;
				f_10.chess_y = i;
			}
		}
	}
	if (f_10.chess == 0)
	{
		return -1;
	}
	for (int i = f_10.chess_y + 1; i < y; i++)
	{
		if (chesstable[f_10.chess_x][i] != -1)
		{
			for (int j = i + 1; j < y; j++)
			{
				if (chesstable[f_10.chess_x][j] == 100)
				{
					ofstream outfile;
					outfile.open("play.txt");
					outfile << "0 10" << " " << f_10.chess_x << " " << j << endl;     //每次跑程式抓有沒有將軍可以吃
					outfile.close();
					return 100;
				}
				else if (chesstable[f_10.chess_x][j] != -1)
				{
					break;
				}
			}
		}
	}
	if (f_10.chess_x == 7 && f_10.chess_y == 2 && chesstable[7][3] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 10 7 4" << endl;
		outfile.close();
		return 2;
	}
	else if (f_10.chess_x == 7 && f_10.chess_y == 2 && chesstable[6][2] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 10 5 2" << endl;
		outfile.close();
		return 2;
	}
	if (f_10.chess_x == 5 && f_10.chess_y == 2 && chesstable[5][3] == -1 && chesstable[5][4] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 10 5 4" << endl;
		outfile.close();
		return 3;
	}
	else
	{
		return -1;
	}
	if (f_10.chess_x == 5 && f_10.chess_y == 4 && chesstable[4][4] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 10 4 4" << endl;
		outfile.close();
		return 4;
	}
	else
	{
		return -1;
	}
	if (f_10.chess_x == 7 && f_10.chess_y == 4 && chesstable[6][4] == -1 && chesstable[5][4] == -1 && chesstable[4][4] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 10 4 4" << endl;
		outfile.close();                     //動兩步 來移成雙砲陣型(如果將軍左右有兩個人就必死)
		return 3;
	}
	else
	{
		return -1;
	}
	return 0;
}
int f_1_defend(int chesstable[x][y], tablechess)
{
	f_1.chess = 0;
	f_1.chess_x = 0;
	f_1.chess_y = 0;
	f_1.chess_x_eat = 0;
	f_1.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 1)
			{
				f_1.chess = chesstable[j][i];
				f_1.chess_x = j;
				f_1.chess_y = i;
			}
		}
	}
	if (f_1.chess == 0)
	{
		return -1;
	}
	if (f_1.chess_x == 3 && f_1.chess_y == 0 && chesstable[4][1] != -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 1 4 1" << endl;
		outfile.close();
		return 100;
	}
	else
	{
		return -2;
	}
	return 0;
}
int f_2_defend(int chesstable[x][y], tablechess)
{
	f_2.chess = 0;
	f_2.chess_x = 0;
	f_2.chess_y = 0;
	f_2.chess_x_eat = 0;
	f_2.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 2)
			{
				f_2.chess = chesstable[j][i];
				f_2.chess_x = j;
				f_2.chess_y = i;
			}
		}
	}
	if (f_2.chess == 0)
	{
		return -1;
	}
	if (f_2.chess_x == 5 && f_2.chess_y == 0 && chesstable[4][1] != -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 2 4 1" << endl;
		outfile.close();
		return 100;
	}
	else
	{
		return -2;
	}
	return 0;
}
int f_0_defend(int chesstable[x][y], tablechess)
{
	f_0.chess = 0;
	f_0.chess_x = 0;
	f_0.chess_y = 0;
	f_0.chess_x_eat = 0;
	f_0.chess_y_eat = 0;
	int a = 0;
	int kingx = 0;
	int kingy = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 0)
			{
				f_0.chess = chesstable[j][i];
				f_0.chess_x = j;
				f_0.chess_y = i;
			}
		}
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 100)                //抓對面將軍的位置
			{
				kingx = j;
				kingy = i;
			}
		}
	}
	if (kingx == f_0.chess_x)
	{
		for (int i = f_0.chess_y; i < y; i++)
		{
			if (chesstable[f_0.chess_x][i] != -1)
			{
				a++;
			}
		}
		if (a == 0)                           //將對將
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << kingy << endl;
			outfile.close();
			return 100;
		}
	}
	for (int i = f_0.chess_y; i < y; i++)
	{
		if ((chesstable[f_0.chess_x][i] != -1) && (chesstable[f_0.chess_x][i] == 105 || chesstable[f_0.chess_x][i] == 106))  //遇到車的情況
		{
			if (f_1_defend(chesstable, f_1) == -1 || f_1_defend(chesstable, f_1) == -2)  //呼叫士
			{
				if (f_2_defend(chesstable, f_2) == -1 || f_2_defend(chesstable, f_2) == -2) //第一隻掛掉或動不了叫第二支士
				{
					if (chesstable[5][0] == -1)       //將直接移位置
					{
						ofstream outfile;
						outfile.open("play.txt");
						outfile << "0 0 5 0" << endl;
						outfile.close();
						return 100;
					}
					else if (chesstable[5][0] == -1)
					{
						ofstream outfile;
						outfile.open("play.txt");
						outfile << "0 0 5 0" << endl;
						outfile.close();
						return 100;
					}
				}
			}
		}
	}
	if (chesstable[f_0.chess_x + 1][f_0.chess_y + 2] == 107 || chesstable[f_0.chess_x + 1][f_0.chess_y + 2] == 108)
	{
		if (chesstable[f_0.chess_x][f_0.chess_y + 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y + 1 << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[f_0.chess_x - 1][f_0.chess_y + 2] == 107 || chesstable[f_0.chess_x - 1][f_0.chess_y + 2] == 108)                       //遇到馬的情況
	{
		if (chesstable[f_0.chess_x][f_0.chess_y + 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y + 1 << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[f_0.chess_x - 2][f_0.chess_y + 1] == 107 || chesstable[f_0.chess_x - 2][f_0.chess_y + 1] == 108)
	{
		if (chesstable[f_0.chess_x - 1][f_0.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y + 1 << endl;       //遇到馬的情況
			outfile.close();
			return 100;
		}
	}
	if (chesstable[f_0.chess_x + 2][f_0.chess_y + 1] == 107 || chesstable[f_0.chess_x + 2][f_0.chess_y + 1] == 108)
	{
		if (chesstable[f_0.chess_x + 1][f_0.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y + 1 << endl;
			outfile.close();
			return 100;
		}
	}
	for (int i = f_0.chess_y; i < y; i++)
	{
		if (chesstable[f_0.chess_x][i] != -1)
		{
			for (int j = i + 1; j < y; j++)
			{
				if (chesstable[f_0.chess_x][j] != -1) {

					if (chesstable[f_0.chess_x][j] == 109 || chesstable[f_0.chess_x][j] == 110)
					{
						if (chesstable[3][0] == 1)
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "0 1 4 1" << endl;
							outfile.close();
							return 100;
						}
						else if (chesstable[3][0] == -1)                            //被砲瞄到
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "0 0 3 0" << endl;
							outfile.close();
							return 100;
						}
						else if (chesstable[5][0] == -1)
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "0 0 5 0" << endl;
							outfile.close();
							return 100;
						}
						else if (chesstable[5][0] == 2)
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "0 2 4 1" << endl;
							outfile.close();
							return 100;
						}
					}
					else {
						break;
					}
				}
			}
		}
	}
	int horsetrapx = 0;
	int horsetrapy = 0;  //用來標示有沒有陷阱(這個是將要往前吃的情況)
	for (int i = f_0.chess_y + 2; i < y; i++)
	{
		if (chesstable[f_0.chess_x][i] == 5 || chesstable[f_0.chess_x][i] == 6)      //測試是不是陷阱 前方有車
		{
			horsetrapy = 1;            //代表有陷阱
		}
	}
	for (int i = f_0.chess_x; i >= 0; i--)
	{
		if (chesstable[i][f_0.chess_y + 1] == 5 || chesstable[i][f_0.chess_y + 1] == 6)
		{
			horsetrapx = 1;
		}
	}
	for (int i = f_0.chess_x; i < x; i++)
	{
		if (chesstable[i][f_0.chess_y + 1] == 5 || chesstable[i][f_0.chess_y + 1] == 6)
		{
			horsetrapx = 1;
		}
	}
	if (chesstable[f_0.chess_x][f_0.chess_y + 1] == 5 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 6 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 7 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 8 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 9 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 10 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 11 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 12 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 13 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 14 || chesstable[f_0.chess_x][f_0.chess_y + 1] == 15)   //將軍前面有敵人
	{
		if (horsetrapx == 0 && horsetrapy == 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y + 1 << endl;
			outfile.close();
			return 100;
		}
		else if (f_1_defend(chesstable, f_1) == 100)
		{
			return 100;
		}
		else if (f_2_defend(chesstable, f_2) == 100)
		{
			return 100;
		}
		else if (chesstable[f_0.chess_x - 1][f_0.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x - 1 << " " << f_0.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_0.chess_x + 1][f_0.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x + 1 << " " << f_0.chess_y << endl;
			outfile.close();
			return 100;
		}
	}
	horsetrapx = 0;
	horsetrapy = 0;//重設 (將要往左吃的情況,只測減的方向就好)
	for (int i = f_0.chess_y - 1; i < y; i++)
	{
		if (chesstable[f_0.chess_x - 1][i] == 5 || chesstable[f_0.chess_x - 1][i] == 6)
		{
			horsetrapy = 1;
		}
	}
	for (int i = f_0.chess_x - 2; i >= 0; i--)
	{
		if (chesstable[i][f_0.chess_y] == 5 || chesstable[i][f_0.chess_y] == 6)
		{
			horsetrapx = 1;
		}
	}
	if (chesstable[f_0.chess_x - 1][f_0.chess_y] == 5 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 6 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 7 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 8 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 9 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 10 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 11 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 12 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 13 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 14 || chesstable[f_0.chess_x - 1][f_0.chess_y] == 15)   //將軍前面有敵人
	{
		if (horsetrapx == 0 && horsetrapy == 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x - 1 << " " << f_0.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_0.chess_x][f_0.chess_y - 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
	}
	horsetrapx = 0;
	horsetrapy = 0;//將往右吃
	for (int i = f_0.chess_y - 1; i < y; i++)
	{
		if (chesstable[f_0.chess_x + 1][i] == 5 || chesstable[f_0.chess_x + 1][i] == 6)
		{
			horsetrapy = 1;
		}
	}
	for (int i = f_0.chess_x + 2; i < x; i++)
	{
		if (chesstable[i][f_0.chess_y] == 5 || chesstable[i][f_0.chess_y] == 6)
		{
			horsetrapx = 1;
		}
	}
	if (chesstable[f_0.chess_x + 1][f_0.chess_y] == 5 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 6 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 7 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 8 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 9 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 10 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 11 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 12 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 13 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 14 || chesstable[f_0.chess_x + 1][f_0.chess_y] == 15)   //將軍前面有敵人
	{
		if (horsetrapx == 0 && horsetrapy == 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x + 1 << " " << f_0.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[f_0.chess_x][f_0.chess_y - 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 0" << " " << f_0.chess_x << " " << f_0.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int f_5_attack(int chesstable[x][y], tablechess)//砲的戰術不行 開始換成雙車的戰術
{
	f_5.chess = 0;
	f_5.chess_x = 0;
	f_5.chess_y = 0;
	f_5.chess_x_eat = 0;
	f_5.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 5)
			{
				f_5.chess = chesstable[j][i];
				f_5.chess_x = j;
				f_5.chess_y = i;
			}
		}
	}
	if (f_5.chess == 0)
	{
		return -1;
	}
	if (chesstable[0][1] == -1 && f_5.chess_x == 0)
	{
		if (f_5.chess_y == 0 || f_5.chess_y == 1 || f_5.chess_y == 2)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 5 0 1" << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[4][1] == -1 && f_5.chess_x == 0 && f_5.chess_y == 1 && chesstable[4][2] != 113)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "0 5 4 1" << endl;
		outfile.close();
		return 100;
	}
	return 0;
}
int f_6_attack(int chesstable[x][y], tablechess)
{
	f_6.chess = 0;
	f_6.chess_x = 0;
	f_6.chess_y = 0;
	f_6.chess_x_eat = 0;
	f_6.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 6)
			{
				f_6.chess = chesstable[j][i];
				f_6.chess_x = j;
				f_6.chess_y = i;
			}
		}
	}
	if (f_6.chess == 0)
	{
		return -1;
	}
	if (chesstable[8][1] == -1 && f_6.chess_x == 8)
	{
		if (f_6.chess_y == 0 || f_6.chess_y == 1 || f_6.chess_y == 2)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 8 1" << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[5][9] == -1 || chesstable[5][9] == 100 || chesstable[5][8] == 100)
	{
		if (chesstable[5][1] == -1 || chesstable[5][1] == 105 || chesstable[5][1] == 106 || chesstable[5][1] == 107 || chesstable[5][1] == 108 || chesstable[5][1] == 109 || chesstable[5][1] == 110)
		{
			if (f_5.chess_x == 8 && f_5.chess_y == 1)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 6 5 1" << endl;
				outfile.close();
				return 100;
			}
		}
	}
	if (chesstable[3][9] == -1 || chesstable[3][9] == 100 || chesstable[3][8] == 100)
	{
		if (chesstable[4][1] == -1 && chesstable[5][1] == -1 && chesstable[6][1] == -1 && chesstable[7][1] == -1)
		{
			if (chesstable[3][1] == -1 || chesstable[3][1] == 105 || chesstable[3][1] == 106 || chesstable[3][1] == 107 || chesstable[3][1] == 108 || chesstable[3][1] == 109 || chesstable[3][1] == 110)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "0 6 3 1" << endl;
				outfile.close();
				return 100;
			}
		}
	}
	if (f_6.chess_x == 5 && f_6.chess_y == 1)
	{
		if (chesstable[5][6] == -1 && chesstable[5][5] == -1 && chesstable[5][4] == -1 && chesstable[5][3] == -1 && chesstable[5][2] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 5 6" << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[5][5] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 5 5" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 3 && f_6.chess_y == 1)
	{
		if (chesstable[3][6] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 3 6" << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[3][5] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 3 5" << endl;
			outfile.close();
			return 100;
		}
	}
	if (f_6.chess_x == 5 && f_6.chess_y == 6)
	{
		if (chesstable[6][6] == -1 || chesstable[6][6] == 114 || chesstable[6][6] == 110 || chesstable[6][6] == 109 || chesstable[6][6] == 105 || chesstable[6][6] == 106 || chesstable[6][6] == 107 || chesstable[6][6] == 108)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 6 6" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 5 && f_6.chess_y == 5)
	{
		if (chesstable[6][5] == -1 || chesstable[6][5] == 114 || chesstable[6][5] == 110 || chesstable[6][5] == 109 || chesstable[6][5] == 105 || chesstable[6][5] == 106 || chesstable[6][5] == 107 || chesstable[6][5] == 108)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 6 5" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 3 && f_6.chess_y == 6)
	{
		if (chesstable[2][6] == -1 || chesstable[2][6] == 114 || chesstable[2][6] == 110 || chesstable[2][6] == 109 || chesstable[2][6] == 105 || chesstable[2][6] == 106 || chesstable[2][6] == 107 || chesstable[2][6] == 108)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 2 6" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 3 && f_6.chess_y == 5)
	{
		if (chesstable[2][5] == -1 || chesstable[2][5] == 114 || chesstable[2][5] == 110 || chesstable[2][5] == 109 || chesstable[2][5] == 105 || chesstable[2][5] == 106 || chesstable[2][5] == 107 || chesstable[2][5] == 108)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 2 5" << endl;
			outfile.close();
			return 100;
		}
	}
	if (f_6.chess_x == 6 && f_6.chess_y == 6)
	{
		if (chesstable[6][9] == -1 || chesstable[6][9] == 104)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 6 9" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 6 && f_6.chess_y == 5)
	{
		if (chesstable[6][9] == -1 || chesstable[6][9] == 104)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 6 9" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 2 && f_6.chess_y == 6)
	{
		if (chesstable[2][9] == -1 || chesstable[2][9] == 104)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 2 9" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (f_6.chess_x == 2 && f_6.chess_y == 5)
	{
		if (chesstable[2][9] == -1 || chesstable[2][9] == 104)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "0 6 2 9" << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int s_105_defend(int chesstable[x][y], tablechess)
{
	s_105.chess = 0;
	s_105.chess_x = 0;
	s_105.chess_y = 0;                               //每一次都要歸零 重新抓棋子位址
	s_105.chess_x_eat = 0;
	s_105.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 105)                 //找出車的位址
			{
				s_105.chess = chesstable[j][i];
				s_105.chess_x = j;
				s_105.chess_y = i;
			}
		}
	}
	if (s_105.chess == 0)                                  //車被吃掉傳出-1值
	{
		return -1;
	}
	for (int j = s_105.chess_x + 1; j < x; j++)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][s_105.chess_y] == 0)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105" << " " << j << " " << s_105.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][s_105.chess_y] == -1)
		{
			if (chesstable[j + 1][s_105.chess_y] == 0 && j + 1 != 9)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 105" << " " << j + 1 << " " << s_105.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = s_105.chess_x - 1; j >= 0; j--)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][s_105.chess_y] == 0)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105" << " " << j << " " << s_105.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][s_105.chess_y] == -1 && j - 1 != -1)
		{
			if (chesstable[j - 1][s_105.chess_y] == 0 && j - 1 != -1)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 105" << " " << j - 1 << " " << s_105.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_105.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[s_105.chess_x][i] == 0)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105" << " " << s_105.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_105.chess_x][i] == -1)
		{
			if (chesstable[s_105.chess_x][i + 1] == 0 && i + 1 != 9)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 105" << " " << s_105.chess_x << " " << i + 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_105.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[s_105.chess_x][i] == 0)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105" << " " << s_105.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_105.chess_x][i] == -1)
		{
			if (chesstable[s_105.chess_x][i - 1] == 0 && i - 1 != -1)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 105" << " " << s_105.chess_x << " " << i - 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_105.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[s_105.chess_x][i] == 1 || chesstable[s_105.chess_x][i] == 2 || chesstable[s_105.chess_x][i] == 3 || chesstable[s_105.chess_x][i] == 4 || chesstable[s_105.chess_x][i] == 5 || chesstable[s_105.chess_x][i] == 6 || chesstable[s_105.chess_x][i] == 7 || chesstable[s_105.chess_x][i] == 8 || chesstable[s_105.chess_x][i] == 9 || chesstable[s_105.chess_x][i] == 10 || chesstable[s_105.chess_x][i] == 11 || chesstable[s_105.chess_x][i] == 12 || chesstable[s_105.chess_x][i] == 13 || chesstable[s_105.chess_x][i] == 14 || chesstable[s_105.chess_x][i] == 15)
		{
			s_105.chess_x_eat = s_105.chess_x;
			s_105.chess_y_eat = i;
			return 1;
		}
		else if (chesstable[s_105.chess_x][i] == -1)
		{
			if (chesstable[s_105.chess_x][i + 1] == 1 || chesstable[s_105.chess_x][i + 1] == 2 || chesstable[s_105.chess_x][i + 1] == 3 || chesstable[s_105.chess_x][i + 1] == 4 || chesstable[s_105.chess_x][i + 1] == 5 || chesstable[s_105.chess_x][i + 1] == 6 || chesstable[s_105.chess_x][i + 1] == 7 || chesstable[s_105.chess_x][i + 1] == 8 || chesstable[s_105.chess_x][i + 1] == 9 || chesstable[s_105.chess_x][i + 1] == 10 || chesstable[s_105.chess_x][i + 1] == 11 || chesstable[s_105.chess_x][i + 1] == 12 || chesstable[s_105.chess_x][i + 1] == 13 || chesstable[s_105.chess_x][i + 1] == 14 || chesstable[s_105.chess_x][i + 1] == 15)
			{
				s_105.chess_x_eat = s_105.chess_x;
				s_105.chess_y_eat = i + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_105.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[s_105.chess_x][i] == 1 || chesstable[s_105.chess_x][i] == 2 || chesstable[s_105.chess_x][i] == 3 || chesstable[s_105.chess_x][i] == 4 || chesstable[s_105.chess_x][i] == 5 || chesstable[s_105.chess_x][i] == 6 || chesstable[s_105.chess_x][i] == 7 || chesstable[s_105.chess_x][i] == 8 || chesstable[s_105.chess_x][i] == 9 || chesstable[s_105.chess_x][i] == 10 || chesstable[s_105.chess_x][i] == 11 || chesstable[s_105.chess_x][i] == 12 || chesstable[s_105.chess_x][i] == 13 || chesstable[s_105.chess_x][i] == 14 || chesstable[s_105.chess_x][i] == 15)
		{
			s_105.chess_x_eat = s_105.chess_x;
			s_105.chess_y_eat = i;
			return 1;
		}
		else if (chesstable[s_105.chess_x][i] == -1)
		{
			if (chesstable[s_105.chess_x][i - 1] == 1 || chesstable[s_105.chess_x][i - 1] == 2 || chesstable[s_105.chess_x][i - 1] == 3 || chesstable[s_105.chess_x][i - 1] == 4 || chesstable[s_105.chess_x][i - 1] == 5 || chesstable[s_105.chess_x][i - 1] == 6 || chesstable[s_105.chess_x][i - 1] == 7 || chesstable[s_105.chess_x][i - 1] == 8 || chesstable[s_105.chess_x][i - 1] == 9 || chesstable[s_105.chess_x][i - 1] == 10 || chesstable[s_105.chess_x][i - 1] == 11 || chesstable[s_105.chess_x][i - 1] == 12 || chesstable[s_105.chess_x][i - 1] == 13 || chesstable[s_105.chess_x][i - 1] == 14 || chesstable[s_105.chess_x][i - 1] == 15)
			{
				s_105.chess_x_eat = s_105.chess_x;
				s_105.chess_y_eat = i - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = s_105.chess_x + 1; j < x; j++)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][s_105.chess_y] == 1 || chesstable[j][s_105.chess_y] == 2 || chesstable[j][s_105.chess_y] == 3 || chesstable[j][s_105.chess_y] == 4 || chesstable[j][s_105.chess_y] == 5 || chesstable[j][s_105.chess_y] == 6 || chesstable[j][s_105.chess_y] == 7 || chesstable[j][s_105.chess_y] == 8 || chesstable[j][s_105.chess_y] == 9 || chesstable[j][s_105.chess_y] == 10 || chesstable[j][s_105.chess_y] == 11 || chesstable[j][s_105.chess_y] == 12 || chesstable[j][s_105.chess_y] == 13 || chesstable[j][s_105.chess_y] == 14 || chesstable[j][s_105.chess_y] == 15)
		{
			s_105.chess_y_eat = s_105.chess_y;
			s_105.chess_x_eat = j;
			return 1;
		}
		else if (chesstable[j][s_105.chess_y] == -1)
		{
			if (chesstable[j + 1][s_105.chess_y] == 1 || chesstable[j + 1][s_105.chess_y] == 2 || chesstable[j + 1][s_105.chess_y] == 3 || chesstable[j + 1][s_105.chess_y] == 4 || chesstable[j + 1][s_105.chess_y] == 5 || chesstable[j + 1][s_105.chess_y] == 6 || chesstable[j + 1][s_105.chess_y] == 7 || chesstable[j + 1][s_105.chess_y] == 8 || chesstable[j + 1][s_105.chess_y] == 9 || chesstable[j + 1][s_105.chess_y] == 10 || chesstable[j + 1][s_105.chess_y] == 11 || chesstable[j + 1][s_105.chess_y] == 12 || chesstable[j + 1][s_105.chess_y] == 13 || chesstable[j + 1][s_105.chess_y] == 14 || chesstable[j + 1][s_105.chess_y] == 15)
			{
				s_105.chess_y_eat = s_105.chess_y;
				s_105.chess_x_eat = j + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = s_105.chess_x - 1; j >= 0; j--)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][s_105.chess_y] == 1 || chesstable[j][s_105.chess_y] == 2 || chesstable[j][s_105.chess_y] == 3 || chesstable[j][s_105.chess_y] == 4 || chesstable[j][s_105.chess_y] == 5 || chesstable[j][s_105.chess_y] == 6 || chesstable[j][s_105.chess_y] == 7 || chesstable[j][s_105.chess_y] == 8 || chesstable[j][s_105.chess_y] == 9 || chesstable[j][s_105.chess_y] == 10 || chesstable[j][s_105.chess_y] == 11 || chesstable[j][s_105.chess_y] == 12 || chesstable[j][s_105.chess_y] == 13 || chesstable[j][s_105.chess_y] == 14 || chesstable[j][s_105.chess_y] == 15)
		{
			s_105.chess_y_eat = s_105.chess_y;
			s_105.chess_x_eat = j;
			return 1;
		}
		if (chesstable[j][s_105.chess_y] == -1)
		{
			if (chesstable[j - 1][s_105.chess_y] == 1 || chesstable[j - 1][s_105.chess_y] == 2 || chesstable[j - 1][s_105.chess_y] == 3 || chesstable[j - 1][s_105.chess_y] == 4 || chesstable[j - 1][s_105.chess_y] == 5 || chesstable[j - 1][s_105.chess_y] == 6 || chesstable[j - 1][s_105.chess_y] == 7 || chesstable[j - 1][s_105.chess_y] == 8 || chesstable[j - 1][s_105.chess_y] == 9 || chesstable[j - 1][s_105.chess_y] == 10 || chesstable[j - 1][s_105.chess_y] == 11 || chesstable[j - 1][s_105.chess_y] == 12 || chesstable[j - 1][s_105.chess_y] == 13 || chesstable[j - 1][s_105.chess_y] == 14 || chesstable[j - 1][s_105.chess_y] == 15)
			{
				s_105.chess_y_eat = s_105.chess_y;
				s_105.chess_x_eat = j - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	if (chesstable[3][9] == 9 || chesstable[3][9] == 10)
	{
		if (chesstable[0][9] == 105)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105 0 8" << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int s_107_defend(int chesstable[x][y], tablechess)
{
	s_107.chess = 0;
	s_107.chess_x = 0;
	s_107.chess_y = 0;
	s_107.chess_x_eat = 0;
	s_107.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 107)
			{
				s_107.chess = chesstable[j][i];
				s_107.chess_x = j;
				s_107.chess_y = i;
			}
		}
	}
	if (s_107.chess == 0)
	{
		return -1;
	}
	if ((chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 0) && (chesstable[f_7.chess_x][f_7.chess_y - 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 107" << " " << s_107.chess_x - 1 << " " << s_107.chess_y - 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 0) && (chesstable[s_107.chess_x][s_107.chess_y - 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 107" << " " << s_107.chess_x + 1 << " " << s_107.chess_y - 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 1 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 2 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 3 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 4 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 5 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 6 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 7 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 8 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 9 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 10 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 11 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 12 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 13 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 14 || chesstable[s_107.chess_x + 1][s_107.chess_y - 2] == 15) && (chesstable[s_107.chess_x][s_107.chess_y - 1] == -1))
	{
		s_107.chess_x_eat = s_107.chess_x + 1;
		s_107.chess_y_eat = s_107.chess_y - 2;
		return 1;
	}
	if ((chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 1 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 2 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 3 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 4 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 5 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 6 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 7 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 8 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 9 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 10 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 11 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 12 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 13 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 14 || chesstable[s_107.chess_x - 1][s_107.chess_y - 2] == 15) && (chesstable[s_107.chess_x][s_107.chess_y - 1] == -1))
	{
		s_107.chess_x_eat = s_107.chess_x - 1;
		s_107.chess_y_eat = s_107.chess_y - 2;
		return 1;
	}
	return 0;
}
int s_103_defend(int chesstable[x][y], tablechess)
{
	s_103.chess = 0;
	s_103.chess_x = 0;
	s_103.chess_y = 0;
	s_103.chess_x_eat = 0;
	s_103.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 103)
			{
				s_103.chess = chesstable[j][i];
				s_103.chess_x = j;
				s_103.chess_y = i;

			}
		}
	}
	if (s_103.chess == 0)
	{
		return -1;
	}
	if ((chesstable[s_103.chess_x - 2][s_103.chess_y - 2] == 5 || chesstable[s_103.chess_x - 2][s_103.chess_y - 2] == 6 || chesstable[s_103.chess_x - 2][s_103.chess_y - 2] == 7 || chesstable[s_103.chess_x - 2][s_103.chess_y - 2] == 8) && (chesstable[s_103.chess_x - 1][s_103.chess_y - 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 103" << " " << s_103.chess_x - 2 << " " << s_103.chess_y - 2 << endl;
		outfile.close();
		return 100;
	}
	if (s_103.chess_x == 2 && s_103.chess_y == 9 && chesstable[3][8] == -1)
	{
		if (chesstable[4][7] == 13)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 103 4 7" << endl;                 //防兵直衝的情況
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int s_104_defend(int chesstable[x][y], tablechess)
{
	s_104.chess = 0;
	s_104.chess_x = 0;
	s_104.chess_y = 0;
	s_104.chess_x_eat = 0;
	s_104.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 104)
			{
				s_104.chess = chesstable[j][i];
				s_104.chess_x = j;
				s_104.chess_y = i;

			}
		}
	}
	if (s_104.chess == 0)
	{
		return -1;
	}
	if ((chesstable[s_104.chess_x + 2][s_104.chess_y - 2] == 5 || chesstable[s_104.chess_x + 2][s_104.chess_y - 2] == 6 || chesstable[s_104.chess_x + 2][s_104.chess_y - 2] == 7 || chesstable[s_104.chess_x + 2][s_104.chess_y - 2] == 8) && (chesstable[s_104.chess_x + 1][s_104.chess_y - 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 104" << " " << s_104.chess_x + 2 << " " << s_104.chess_y - 2 << endl;
		outfile.close();
		return 100;
	}
	if (s_104.chess_x == 6 && s_104.chess_y == 9 && chesstable[5][8] == -1)
	{
		if (chesstable[4][7] == 13)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 104 4 7" << endl;                 //防兵直衝的情況
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int s_106_1(int chesstable[x][y], tablechess)
{
	s_106.chess = 0;
	s_106.chess_x = 0;
	s_106.chess_y = 0;
	s_106.chess_x_eat = 0;
	s_106.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 106)
			{
				s_106.chess = chesstable[j][i];
				s_106.chess_x = j;
				s_106.chess_y = i;

			}
		}
	}
	if (s_106.chess == 0)
	{
		return -1;
	}
	for (int j = s_106.chess_x + 1; j < x; j++)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][s_106.chess_y] == 0)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106" << " " << j << " " << s_106.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][s_106.chess_y] == -1)
		{
			if (chesstable[j + 1][s_106.chess_y] == 0 && j + 1 != 9)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 106" << " " << j + 1 << " " << s_106.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = s_106.chess_x - 1; j >= 0; j--)                         //車可以吃到就直接傳出位址
	{
		if (chesstable[j][s_106.chess_y] == 0)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106" << " " << j << " " << s_106.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[j][s_106.chess_y] == -1)
		{
			if (chesstable[j - 1][s_106.chess_y] == 0 && j - 1 != -1)                      //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 106" << " " << j - 1 << " " << s_106.chess_y << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_106.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[s_106.chess_x][i] == 0)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106" << " " << s_106.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_106.chess_x][i] == -1)
		{
			if (chesstable[s_106.chess_x][i + 1] == 0 && i + 1 != 9)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 106" << " " << s_106.chess_x << " " << i + 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_106.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址
	{
		if (chesstable[s_106.chess_x][i] == 0)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106" << " " << s_106.chess_x << " " << i << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_106.chess_x][i] == -1)
		{
			if (chesstable[s_106.chess_x][i - 1] == 0 && i - 1 != -1)                 //如果可以吃到帥直接寫入檔案,程式傳出100標示
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 106" << " " << s_106.chess_x << " " << i - 1 << endl;
				outfile.close();
				return 100;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_106.chess_y + 1; i < y; i++)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[s_106.chess_x][i] == 1 || chesstable[s_106.chess_x][i] == 2 || chesstable[s_106.chess_x][i] == 3 || chesstable[s_106.chess_x][i] == 4 || chesstable[s_106.chess_x][i] == 5 || chesstable[s_106.chess_x][i] == 6 || chesstable[s_106.chess_x][i] == 7 || chesstable[s_106.chess_x][i] == 8 || chesstable[s_106.chess_x][i] == 9 || chesstable[s_106.chess_x][i] == 10 || chesstable[s_106.chess_x][i] == 11 || chesstable[s_106.chess_x][i] == 12 || chesstable[s_106.chess_x][i] == 13 || chesstable[s_106.chess_x][i] == 14 || chesstable[s_106.chess_x][i] == 15)
		{
			s_106.chess_x_eat = s_106.chess_x;
			s_106.chess_y_eat = i;
			return 1;
		}
		if (chesstable[s_106.chess_x][i] == -1)
		{
			if (chesstable[s_106.chess_x][i + 1] == 1 || chesstable[s_106.chess_x][i + 1] == 2 || chesstable[s_106.chess_x][i + 1] == 3 || chesstable[s_106.chess_x][i + 1] == 4 || chesstable[s_106.chess_x][i + 1] == 5 || chesstable[s_106.chess_x][i + 1] == 6 || chesstable[s_106.chess_x][i + 1] == 7 || chesstable[s_106.chess_x][i + 1] == 8 || chesstable[s_106.chess_x][i + 1] == 9 || chesstable[s_106.chess_x][i + 1] == 10 || chesstable[s_106.chess_x][i + 1] == 11 || chesstable[s_106.chess_x][i + 1] == 12 || chesstable[s_106.chess_x][i + 1] == 13 || chesstable[s_106.chess_x][i + 1] == 14 || chesstable[s_106.chess_x][i + 1] == 15)
			{
				s_106.chess_x_eat = s_106.chess_x;
				s_106.chess_y_eat = i + 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int i = s_106.chess_y - 1; i >= 0; i--)                      //車可以吃到就直接傳出位址(Y軸的)
	{
		if (chesstable[s_106.chess_x][i] == 1 || chesstable[s_106.chess_x][i] == 2 || chesstable[s_106.chess_x][i] == 3 || chesstable[s_106.chess_x][i] == 4 || chesstable[s_106.chess_x][i] == 5 || chesstable[s_106.chess_x][i] == 6 || chesstable[s_106.chess_x][i] == 7 || chesstable[s_106.chess_x][i] == 8 || chesstable[s_106.chess_x][i] == 9 || chesstable[s_106.chess_x][i] == 10 || chesstable[s_106.chess_x][i] == 11 || chesstable[s_106.chess_x][i] == 12 || chesstable[s_106.chess_x][i] == 13 || chesstable[s_106.chess_x][i] == 14 || chesstable[s_106.chess_x][i] == 15)
		{
			s_106.chess_x_eat = s_106.chess_x;
			s_106.chess_y_eat = i;
			return 1;
		}
		if (chesstable[s_106.chess_x][i] == -1)
		{
			if (chesstable[s_106.chess_x][i - 1] == 1 || chesstable[s_106.chess_x][i - 1] == 2 || chesstable[s_106.chess_x][i - 1] == 3 || chesstable[s_106.chess_x][i - 1] == 4 || chesstable[s_106.chess_x][i - 1] == 5 || chesstable[s_106.chess_x][i - 1] == 6 || chesstable[s_106.chess_x][i - 1] == 7 || chesstable[s_106.chess_x][i - 1] == 8 || chesstable[s_106.chess_x][i - 1] == 9 || chesstable[s_106.chess_x][i - 1] == 10 || chesstable[s_106.chess_x][i - 1] == 11 || chesstable[s_106.chess_x][i - 1] == 12 || chesstable[s_106.chess_x][i - 1] == 13 || chesstable[s_106.chess_x][i - 1] == 14 || chesstable[s_106.chess_x][i - 1] == 15)
			{
				s_106.chess_x_eat = s_106.chess_x;
				s_106.chess_y_eat = i - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	for (int j = s_106.chess_x + 1; j < x; j++)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][s_106.chess_y] == 1 || chesstable[j][s_106.chess_y] == 2 || chesstable[j][s_106.chess_y] == 3 || chesstable[j][s_106.chess_y] == 4 || chesstable[j][s_106.chess_y] == 5 || chesstable[j][s_106.chess_y] == 6 || chesstable[j][s_106.chess_y] == 7 || chesstable[j][s_106.chess_y] == 8 || chesstable[j][s_106.chess_y] == 9 || chesstable[j][s_106.chess_y] == 10 || chesstable[j][s_106.chess_y] == 11 || chesstable[j][s_106.chess_y] == 12 || chesstable[j][s_106.chess_y] == 13 || chesstable[j][s_106.chess_y] == 14 || chesstable[j][s_106.chess_y] == 15)
		{
			s_106.chess_y_eat = s_106.chess_y;
			s_106.chess_x_eat = j;
			return 1;
		}

		if (chesstable[j][s_106.chess_y] == -1)
		{
			if (chesstable[j + 1][s_106.chess_y] == 1 || chesstable[j + 1][s_106.chess_y] == 2 || chesstable[j + 1][s_106.chess_y] == 3 || chesstable[j + 1][s_106.chess_y] == 4 || chesstable[j + 1][s_106.chess_y] == 5 || chesstable[j + 1][s_106.chess_y] == 6 || chesstable[j + 1][s_106.chess_y] == 7 || chesstable[j + 1][s_106.chess_y] == 8 || chesstable[j + 1][s_106.chess_y] == 9 || chesstable[j + 1][s_106.chess_y] == 10 || chesstable[j + 1][s_106.chess_y] == 11 || chesstable[j + 1][s_106.chess_y] == 12 || chesstable[j + 1][s_106.chess_y] == 13 || chesstable[j + 1][s_106.chess_y] == 14 || chesstable[j + 1][s_106.chess_y] == 15)
			{
				s_106.chess_y_eat = s_106.chess_y;
				s_106.chess_x_eat = j + 1;
				return 1;
			}
			else
			{
				break;
			}
		}
	}
	for (int j = s_106.chess_x - 1; j >= 0; j--)                      //車可以吃到就直接傳出位址(X軸的)
	{
		if (chesstable[j][s_106.chess_y] == 1 || chesstable[j][s_106.chess_y] == 2 || chesstable[j][s_106.chess_y] == 3 || chesstable[j][s_106.chess_y] == 4 || chesstable[j][s_106.chess_y] == 5 || chesstable[j][s_106.chess_y] == 6 || chesstable[j][s_106.chess_y] == 7 || chesstable[j][s_106.chess_y] == 8 || chesstable[j][s_106.chess_y] == 9 || chesstable[j][s_106.chess_y] == 10 || chesstable[j][s_106.chess_y] == 11 || chesstable[j][s_106.chess_y] == 12 || chesstable[j][s_106.chess_y] == 13 || chesstable[j][s_106.chess_y] == 14 || chesstable[j][s_106.chess_y] == 15)
		{
			s_106.chess_y_eat = s_106.chess_y;
			s_106.chess_x_eat = j;
			return 1;
		}
		if (chesstable[j][s_106.chess_y] == -1)
		{
			if (chesstable[j - 1][s_106.chess_y] == 1 || chesstable[j - 1][s_106.chess_y] == 2 || chesstable[j - 1][s_106.chess_y] == 3 || chesstable[j - 1][s_106.chess_y] == 4 || chesstable[j - 1][s_106.chess_y] == 5 || chesstable[j - 1][s_106.chess_y] == 6 || chesstable[j - 1][s_106.chess_y] == 7 || chesstable[j - 1][s_106.chess_y] == 8 || chesstable[j - 1][s_106.chess_y] == 9 || chesstable[j - 1][s_106.chess_y] == 10 || chesstable[j - 1][s_106.chess_y] == 11 || chesstable[j - 1][s_106.chess_y] == 12 || chesstable[j - 1][s_106.chess_y] == 13 || chesstable[j - 1][s_106.chess_y] == 14 || chesstable[j - 1][s_106.chess_y] == 15)
			{
				s_106.chess_y_eat = s_106.chess_y;
				s_106.chess_x_eat = j - 1;
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
int s_108_1(int chesstable[x][y], tablechess)
{
	s_108.chess = 0;
	s_108.chess_x = 0;
	s_108.chess_y = 0;
	s_108.chess_x_eat = 0;
	s_108.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 108)
			{
				s_108.chess = chesstable[j][i];
				s_108.chess_x = j;
				s_108.chess_y = i;
			}
		}
	}
	if (s_108.chess == 0)
	{
		return -1;
	}
	if ((chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 0) && (chesstable[s_108.chess_x][s_108.chess_y - 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 108" << " " << s_108.chess_x + 1 << " " << s_108.chess_y - 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 0) && (chesstable[s_108.chess_x][s_108.chess_y + 1] == -1))
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 108" << " " << s_108.chess_x - 1 << " " << s_108.chess_y - 2 << endl;
		outfile.close();
		return 100;
	}
	if ((chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 0 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 1 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 2 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 3 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 4 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 5 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 6 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 7 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 8 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 9 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 10 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 11 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 12 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 13 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 14 || chesstable[s_108.chess_x + 1][s_108.chess_y - 2] == 15) && (chesstable[s_108.chess_x][s_108.chess_y - 1] == -1))
	{
		s_108.chess_x_eat = s_108.chess_x + 1;
		s_108.chess_y_eat = s_108.chess_y - 2;
		return 1;
	}
	if ((chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 0 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 1 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 2 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 3 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 4 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 5 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 6 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 7 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 8 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 9 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 10 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 11 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 12 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 13 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 14 || chesstable[s_108.chess_x - 1][s_108.chess_y - 2] == 15) && (chesstable[s_108.chess_x][s_108.chess_y - 1] == -1))
	{
		s_108.chess_x_eat = s_108.chess_x - 1;
		s_108.chess_y_eat = s_108.chess_y - 2;
		return 1;
	}
	return 0;
}
int s_111_1(int chesstable[x][y], tablechess)
{
	s_111.chess = 0;
	s_111.chess_x = 0;
	s_111.chess_y = 0;
	s_111.chess_x_eat = 0;
	s_111.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 111)
			{
				s_111.chess = chesstable[j][i];
				s_111.chess_x = j;
				s_111.chess_y = i;
			}
		}
	}
	if (s_111.chess == 0)
	{
		return -1;
	}
	if (chesstable[s_111.chess_x][s_111.chess_y + 1] == 5 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 6 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 7 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 8 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 9 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 10 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 11 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 12 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 13 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 14 || chesstable[s_111.chess_x][s_111.chess_y + 1] == 15)
	{
		s_111.chess_x_eat = s_111.chess_x;
		s_111.chess_y_eat = s_111.chess_y + 1;
		return 1;
	}
	return 0;
}
int s_112_1(int chesstable[x][y], tablechess)
{
	s_112.chess = 0;
	s_112.chess_x = 0;
	s_112.chess_y = 0;
	s_112.chess_x_eat = 0;
	s_112.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 112)
			{
				s_112.chess = chesstable[j][i];
				s_112.chess_x = j;
				s_112.chess_y = i;
			}
		}
	}
	if (s_112.chess == 0)
	{
		return -1;
	}
	if (chesstable[s_112.chess_x][s_112.chess_y + 1] == 5 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 6 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 7 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 8 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 9 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 10 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 11 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 12 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 13 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 14 || chesstable[s_112.chess_x][s_112.chess_y + 1] == 15)
	{
		s_112.chess_x_eat = s_112.chess_x;
		s_112.chess_y_eat = s_112.chess_y + 1;
		return 1;
	}
	return 0;
}
int s_114_1(int chesstable[x][y], tablechess)
{
	s_114.chess = 0;
	s_114.chess_x = 0;
	s_114.chess_y = 0;
	s_114.chess_x_eat = 0;
	s_114.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 114)
			{
				s_114.chess = chesstable[j][i];
				s_114.chess_x = j;
				s_114.chess_y = i;
			}
		}
	}
	if (s_114.chess == 0)
	{
		return -1;
	}
	if (chesstable[s_114.chess_x][s_114.chess_y + 1] == 5 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 6 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 7 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 8 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 9 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 10 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 11 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 12 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 13 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 14 || chesstable[s_114.chess_x][s_114.chess_y + 1] == 15)
	{
		s_114.chess_x_eat = s_114.chess_x;
		s_114.chess_y_eat = s_114.chess_y + 1;
		return 1;
	}
	return 0;
}
int s_115_1(int cheestable[x][y], tablechess)
{
	s_115.chess = 0;
	s_115.chess_x = 0;
	s_115.chess_y = 0;
	s_115.chess_x_eat = 0;
	s_115.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 115)
			{
				s_115.chess = chesstable[j][i];
				s_115.chess_x = j;
				s_115.chess_y = i;
			}
		}
	}
	if (s_115.chess == 0)
	{
		return -1;
	}
	if (chesstable[s_115.chess_x][s_115.chess_y + 1] == 5 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 6 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 7 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 8 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 9 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 10 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 11 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 12 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 13 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 14 || chesstable[s_115.chess_x][s_115.chess_y + 1] == 15)
	{
		s_115.chess_x_eat = s_115.chess_x;
		s_115.chess_y_eat = s_115.chess_y + 1;
		return 1;
	}
	return 0;
}
int s_113_attack(int chesstable[x][y], tablechess)
{
	s_113.chess = 0;
	s_113.chess_x = 0;
	s_113.chess_y = 0;
	s_113.chess_x_eat = 0;
	s_113.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 113)
			{
				s_113.chess = chesstable[j][i];
				s_113.chess_x = j;
				s_113.chess_y = i;
			}
		}
	}
	if (s_113.chess == 0)
	{
		return -1;
	}
	if (s_113.chess_y > 4)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 113" << " " << s_113.chess_x << " " << s_113.chess_y - 1 << endl;
		outfile.close();
		return 2;
	}
	if (s_113.chess_y == 4 && s_113.chess_x == 4)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 113" << " " << s_113.chess_x + 1 << " " << s_113.chess_y << endl;
		outfile.close();
		return 3;
	}
	return 0;
}
int s_109_attack(int chesstable[x][y], tablechess)
{
	s_109.chess = 0;
	s_109.chess_x = 0;
	s_109.chess_y = 0;
	s_109.chess_x_eat = 0;
	s_109.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 109)
			{
				s_109.chess = chesstable[j][i];
				s_109.chess_x = j;
				s_109.chess_y = i;
			}
		}
	}
	if (s_109.chess == 0)
	{
		return -1;
	}
	if (chesstable[4][7] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 109 4 7" << endl;
		outfile.close();
		return 100;
	}
	for (int i = s_109.chess_y - 1; i >= 0; i--)
	{
		if (chesstable[s_109.chess_x][i] != -1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (chesstable[s_109.chess_x][j] == 0)
				{
					ofstream outfile;
					outfile.open("play.txt");
					outfile << "1 109" << " " << s_109.chess_x << " " << j << endl;
					outfile.close();
					return 100;
				}
				else if (chesstable[s_109.chess_x][j] != -1)
				{
					return 0;
				}
			}
		}
	}
	return 0;
}
int s_110_attack(int chesstable[x][y], tablechess)
{
	s_110.chess = 0;
	s_110.chess_x = 0;
	s_110.chess_y = 0;
	s_110.chess_x_eat = 0;
	s_110.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 110)
			{
				s_110.chess = chesstable[j][i];
				s_110.chess_x = j;
				s_110.chess_y = i;
			}
		}
	}
	if (s_110.chess == 0)
	{
		return -1;
	}
	for (int i = s_110.chess_y - 1; i >= 0; i--)
	{
		if (chesstable[s_110.chess_x][i] != -1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (chesstable[s_110.chess_x][j] == 0)
				{
					ofstream outfile;
					outfile.open("play.txt");
					outfile << "1 110" << " " << s_110.chess_x << " " << j << endl;
					outfile.close();
					return 100;
				}
				else if (chesstable[s_110.chess_x][j] != -1)
				{
					break;
				}
			}
		}
	}
	if (s_110.chess_x == 7 && s_110.chess_y == 7 && chesstable[7][6] == -1 && chesstable[7][5] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 110 7 5" << endl;
		outfile.close();
		return 2;
	}
	else
	{
		return -1;
	}
	if (s_110.chess_x == 7 && s_110.chess_y == 5 && chesstable[6][5] == -1 && chesstable[5][5] == -1 && chesstable[4][5] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 110 4 5" << endl;
		outfile.close();
		return 3;
	}
	else if (chesstable[7][4] == -1 && chesstable[6][4] == -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 110 7 4" << endl;
		outfile.close();
		return 3;
	}
	else
	{
		return -1;
	}
	if (chesstable[5][4] == -1 && chesstable[4][4] == -1 && chesstable[4][3] != 13)
	{
		if (s_110.chess_x == 7 && s_110.chess_y == 4)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 110 4 4" << endl;
			outfile.close();
			return 3;
		}
	}
	else if (s_110.chess_x == 4 && s_110.chess_y == 4)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 110 5 4" << endl;
		outfile.close();
		return 3;
	}
	if (chesstable[5][5] == -1 && s_110.chess_x == 5 && s_110.chess_y == 4)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 110 5 5" << endl;
		outfile.close();
		return 3;
	}
	else
	{
		return -1;
	}
	if (chesstable[4][5] == -1 && s_110.chess_x == 5 && s_110.chess_y == 5)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 110 4 5" << endl;
		outfile.close();
		return 3;
	}
	else
	{
		return -1;
	}
	return 0;
}
int s_101_defend(int chesstable[x][y], tablechess)
{
	s_101.chess = 0;
	s_101.chess_x = 0;
	s_101.chess_y = 0;                               //每一次都要歸零 重新抓棋子位址
	s_101.chess_x_eat = 0;
	s_101.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 101)                 //找出士的位址
			{
				s_101.chess = chesstable[j][i];
				s_101.chess_x = j;
				s_101.chess_y = i;
			}
		}
	}
	if (s_101.chess == 0)                                  //士被吃掉傳出-1值
	{
		return -1;
	}
	if (s_101.chess_x == 3 && s_101.chess_y == 9 && chesstable[4][8] != -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 101 4 8" << endl;
		outfile.close();
		return 100;
	}
	else
	{
		return -2;
	}
	return 0;
}
int s_102_defend(int chesstable[x][y], tablechess)
{
	s_102.chess = 0;
	s_102.chess_x = 0;
	s_102.chess_y = 0;                               //每一次都要歸零 重新抓棋子位址
	s_102.chess_x_eat = 0;
	s_102.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 102)                 //找出士的位址
			{
				s_102.chess = chesstable[j][i];
				s_102.chess_x = j;
				s_102.chess_y = i;
			}
		}
	}
	if (s_102.chess == 0)                                  //士被吃掉傳出-1值
	{
		return -1;
	}
	if (s_102.chess_x == 5 && s_102.chess_y == 9 && chesstable[4][8] != -1)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 102 4 8" << endl;
		outfile.close();
		return 100;
	}
	else
	{
		return -2;
	}
	return 0;
}
int s_100_defend(int chesstable[x][y], tablechess)
{
	s_100.chess = 0;
	s_100.chess_x = 0;
	s_100.chess_y = 0;
	s_100.chess_x_eat = 0;
	s_100.chess_y_eat = 0;
	int a = 0;
	int kingx = 0;
	int kingy = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 100)
			{
				s_100.chess = chesstable[j][i];
				s_100.chess_x = j;
				s_100.chess_y = i;
			}
		}
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 0)                //抓對面將軍的位置
			{
				kingx = j;
				kingy = i;
			}
		}
	}
	if (kingx == s_100.chess_x)
	{
		for (int i = s_100.chess_y; i >= 0; i--)
		{
			if (chesstable[s_100.chess_x][i] != -1)
			{
				a++;
			}
		}
		if (a == 0)                           //將對將
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << kingy << endl;
			outfile.close();
			return 100;
		}
	}
	for (int i = s_100.chess_y; i >= 0; i--)
	{
		if ((chesstable[s_100.chess_x][i] != -1) && (chesstable[s_100.chess_x][i] == 5 || chesstable[s_100.chess_x][i] == 6))
		{
			if (s_101_defend(chesstable, s_101) == -1 || s_101_defend(chesstable, s_101) == -2)
			{
				if (s_102_defend(chesstable, s_102) == -1 || s_102_defend(chesstable, s_102) == -2)
				{
					if (chesstable[5][9] == -1)
					{
						ofstream outfile;
						outfile.open("play.txt");
						outfile << "1 100 5 9" << endl;
						outfile.close();
						return 100;
					}
					else if (chesstable[3][9] == -1)                                //遇到車的情況
					{
						ofstream outfile;
						outfile.open("play.txt");
						outfile << "1 100 3 9" << endl;
						outfile.close();
						return 100;
					}
				}
			}
		}
	}
	if (chesstable[s_100.chess_x + 1][s_100.chess_y - 2] == 7 || chesstable[s_100.chess_x + 1][s_100.chess_y - 2] == 8)
	{
		if (chesstable[s_100.chess_x][s_100.chess_y - 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[s_100.chess_x - 1][s_100.chess_y - 2] == 7 || chesstable[s_100.chess_x - 1][s_100.chess_y - 2] == 8)                       //遇到馬的情況
	{
		if (chesstable[s_100.chess_x][s_100.chess_y - 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[s_100.chess_x - 2][s_100.chess_y - 1] == 7 || chesstable[s_100.chess_x - 2][s_100.chess_y + 1] == 8)
	{
		if (chesstable[s_100.chess_x - 1][s_100.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y - 1 << endl;       //遇到馬的情況
			outfile.close();
			return 100;
		}
	}
	if (chesstable[s_100.chess_x + 2][s_100.chess_y + 1] == 7 || chesstable[s_100.chess_x + 2][s_100.chess_y + 1] == 8)
	{
		if (chesstable[s_100.chess_x + 1][s_100.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y + 1 << endl;
			outfile.close();
			return 100;
		}
	}
	for (int i = s_100.chess_y; i >= 0; i--)
	{
		if (chesstable[s_100.chess_x][i] != -1)
		{
			for (int j = s_100.chess_y - 1; j >= 0; j--)
			{
				if (chesstable[s_100.chess_x][j] != -1) {
					if (chesstable[s_100.chess_x][j] == 9 || chesstable[s_100.chess_x][j] == 10)
					{
						if (chesstable[3][9] == 101)
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "1 101 4 8" << endl;
							outfile.close();
							return 100;
						}
						else if (chesstable[3][9] == -1)                            //被砲瞄到
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "1 100 3 9" << endl;
							outfile.close();
							return 100;
						}
						else if (chesstable[5][9] == -1)
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "1 100 5 9" << endl;
							outfile.close();
							return 100;
						}
						else if (chesstable[5][9] == 102)
						{
							ofstream outfile;
							outfile.open("play.txt");
							outfile << "1 102 4 8" << endl;
							outfile.close();
							return 100;
						}
					}
					else {
						break;
					}
				}
			}
		}
	}
	int horsetrapx = 0;
	int horsetrapy = 0;  //用來標示有沒有陷阱(這個是將要往前吃的情況)
	for (int i = s_100.chess_y - 2; i >= 0; i--)
	{
		if (chesstable[s_100.chess_x][i] == 5 || chesstable[s_100.chess_x][i] == 6)      //測試是不是陷阱 前方有車
		{
			horsetrapy = 1;            //代表有陷阱
		}
		else if (chesstable[s_100.chess_x][i] != -1)
		{
			horsetrapy = 0;
		}
	}
	for (int i = s_100.chess_x; i >= 0; i--)
	{
		if (chesstable[i][s_100.chess_y - 1] == 5 || chesstable[i][s_100.chess_y - 1] == 6)
		{
			horsetrapx = 1;
		}
		else if (chesstable[i][s_100.chess_y - 1] != -1)
		{
			horsetrapx = 0;
		}
	}
	for (int i = s_100.chess_x; i < x; i++)
	{
		if (chesstable[i][s_100.chess_y - 1] == 5 || chesstable[i][s_100.chess_y - 1] == 6)
		{
			horsetrapx = 1;
		}
		else if (chesstable[i][s_100.chess_y - 1] != -1)
		{
			horsetrapx = 0;
		}
	}
	if (chesstable[s_100.chess_x][s_100.chess_y - 1] == 5 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 6 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 7 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 8 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 9 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 10 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 11 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 12 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 13 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 14 || chesstable[s_100.chess_x][s_100.chess_y - 1] == 15)   //將軍前面有敵人
	{
		if (horsetrapx == 0 && horsetrapy == 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
		else if (s_101_defend(chesstable, s_101) == 100)
		{
			return 100;
		}
		else if (s_102_defend(chesstable, s_102) == 100)
		{
			return 100;
		}
		else if (chesstable[s_100.chess_x - 1][s_100.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x - 1 << " " << s_100.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_100.chess_x + 1][s_100.chess_y] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x + 1 << " " << s_100.chess_y << endl;
			outfile.close();
			return 100;
		}
	}
	horsetrapx = 0;
	horsetrapy = 0;//重設 (將要往左吃的情況,只測減的方向就好)
	for (int i = s_100.chess_y - 1; i >= 0; i--)
	{
		if (chesstable[s_100.chess_x - 1][i] == 5 || chesstable[s_100.chess_x - 1][i] == 6)
		{
			horsetrapy = 1;
		}
		else if (chesstable[s_100.chess_x - 1][i] != -1)
		{
			horsetrapy = 0;
		}
	}
	for (int i = s_100.chess_x - 2; i >= 0; i--)
	{
		if (chesstable[i][s_100.chess_y] == 5 || chesstable[i][s_100.chess_y] == 6)
		{
			horsetrapx = 1;
		}
		else if (chesstable[i][s_100.chess_y] != -1)
		{
			horsetrapx = 0;
		}
	}
	if (chesstable[s_100.chess_x - 1][s_100.chess_y] == 5 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 6 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 7 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 8 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 9 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 10 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 11 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 12 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 13 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 14 || chesstable[s_100.chess_x - 1][s_100.chess_y] == 15)   //將軍前面有敵人
	{
		if (horsetrapx == 0 && horsetrapy == 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x - 1 << " " << s_100.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_100.chess_x][s_100.chess_y - 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
	}
	horsetrapx = 0;
	horsetrapy = 0;//將往右吃
	for (int i = s_100.chess_y - 1; i >= 0; i--)
	{
		if (chesstable[s_100.chess_x + 1][i] == 5 || chesstable[s_100.chess_x + 1][i] == 6)
		{
			horsetrapy = 1;
		}
		else if (chesstable[s_100.chess_x + 1][i] != -1)
		{
			horsetrapy = 0;
		}
	}
	for (int i = s_100.chess_x + 2; i < x; i++)
	{
		if (chesstable[i][s_100.chess_y] == 5 || chesstable[i][s_100.chess_y] == 6)
		{
			horsetrapx = 1;
		}
		else if (chesstable[i][s_100.chess_y] != -1)
		{
			horsetrapx = 0;
		}
	}
	if (chesstable[s_100.chess_x + 1][s_100.chess_y] == 5 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 6 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 7 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 8 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 9 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 10 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 11 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 12 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 13 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 14 || chesstable[s_100.chess_x + 1][s_100.chess_y] == 15)   //將軍前面有敵人
	{
		if (horsetrapx == 0 && horsetrapy == 0)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x + 1 << " " << s_100.chess_y << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[s_100.chess_x][s_100.chess_y - 1] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 100" << " " << s_100.chess_x << " " << s_100.chess_y - 1 << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
int s_105_attack(int chesstable[x][y], tablechess)
{
	s_105.chess = 0;
	s_105.chess_x = 0;
	s_105.chess_y = 0;
	s_105.chess_x_eat = 0;
	s_105.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 105)
			{
				s_105.chess = chesstable[j][i];
				s_105.chess_x = j;
				s_105.chess_y = i;
			}
		}
	}
	if (s_105.chess == 0)
	{
		return -1;
	}
	if (chesstable[0][8] == -1 && s_105.chess_x == 0)
	{
		if (s_105.chess_y == 9 || s_105.chess_y == 8 || s_105.chess_y == 7)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 105 0 8" << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[4][8] == -1 && s_105.chess_x == 0 && s_105.chess_y == 8 && chesstable[4][7] != 13)
	{
		ofstream outfile;
		outfile.open("play.txt");
		outfile << "1 105 4 8" << endl;
		outfile.close();
		return 100;
	}
	return 0;
}
int s_106_attack(int chesstable[x][y], tablechess)
{
	s_106.chess = 0;
	s_106.chess_x = 0;
	s_106.chess_y = 0;
	s_106.chess_x_eat = 0;
	s_106.chess_y_eat = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (chesstable[j][i] == 106)
			{
				s_106.chess = chesstable[j][i];
				s_106.chess_x = j;
				s_106.chess_y = i;
			}
		}
	}
	if (s_106.chess == 0)
	{
		return -1;
	}
	if (chesstable[8][8] == -1 && s_106.chess_x == 8)
	{
		if (s_106.chess_y == 7 || s_106.chess_y == 8 || s_106.chess_y == 9)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 8 8" << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[5][0] == -1 || chesstable[5][0] == 0 || chesstable[5][1] == 0)
	{
		if (chesstable[5][8] == -1 || chesstable[5][8] == 5 || chesstable[5][8] == 6 || chesstable[5][8] == 7 || chesstable[5][8] == 8 || chesstable[5][8] == 9 || chesstable[5][8] == 10)
		{
			if (s_106.chess_x == 8 && s_106.chess_y == 8)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 106 5 8" << endl;
				outfile.close();
				return 100;
			}
		}
	}
	if (chesstable[3][0] == -1 || chesstable[3][0] == 0 || chesstable[3][1] == 0)
	{
		if (chesstable[4][8] == -1 && chesstable[5][8] == -1 && chesstable[6][8] == -1 && chesstable[7][8] == -1)
		{
			if (chesstable[3][8] == -1 || chesstable[3][8] == 5 || chesstable[3][8] == 6 || chesstable[3][8] == 7 || chesstable[3][8] == 8 || chesstable[3][8] == 9 || chesstable[3][8] == 10)
			{
				ofstream outfile;
				outfile.open("play.txt");
				outfile << "1 106 3 8" << endl;
				outfile.close();
				return 100;
			}
		}
	}
	if (s_106.chess_x == 5 && s_106.chess_y == 8)
	{
		if (chesstable[5][3] == -1 && chesstable[5][4] == -1 && chesstable[5][5] == -1 && chesstable[5][6] == -1 && chesstable[5][7] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 5 3" << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[5][4] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 5 4" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 3 && s_106.chess_y == 8)
	{
		if (chesstable[3][3] == -1 && chesstable[3][4] == -1 && chesstable[3][5] == -1 && chesstable[3][6] == -1 && chesstable[3][7] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 3 3" << endl;
			outfile.close();
			return 100;
		}
		else if (chesstable[3][4] == -1)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 3 4" << endl;
			outfile.close();
			return 100;
		}
	}
	if (s_106.chess_x == 5 && s_106.chess_y == 3)
	{
		if (chesstable[6][3] == -1 || chesstable[6][3] == 14 || chesstable[6][3] == 10 || chesstable[6][3] == 9 || chesstable[6][3] == 5 || chesstable[6][3] == 6 || chesstable[6][3] == 7 || chesstable[6][3] == 8)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 6 3" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 5 && s_106.chess_y == 4)
	{
		if (chesstable[6][4] == -1 || chesstable[6][4] == 14 || chesstable[6][4] == 10 || chesstable[6][4] == 9 || chesstable[6][4] == 5 || chesstable[6][4] == 6 || chesstable[6][4] == 7 || chesstable[6][4] == 8)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 6 4" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 3 && s_106.chess_y == 3)
	{
		if (chesstable[2][3] == -1 || chesstable[2][3] == 14 || chesstable[2][3] == 10 || chesstable[2][3] == 9 || chesstable[2][3] == 5 || chesstable[2][3] == 6 || chesstable[2][3] == 7 || chesstable[2][3] == 8)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 2 3" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 3 && s_106.chess_y == 4)
	{
		if (chesstable[2][4] == -1 || chesstable[2][4] == 14 || chesstable[2][4] == 10 || chesstable[2][4] == 9 || chesstable[2][4] == 5 || chesstable[2][4] == 6 || chesstable[2][4] == 7 || chesstable[2][4] == 8)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 2 4" << endl;
			outfile.close();
			return 100;
		}
	}
	if (s_106.chess_x == 6 && s_106.chess_y == 3)
	{
		if (chesstable[6][0] == -1 || chesstable[6][0] == 4)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 6 0" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 6 && s_106.chess_y == 4)
	{
		if (chesstable[6][0] == -1 || chesstable[6][0] == 4)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 6 0" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 2 && s_106.chess_y == 3)
	{
		if (chesstable[2][0] == -1 || chesstable[2][0] == 4)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 2 0" << endl;
			outfile.close();
			return 100;
		}
	}
	else if (s_106.chess_x == 2 && s_106.chess_y == 4)
	{
		if (chesstable[2][0] == -1 || chesstable[2][0] == 4)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 2 0" << endl;
			outfile.close();
			return 100;
		}
	}
	if (chesstable[5][9] == 9 || chesstable[5][9] == 10)
	{
		if (chesstable[8][9] == 106)
		{
			ofstream outfile;
			outfile.open("play.txt");
			outfile << "1 106 8 8" << endl;
			outfile.close();
			return 100;
		}
	}
	return 0;
}
