#include <iostream>
#include <queue>

using namespace std;

// 이진트리 노드 
struct node{
	string position;
	node* left;     // 왼쪽 자식 노드
	node* right;    // 오른쪽 자식 노드
};

struct org_tree{    // root node 생성
	node* root;     
}

// root node 생성하는 함수
static org_tree create_org_structure(const string& pos){
	org_tree tree;
	tree.root = new node {pos, NULL, NULL};
	return tree;
}

static node* find(node * root, string& value) {
	if(root == NULL) return NULL;

	if(root->position == value)
		return root;
	
}