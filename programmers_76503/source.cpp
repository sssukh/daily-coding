#include <string>
#include <vector>

using namespace std;

class Node
{
public:
    int m_value;
    int m_idx;
    vector<Node*> incident;
    Node()
    {
        m_value = 0;
        m_idx = NULL;
    }
    Node(int value , int idx)
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

void DFS(long long& answer, Tree& tree, int idx,int& stack)
{
    Node* current = tree.findNode(idx);
    int chiSize = current->incident.size();
    stack++;

    if (chiSize==1)
    {

    }
    else
    {
        for (int i = 0; i < chiSize; i++)
        {
            DFS(answer, tree, current->incident[i]->m_idx);
        }
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) 
{
    long long answer = -2;
    int size = a.size();
    int stack = 0;


    Tree tree;
    for (int i = 0; i < size; i++)
    {
        Node* node = new Node(a[i],i);
        tree.addNode(node);
    }

    for (int i = 0; i < edges.size(); i++)
    {
        tree.nodelist[edges[i][0]]->addIncident(tree.nodelist[edges[i][1]]);
        tree.nodelist[edges[i][1]]->addIncident(tree.nodelist[edges[i][0]]);
    }

    tree.setRoot(tree.nodelist[0]);
    Node* current = tree.root;
    

    return answer;
}