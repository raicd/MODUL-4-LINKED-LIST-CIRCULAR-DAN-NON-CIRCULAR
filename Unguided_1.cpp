#include <iostream>
#include <iomanip>

using namespace std;

struct mahasiswa
{
    string nama;
    string nim;
};

struct node
{
    mahasiswa identitas;
    node *prev;
    node *next;
};

node *head, *tail;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    return head == NULL;
}

mahasiswa mintaData()
{
    system("cls");
    mahasiswa identitas;
    cout << "\nMasukkan Nama\t: ";
    cin.ignore();
    getline(cin, identitas.nama);
    cout << "Masukkan NIM\t: ";
    cin >> identitas.nim;
    return identitas;
}

void insertDepan(mahasiswa identitas)
{
    node *baru = new node;
    baru->identitas = identitas;
    baru->next = head;
    baru->prev = NULL;
    if (isEmpty())
    {
        tail = baru;
    }
    else
    {
        head->prev = baru;
    }
    head = baru;
}

void insertBelakang(mahasiswa identitas)
{
    node *baru = new node;
    baru->identitas = identitas;
    baru->next = NULL;
    baru->prev = tail;
    if (isEmpty())
    {
        head = baru;
    }
    else
    {
        tail->next = baru;
    }
    tail = baru;
}

void insertTengah(mahasiswa identitastitas, int posisi)
{
    if (posisi <= 1)
    {
        insertDepan(identitastitas);
        return;
    }
    node *baru = new node;
    baru->identitas = identitastitas;
    node *bantu = head;
    for (int i = 1; i < posisi - 1 && bantu != NULL; i++)
    {
        bantu = bantu->next;
    }
    if (bantu == NULL)
    {
        cout << "Posisi diluar jangkauan" << endl;
        return;
    }
    baru->next = bantu->next;
    baru->prev = bantu;
    if (bantu->next != NULL)
    {
        bantu->next->prev = baru;
    }
    bantu->next = baru;
}

void ubahNode(node *target, mahasiswa data)
{
    target->identitas = data;
}

void ubahDepan(mahasiswa data)
{
    if (isEmpty())
    {
        cout << "List kosong" << endl;
        return;
    }
    ubahNode(head, data);
}

void ubahBelakang(mahasiswa data)
{
    if (isEmpty())
    {
        cout << "List kosong" << endl;
        return;
    }
    ubahNode(tail, data);
}

void ubahTengah(mahasiswa data, string nim)
{
    node *bantu = head;
    while (bantu != NULL)
    {
        if (bantu->identitas.nim == nim)
        {
            ubahNode(bantu, data);
            return;
        }
        bantu = bantu->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan" << endl;
}

void tampil()
{
    system("cls");
    node *bantu = head;
    cout << "Nama "
         << " Nim\n";
    while (bantu != NULL)
    {
        cout << bantu->identitas.nama << " " << bantu->identitas.nim << endl;
        bantu = bantu->next;
    }
}

void hapusDepan()
{
    if (isEmpty())
    {
        cout << "List kosong" << endl;
        return;
    }
    node *hapus = head;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    delete hapus;
}

void hapusBelakang()
{
    if (isEmpty())
    {
        cout << "List kosong" << endl;
        return;
    }
    node *hapus = tail;
    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete hapus;
}

void hapusTengah(string nim)
{
    if (isEmpty())
    {
        cout << "List kosong" << endl;
        return;
    }
    node *bantu = head;
    while (bantu != NULL)
    {
        if (bantu->identitas.nim == nim)
        {
            if (bantu == head)
            {
                hapusDepan();
            }
            else if (bantu == tail)
            {
                hapusBelakang();
            }
            else
            {
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
                delete bantu;
            }
            return;
        }
        bantu = bantu->next;
    }
    cout << "Data dengan NIM " << nim << " tidak ditemukan" << endl;
}

void hapusList()
{
    while (!isEmpty())
    {
        hapusDepan();
    }
    cout << "Semua data berhasil dihapus" << endl;
}

int main()
{
    init();
    mahasiswa identitas;
    int operasi, posisi;

    do
    {
        cout << "PROGRAM DOUBLE LINKED LIST NON-CIRCULAR\n\n";
        cout << "1.Tambah Depan" << endl;
        cout << "2.Tambah Belakang" << endl;
        cout << "3.Tambah Tengah" << endl;
        cout << "4.Ubah Depan" << endl;
        cout << "5.Ubah Belakang" << endl;
        cout << "6.Ubah Tengah" << endl;
        cout << "7.Hapus Depan" << endl;
        cout << "8.Hapus Belakang" << endl;
        cout << "9.Hapus Tengah" << endl;
        cout << "10.Hapus List" << endl;
        cout << "11.Tampilkan" << endl;
        cout << "0.Exit" << endl;
        cout << "\nPilih Operasi : ";
        cin >> operasi;

        switch (operasi)
        {
        case 1:
            cout << "Tambah Depan\n";
            insertDepan(mintaData());
            cout << endl;
            break;
        case 2:
            cout << "Tambah Belakang\n";
            insertBelakang(mintaData());
            cout << endl;
            break;
        case 3:
            cout << "Tambah Tengah\n";
            cout << "Nama : ";
            cin >> identitas.nama;
            cout << "NIM : ";
            cin >> identitas.nim;
            cout << "Posisi : ";
            cin >> posisi;
            insertTengah(identitas, posisi);
            cout << endl;
            break;
        case 4:
            cout << "Ubah Depan\n";
            ubahDepan(mintaData());
            cout << endl;
            break;
        case 5:
            cout << "Ubah Belakang\n";
            ubahBelakang(mintaData());
            cout << endl;
            break;
        case 6:
            cout << "Ubah Tengah\n";
            cout << "NIM : ";
            cin >> identitas.nim;
            ubahTengah(mintaData(), identitas.nim);
            cout << endl;
            break;
        case 7:
            cout << "Hapus Depan\n";
            hapusDepan();
            cout << endl;
            break;
        case 8:
            cout << "Hapus Belakang\n";
            hapusBelakang();
            cout << endl;
            break;
        case 9:
            cout << "Hapus Tengah\n";
            cout << "NIM : ";
            cin >> identitas.nim;
            hapusTengah(identitas.nim);
            cout << endl;
            break;
        case 10:
            cout << "Hapus List\n";
            hapusList();
            cout << endl;
            break;
        case 11:
            cout << "Tampilkan\n";
            tampil();
            cout << endl;
            break;
        case 0:
            cout << "Exit Program\n";
            break;
        default:
            cout << "Salah input operasi\n";
            cout << endl;
            break;
        }
    } while (operasi != 0);

    return 0;
}
