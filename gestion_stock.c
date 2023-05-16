

#include<stdio.h>
#include<unistd.h>
struct{
int code;
char designation;
float prix;
}article;





int Rechercher (int code)
    {
        int exist = 0;
        FILE *F;
        F = fopen("article.txt", "r");
        do {
            fscanf(F, "%d %S  %f", &article.code, &article.designation,&article.prix);
            if (article.code ==code)
            exist = 1;
        } while ((!feof(F)) && (exist == 0));
        fclose(F);
        return exist;
    }

    void Ajouter ()
    {
        int code;
        FILE *F;
        F = fopen("article.txt", "a");
        printf("Donner la code de l'article : ");
        scanf("%d", &code);
        while (Rechercher(code) == 1)
        {
            printf("\nIl existe déja un article avec cette code.\n\nTaper une autre code: ");
            scanf("%d", &code);
        }
        article.code = code;
        printf("Donner le Designation: ");
        scanf("%s",&article.designation);
        printf("Donner le Prix: ");
        scanf("%d", &article.prix);
        fprintf(F, "%d %s %f", article.code,&article.designation,&article.prix);
        fprintf(F, "\n");
        fclose(F);
        printf("\nAjout effectue avec succes\n");
    }

    void Modifier ()
    {
        FILE *F;
        int code, exist = 0, test1 = 0, test2 = 1;
        F = fopen("article.txt", "r");
        if (access("article.txt", F_OK) == 0) // access() permet de vérifier  les permissions d'utilisateur réel à un fichier
            //F_ok indiquer un vérification  de l'existence de fichier
        {
        if (fscanf(F, "%d %s %f",  &article.code, &article.designation,&article.prix) != EOF)
        {
            fclose(F);
            printf("Donner la code de l'article a modifier: ");
            scanf("%d", &code);
            FILE *FT;
            FT = fopen("Temp.txt", "w");
            F = fopen("article.txt", "r");
            do
            {
                fscanf(F, "%d %s  %f", &article.code, &article.designation,&article.prix);
                test2 = article.code;
                if (code == article.code)
                {
                    exist = 1;
                    code = 0;
                    printf("Donner le nouveau Designation: ");
                    scanf("%s", &article.designation);
                    printf("Donner le nouveau Prix: ");
                    scanf("%f", &article.prix);

                }
                if (test1 != test2)
                {
                    fprintf(FT, "%d %s %f", article.code, &article.designation,&article.prix);
                    fprintf(FT, "\n");
                }
                test1 = article.code;
            } while (!feof(F));
            if (exist == 1)
                printf("\nModification effectuee avec succes\n");
                else
                    printf("\nArticle inexistant\n");
                fclose(F);
                fclose(FT);
                remove("article.txt");
                rename("Temp.txt", "article.txt");
        } else
        printf("Fichier vide\n");
        fclose(F);
        } else
        printf("Fichier inexistant\n");
        fclose(F);
    }

    void Supprimer ()
    {
        FILE *F;
        int code, exist = 0, del = 0, test1 = 0, test2 = 1;
        F = fopen("article.txt", "r");
        if (access("article.txt", F_OK) == 0)
        {
            if (fscanf(F, "%d %s %f", &article.code, &article.designation,&article.prix) != EOF)
            {
                fclose(F);
                printf("Donner le code de l'article a supprimer: ");
                scanf("%d", &code);
                FILE *FT;
                FT = fopen("Temp.txt", "w");
                F = fopen("article.txt", "r");
                do
              {
                test2 = article.code;
                exist = 0;
                if (code == article.code)
                {
                    exist = 1;
                    del = 1;
                }
                if ((test1 != test2) && (exist == 0))
                {
                    fprintf(FT, "%d %s %f",&article.code,&article.designation,&article.prix);
                    fprintf(FT, "\n");
                }
                test1 = article.code;
                fscanf(F, "%d %s %f", &article.code, &article.designation,&article.prix);
              } while (!feof(F));
              if (del == 1)
                printf("\nSuppression effectuee avec succes\n");
            else
                printf("\nArticle inexistant\n");
                fclose(F);
                fclose(FT);
                remove("article.txt");
                rename("Temp.txt", "article.txt");
            } else
            printf("Fichier vide\n");
            fclose(F);
        } else
        printf("Fichier inexistant\n");
        fclose(F);

    }


    void Consulter ()
    {
        FILE *F;
        int exist = 0, vide = 0, inexist = 0, code;
        F = fopen("article.txt", "r");
        if (access("article.txt", F_OK) == 0)
        {
            if (fscanf(F, "%d %s %f", &article.code, &article.designation,&article.prix) != EOF)
        {
            printf("Donner le code de l'article a consulter: ");
            scanf("%d", &code);
            do
            {
                if (code == article.code)
                {
                    printf("\n*******************");
                    exist = 1;
                    printf("\ncode: %d\nDesignation: %s\nPrix: %f\n*******************", article.code,&article.designation,&article.prix) ;           }
                  fscanf(F, "%d %s %f",&article.code, &article.designation,&article.prix);
            } while (!feof(F));
            printf("\n");
        } else {
        printf("Fichier vide\n");
        vide = 1;
        }
        fclose(F);
        } else {
        printf("Fichier inexistant\n");
        inexist = 1;
        }
        fclose(F);
        if (exist == 0 && vide == 0 && inexist == 0)
            printf("Article inexistant\n");
            fclose(F);
    }


    void main (){
        int choix;
         do{
  printf("                  Menu        \n");
  printf("\n");
  printf(" [1]:Ajouter un article \n");
  printf(" [2]:modifier un article \n");
  printf(" [3]:Supprimer un article \n");
  printf(" [4]:Consulter un article \n");
  printf(" [5]:Quttier \n");

  printf("Veuillez introduire votre choix:");
  scanf("%d",&choix);
switch (choix)
        {
            case 1 : Ajouter();
                     break;

            case 2 : Modifier();
                     break;

            case 3 : Supprimer();
                     break;

            case 4 : Consulter();
                     break;

            case 5 : exit(0);
                     break;
            default : printf("Choix incorrect\n");
                      break;
        }
        }
while(choix!=(5));

        }
