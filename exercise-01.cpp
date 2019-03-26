/*
Nama Program		: Strukdat-05
Nama				: Muhammad Daffa Alfarizqi
NPM					: 140810180039
Tanggal Pembuatan	: Selasa, 26 Maret 2019
Deskripsi			: Duoble linked list
*/

#include <iostream>
using namespace std;

struct Pembalap
{
    int nomor;
    char nama;
    int waktu;
    Pembalap *next;
    Pembalap *prev;
};

void createNode(Pembalap* &p, int nomor, char nama)
{
    p = new Pembalap;
    cout << "No  : "; p->nomor = nomor;
    cout << "Nama  : "; p->nama = nama;
    cout << "Waktu  : "; cin >> p->waktu;
    p->next = NULL;
    p->prev = NULL;
}

void insertFirst(Pembalap* &head, Pembalap* node)
{
    if (head == NULL)
    {
        head = node;
    } else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

/*void insertBefore(Pembalap *&head, int nomorKey, Pembalap *node){

}

void deleteByKey(Pembalap *&head, int nomorKey, Pembalap *&deletedNode){

}

void search(Pembalap *&firstNode, int nomorKey, Pembalap *&pToUpdate){

}*/

void traversal(Pembalap *head)
{
    Pembalap* pBantu;
    pBantu = head;
    if (head == NULL)
    {
        cout << "DATA KOSONG!" << endl;
    } else
    {
        while(pBantu != NULL)
        {
            cout << pBantu->nomor << "\t" << pBantu->nama << "\t" << pBantu->waktu << endl;
            pBantu = pBantu->next;
        }
        cout << endl;
    }
}
/*
void sortingByNomor(Pembalap *&head){

}

void update(Pembalap *firstNode, int nomorKey){

}
*/
int main()
{
    Pembalap *head = NULL;
    Pembalap *pBaru = NULL;
    Pembalap *pToUpdate = NULL;
    char nama = 'a';

    for (int i = 0; i < 4; i++)
    {
        createNode(pBaru, i + 1, nama++);
        insertFirst(head, pBaru);
    }

    cout << "\n>>> List" << endl;
    traversal(head);

    int keyNomor = 2;

    cout << "\n>>> Insert Before nomor " << keyNomor << endl;
    createNode(pBaru, 99, 'z');
    insertBefore(head, keyNomor, pBaru);
    traversal(head);

    cout << "\n>>> SortingByNomor" << endl;
    sortingByNomor(head);
    traversal(head);

    keyNomor = 3;
    cout << "\n>>> Delete nomor " << keyNomor << endl;
    Pembalap *pHapus = NULL;
    deleteByKey(head, keyNomor, pHapus);
    traversal(head);

    keyNomor = 4;
    cout << "\n>>> Update nomor " << keyNomor << endl;
    update(head, keyNomor);

    cout << "\n>>> Updated list\n";
    traversal(head);
}
