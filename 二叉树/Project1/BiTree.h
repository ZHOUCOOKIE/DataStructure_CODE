typedef char Elemtype;

typedef struct node {
	Elemtype data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

void CreateBiTree(BTNode*& T, char* str);
//BTNode* FindNode(BTNode* T, Elemtype x);
BTNode* FindNode(BTNode* BT, char X);
BTNode* Parent(BTNode* ptr, Elemtype child);
BTNode* FindParent(BTNode* ptr, Elemtype child);
BTNode* Getparent(BTNode* T, Elemtype x);