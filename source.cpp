#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//tao cau truc sinh vien
struct SinhVien
{
	int ma;
	char ten[150];
};
//tao cau truc danh sach lien ket don
struct Node
{
	SinhVien *data;
	Node *pNext;
};
struct SingleList
{
	Node *pHead;
};
//khoi tao danh sach lien ket don
void Initialize(SingleList *&list)
{
	list=new SingleList;
	list->pHead=NULL;
}
//nhap thong tin sinh vien
SinhVien *NhapSinhVien()
{
	SinhVien *sv=new SinhVien;
	cout<<"Nhap MSSV:";
	cin>>sv->ma;
	cin.ignore();
	cout<<"Nhap ho va ten:";
	gets(sv->ten);
	return sv;
}
//tao node sinh vien
Node *CreateNode(SinhVien *sv)
{
	Node *pNode=new Node;
	if(pNode!=NULL)
	{
		pNode->data=sv;
		pNode->pNext=NULL;
	}
	else
	{
		cout<<"cap phat bo nho that bai!!!";
	}
	return pNode;
}
//them node vao cuoi danh sach
void InsertLast(SingleList *&list,SinhVien *sv)
{
	Node *pNode=CreateNode(sv);
	if(list->pHead==NULL)
	{
		list->pHead=pNode;
	}
	else
	{
		Node *pTmp=list->pHead;
		
		while(pTmp->pNext!=NULL)
		{
			pTmp=pTmp->pNext;
		}
		pTmp->pNext=pNode;
	}
}
//hien thi danh sach
void PrintList(SingleList *list)
{
	Node *pTmp=list->pHead;
	if(pTmp==NULL)
	{
		cout<<"Danh sach rong";
		return;
	}
	while(pTmp!=NULL)
	{
		SinhVien *sv=pTmp->data;
		cout<<sv->ma<<"\t"<<sv->ten<<"\n";
		pTmp=pTmp->pNext;
	}
}
//sap xep
void SortList(SingleList *&list)
{
	for(Node *pTmp=list->pHead;pTmp!=NULL;pTmp=pTmp->pNext)
	{
		for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext)
		{	
			SinhVien *svTmp=pTmp->data;
			SinhVien *svTmp2=pTmp2->data;
			if(svTmp2->ma<svTmp->ma)
			{
				int ma=svTmp->ma;
				char ten[150];
				strcpy(ten,svTmp->ten);
				
				svTmp->ma=svTmp2->ma;
				strcpy(svTmp->ten,svTmp2->ten);
				svTmp2->ma=ma;
				strcpy(svTmp2->ten,ten);				
			}
		}	
	}
}
//xoa
void RemoveNode(SingleList *&list,int ma)
{
	Node *pDel=list->pHead;
	if(pDel==NULL)
	{
		cout<<"Danh sach rong!";
	}
	else
	{
		Node *pPre=NULL;
		while(pDel!=NULL)
		{
			SinhVien *sv=pDel->data;
			if(sv->ma==ma)
				break;
			pPre=pDel;
			pDel=pDel->pNext;
		}
		if(pDel==NULL)
		{
			cout<<"khong tim thay MSSV: "<<ma;
		}
		else
		{
			if(pDel==list->pHead)
			{
				list->pHead=list->pHead->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
			else
			{
				pPre->pNext=pDel->pNext;
				pDel->pNext=NULL;
				delete pDel;
				pDel=NULL;
			}
		}
	}
}
int main(int argc, char** argv) {
	SingleList *list;
	Initialize(list);
	SinhVien *teo=NhapSinhVien();
	InsertLast(list,teo);
	SinhVien *ty=NhapSinhVien();
	InsertLast(list,ty);
	SinhVien *bin=NhapSinhVien();
	InsertLast(list,bin);
	PrintList(list);
	SortList(list);
	cout<<"\nSau khi sap xep:\n";
	PrintList(list);
	cout<<"\nBan muon xoa sinh vien co MSSV: ";
	int ma;
	cin>>ma;
	RemoveNode(list,ma);
	cout<<"\nSau khi xoa:\n";
	PrintList(list);

  cout<<"\n---------------------------\n";
  cout<<"Chuong trinh nay duoc dang tai Freetuts.net";
}