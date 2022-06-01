#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include<time.h>
int piocherMot(char *motPioche);
int indexmot(FILE *fp2, const char *word, int *line, int *col);
int nombreAleatoire(int nombreMax);
void suppressionmot(char*motPioche);
int indexmot(FILE *fp2, const char *word, int *line, int *col)
{
    char str[300];
    char *pos;

    *line = -1;
    *col  = -1;

    while ((fgets(str,300, fp2)) != NULL)
    {
        *line += 1;


        pos = strstr(str, word);

        if (pos != NULL)
        {

            *col = (pos - str);
            break;
        }
    }
if (*col == -1)
        *line = -1;

    return *col;
}
int piocherMot(char *motPioche)
{FILE* f ;
   int nombreMots = 0, numMotChoisi = 0;
   int caractereLu = 0;
  f = fopen("motus.txt", "r");
   if (f == NULL)
   {printf("\n erreur lors de l'ouverture de fichier");return 0;
   }
do{ caractereLu = fgetc(f);
if (caractereLu == '\n')
             nombreMots++;}while(caractereLu!=EOF);
numMotChoisi = nombreAleatoire(nombreMots);

rewind(f);
   while (numMotChoisi > 0)
   {caractereLu = fgetc(f);
       if (caractereLu == '\n')
           numMotChoisi--;}
   fgets(motPioche,3000, f);

   motPioche[strlen(motPioche) - 1] = '\0';
fclose(f);
return 1;
}
int nombreAleatoire(int nombreMax)
{
   srand(time(NULL));
   return (rand() % nombreMax);
}
void suppressionmot(char *motPioche)
{ FILE *f1;FILE*f2;char ctr[9];
  char str[9];char FILENAME[10]="motus.txt";
     f1 = fopen(FILENAME, "r");
        if (!f1)
		{
                printf(" impossible d'ouvrir le fichier !!\n");

        }
        else{
        f2 = fopen("copy.txt", "w");
        if (!f2)
		{
                printf("!!impossible d'ouvrir le fichier\n");
                fclose(f1);

        }

        while (!feof(f1))
        {
            fscanf(f1,"%s",&str);
            if (strcmp(str,motPioche)!=0)
            { fprintf(f2,"%s",str);
              fprintf(f2,"\n",str);
            }
        }
        fclose(f1);
        fclose(f2);
        remove(FILENAME);
        rename("copy.txt", FILENAME);}
}
int verifie ( char mot1[], char mot2[]);
void Color(int couleurDuTexte, int couleurDeFond);
 int main(int argc, char* argv[])
{ char FILENAME[10]="motus.txt"; FILE*fp1;FILE*fp2;
 int col,liness;
char bienplace[8];
   char line[9];int tableau[4];
  int score=0;char ch; int count=0;
int temps=30000;
   long mdp=0;
   int test;
   char motadd[8];
   char motsaisie[8];
   char motchoisi[8] = {0};
   int *lettreTrouvee = NULL;
   long nbessai=0;
char nom1[20];
time_t deb,end;
    double diff ;
 char prop[9],string[9];
   long l,j=1,i,k;
   long longMot = 0;
    long choix_menu=0;
    long choixad=0;
    long choix=0;
    long  n=0;

char affiche[8];
system("cls");
printf("\n\n\t\t\t\t............Loading............");
printf("\n\n");
for(i=0;i<100;i++)
{
    Sleep(12);
    printf("%c",219);
}

     system("cls");
     system("COLOR C");
  printf("\n                                                 ****************************                                         \n");
  printf("\n                                                            MOTUS                                                      \n");
  printf("\n                                                 ****************************                                         \n");
  Sleep(2000);
  system("Cls");
   Color(3,0);
  printf("\n                       || BIENVENUE ||                          \n");
  Color(4,0);
  printf("\n \n \n \n");
  printf("\n-----------------------Regles du jeu------------------------------------------------------------------------------------\n");
  Color(15,0);
  printf("\n -Le but de jeu est de trouver le mot de 8 lettres en miniscules en minimum de coups avec un nombre d'essais bien precis \n");
  printf("\n -La premiere lettre est deja donnee comme indice \n");
  printf("\n -A chaque tentative, la lettre bien placee va apparaitre en couleur \n");
   Sleep(5000);

  Color(4,0);
  printf("\n ----------------------Legende------------------------------------------------------------------------------------------\n");
 Sleep(1000);
Color(2,0);
  printf("\n                    #la Lettre verte=lettre correcte bien placee #\n");
  Sleep(1000);
Color(14,0);
  printf("\n                    #la Lettre jaune=lettre correcte mais mal placee# \n");
  Sleep(1000);
Color(7,0);
  printf("\n                    #le symbole '+' =lettre incorrecte #          \n");
   Sleep(2000);
system("PAUSE");
do{
        system("cls");
  Sleep(1000);
  Color(4,0);
printf("---------------------------Vous etes-----------------------------------------------------------------------------------\n");
Sleep(1000);
Color(7,0);
printf("\n                         1.administrateur                       \n");
printf("\n                         2.utilisateur                       \n\n");
printf("\n                         0.Deconnexion                            \n");

do
  {printf(" \n choix:");

  scanf("%ld",&choixad);
  if(choixad!=1 && choixad!=2 && choixad==0)
    printf("\n tapez sur 1 ou 2 ou 0 si vous voulez quitter le jeu!!");
  }while(choixad!=1 && choixad!=2 && choixad!=0);
if(choixad==0)
    exit(0);
  else  if(choixad==1)
   {

    system("cls"); do {
        printf(" \n mot de passe \n ");
        scanf("%ld",&mdp);
        if(mdp!=1999)
            printf("\n mot de passe incorrect \n");
        }while(mdp!=1999);

        system("cls");
fp1=fopen("motus.txt","a");
fp2=fopen("motus.txt","r");
if (fp2 == NULL)
        {
            printf("erreur lors de l'ouverture de fichier \n");

            exit(0);
        }
        if ( fp1 != NULL )
        {
     do{printf("\n donner un mot a ajouter \n");
            scanf("%s",&motadd);
             printf("\n %s",motadd);
            indexmot(fp2, motadd, &liness, &col);
            if(liness!=-1) printf("\n mot existe deja \n veuillez entrer un autre mot");
            }while((strlen(motadd)!=8) || (liness!=-1)  );
               fprintf (fp1, "%s\n",motadd);
            printf("\n mot ajoute avec succes \n");
            fclose(fp1);
            fp1 = NULL;
            fclose(fp2);
            fp2 = NULL;
     system("PAUSE");   }else printf("impossible d'ouvrir le fichier a ce moment!!\n");} }while(choixad==1);



  if (choixad==2)


 goto game;
  game:{ score=score; bienplace[8]="++++++++";
  printf("\n donner votre nom");
  scanf("%s",&nom1);
 Sleep(2000);
 system("cls");
 Color(4,0);
  printf ("\n---------------------MENU-----------------------------------------------------------------------------------------------\n ");
          Sleep(1000);
          Color(15,0);
            printf ("\n                    1.   commencer le jeu (tapez 1)        \n");
            printf ("\n                    2.    Quitter (tapez 2)             \n\n");

            do{printf (" choix :");scanf ("%ld", &choix_menu);
            printf ("\n\n");

            if (choix_menu > 2 || choix_menu < 1)

                printf ("Choix incorrect\n\n\n");
            }while(choix_menu > 2 || choix_menu < 1);


            if(choix_menu==2 )
            {
                system("cls");
                exit(1);
            }
            else{ Sleep(1000);
            system("cls");
            Color(4,0);
  printf("\n-------------------Choissisez le niveau de difficulte------------------------------------------------------------------\n\n" );
Color(15,0);
 printf("                             1.  DEBUTANT (10 essai) (tapez 1 )                  \n" );
 printf("                             2.   MOYEN (6 essais), (tapez 2)                    \n" );
 printf("                             3.   EXPERT (4 essais), (tapez 3)                   \n\n" );

do{ printf("Choix : " ); scanf("%ld", &choix);
 if (choix!=1 && choix!=2 && choix!=3)

        printf("\n tapez 1 ou 2 ou 3!!!!");

  } while (choix!=1 && choix!=2 && choix!=3);
 if(choix == 1)

  nbessai = 10;

 else if(choix == 2)

   nbessai = 6;

else

    nbessai=4;


}
system("cls");
printf("\n\n\t\t\t\t............Loading............");
printf("\n\n");
for(i=0;i<100;i++)
{
    Sleep(12);
    printf("%c",219);
}
 system("cls");

  Sleep(2000);
  system("cls");
          Color(4,0);
  printf("\n-----------------------C'est parti!!!-----------------------------------------------------------------------------------\n");
     Color(15,0);
    if (!piocherMot(motchoisi))
       exit(0);

   longMot = strlen(motchoisi);
suppressionmot(motchoisi);
lettreTrouvee = malloc(longMot * sizeof(int));
   if (lettreTrouvee == NULL)
       exit(0);

   for (i = 0 ; i < longMot ; i++)
       lettreTrouvee[i] = 0;


deb=time(NULL);
while( nbessai >0 && k!=longMot && diff<temps )
{do { printf("\n\n Il vous reste %ld coups a jouer", nbessai);
       printf("\n Donner un mot \n");

         printf("%c",motchoisi[0]);
       for(i=1;i< longMot ; i++){if (motsaisie[i]!=motchoisi[i] || strlen(motsaisie)!=8)
                                                            { printf("%c",bienplace[i]);}
                                                             else if( (motsaisie[i]==motchoisi[i]) && (strlen(motsaisie)==longMot)) {   bienplace[i]=motchoisi[i];printf("%c",bienplace[i]);}else printf("+");}
           printf("\n");
       scanf("\n %s",&motsaisie);

      if (strlen(motsaisie)!=longMot)printf("\n vous devez entrer un mot de 8 lettres!!");}while(strlen(motsaisie)!=longMot );

test=verifie(motsaisie, motchoisi);
       nbessai--;

for(i=0,k=0;i<longMot;i++)
if(motchoisi[i]==motsaisie[i])
    k++;

end=time(NULL);
diff=difftime(end,deb); }



if (k==longMot && diff<temps)
{printf("\n BRAVO!!! vous avez a gagne  \n");
score+=100;for(i=0;i<longMot;i++)
                            {
                                    Color(10,0);
                                    printf("%c",motsaisie[i]);
                                    Color(7,0);
                            } printf("\n votre score est %d",score);printf("\n le temps ecoule est %lf s",diff); }
else if(k!=longMot || diff==temps)
 {printf("\n PERDU!!! vos tentatives sont terminees\n");for(i=0;i<longMot;i++)
                            {
                                    Color(12,0);
                                    printf("%c",motchoisi[i]);
                                    Color(15,0);
                            }}
 Sleep(3000);
system("cls");
printf("\n");
system("PAUSE");
system("cls");
Color(4,0);
printf("\n-------------------------- Votre score---------------------------------------------------------------------------\n");
Color(15,0);
printf("SCORE:%d",score);
printf("\n temps : %lf",diff);
Sleep(1000);
free(lettreTrouvee);
Sleep(1000);
printf("\n ");
system("PAUSE");
system("cls");
Color(4,0);
printf("\n-----------------voulez vous rejouer une autre partie-------------------------------------------------------------------\n");
Color(7,0);
printf("\n                 1.oui           \n");
printf("\n                 0.non           \n");
printf("Choix:        ");
    do
    {
        scanf("%ld",&n);
        if(n!=0 && n!=1)
            printf("\n tapez 0 ou 1 !!! \n");
    }
    while(n!=1&&n!=0);
   } if(n==1)  goto game;
  else  { score=0;
    goto identity;}
identity:{do{Color(4,0);printf("\n---------------------------Vous etes-----------------------------------------------------------------------------------\n");
Sleep(1000);
Color(7,0);
printf("\n                         1.administrateur                       \n");
Color(8,0);
printf("\n                         2.utilisateur (s)                       \n\n");
Color(15,0);
printf("\n                         0.deconnexion                             \n");
printf(" \n choix:");
do
  {

  scanf("%ld",&choixad);
  if(choixad!=1  && choixad==0)
    printf("\n tapez sur 1 ou 0!!");
  }while(choixad!=1 && choixad!=0);
if(choixad==0)
    exit(0);
  else  if(choixad==1)
    do{ system("cls"); do {
        printf(" \n mot de passe \n ");
        scanf("%ld",&mdp);
        if(mdp!=1999)
            printf("\n mot de passe incorrect \n");
        }while(mdp!=1999);
    system("cls");
fp1=fopen("motus.txt","a");
fp2=fopen("motus.txt","r");
if (fp2 == NULL)
        {
            printf("erreur lors de l'ouverture de fichier \n");

            exit(0);
        }
        if ( fp1 != NULL )
        { do{printf("\n donner un mot a ajouter \n");
            scanf("%s",&motadd);
             printf("\n %s",motadd);
            indexmot(fp2, motadd, &liness, &col);
            if(liness!=-1) printf("\n mot existe deja \n veuillez entrer un autre mot");
            }while((strlen(motadd)!=8) || (liness!=-1)  );
               fprintf (fp1, "%s\n",motadd);
            printf("\n mot ajoute avec succes \n");
            fclose(fp1);
            fp1 = NULL;
            fclose(fp2);
            fp2 = NULL;

   system("PAUSE");     }}while(choixad==1);}while(choixad!=0);}


       return 0;

}
int verifie ( char mot1[], char mot2[])
{
char reste_a_trouver[9];
char bien_place[9];
char mal_place[8];
char prv[1]="+";
int tab[26];
int i, k,nb_ltr ;
nb_ltr = strlen(mot1);
for(i=0;i<5;i++)
{
bien_place[i]=prv[0];
mal_place[i]=prv[0];
reste_a_trouver[i]=mot2[i];
tab[i]=0;
}
for(i=0;i<nb_ltr;i++)
if(mot1[i]==reste_a_trouver[i])
{
bien_place[i]=mot1[i];
reste_a_trouver[i]='+';
tab[i]=1;

}
for(i=0;i<nb_ltr;i++)
{
for (k=0;k<nb_ltr;k++)
{
if ((mot1[i]==reste_a_trouver[k])&&(tab[i] != 1))
{
mal_place[i]=mot1[i];
tab[i]=2;
reste_a_trouver[k]='+';
}
}
}
for(i=0;i<nb_ltr;i++)
{
if (mot1[i]==bien_place[i])
{
Color(2,0);
printf(" \t %c",mot1[i]);
Color(7,0);
}
else if (mot1[i]==mal_place[i])
{
Color(14,0);
printf(" \t %c",mot1[i]);
Color(7,0);
}
else
{
Color(7,0);
printf(" \t +");
}
}
return 1;
}
void Color(int couleurDuTexte, int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
