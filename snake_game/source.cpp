#include <iostream>
#include <Windows.h>
#include <queue>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

#define MAPSIZE 32

char map[MAPSIZE][MAPSIZE];



struct Pos
{
	int x, y;
};
Pos direction[4] = { {0,1},{-1,0},{0,-1},{1,0} };

struct Snake
{
	int snake_length;
	int current_dir;
	
	queue<Pos> body;

};

clock_t timeLaps;

void Initialize(Snake&);

int Input();

bool Update(int,Snake&);

void Display();

Pos make_fruit(Snake&);



int main()
{
	
	Snake snake;

	srand(time(NULL));
	bool running = true;
	int dir=0;
	Initialize(snake);
	

	timeLaps = clock();
	while (running)
	{
		dir = Input();
		running = Update(dir,snake);
		Display();
	}
	
}

void Initialize(Snake& snake)
{
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (i == 0 || j == 0 || i == MAPSIZE - 1 || j == MAPSIZE - 1)
				map[i][j] = 'O';
			else
				map[i][j] = ' ';
		}
	}
	map[15][15] = 'D';
	snake.snake_length = 1;
	snake.current_dir = 0;
	snake.body.push({ 15,15 });
	int x = rand() % 30 + 1;
	int y = rand() % 30 + 1;
	map[x][y] = '&';
}

int Input()
{
	
	if (_kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 'a':
			//시계 반대방향
			return -1;
		case 'd':
			//시계 방향
			return 1;
		default:
			break;
		}
	}
	return 0;
}

bool Update(int dir,Snake& snake)
{
	clock_t after_timeLaps = clock();
	while (after_timeLaps - timeLaps < 200)
	{
		after_timeLaps = clock();
	}
	timeLaps = after_timeLaps;
	
	

	bool running = true;
	Pos head = snake.body.back();
	//벽과 충돌 처리
	if (head.x == 0 || head.x == MAPSIZE - 1 ||
		snake.body.back().y == 0 || snake.body.back().y == MAPSIZE - 1)
		running = false;
	//몸통과 충돌 처리
	if (map[head.x][head.y] == '□')
		running = false;



	//열매 충돌 처리
	if (map[head.x][head.y] != '&')
	{
		map[snake.body.front().x][snake.body.front().y] = ' ';
		snake.body.pop();
	}
	else
	{
		snake.snake_length++;
		int x = rand() % 30 + 1;
		int y = rand() % 30 + 1;
		map[x][y] = '&';
	}
	snake.current_dir = (snake.current_dir + dir + 4) % 4;
	snake.body.push({ direction[snake.current_dir].x + head.x, direction[snake.current_dir].y + head.y });
	map[snake.body.back().x][snake.body.back().y] = 'D';

	return running;
}

void Display()
{
	system("cls");
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	//Sleep(1000);
}

