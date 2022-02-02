#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node
{
public:
    long m_value;
    int m_idx;
    vector<Node*> incident;
    Node()
    {
        m_value = 0;
        m_idx = NULL;
    }
    Node(long value , int idx)
    {
        m_value = value;
        m_idx = idx;
    }
    void addIncident(Node* node)
    {
        incident.push_back(node);
    }
};

class Tree
{
public:
    vector<Node*> nodelist;
    Node* root;
    Tree(){}
    ~Tree()
    {
        for (int i = 0; i < nodelist.size(); i++)
        {
            delete nodelist[i];
        }
    }
    void addNode(Node* node)
    {
        nodelist.push_back(node);
    }
    void setRoot(Node* node)
    {
        root = node;
    }
    Node* findNode(int idx)
    {
        return nodelist[idx];
    }

};

long DFS(long long& answer, Tree& tree, int idx,vector<bool>& visit)
{
    if (visit[idx])
        return 0;
    visit[idx] = true;


    Node* current = tree.findNode(idx);
    int chiSize = current->incident.size();
 
    for (int i = 0; i < chiSize; i++)
    {
        long tmp = DFS(answer, tree, current->incident[i]->m_idx, visit);
        //answer += abs(tmp);
        current->m_value += tmp;
    }
    long result = current->m_value;
    answer += abs(result);
    current->m_value = 0;
    return result;
}

long long solution(vector<int> a, vector<vector<int>> edges) 
{
    long long answer = 0;
    int size = a.size();
    vector<bool> visit(a.size(), 0);
    vector<long> arr (a.begin(),a.end());
    long long tmp = 0;

    Tree tree;
    for (int i = 0; i < size; i++)
    {
        tmp += arr[i];
        Node* node = new Node(arr[i],i);
        tree.addNode(node);
    }
    if (tmp)
        return -1;
    for (int i = 0; i < edges.size(); i++)
    {
        tree.nodelist[edges[i][0]]->addIncident(tree.nodelist[edges[i][1]]);
        tree.nodelist[edges[i][1]]->addIncident(tree.nodelist[edges[i][0]]);
    }

    tree.setRoot(tree.nodelist[0]);
    Node* current = tree.root;
    
    if (DFS(answer, tree, 0, visit))
        answer = -1;

    return answer;
}