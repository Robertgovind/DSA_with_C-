#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

void solve(Node *root, int sum, int &maxSum, int len, int maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum += root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0, maxLen = 0;
    int sum = 0, maxSum = INT8_MIN;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}