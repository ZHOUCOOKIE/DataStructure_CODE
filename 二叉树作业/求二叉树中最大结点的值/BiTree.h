typedef char Elemtype;

typedef struct node {
	Elemtype data;
	struct node* lchild;
	struct node* rchild;
}BTNode;
void CreateBiTree(BTNode*& T, char* str);
int FindMax(BTNode* T);
void CopyTree(BTNode* T1, BTNode*& T2);
BTNode* FirstNode(BTNode*& T);
void VistNode(BTNode* T);
BTNode* Parent(BTNode* ptr, Elemtype child);
BTNode* FindParent(BTNode* ptr, Elemtype child);