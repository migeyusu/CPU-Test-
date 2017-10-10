#ifndef _I_DATASTRUCTURE_H_
#define _I_DATASTRUCTURE_H_
/*  
    1.B-��
	2.������int��
    3.����(int)������Ķ���
	4.˫����ģ������
	5.���������ջ
*/
typedef int tnode;
//����ڵ�,int
struct nodes
{
	int data;
	nodes *next;
};
//���ڵ�,tnode
struct roots
{
	tnode data;
	roots *lchild;
	roots *rchild;
};
//˫��ڵ�
template <typename S> struct links
{
	S data;
	links *next;
	links *prev;
};

/*---------������---------*/
class Oneway_List
{
public:
	nodes *OneWay_Chain;
	//׷��
	void nodeAppend(nodes *&nds, int x);
	//����
	void createList(nodes *&nds, int ary[], int size);
	//���
	void listPrint(nodes *nds, int ary[], int size);
	//�ڵ���
	int listCount(nodes *nds);
	//����
	bool nodeSearch(nodes *nds, int finder);
	//ָ���ڵ�֮�����
	bool nodeInsert(nodes *&nds, int prenode, int nextnode);
	//ָ���ڵ�ɾ��
	bool nodeDelete(nodes *&nds, int delenode);
	//�ͷ��ڴ�,�������
	void nodeClean(nodes *&nds);
private:
	//��ͷ���ɾ��
	bool nodeNextDele(nodes *&nds, int delenode);
};

/*------------B��(��������)---------*/
class B_tree
{
public:
	//����
	void btreebuild(roots *&bst, tnode a[], int n);
	//����
	void InsertIn(roots *&bst, tnode x);
	//˳�����
	void Inorder(roots *bst);
	//b������
	bool FindData(roots *bst, tnode &x);
	//ָ���ڵ�ɾ��
	bool DeleteOn(roots *&bst, tnode x);
	//�ڵ��������
	int NodeCount(roots *bst);
	//���b��
	void clearbstree(roots *&bst);
	roots *MainBst;
    int *Result_Ary;
	int Current_SN;
private:
	void outInorder(roots *bst);
};

/*---------------ջ------------------*/
template<typename T> class I_Stack
{
public:
	T *stackAry;
	bool iniStack(int lenx);
	//���
	void clearStack();
	//�ؽ�
	bool rebuildStack(int lenx);
	bool push(T x);
	//��ȡ
	bool peek(T &x);
	//�Ƴ�
	bool pop(T &x);
	bool closeStack();
private:
	int Current_Hand;
	int Current_Length;
};

/*------------˫������-------------*/
template<typename S> class Twoway_List
{
public:
	links<S> *Twoway_Chain;//ͷ���
	links<S> *tail_Link;//β�ڵ�
	bool create();
	//���������
	bool print(S x[]);
	int  count();
	bool search(S x);
	//ͷ�ڵ����
	bool headinsert(S x);
	//ͷ����Ƴ�
	bool headdelete();
	//β�ڵ��Ƴ�
	bool taildelete();
	//β�ڵ�׷��
	bool tailappend(S x);
	//����ָ���ڵ��
	bool insert(S x1,S x2);
	//�Ƴ�ָ���ڵ�
	bool dele(S x);
	void clean();
private:
	void deleLink(links<S> *&nks);
};

/*------------����-----------------*/
class I_Queue
{
public:
	nodes *queueAry;//ͷ���
	int queueLength;//��ǰ���г���
	bool createQueue();
	bool push(int x);
	bool pop(int &x);
	bool peek(int &x);
	bool find(int x);
	void queueClear();
private:
	void clears(nodes *&nds);
};

//ģ��ջ-----------------------------------------------------------------------
template <typename T>bool I_Stack<T>::iniStack(int lenx)
{
	if (stackAry!=NULL)
	{
		delete[] stackAry;
		stackAry = NULL;
	}
	stackAry = new T[lenx];
	if (stackAry == NULL)
		return false;
	Current_Length = lenx-1;
	Current_Hand = 0;
	return true;
}

template <typename T>void I_Stack<T>::clearStack()
{
	Current_Hand = 0;
}

template <typename T>bool I_Stack<T>::rebuildStack(int lenx)
{
	Current_Hand = 0;
	delete[] stackAry;
	return iniStack(lenx);
}

template <typename T>bool I_Stack<T>::push(T x)
{
	if (Current_Hand == Current_Length)
		return false;
	stackAry[Current_Hand] = x;
	++Current_Hand;
	return true;
}

template <typename T>bool I_Stack<T>::pop(T &x)
{
	if (Current_Hand == 0)
		return false;
	--Current_Hand;
	x = stackAry[Current_Hand];
	return true;
}

template <typename T>bool I_Stack<T>::peek(T &x)
{
	if (Current_Hand == 0)
		return false;
	x = stackAry[Current_Hand-1];
	return true;
}

template <typename T>bool I_Stack<T>::closeStack()
{
	Current_Hand = 0;
	Current_Length = 0;
	delete[] stackAry;
	stackAry = NULL;
	return true;
}
/*----------------------------------------------------------------------------*/

//ģ��˫������----------------------------------------------------------------

template <typename S> bool Twoway_List<S>::create()
{
	Twoway_Chain = NULL;
	return true;
}

template <typename S> bool Twoway_List<S>::tailappend(S x)
{
	if (Twoway_Chain == NULL)
	{
		links<S> *p = new links < S > ;
		Twoway_Chain = p;
		Twoway_Chain->prev = NULL;
		Twoway_Chain->data = x;
		Twoway_Chain->next = NULL;
		tail_Link = Twoway_Chain;
		return true;
	}
	else
	{
		links<S> *p = new links < S > ;
		p->prev = tail_Link;
		p->next = NULL;
		p->data = x;
		tail_Link->next = p;
		tail_Link = p;
		return true;
	}
}

template <typename S> bool Twoway_List<S>::print(S x[])
{
	int i = 0;
	links<S> *p = Twoway_Chain;
	while (p != NULL)
	{
		x[i] = p->data;
		p = p->next;
		++i;
	}
	return true;
}

template <typename S> int Twoway_List<S>::count()
{
	links<S> *p = new links<S>;
	p = Twoway_Chain;
	int l = 0;
	do
	{
		if (p == NULL)
			return l;
		p = p->next;
		++l;
	} while (true);
}

template <typename S> bool Twoway_List<S>::search(S x)
{
	links<S> *lp = new links<S>;
	lp = Twoway_Chain;
	do
	{
		if (lp == NULL)
		{
			return false;
		}

		else if (lp->data == x)
		{
			return true;
		}
		lp = lp->next;
	} while (true);
}

template <typename S> bool Twoway_List<S>::headinsert(S x)
{
	links <S> *p = new links<S>;
	p->data = x;
	p->prev = NULL;
	if (Twoway_Chain==NULL)
	{
		p->next = NULL;
		Twoway_Chain = p;
		tail_Link = Twoway_Chain;
	}
	else
	{
		p->next = Twoway_Chain;
		Twoway_Chain->prev = p;
		Twoway_Chain = p;
	}
	return true;
}

template <typename S> bool Twoway_List<S>::headdelete()
{
	if (Twoway_Chain==NULL)
	{
		return true;
	}
	else
	{
		if (Twoway_Chain->next==NULL)
		{
			delete Twoway_Chain;
			Twoway_Chain = NULL;
			tail_Link = NULL;
		}
		else
		{
			Twoway_Chain = Twoway_Chain->next;
			delete Twoway_Chain->prev;
			Twoway_Chain->prev = NULL;
		}
	}
	return true;
}

template <typename S> void Twoway_List<S>::clean()
{
	tail_Link = NULL;
	if (Twoway_Chain==NULL)
	{
		return;
	}
	else if (Twoway_Chain->next==NULL)
	{
		delete Twoway_Chain;
		Twoway_Chain = NULL;
		return;
	}
	while (Twoway_Chain->next!=NULL)
	{
		Twoway_Chain=Twoway_Chain->next;
		delete Twoway_Chain->prev;
		Twoway_Chain->prev = NULL;
	}
	delete Twoway_Chain;
	Twoway_Chain=NULL;
	return;
}

template <typename S> bool Twoway_List<S>::dele(S x)
{
	if (Twoway_Chain == NULL)
	{
		return false;
	}
	else if (Twoway_Chain->data == x)
	{
		return headdelete();
	}
	links<S> *p = new links<S>;
	p = Twoway_Chain;
	while (p != NULL)
	{
		if (p->data == x)
		{
			if (p->next == NULL)
			{
				return taildelete();
			}
			else
			{
				p->prev->next = p->next;
				p->next->prev = p->prev;
				delete p;
				p = NULL;
				return true;
			}
		}
		p = p->next;
	}
	return true;
}

template <typename S> bool Twoway_List<S>::insert(S x1, S x2)
{
	links<S> *p = new links<S>;
	p = Twoway_Chain;
	while (p != NULL)
	{
		if (p->data == x1)
		{
			if (p->next == NULL)
			{
				return tailappend(x2);
			}
			else
			{
				links<S> *q = new links<S>;
				q->data = x2;
				q->next = p->next;
				p->next->prev = q;
				q->prev = p;
				p->next = q;
				return true;
			}
		}
		p = p->next;
	}
	return false;
}

template <typename S> bool Twoway_List<S>::taildelete()
{
	if (tail_Link==NULL)
	{
		return true;
	}
	else
	{
		if (tail_Link->prev==NULL)
		{
			delete tail_Link;
			tail_Link = NULL;
			Twoway_Chain = NULL;
		}
		else
		{
	        tail_Link=tail_Link->prev;
			delete tail_Link->next;
			tail_Link->next = NULL;
		}
	}
	
}

#endif