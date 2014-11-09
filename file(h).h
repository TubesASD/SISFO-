#ifndef FILE(H)_H_INCLUDED
#define FILE(H)_H_INCLUDED
#define nil NULL
#define info(p) (p)->info
#define next(p) (p)->next
#define prev(p) (p)->prev
#define firstlevel2(p) (p)->firstlevel2
#define lastlevel2(p) (p)->lastlevel2
#define firstlevel3(p) (p)->firstlevel3
#define lastlevel3(p) (p)->lastlevel3
#define firstlevel4(p) (p)->firstlevel4
#define lastlevel4(p) (p)->lastlevel4
#define firstlevel5(p) (p)->firstlevel5
#define lastlevel5(p) (p)->lastlevel5
#define first(l) (l)->first
#define last(l) (l)->last

typedef struct induk{
    char jabatan[30];
    char nama[30];
    int nip[10];
    int thn[4];
} infotypeinduk;
typedef struct level2{
    int jabatan[4];
    char nama[30];
    int nip[10],thn[4];
} infotypelevel2;
typedef struct level3{
    char jabatan[30];
    char nama[30];
    int nip[10],thn[4];
} infotypelevel3;
typedef struct level4{
    char jabatan[30];
    char nama[30];
    int nip[10],thn[4];
} infotypelevel4;
typedef struct level5{
    char jabatan[30];
    char nama[30];
    int nip[10],thn[4];
} infotypelevel5;
typedef struct telmlistinduk *addressinduk;
typedef struct telmlistlevel2 *addresslevel2;
typedef struct telmlistlevel3 *addresslevel3;
typedef struct telmlistlevel4 *addresslevel4;
typedef struct telmlistlevel5 *addresslevel5;
typedef struct telmlistinduk{
    infotypeinduk info;
    addressinduk next;
    addressinduk prev;
    addresslevel2 firstlevel2;
} elmlistinduk;
typedef struct telmlistlevel2{
    infotypelevel2 info;
    addresslevel2 next;
    addresslevel2 prev;
    addresslevel3 firstlevel3;
} elmlistlevel2;
typedef struct telmlistlevel3{
    infotypelevel3 info;
    addresslevel3 next;
    addresslevel3 prev;
    addresslevel4 firstlevel4;
} elmlistlevel3;
typedef struct telmlistlevel4{
    infotypelevel4 info;
    addresslevel4 next;
    addresslevel4 prev;
    addresslevel5 firstlevel5;
} elmlistlevel4;
typedef struct telmlistlevel5{
    infotypelevel5 info;
    addresslevel5 next;
    addresslevel5 prev;
} elmlistlevel5;
typedef struct{
    addressinduk first;
    addressinduk last;
} list;

void menuAwal();
void menuAdmin();
void loginAdmin();
addressinduk alokasiInduk(infotypeinduk data);
addresslevel2 alokasiLevel2(infotypelevel2 data);
long int nipDirek(int counter,infotypeinduk data);
void createStrukturDirek(list *l,int *counter);
long int nipWakil(int counter,infotypelevel2 data);
void createSturkturWakil(list *l,int *counter);
void tampilGroup(list *l);

#endif // FILE(H)_H_INCLUDED
