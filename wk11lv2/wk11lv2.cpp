#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void downheap(int, vector<int>&);
int removemin(vector<int>&);
void upheap(int, vector<int>&);


int solution(vector<int> scoville, int K) {
    int answer = 0;
    scoville.push_back(-1);
    sort(scoville.begin(), scoville.end());
    while (scoville[1] < K)
    {

        int minsco1 = removemin(scoville);
        int minsco2 = removemin(scoville);
        int newsco = minsco1 + minsco2 * 2;
        scoville.push_back(newsco);
        upheap(scoville.size() - 1, scoville);
        for (int i : scoville)
        {
            cout << i << " ";
        }
        cout << endl;



        answer++;
        if (scoville.size() == 1 && scoville.front() < K)
        {
            answer = -1;
            break;
        }
    }


    return answer;
}

int main()
{
    vector<int> test = { 1,2,3,9,10,12 };
    int k = 7;
    cout << solution(test, k);
}



void downheap(int idx, vector<int> &heap)
{
    int lchild = 2 * idx;
    int rchild = 2 * idx + 1;
    if (lchild > heap.size()-1)//child 없는경우
    {
        return;
    }
    else if (rchild > heap.size()-1) //left child만 있는경우
    {
        rchild = heap.size() - 1;
    }
   
        if (heap[lchild] > heap[rchild])
        {
            if (heap[idx] > heap[rchild])
            {
                int tmp = heap[idx];
                heap[idx] = heap[rchild];
                heap[rchild] = tmp;
                downheap(rchild, heap);
            }

        }
        else
        {
            if (heap[idx] > heap[lchild])
            {
                int tmp = heap[idx];
                heap[idx] = heap[lchild];
                heap[lchild] = tmp;
                downheap(lchild, heap);
            }
        }
    
}

void upheap(int idx, vector<int>& heap)
{
    if (idx == 1) return;
    int parrent = idx / 2;
    if (heap[parrent] > heap[idx])
    {
        int tmp = heap[idx];
        heap[idx] = heap[parrent];
        heap[parrent] = tmp;
        upheap(parrent, heap);
    }
}

int removemin(vector<int>& heap)
{
    int min = heap[1];
    heap[1] = heap.back();
    heap.pop_back();
    downheap(1, heap);

    return min;
}