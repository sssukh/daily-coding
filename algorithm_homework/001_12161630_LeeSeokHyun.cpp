#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class user
{
public:
	int userid,leader; 

	// �� ������ �ȷο��ϴ� ������(��������Ʈ)
	vector<user*> followId;

	// �� ������ �ȷο��� (��������Ʈ�� transpose�� ���)
	vector<user*> followersId;
	user()
	{
		userid = 50001;
		leader = 0;
	}
	user(int _id)
	{
		userid = _id;
		leader = _id;
	}
	~user()
	{
		
	}
};

// �ȷο��� ���� ������ userid�� ���� ������, �׷��� ������ �ȷο��� ���� ������
bool cmp(user* a, user* b)
{
	if (a->followersId.size() == b->followersId.size())
		return a->userid < b->userid;
	else
		return a->followersId.size() > b->followersId.size();
}

// ù��° �ܰ��� DFS�� �ش� ������ �湮�ϰ� �ǵ��ư� �� stack�� push�Ѵ�.
void DFS1(vector<user*>& users, vector<int>& userStack, vector<bool>& visited, int currentUser)
{
	if (visited[currentUser])
		return;
	visited[currentUser] = true;
	for (int i = 0; i < users[currentUser]->followId.size(); i++)
	{
		DFS1(users, userStack, visited, users[currentUser]->followId[i]->userid);
	}
	userStack.push_back(currentUser);
}

// �ι�° �ܰ��� DFS�� �湮�ϸ� ���� ������ leader�� �������ְ� ���� �ȷο����� �湮�Ѵ�.
void DFS2(vector<user*>& users, vector<bool>& unvisited, int currentUser,int leader)
{
	if (!unvisited[currentUser])
		return;
	unvisited[currentUser] = false;
	users[currentUser]->leader = leader;
	for (int i = 0; i < users[currentUser]->followersId.size(); i++)
	{
		DFS2(users, unvisited, users[currentUser]->followersId[i]->userid,leader);
	}

}

int main()
{
	int N, M;
	cin >> N >> M;
	
	// �������
	vector<user*> users;

	// ù��° DFS�� ���� ����
	vector<int> userStack;

	//ù��° DFS�� ���� visited
	vector<bool> visited(N+1,0);

	// index ���߱����� ���� ����
	users.push_back(new user);

	// ���� �� ��ŭ ������Ͽ� �־��ֱ�
	for (int i = 1; i <= N; i++)
	{
		users.push_back(new user{ i });
	}
	
	// �Է¹ޱ�
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		users[u]->followId.push_back(users[v]);
		users[v]->followersId.push_back(users[u]);

		
	}


	// �˸��� ������ �湮�ϱ����� sorting�ϱ�
	vector<user*> sortedUsers = users;
	sort(sortedUsers.begin(), sortedUsers.end(), cmp);
	for (int i = 1; i <= N; i++)
	{
		sort(users[i]->followId.begin(), users[i]->followId.end(), cmp);
		sort(users[i]->followersId.begin(), users[i]->followersId.end(), cmp);
	}
	
	// 1�ܰ�
	for (int i = 0; i < N; i++)
	{
		DFS1(users, userStack, visited, sortedUsers[i]->userid);
	}

	// �˰��� ���� �� �߰����� ���
	for (int i = 0; i < userStack.size(); i++)
	{
		cout << userStack[i] << " ";
	}
	cout << "\n";
	
	// 2�ܰ�
	while (!userStack.empty())
	{
		DFS2(users, visited, userStack.back(), userStack.back());
		userStack.pop_back();
	}

	//�˰��� ���� �� ���� ���
	for (int i = 1; i <= N; i++)
	{
		cout << users[i]->leader << " ";
	}
	cout << "\n";

	for (int i = 0; i <= N; i++)
	{
		delete users[i];
	}
}