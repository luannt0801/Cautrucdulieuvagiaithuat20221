#include <iostream>

using namespace std;

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

struct Node
{
    Sinhvien data;
    Node* Link;
};
typedef struct Node NODE;

struct List
{
    Node* first;
    Node* last;
};
typedef struct  List LIST;

void taodanhsach (LIST &ds)
{
    ds.first = NULL;
    ds.last = NULL;
}

int CheckRong (LIST ds)
{
    if (ds.first = NULL)
        return 1;
    else
        return 0;
}

NODE* taonode (Sinhvien SV)  // char a, char b, int c, char d, char e, char f // char a[8], char b[50], int c, int d, char e[100], char f[12], char g[7]
{
    NODE* p; // tao node P moi
    p = new NODE;
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

void add_ds (LIST *&ds, Sinhvien sv)
{
    NODE* pList = taonode(sv);
    if (ds->first == NULL)
    {
        ds->first = pList;
    }
    else
    {
        NODE* padd = ds->first;
        while (padd->Link != NULL)
        {
            padd = padd->Link;
        }
        padd->Link = pList;
    }
}

int main()
{
    List* ds;
    taodanhsach(ds);
    CheckRong(ds);

}