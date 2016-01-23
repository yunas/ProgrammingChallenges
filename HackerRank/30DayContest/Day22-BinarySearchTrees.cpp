#include <iostream>
#include <cstddef>
using namespace std;	
class Node{
	public:
		int data;
		Node *left,*right;
		Node(int d){
			data=d;
			left=right=NULL;
		}
};
class Solution{
	public:
  		Node* insert(Node* root, int data){
			if(root==NULL){
				return new Node(data);
			}
			else{
				Node* cur=new Node(data);
				if(data<=root->data){
					cur=insert(root->left,data);
					root->left=cur;
				}
				else{
				   cur=insert(root->right,data);
				   root->right=cur;
				 }
		   return root;
		   }
		}
		
		
		int getHeight(Node* root){
			  //Write your code here
			if (root == NULL) return 0;
			if (root -> left == NULL && root -> right == NULL) return 1;
				
			int left, right = 1;
			left = right = 1;
			left += getHeight(root->left);
			right += getHeight(root->right);
				
			return left > right ? left : right;
		}


};//End of Solution
		int main(int argc, char *argv[]) {

			Solution myTree;
			Node* root=NULL;
			int T,data;
			cin>>T;
			while(T-->0){
				cin>>data;
				root= myTree.insert(root,data);
			}
			int height= myTree.getHeight(root);
			cout<<height;
			return 0;
		}
				
				 
