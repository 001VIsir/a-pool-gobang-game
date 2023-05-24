#include <stdio.h>
#include <stdlib.h>

 //程序设计作业1，五子棋 
const int max = 15;//在这里改变棋盘大小 
char map[max][max];//用二维数组存储棋盘 
int turn = 0;//黑白回合 ，默认黑子先行 
bool judge = true;//是否结束游戏的标志
int h, l;//输入的行和列 
int xia = 8;//判断下子之后需不需要进入到判断输赢 
char winner = 'r';//存储赢方,'r'代表平局 
 
bool menu()//菜单 
{
	printf("=================================\n");
	printf("请问是否开始，输入1开始,输入0结束\n");
	printf("=================================\n");
	int b;
	scanf("%d", &b);
	if(b == 1)
	return true;
	else
	return false;
}

void int_map()//初始化 
{
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			map[i][j] = '+';//用+表示空白 
		}
	}
	turn = 0;
	judge = true;
	winner = 'r';
}

void chess()//下棋落子函数
{
	scanf("%d%d", &h, &l);//输入行列 
	if(h > max || h < 0 || l > max || l < 0 || map[h-1][l-1] != '+')
	{
		printf("\n");
		printf("\n");
		printf("================================\n");
		printf("下那个地方不合法，请重新选个位置\n");
		printf("================================\n");
		xia = 0;
		return;
	}
	else if(turn >= max * max)
	{
		printf("\n");
		printf("\n");
		printf("===========================\n");
		printf("棋盘满了噢， 请重新选个位置\n");
		printf("===========================\n");
		xia = 0;
		return;
	}
	else if(turn & 1)//如果是奇数就是白棋动 
	{
		map[h-1][l-1] = 'o';//白棋为o 
		xia = 1;
		turn++; //回合自加进入到下一个子 
	}
	else//偶数为黑 
	{
		map[h-1][l-1] = 'v';//黑棋为v 
		xia = 1;
		turn++;
	}
 } 
 
void print()//打印棋盘 
{
	system("cls");//刷新
	printf("\n");
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max; j++)
		{
			printf("%c ", map[i][j]);//普通遍历数组 
		}
		printf("\n");
	}
//	printf("\n");
//	printf("\n");
}

void lose_win()//判断输赢， 思路为从四个方向遍历 
{
	int count = 1;//计数,因为已经下了一个子所以从1开始 
	char temp = map[h-1][l-1];//一个临时的储存现在下的子是什么颜色之后用来跳出循环 
	for(int x = 0; x == 0; x++)//水平方向
	{
		for(int i = 1; map[h-1-i][l-1] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1+i][l-1] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)//连成的个数超过5个就结束跳出函数 
	{
		winner = temp;
		judge = false;
		return;
	}
	count = 1;//每次遍历一个方向后就重置 
	for(int x = 0; x == 0; x++)//竖直方向 
	{
		for(int i = 1; map[h-1][l-1-i] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1][l-1+i] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)
	{
		winner = temp;
		judge = false;
		return;
	}
	count = 1;
	for(int x = 0; x == 0; x++)//'\'方向 
	{
		for(int i = 1; map[h-1-i][l-1-i] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1+i][l-1+i] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)
	{
		winner = temp;
		judge = false;
		return;
	}
	count = 1;
	for(int x = 0; x == 0; x++)//'/'方向 
	{
		for(int i = 1; map[h-1+i][l-1-i] == temp; i++)
		{
			count++;
		}
		 for(int i = 1; map[h-1-i][l-1+i] == temp; i++)
		{
			count++;
		}
	}
	if(count >= 5)
	{
		winner = temp;
		judge = false;
		return;
	}
}

int main()//主函数 
{
	if(!menu())//输入0结束 
	{
		printf("欢迎以后再来玩");
	}
	else//输入1游戏开始 
	{
		c:;
		printf("游戏规则：黑子先行，黑子为'v'，白子为'o'，若在水平、竖直或斜方向连成五颗相同的棋子则获胜\n");
		int_map();
		do{
			print();//给玩家看一下棋盘是什么情况 
			if(turn & 1)
			{
				printf("现在是白子回合， 请输入下棋坐标，格式为：行+空格+列。如:1 2\n"); 
			}
			else
			{
				printf("现在是黑子回合， 请输入下棋坐标，格式为：行+空格+列。如:1 2\n"); 
			}
			chess();//下子 
			if(xia == 1)//如果下的位置合法进入到判断输赢 
			lose_win();//判断输赢 
		}while(judge != false);//若判断结果不为假则一直继续 
		print();
		if(winner == 'o')
		printf("白棋获胜"); 
		else if(winner == 'v')
		printf("黑棋获胜"); 
		else
		printf("平局");
		printf("\n请问是否再来一局，再来一局请输入1， 结束游戏请输入2\n");//这里是判断是否要再来一局 
	int k;
	scanf("%d", &k);
	if(k == 1)//输入1 就再来一局 
	goto c;
	else
	printf("游戏结束，欢迎下次再玩");
	}
	return 0;
}
