typedef char Elemtype;

typedef struct node {
	Elemtype data;
	struct node* lchild;
	struct node* rchild;
}BTNode;
void CreateBiTree(BTNode*& T, char* str);//����������
int BiTreeNodeAmount(BTNode* T);//�������н�����
void VisitRDL(BTNode* T, int n);//�������������
int BiTreeDepth(BTNode* T);//�������ĸ߶�
void InOrderTraverse(BTNode* T);//���������������
void LevelTraverse(BTNode* T);//�������Ĳ�α���