#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
// tạo cấu trúc sinh viên
struct Sinhvien
{
    char msSV[8];
    char hoTen[50];
    int gioiTinh;
    int ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};

struct Ngay
{
    int ngay, thang, nam;
};
// tạo cấu trúc danh sách liên kết đơn
struct Node
{
    Sinhvien *data;
    Node* Link;
};

struct List
{
    Node* first;
    Node* last;
};
// Khởi tạo danh sách liên kết đơn
void taodanhsach (List &ds)
{
    ds.first = NULL;
}

int CheckRong (List ds)
{
    if (ds.first = NULL)
        return 1;
    else
        return 0;
}
// tạo node sinh viên
Node *taonode (Sinhvien *SV) 
{
    Node* p; // tao node P moi
    p = new Node;
    if (p == NULL)  // neu p null thi khong luu duoc vao danh sach
    {
        cout << "KHONG DU BO NHO";
        return NULL;
    }
    p->data = SV;  // gan data node moi vao p
    p->Link = NULL; // node moi la node cuoi
    return p;
}

Sinhvien* Nhapsinhvien()
{
    Sinhvien *sv = new Sinhvien;
    cout << "Nhap MSSV: ";
    cin >> sv->msSV;
    cout << "Nhap Ho va ten: ";
    cin >> sv->hoTen;
    cout << "Nhap gioi tinh: ";
    cin >> sv->gioiTinh;
    cout << "Nhap ngay sinh: ";
    cin>> sv->ngaySinh;
    cout << "Nhap dia chi: ";
    cin >> sv->diaChi;
    cout << "Nhap lop: ";
    cin >> sv->lop;
    cout << "Nhap khoa: ";
    cin >> sv->khoa;

    return sv;
}
// thêm node mới vào danh sách
void add_ds (List *&ds, Sinhvien *sv)
{
    Node *pList = taonode(sv);
    if (ds->first == NULL)
    {
        ds->first = pList;
    }
    else
    {
        Node* padd = ds->first;
        while (padd->Link != NULL)
        {
            padd = padd->Link;
        }
        padd->Link = pList;
    }
}

void PrintDs(List *ds)
{
    Node *pPrint = ds->first;
    if (pPrint == NULL)
    {
        cout <<"Danh sach rong";
        return;
    }
    while (pPrint != NULL)
    {
        Sinhvien *sv = pPrint->data;
        cout << sv->hoTen << endl << sv->msSV << endl << sv->gioiTinh << endl << sv->lop << endl << sv->khoa << endl << sv->ngaySinh << endl << sv->diaChi;
        pPrint = pPrint->Link;
    }
}

void Sapxep(List *&ds)
{
    for (Node *pRun = ds->first; pRun != NULL; pRun = pRun->Link)
    {
        for (Node *pRun2 = pRun->Link; pRun != NULL; pRun2 = pRun2->Link)
        {
            Sinhvien *sv1 = pRun->data;
            Sinhvien *sv2 = pRun2->data;
            if (sv1->msSV > sv2->msSV )
            {
                char massv[8];
                strcpy(massv, sv1->msSV);
                char ten[150];
                strcpy(sv1->hoTen, ten);

                strcpy(sv1->msSV, sv2->msSV);
                strcpy(sv1->hoTen, sv2->hoTen);

                strcpy(sv2->msSV, massv);
                strcpy(sv2->hoTen, ten);

            } 
        }
    }
}



int main()
{
    List *ds;
    CheckRong(*ds);
    taodanhsach(*ds);
    Sinhvien *luan = Nhapsinhvien();
    add_ds(ds);
    PrintDs(ds);

}