#ifndef SOLUTION_H_H
#define SOLUTION_H_H
#define DLLOUT extern "C" __declspec(dllexport)

DLLOUT void _stdcall Merge_Sort(int ary1[], int size);//sizeΪ���ȣ�����Ŵ�1��ʼ

DLLOUT void _stdcall Insert_Sort(int ary1[], int size);//��������

DLLOUT int _stdcall Mid_Search(int ary1[], int size, int num1);//���ֲ���

DLLOUT void _stdcall AryBuild(int ary1[], int len1, int ary2[], int len2, int newAry[]);//�鲢����

DLLOUT int _stdcall Int_Test(int times,int &usedTime);//int32�����������;

DLLOUT double _stdcall Float_Test(int times, int &usedTime);//double/float����������

DLLOUT double _stdcall Newton_Sqrt(double x, int y);//ţ�ٹ�ʽ����

DLLOUT double _stdcall T_Sqrt(double x);//Talor����ʽ

DLLOUT int _stdcall SuperPi(int ary1[], int size);//������PI

DLLOUT int _stdcall Int_MatrixMulti(int Lary[], int m, int n, int Rary[], int p, int Ary[]);//��������˷�

DLLOUT int _stdcall Double_MatrixMulti(double Lary[], int m, int n, double Rary[], int p, double Ary[]);//�������˷�

DLLOUT void _stdcall IssueTest(int resultAry[]);//issue����

DLLOUT void _stdcall CacheTest(int resultAry[]);//�������

DLLOUT int _stdcall TalorSeries_Test(int times);//̩�ն���ʽ����

DLLOUT int _stdcall renderTest(int size);//��Ⱦ����

DLLOUT void _stdcall List_Test(int resultAry[]);//������ʲ���

DLLOUT int _stdcall imageDeal(int x, int y);//ͼ��Ŵ�ԭʼ�߳���������

//b����������������������������������������������������������
DLLOUT void _stdcall Btree_Sort(int ary1[],int size,bool keep);

DLLOUT void _stdcall Btree_Create(int ary1[], int size);

DLLOUT void _stdcall Btree_Insert(int seeds);

DLLOUT bool _stdcall Btree_Find(int field);

DLLOUT int _stdcall  Btree_Count();

DLLOUT void _stdcall Btree_Clean();

DLLOUT void _stdcall Btree_Print(int ary1[]);

DLLOUT bool _stdcall Btree_Delete(int x);

//�������������������������������������������������������������������������
DLLOUT void _stdcall Create_List(int ary[], int size);

DLLOUT void _stdcall List_Append(int x);

DLLOUT void _stdcall List_Insert(int preNode, int nextNode);

DLLOUT int  _stdcall List_Count();

DLLOUT void _stdcall List_Print(int ary[], int size);

DLLOUT void _stdcall List_Search(int x);

DLLOUT void _stdcall List_Delete(int delenode);

DLLOUT void _stdcall List_Clean();

//˫�������----------------------------------------
DLLOUT void _stdcall TwowayList_Create(int ary[], int size);

DLLOUT void _stdcall TwowayList_Append(int x);

DLLOUT void _stdcall TwowayList_Print(int ary[]);

DLLOUT int _stdcall TwowayList_Count();

DLLOUT bool _stdcall TwowayList_Search(int x);

DLLOUT void _stdcall TwowayList_Headin(int x);

DLLOUT void _stdcall TwowayList_Headde();

DLLOUT void _stdcall TwowayList_Clean();

DLLOUT void _stdcall TwowayList_Dele(int x);

DLLOUT void _stdcall TwowayList_Insert(int x1, int x2);

DLLOUT void _stdcall TwowayList_Tailde();

/*�����������������������������У�������ʵ�֣���������������������*/

DLLOUT void _stdcall Queue_Ini();

DLLOUT void _stdcall Queue_Push(int x);

DLLOUT bool _stdcall Queue_Pop(int &x);

DLLOUT bool _stdcall Queue_Peek(int &x);

DLLOUT void _stdcall Queue_Clear();

/*������������������������ջ�����飩��������������������������*/

DLLOUT void _stdcall Stack_Create(int x);

DLLOUT void _stdcall Stack_Clear(int x);

DLLOUT void _stdcall Stack_Close();

DLLOUT void _stdcall Stack_Push(int x);

DLLOUT bool _stdcall Stack_Pop(int &x);

DLLOUT bool _stdcall Stack_Peek(int &x);

//DLLOUT
//DLLOUT
//DLLOUT
//DLLOUT
//DLLOUT
//DLLOUT
//DLLOUT
//
//DLLOUT
//DLLOUT


#endif
