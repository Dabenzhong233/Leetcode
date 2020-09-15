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

	// 3���ݹ�
	TreeNode *helper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end)
	{
		// �ݹ����(��Ϊǰ����������ƣ���ֻ��һ���жϼ���)
		if (pre_start > pre_end) return NULL;
		// �ݹ����:���ڵ㣬�����
		TreeNode *root = new TreeNode(preorder[pre_start]);
		if (pre_start == pre_end) return root;

		int root_inindex = hm[preorder[pre_start]];		//���Ҹ��ڵ��������е�λ��
		int left_nodes = root_inindex - in_start;		//�����������ڵ�
		int right_nodes = in_end - root_inindex;		//��������ʼ�ڵ�

		root->left = helper(preorder, pre_start + 1, pre_start + left_nodes, inorder, in_start, root_inindex - 1);		
		root->right = helper(preorder, pre_end - right_nodes + 1, pre_end, inorder, root_inindex + 1, in_end);		 //ÿ�εݹ鶼����٣�����ֱ��prestart��ӡ�
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		// 1���������Ƶ�map��
		for (int i = 0; i < inorder.size(); i++)
		{
			hm[inorder[i]] = i;
		}
		// 2��׼���ݹ�
		return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
private:
	unordered_map<int, int> hm;

};

