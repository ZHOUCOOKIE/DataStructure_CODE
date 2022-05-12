typedef char Elemtype;

typedef struct node {
	Elemtype data;
	struct node* lchild;
	struct node* rchild;
}BTNode;
void CreateBiTree(BTNode*& T, char* str);//创建二叉树
int BiTreeNodeAmount(BTNode* T);//二叉树中结点个数
void VisitRDL(BTNode* T, int n);//横向输出二叉树
int BiTreeDepth(BTNode* T);//二叉树的高度
void InOrderTraverse(BTNode* T);//二叉树的中序遍历
void LevelTraverse(BTNode* T);//二叉树的层次遍历