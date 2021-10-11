#include<iostream>
#include<vector>
using namespace std;

void check_danger(int, int, vector<vector<int>>&);//�������� ǥ��
void go_safe(int, int,int,int, vector<vector<int>>&,int);//������ġ�� ���� �ּ�Ƚ�� ǥ��

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, ax, ay, bx, by, cx, cy, dx, dy;
		cin >> N; // ��ǥ���
		cin >> ax >> ay >> bx >> by;//������ ��ġ, ���������� ��ġ
		cin >> cx >> cy >> dx >> dy;//�˻��� ��ġ, ���Ѽ��� ��ġ
		vector<vector<int>> map(N,vector<int>(N,0));
		map[cx-1][cy-1] = -2;//�˻���ġ
		check_danger(dx-1, dy-1, map);
		go_safe(ax-1, ay-1, bx-1, by-1, map, 0);
		cout << map[bx-1][by-1] << endl;
	}
}

void go_safe(int x, int y,int sx,int sy, vector<vector<int>>& map,int d)
{
	if (x < 0 || y < 0 || x >= map.size() || y >= map.size())
		return;
	if (map[x][y] < 0)//�������� �ƴϸ�
		return;
	if (map[x][y] == 0 || map[x][y] > d)
		map[x][y] = d;
	else
		return;
	int dirx = sx - x;
	int diry = sy - y;
	if (dirx > 0 && diry > 0)//3
	{
		
		go_safe(x+1, y+1, sx, sy, map, d + 1);
		go_safe(x+1, y, sx, sy, map, d + 1);
		go_safe(x, y+1, sx, sy, map, d + 1);
	}
	else if (dirx > 0 && diry < 0)//9
	{
		
		go_safe(x+1, y-1, sx, sy, map, d + 1);
		go_safe(x+1, y, sx, sy, map, d + 1);
		go_safe(x, y-1, sx, sy, map, d + 1);
	}
	else if (dirx < 0 && diry>0)//1
	{
		
		go_safe(x-1, y+1, sx, sy, map, d + 1);
		go_safe(x-1, y, sx, sy, map, d + 1);
		go_safe(x, y+1, sx, sy, map, d + 1);
	}
	else if (dirx < 0 && diry < 0)//7
	{
		
		go_safe(x-1, y-1, sx, sy, map, d + 1);
		go_safe(x-1, y, sx, sy, map, d + 1);
		go_safe(x, y-1, sx, sy, map, d + 1);
	}
	else if (dirx == 0 && diry > 0)//2
	{
		go_safe(x, y + 1, sx, sy, map, d + 1);
		go_safe(x + 1, y + 1, sx, sy, map, d + 1);
		go_safe(x - 1, y + 1, sx, sy, map, d + 1);
	}
	else if (dirx == 0 && diry < 0)//8
	{
		go_safe(x, y - 1, sx, sy, map, d + 1);
		go_safe(x + 1, y - 1, sx, sy, map, d + 1);
		go_safe(x - 1, y - 1, sx, sy, map, d + 1);
	}
	else if (dirx > 0 && diry == 0)//6
	{
		go_safe(x + 1, y, sx, sy, map, d + 1);
		go_safe(x + 1, y + 1, sx, sy, map, d + 1);
		go_safe(x + 1, y - 1, sx, sy, map, d + 1);
	}
	else if (dirx < 0 && diry == 0)//4
	{
		go_safe(x - 1, y , sx, sy, map, d + 1);
		go_safe(x - 1, y + 1, sx, sy, map, d + 1);
		go_safe(x - 1, y - 1, sx, sy, map, d + 1);
	}
	else//5
	{
		return;
	}
}

void check_danger(int x, int y, vector<vector<int>>& map)
{
	int tmp_x = x-1;
	int tmp_y = y-1;
	while (tmp_x >= 0 && tmp_y >= 0) // x- y-
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_x--;
		tmp_y--;
	}

	

	tmp_x = x + 1;
	tmp_y = y + 1;
	while (tmp_x < map.size() && tmp_y < map.size())//x+ y+
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_x++;
		tmp_y++;
	}



	tmp_x = x+1;
	tmp_y = y-1;
	while (tmp_x < map.size() && tmp_y >= 0)//x+ y-
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_x++;
		tmp_y--;
	}

	

	tmp_x = x - 1;
	tmp_y = y + 1;
	while (tmp_x >= 0 && tmp_y < map.size())//x- y+
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_x--;
		tmp_y++;
	}

	

	tmp_x = x;
	tmp_y = y - 1;
	while (tmp_y >= 0)// x  y-
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_y--;
	}

	

	tmp_x = x;
	tmp_y = y + 1;
	while (tmp_y <map.size())// x y+
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_y++;
	}

	

	tmp_x = x+1;
	tmp_y = y;
	while (tmp_x < map.size())//x+ y
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_x++;
	}

	

	tmp_x = x-1;
	tmp_y = y;
	while (tmp_x >= 0)//x- y
	{
		if (map[tmp_x][tmp_y] == -2)
			break;
		map[tmp_x][tmp_y] = -1;
		tmp_x--;
	}

	
}