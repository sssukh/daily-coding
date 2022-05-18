#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class user
{
public:
	int userid,leader; 

	// 이 유저가 팔로우하는 유저들(인접리스트)
	vector<user*> followId;

	// 이 유저의 팔로워들 (인접리스트의 transpose된 모양)
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

// 팔로워의 수가 같으면 userid가 작은 순으로, 그렇지 않으면 팔로워가 많은 순으로
bool cmp(user* a, user* b)
{
	if (a->followersId.size() == b->followersId.size())
		return a->userid < b->userid;
	else
		return a->followersId.size() > b->followersId.size();
}

// 첫번째 단계의 DFS로 해당 유저를 방문하고 되돌아갈 때 stack에 push한다.
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

// 두번째 단계의 DFS로 방문하면 현재 유저의 leader를 설정해주고 다음 팔로워에게 방문한다.
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
	
	// 유저목록
	vector<user*> users;

	// 첫번째 DFS를 위한 스택
	vector<int> userStack;

	//첫번째 DFS를 위한 visited
	vector<bool> visited(N+1,0);

	// index 맞추기위한 더미 유저
	users.push_back(new user);

	// 유저 수 만큼 유저목록에 넣어주기
	for (int i = 1; i <= N; i++)
	{
		users.push_back(new user{ i });
	}
	
	// 입력받기
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		users[u]->followId.push_back(users[v]);
		users[v]->followersId.push_back(users[u]);

		
	}


	// 알맞은 순서로 방문하기위해 sorting하기
	vector<user*> sortedUsers = users;
	sort(sortedUsers.begin(), sortedUsers.end(), cmp);
	for (int i = 1; i <= N; i++)
	{
		sort(users[i]->followId.begin(), users[i]->followId.end(), cmp);
		sort(users[i]->followersId.begin(), users[i]->followersId.end(), cmp);
	}
	
	// 1단계
	for (int i = 0; i < N; i++)
	{
		DFS1(users, userStack, visited, sortedUsers[i]->userid);
	}

	// 알고리즘 진행 중 중간정보 출력
	for (int i = 0; i < userStack.size(); i++)
	{
		cout << userStack[i] << " ";
	}
	cout << "\n";
	
	// 2단계
	while (!userStack.empty())
	{
		DFS2(users, visited, userStack.back(), userStack.back());
		userStack.pop_back();
	}

	//알고리즘 종료 후 정보 출력
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