#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstring.h>
#include <string.h>
#include <stdlib.h>
#include "file(h).h"
#include "file(cpp).cpp"

using namespace std;

int main() {
    int i;
    int pil;
    do{
        menuAwal();
        cout<<"\n\n\tPilihan: "; cin>>pil;
        switch(pil){
            case 1:
                loginAdmin();
                break;

            case 2:break;
            case 3: break;
            default: menuAwal(); break;
        }
    }while(pil!=3);
    return 0;
}
