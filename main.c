#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure
typedef struct {
    int Temps;
    char Distance[6];
    char Termine[4];
}score;
typedef struct {
    int code;
    char *Nom_Prenom;
    char *Date_Naissance;
    score Competition;
    struct athlete *suivant;
    struct athlete *precedent;
}athlete;

//Inseration dans liste vide 
athlete *ins_lvide(int code,char *NP,char *DN,int T,char D[],char Ter[]) {
    athlete *nvelm=(athlete *)malloc(sizeof(athlete));
    if(nvelm==NULL) exit(1);
    nvelm->Nom_Prenom=malloc(50);
    nvelm->Date_Naissance=malloc(10);
    strcpy(nvelm->Nom_Prenom,NP);
    strcpy(nvelm->Date_Naissance,DN);
    strcpy(nvelm->Competition.Distance,D);
    strcpy(nvelm->Competition.Termine,Ter);
    nvelm->code=code;
    nvelm->Competition.Temps=T;
    nvelm->suivant=NULL;
    nvelm->precedent=NULL;
    return nvelm;
}

//Inseration au debut de la liste
athlete *ins_d(athlete *lis,int code,char *NP,char *DN,int T,char D[],char Ter[]) {
    athlete *debut=ins_lvide(code,NP,DN,T,D,Ter);
    if(lis==NULL)  lis=debut;
    else {
        debut->suivant=lis;
        lis->precedent=debut;
    }
    lis=debut;
    return lis;
}

//Recuperation de donnee
athlete *dataR() {
    athlete *lis,D;
    D.Nom_Prenom=malloc(50);D.Date_Naissance=malloc(10);
    int n,i;
    printf("NBR des athletes");scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("Code:");scanf("%d",&D.code);
        printf("Nom et Prenom:");scanf("%s",D.Nom_Prenom);
        printf("Date de Naissance:");scanf("%s",D.Date_Naissance);
        printf("Temps:");scanf("%d",&D.Competition.Temps);
        printf("Distance:");scanf("%s",D.Competition.Distance);
        printf("Termine:");scanf("%s",D.Competition.Termine);
        lis=ins_d(lis,D.code,D.Nom_Prenom,D.Date_Naissance,D.Competition.Temps,D.Competition.Distance,D.Competition.Termine);
    }
return lis;
}

//Main
int main() {
    athlete *lis=dataR();
    return 0;
}