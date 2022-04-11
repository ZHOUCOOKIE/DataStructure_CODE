#define _CRT_SECURE_NO_WARNINGS

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_PHNUM 12
#define MAX_QQNUM 10
#define MAX_COMP 30
#define MAX_EMAIL 30

typedef struct Contact {
	int age;//年龄
	char Name[MAX_NAME];//姓名
	char Sex[MAX_SEX];//性别
	char PhNum[MAX_PHNUM];//手机号
	long long QQNuM;//QQ号
	char ComP[MAX_COMP];//公司
	char Email[MAX_EMAIL];//邮箱
	struct Contact* Next;
}Contact;

void Menu();//主界面
void PrintPlus(Contact*& L1, Contact*& L2);//显示所有联系人
void Print(Contact*& L);//基础打印函数
void Search(Contact*& L2);//查找联系人
void Add(Contact*& L1, Contact*& L2);//添加联系人信息
void Modify(Contact*& L2);//修改联系人信息
void Delete(Contact*& L1, Contact*& L2);//删除联系人信息
void Save(Contact*& L);//保存
void NoSave(Contact*& L1, Contact*& L2);//不保存
void Destroy(Contact*& L);//摧毁单链表
void Fread(Contact*& L2);//读取文件
void Sort(Contact*& L2);//按姓名排序联系人