#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int m_idx;
    int m_total;
    Node* parent;
    vector<Node*> child_list;
    Node()
    {
        m_idx = NULL;
        m_total = NULL;
        parent == NULL;
    }
    Node(int idx)
    {
        m_idx = idx;
        m_total = 0;
        parent == NULL;
    }
    ~Node()
    {
        m_idx = NULL;
        m_total = NULL;
        child_list.clear();
        parent = NULL;
    }
    void insertChild(Node* node)
    {
        child_list.push_back(node);
    }

    void insertParent(Node* node)
    {
        parent = node;
    }
};

class Tree
{
public:
    Node* root;
    vector<Node*> node_list;
    Tree()
    {
        root = NULL;
    }
    Tree(Node* node)
    {
        root = node;
    }
    ~Tree()
    {
        for (int i = 0; i < node_list.size(); i++)
        {
            delete node_list[i];
        }
        delete root;
    }
    void insertNode(Node* node)
    {
        node_list.push_back(node);
    }

    Node* findNode(int i)
    {
        return node_list[i];
    }
    
    void pass_value_to_parent(Node* current, int value)
    {
        if (current->m_idx < 0 || value == 0)
            return;
        current->m_total += value - value/10;
        
        pass_value_to_parent(current->parent, value / 10);
    }
    
    
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    unordered_map<string, int> getIdx;
    Node* empty = new Node(-1);
    Tree tree(empty);
    for (int i = 0; i < enroll.size(); i++)
    {
        getIdx[enroll[i]] = i;
        Node* current = new Node(i);
        tree.insertNode(current);
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        if (referral[i] != "-")
        {
            tree.findNode(i)->insertParent(tree.findNode(getIdx[referral[i]]));
            tree.findNode(i)->parent->insertChild(tree.findNode(i));
        }
        else
        {
            tree.root->insertChild(tree.findNode(i));
            tree.findNode(i)->insertParent(tree.root);
        }
    }

    for (int i = 0; i < seller.size(); i++)
    {
        tree.pass_value_to_parent(tree.findNode(getIdx[seller[i]]), amount[i] * 100);
        
    }
    //tree.postOrder(tree.root);
    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(tree.node_list[i]->m_total);
        //cout << answer.back() << endl;
    }

    return answer;
}

int main()
{
    vector<string> test1 = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> test2 = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string> test3 = { "young", "john", "tod", "emily", "mary" };
    vector<int> test4 = { 12,4,2,5,10 };
    vector<string> test21 = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    vector<string> test22 = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    vector<string> test23 = { "sam", "emily", "jaimie", "edward" };
    vector<int> test24 = { 2,3,5,4 };
    solution(test21, test22, test23, test24);
}