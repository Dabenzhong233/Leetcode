#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};
class Solution {
public:

	// 3、递归
	TreeNode *helper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end)
	{
		// 递归出口(因为前序和中序类似，故只用一个判断即可)
		if (pre_start > pre_end) return NULL;
		// 递归操作:建节点，算参数
		TreeNode *root = new TreeNode(preorder[pre_start]);
		if (pre_start == pre_end) return root;

		int root_inindex = hm[preorder[pre_start]];		//查找根节点在中序中的位置
		int left_nodes = root_inindex - in_start;		//左子树结束节点
		int right_nodes = in_end - root_inindex;		//右子树开始节点

		root->left = helper(preorder, pre_start + 1, pre_start + left_nodes, inorder, in_start, root_inindex - 1);		
		root->right = helper(preorder, pre_end - right_nodes + 1, pre_end, inorder, root_inindex + 1, in_end);		 //每次递归都会减少，不能直接prestart相加。
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		// 1、将数组移到map中
		for (int i = 0; i < inorder.size(); i++)
		{
			hm[inorder[i]] = i;
		}
		// 2、准备递归
		return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
private:
	unordered_map<int, int> hm;

};

