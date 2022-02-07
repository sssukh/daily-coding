#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;


class Node
{
public:
    int num;
    int x;
    int y;
    Node* left;
    Node* right;
    Node* parent;
    Node()
    {

    }
    Node(int node_x, int node_y, int node_num)
    {
        num = node_num;
        x = node_x;
        y = node_y;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    ~Node()
    {

    }
    void addLeft(Node* node)
    {
        left = node;
    }
    void addRight(Node* node)
    {
        right = node;
    }
    void addParent(Node* node)
    {
        parent = node;
    }
    bool operator==(Node* a)
    {
        return a->x == this->x && a->y == this->y && a->num == this->num;
    }
};



class binaryTree
{
public:
    vector<Node*> nodelist;
    Node* root;
    Node* empty;
    binaryTree()
    {

    }
    ~binaryTree()
    {
        for (int i = 0; i < nodelist.size(); i++)
        {
            delete nodelist[i];
        }
        delete empty;
    }
    void preOrder(Node* node,vector<int>& preorder)
    {
        preorder.push_back(node->num);
        if (node->left)
        {
            preOrder(node->left,preorder);
        }
        if (node->right)
        {
            preOrder(node->right,preorder);
        }
        
    }
    void postOrder(Node* node, vector<int>& postorder)
    {
        
        if (node->left)
        {
            postOrder(node->left, postorder);
        }
        if (node->right)
        {
            postOrder(node->right, postorder);
        }
        postorder.push_back(node->num);
    }
    void addNode(Node* node)
    {
        nodelist.push_back(node);
    }
    
    Node* make_tree(int low, int high, int addlevel, set<int>& levels)
    {
        int levelsize = levels.size();
        if (addlevel >= levelsize)
        {
            return NULL;
        }
        Node* current;
        auto iter = levels.crbegin();
        for (int i = 0; i < addlevel; i++)
            iter++;
        int level = *iter;
        //cout << level << endl;
        int i;
        //cout << "low : " << low << " high : " << high << " level : " << level << endl;
        for (i = low; i < high; i++)
        {
            if (nodelist[i]->y == level)
            {
                current = nodelist[i];
                if (addlevel == 0)
                    root = current;
                //cout << current->num << endl;
                //cout << i << endl;
                current->addLeft(make_tree(low, i, addlevel + 1,levels));
                current->addRight(make_tree(i, high, addlevel + 1,levels));
                return current;
            }
        }
        return NULL;
    }
    
};

bool cmp(Node* a, Node* b)
{
    
        return a->x < b->x;
   
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;
    
    vector<int> preorder;
    vector<int> postorder;
    binaryTree tree;
    set<int> levels;
    int nodesize = nodeinfo.size();
    for (int i = 0; i < nodesize; i++)
    {
        Node* node = new Node(nodeinfo[i][0], nodeinfo[i][1], i+1);
        tree.addNode(node);
        levels.insert(nodeinfo[i][1]);
    }
    
    tree.empty = new Node(-1, -1, -1);
    sort(tree.nodelist.begin(), tree.nodelist.end(), cmp);
    //auto iter = levels.crbegin();
    tree.make_tree(0, nodesize, 0, levels);

    /*
    levels.insert(-1);
    sort(tree.nodelist.begin(), tree.nodelist.end(), cmp);

    tree.root = tree.nodelist[0];
    auto iter = levels.crbegin();
    for (int i = 1; i < nodesize; i++)
    {
        Node* current = tree.nodelist[i - 1];
        while(*iter >= current->y)
            iter++;
        cout << "current : "<<current->num << endl;
        for (int j = i;j < nodesize; j++)
        {
            
            Node* child = tree.nodelist[j];
            cout << "j : " << j << "node number : " << child->num << endl;
            if (*iter > child->y)
                break;
            if (current == tree.root)
            {
                if (child->x < current->x)
                {
                    current->addLeft(child);
                }
                else
                {
                    current->addRight(child);
                }
                child->addParent(current);
            }
            else
            {
                if (current == current->parent->left && child->x<current->parent->x)
                {
                    if (child->x > current->x)
                    {
                        current->addRight(child);
                    }
                    else
                        current->addLeft(child);
                    child->addParent(current);
                }
                else if(current == current->parent->right && child->x>current->parent->x)
                {
                    if (child->x > current->x)
                    {
                        current->addRight(child);
                    }
                    else
                        current->addLeft(child);
                    child->addParent(current);
                }
            }
        }
    }
    */
    tree.preOrder(tree.root, preorder);
    tree.postOrder(tree.root, postorder);
    answer.push_back(preorder);
    answer.push_back(postorder);

    for (int i : preorder)
        cout << i << " ";
    cout << endl;
    for (int i : postorder)
        cout << i << " ";
    cout << endl;

    return answer;
}

int main()
{
    vector<vector<int>> test = { {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
    solution(test);
}