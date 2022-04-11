#define _CRT_SECURE_NO_WARNINGS

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_PHNUM 12
#define MAX_QQNUM 10
#define MAX_COMP 30
#define MAX_EMAIL 30

typedef struct Contact {
	int age;//����
	char Name[MAX_NAME];//����
	char Sex[MAX_SEX];//�Ա�
	char PhNum[MAX_PHNUM];//�ֻ���
	long long QQNuM;//QQ��
	char ComP[MAX_COMP];//��˾
	char Email[MAX_EMAIL];//����
	struct Contact* Next;
}Contact;

void Menu();//������
void PrintPlus(Contact*& L1, Contact*& L2);//��ʾ������ϵ��
void Print(Contact*& L);//������ӡ����
void Search(Contact*& L2);//������ϵ��
void Add(Contact*& L1, Contact*& L2);//�����ϵ����Ϣ
void Modify(Contact*& L2);//�޸���ϵ����Ϣ
void Delete(Contact*& L1, Contact*& L2);//ɾ����ϵ����Ϣ
void Save(Contact*& L);//����
void NoSave(Contact*& L1, Contact*& L2);//������
void Destroy(Contact*& L);//�ݻٵ�����
void Fread(Contact*& L2);//��ȡ�ļ�
void Sort(Contact*& L2);//������������ϵ��