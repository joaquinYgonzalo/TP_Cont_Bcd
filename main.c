#include "MKL25Z4.h"

int contador1 [4]={1, 2, 3, 4};
int contador2 [4]={5, 6, 7, 8};
int puls= 9;
int display[10][4]={
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 1}
};
int ContB=0;
int main(){
    SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
    for(int j=0; j<4; j++){
        PORTA->PCR[contador1[j]]|=PORT_PCR_MUX(1);
        PORTA->PCR[contador2[j]]|=PORT_PCR_MUX(1);
    }
    PORTA->PCR[puls]|=PORT_PCR_MUX(0);
    while (1){
        while(puls ==1){
            for(int i=0; i<10;i++){
                for(int j=0; j<4;j++){
                     PTA->PSOR|=(display[i][j]<<contador1[j]);
                     if(i==9){
                        ContB++;//cuenta en Y para el contador de decenas
                        for(int j=0; j<4;j++){
                            PTA->PSOR|=(display[ContB][j]<<contador2[j]);
                        }
                        i=0;
                     }
                }
            }
        }
        for(int i=9; i=0;i--){
            for(int j=4; j=0;j--){
                PTA->PSOR|=(display[i][j]<<contador1[j]);
                if(i==0){
                    ContB --;
                    for(int j=0; j<4;j++){
                        PTA->PSOR|=(display[ContB][j]<<contador2[j]);
                        }
                        i=9;
                    }
                }
            }
    }
}