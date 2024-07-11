#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <math.h>



int main(){
    int sygkrothmata,i,j,k,sygkrothmata_ana_wra[24],max,wra;


   printf("Dwse arithmo sygkrothmatwn:");
   sygkrothmata=GetInteger();


   int h_afijhs[sygkrothmata],h_anaxwrhshs[sygkrothmata],paramonh[sygkrothmata],idios_arithmos[sygkrothmata];


   for (i=0;i<sygkrothmata;i++){

      printf("Dwse wra afijhs gia to %do sygkrothma:",i+1);
      h_afijhs[i]=GetInteger();
      printf("Dwse wra apoxwrhshs gia to %do sygkrothma:",i+1);
      h_anaxwrhshs[i]=GetInteger();
    }


    for (i=0;i<sygkrothmata;i++){
        paramonh[i]=0;
    }

    for (i=0;i<sygkrothmata;i++){
        paramonh[i]=h_anaxwrhshs[i]-h_afijhs[i];
    }

    for (i=0;i<24;i++)
        sygkrothmata_ana_wra[i]=0;

    for (i=0;i<24;i++){
        for (j=0;j<sygkrothmata;j++){
            if ((h_afijhs[j]+paramonh[j]>i)&&(i>=h_afijhs[j])){
               sygkrothmata_ana_wra[i]=sygkrothmata_ana_wra[i]+1;
               }
        }
    }

    wra=0;
    max=sygkrothmata_ana_wra[0];

    for (i=1;i<24;i++){
        if (sygkrothmata_ana_wra[i]>max){
            max=sygkrothmata_ana_wra[i];
            wra=i;
        }
    }
    k=0;
    for(i=0;i<24;i++){
        if (sygkrothmata_ana_wra[i]==max){
            idios_arithmos[k]=i;
            k=k+1;
        }
    }
    printf("\n");
    for (i=0;i<k;i++){
      printf("To paidi mporei  na paei stis %d:00-%d:00 gia na dei %d sygkrothmata\n",idios_arithmos[i],idios_arithmos[i]+1,max);
      printf("Sygkrothmata pou tha dei einai:");

      for (j=0;j<sygkrothmata;j++){
         if ((h_afijhs[j]+paramonh[j]>idios_arithmos[i])&&(idios_arithmos[i]>=h_afijhs[j])){
                printf("%d,",j+1);
         }
      }
      printf("\n");
    }


return(0);
}
