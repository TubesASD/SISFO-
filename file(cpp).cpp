#include "file(h).h"

using namespace std;

list l;
int counter=0;

void menuAwal() {
    system("cls");
    cout<<"\n\tSELAMAT DATANG DI MENU UTAMA"<<endl;
    cout<<"\n\tLogin Sebagai:"<<endl;
    cout<<"\n\t1. Admin";
    cout<<"\n\t2. Pegawai";
    cout<<"\n\t3. Keluar";
}

void menuAdmin() {
    system("cls");
    cout<<"\n\tMENU UTAMA ADMIN"<<endl;
    cout<<"\n\t 1. Create Struktur";
    //cout<<"\n\t 2. Create Sturktur Baru";
    cout<<"\n\t 3. Update Data Pegawai";
    cout<<"\n\t 4. Update Deskripsi Pekerjaan";
    cout<<"\n\t 5. Delete Pegawai";
    cout<<"\n\t 6. Delete Struktur";
    cout<<"\n\t 7. View";
    cout<<"\n\t 8. Search Data Pegawai";
    cout<<"\n\t 9. Statistik Perusahaan";
    cout<<"\n\t12. Kembali ke Menu Utama";
}

void menuCreate() {
    system("cls");
    cout<<"\n\tMENU CREATE STRUKTUR"<<endl;
    cout<<"\n\t1. Create Struktur Utama";
    cout<<"\n\t2. Create Wakil Direktur";
	cout<<"\n\t2. Create Divisi";
	cout<<"\n\t3. Create Manajer";
	cout<<"\n\t4. Create Staff";
	cout<<"\n\t5. Kembali ke Menu Admin";
}

void menuView() {
    system("cls");
    cout<<"\n\tMENU VIEW"<<endl;
    cout<<"\n\t1. View All";
    cout<<"\n\t2. View Data Pegawai";
    cout<<"\n\t3. View by Group";
    cout<<"\n\t4. Kembali ke Menu Admin";
}

void loginAdmin() {
    char *sandi,*pass;
    bool kondisi;
    int i=1,pil;

    pass="admin";
    while(i<=3){
        system("cls");
        cout<<"\n\tPassword : "; cin>>sandi;
        if(strcmp(pass,sandi)==0){
            i=4;
            kondisi=true;
            break;
        }else{
            cout<<"\n\n\n\tPassword Salah!";
            getch();
        }
        i++;
    }

    if(kondisi==true){
        do{
            menuAdmin();
            cout<<"\n\n\tPilihan: "; cin>>pil;
            switch(pil){
                case 1:
                    do{
                        menuCreate();
                        cout<<"\n\n\tPilihan: "; cin>>pil;
                        switch(pil){
                            case 1: createStrukturDirek(&l,&counter); break;
                            case 2: createSturkturWakil(&l,&counter); break;
                            case 3: break;
                            case 4: break;
                            case 5: menuAdmin(); break;
                            default: menuCreate(); break;
                        }
                    }while(pil!=5);
                    break;

                case 2: break;
                case 3: break;
                case 4: break;
                case 5: break;
                case 6: break;
                case 7:
                    do{
                        menuView();
                        cout<<"\n\n\tPilihan: "; cin>>pil;
                        switch(pil){
                            case 1: break;
                            case 2: break;
                            case 3: tampilGroup(&l); break;
                            case 4: menuAdmin(); break;
                            default: menuView(); break;
                        }
                    }while(pil!=4);
                    break;
                case 8: break;
                case 9: break;
                case 10: break;
                case 11: break;
                case 12: menuAwal(); break;
                default: menuAdmin(); break;
            }
        }while(pil!=12);
    }else{
        menuAwal();
    }
}

addressinduk alokasiInduk(infotypeinduk data) {
    addressinduk p=(addressinduk)malloc(sizeof(elmlistinduk));
    info(p)=data;
    next(p)=nil;
    prev(p)=nil;
    firstlevel2(p)=nil;
    return p;
}

addresslevel2 alokasiLevel2(infotypelevel2 data) {
    addresslevel2 p=(addresslevel2)malloc(sizeof(elmlistlevel2));
    info(p)=data;
    next(p)=nil;
    prev(p)=nil;
    firstlevel3(p)=nil;
    return p;
}

addresslevel3 alokasiLevel3(infotypelevel3 data) {
    addresslevel3 p=(addresslevel3)malloc(sizeof(elmlistlevel3));
    info(p)=data;
    next(p)=nil;
    prev(p)=nil;
    firstlevel3(p)=nil;
    return p;
}

addresslevel4 alokasiLevel4(infotypelevel4 data) {
    addresslevel4 p=(addresslevel4)malloc(sizeof(elmlistlevel4));
    info(p)=data;
    next(p)=nil;
    prev(p)=nil;
    firstleve4(p)=nil;
    return p;
}

addresslevel5 alokasiLevel5(infotypelevel5 data) {
    addresslevel5 p=(addresslevel5)malloc(sizeof(elmlistlevel5));
    info(p)=data;
    next(p)=nil;
    prev(p)=nil;
    return p;
}

long int nipDirek(int counter,infotypeinduk data) {
    long temp=1210000;
    temp += counter;
    return temp;
};

void createStrukturDirek(list *l,int *counter) {
    system("cls");
    addressinduk p;
    infotypeinduk data;

    cout<<"\n\tDirektur "; cin>>data.jabatan;
    cout<<"\n\tNama        : "; cin>>data.nama;
    cout<<"\n\tTahun Masuk : "; cin>>*data.thn;
    *data.nip=nipDirek(*counter,data);

    p=alokasiInduk(data);

    if(first(l)==nil){
        first(l)=p;
        last(l)=p;
    }else{
        next(last(l))=p;
        last(l)=p;
    }
    *counter=*counter+1;
}

long int nipWakil(int counter,infotypelevel2 data) {
    long temp=1220000;
    temp += counter;
    return temp;
};

void createSturkturWakil(list *l,int *counter) {
    addressinduk p=first(l);
    addresslevel2 q;
    addresslevel2 baru;
    infotypelevel2 data;
    char *jabatan;
    bool found=false;

    if(first(l)==nil){
        cout<<"\n\tTidak Ada Data yang Terdaftar dalam Struktur";
    }else{
        system("cls");
        cout<<"\n\tNama Departemen : "; cin>>jabatan;
        while(p!=nil&&found==false){
            if(strcmp(info(p).jabatan,jabatan)==0){
                    found=true;
            }else{
                p=next(p);
            }
        }
        if(found==true){
            cout<<"\n\n\tDepartemen Ditemukan, Silakan Input Data";
            cout<<"\n\tNama     : "; cin>>data.nama;
            cout<<"\n\tTahnu Masuk : "; cin>>*data.thn;
            *data.nip=nipWakil(*counter,data);
            *data.jabatan=1;

            baru=alokasiLevel2(data);
            if(firstlevel2(p)==nil){
                firstlevel2(p)=baru;
            }else{
                next(baru)=firstlevel2(p);;
                prev(firstlevel2(p))=baru;
                firstlevel2(p)=baru;
                *info(next(baru)).jabatan=*info(baru).jabatan+1;
            }
            *counter=*counter+1;
        }else{
            cout<<"\n\n\tDepartemen Tidak Terdaftar Dalam Struktur";
        }
    }
    getch();
}

void tampilGroup(list *l) {
    system("cls");
    addressinduk p=first(l),temp;
    addresslevel2 q;
    char *jabatan;
    bool found=false;

    if(first(l)==nil){
        cout<<"\n\tTidak Ada Data yang Terdaftar dalam Struktur";
    }else{
        system("cls");
        cout<<"\n\tNama Departemen : "; cin>>jabatan;
        while(p!=nil&&found==false){
            if(strcmp(info(p).jabatan,jabatan)==0){
                    found=true;
            }else{
                p=next(p);
            }
        }
        if(found==true){
            cout<<"\n\tDepartemen "<<info(p).jabatan;
            cout<<"\n\n\tDirektur Utama "<<info(p).jabatan;
            cout<<"\n\tNIP         : "<<*info(p).nip;
            cout<<"\n\tNama        : "<<info(p).nama;
            cout<<"\n\tTahun Masuk : "<<*info(p).thn;
            q=firstlevel2(p);
            if(q==nil){
                cout<<"\n\tTidak Ada Data yang Terdaftar dalam Struktur";
            }else{
                while(q!=nil){
                    cout<<"\n\tWakil Direktur "<<*info(q).jabatan;
                    cout<<"\n\tNIP         : "<<*info(q).nip;
                    cout<<"\n\tNama        : "<<info(q).nama;
                    cout<<"\n\tTahun Masuk : "<<*info(q).thn;
                    cout<<endl;
                    q=next(q);
                }
            }
        }else{
            cout<<"\n\n\tDepartemen Tidak Terdaftar Dalam Struktur";
        }
    }
    getch();
}

hbhbjhbkjhbkjhbkjnjunjunnklnlknlknklnjhgkctrcjhbgyuhjblfgbjlhfdjhugkjhgfbmjhnbhdjmnldnjmhdfnhgtfhyggvfscfvdecfgtrdsgfsgf
