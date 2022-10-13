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
// 18 ��С�� �� 13242424240 2117777222 ����ũҵ����ѧԺ 231@21312.com
// 18 �Ƴ� �� 13232424240 2117557222 ����ũҵ����ѧԺ 231@223312.com
// 18 �ű� �� 13223424240 3217557222 ����ũҵ����ѧԺ 23@223312.com
void Menu();//������
void display(Contact*& L1, Contact*& L2);//��ʾ������ϵ��
void Print(Contact*& L);//������ӡ����
void search(Contact*& L2);//������ϵ��
void enter(Contact*& L1, Contact*& L2);//�����ϵ����Ϣ
void Modify(Contact*& L2);//�޸���ϵ����Ϣ
void Delete(Contact*& L1, Contact*& L2);//ɾ����ϵ����Ϣ
void save(Contact*& L1, Contact*& L2);//����
void NoSave(Contact*& L1, Contact*& L2);//������
void Destroy(Contact*& L);//�ݻٵ�����
void load(Contact*& L2);//��ȡ�ļ�
void Sort(Contact*& L2);//������������ϵ��