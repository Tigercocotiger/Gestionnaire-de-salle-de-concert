#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

#define PORT 6000
#define MAX_BUFFER 1000
#define MAX_CLIENTS 100  
#define BUF 128 /* can change the buffer size as well */
#define TOT 100 /* change to accomodate other sizes, change ONCE here */
#define MAX 256

const char *EXIT = "exit";

int searchresa(char resa[], char reponse[2], int compteur, char tampon[]){
    for(int k=0;k < compteur;k++ ){
        if(resa[k]==reponse[0]){
            k++;
            if(resa[k]==reponse[1]){
                return 1;
            }else{
                k++;
            }
        }else{
            k=k+2;
        }    
    }
    return 0;
}

void displayresa(char resa[], int compteur, char tampon[]){
    char nombres[4];
    strcat(tampon, "\n\n");
    strcat(tampon,"    0 1 2 3 4 5 6 7 8 9\n");
    for(int i=0; i <100;i++){
        if((i%10==0)&&(i!=0)){
            sprintf(nombres,"\n%d ", i);
            strcat(tampon, nombres);
        }else if((i==0)){
            sprintf(nombres," 0 ");
            strcat(tampon, nombres);
        }
        char buf[100];
        if(i<10){
        snprintf(buf, 15, "0%d", i);
        }else{
        snprintf(buf, 15, "%d", i); 
        }
        if(searchresa(resa, buf, compteur, tampon)==0){
            strcat(tampon,"🟢");
        }else{
            strcat(tampon,"🔴");
        }
    }
    strcat(tampon,"\n\n");
}

void delete(int n, char tampon[]){
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";

        fptr1 = fopen("file", "r");

        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 

        lno=n;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            
            /* skip the line at given line number */
            if (ctr != lno) 
            {
                    fprintf(fptr2, "%s", str);
            }
            ctr++;
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("file");  		// remove the original file 
        rename(temp, "file"); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
        fptr1=fopen("file","r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n","file"); 
           do
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }while(ch!=EOF);
        fclose(fptr1);
}  

void add(int n, char tampon[]){
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";

        fptr1 = fopen("file", "r");

        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 

        lno=n;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            
            /* skip the line at given line number */
            if (ctr != lno) 
            {
                    fprintf(fptr2, "%s", str);
            }
            else{
                    strcat(str, tampon);
                    strcat(str, ", \n");
                    fprintf(fptr2, "%s", str);
            }
            ctr++;
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("file");  		// remove the original file 
        rename(temp, "file"); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
        fptr1=fopen("file","r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n","file"); 
           do
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }while(ch!=EOF);
        fclose(fptr1);
} 

void addprenom(int n, char tampon[]){
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";

        fptr1 = fopen("file", "r");

        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 

        lno=n+1;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            
            /* add the line at given line number */
            if (ctr != lno) 
            {
                    fprintf(fptr2, "%s", str);
            }
            else{
                    strtok(str, "\n");
                    strtok(str, " ");
                    strcat(str, tampon);
                    strcat(str, " *\n");
                    fprintf(fptr2, "%s", str);
            }
            ctr++;
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("file");  		// remove the original file 
        rename(temp, "file"); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
        fptr1=fopen("file","r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n","file"); 
           do
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }while(ch!=EOF);
        fclose(fptr1);
} 

void addnom(int n, char tampon[]){
        int lno, ctr = 0;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";

        fptr1 = fopen("file", "r");

        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 

        lno=n+1;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            
            /* add the line at given line number */
            if (ctr != lno) 
            {
                    fprintf(fptr2, "%s", str);
            }
            else{
                    strtok(str, "\n");
                    strtok(str, " ");
                    strcat(str, tampon);
                    strcat(str, " \n");
                    fprintf(fptr2, "%s", str);
            }
            ctr++;
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("file");  		// remove the original file 
        rename(temp, "file"); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
        fptr1=fopen("file","r"); 
            ch=fgetc(fptr1); 
          printf(" Now the content of the file %s is : \n","file"); 
           do
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }while(ch!=EOF);
        fclose(fptr1);
} 

void actualiser(char tampon[], int STATE){
    char line[TOT][BUF];
    FILE *plist = NULL; 
    int i = 0;
    int total = 0; 
    int place;

    plist = fopen("file", "r");
    if(plist == NULL)
    {
        /* Unable to open file hence exit */
        printf("Le fichier des réservations n'a pas pu etre ouvert.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line[i], BUF, plist)) {
        /* get rid of ending \n from fgets */
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }

    total = i;
    char resa[300];
    char reponse[2];

    int compteur=0;
        for(i = 0; i < total; ++i){
            char str[100];
            strcpy(str,line[i]);
                
            for(int j = 0; j<=2; j++)
            {
                resa[compteur]=str[j];
                compteur++;
            }
            
            if(STATE==3){
                strtok(tampon, "*");
                strtok(tampon, "\n");
            if(strstr(line[i], tampon)!=NULL){
                fclose(plist);
                delete(i, tampon);
                sprintf(tampon, "\nCette réservation a été supprimée\n");
                plist = fopen("file", "r");           
                }
            }
        }

    if(STATE==2)displayresa(resa, compteur,tampon);
    else if(STATE==6){
        strtok(tampon, "\n");
        addnom(place, tampon);
        strcat(tampon, "\nVotre réservation a bien été prise en compte\n");
    }
    else if(STATE==5){
        strtok(tampon, "\n");
        addprenom(place, tampon);
        strcat(tampon, "\nSaisissez votre NOM\n");
    }
    else if(STATE==4){
        strtok(tampon, "\n");
        if(searchresa(resa, tampon, compteur, tampon)==1)strcat(tampon, "\nCette Place est déjà prise / n'existe pas. Tapez le numéro correspondant\n");
        else {
            strtok(tampon, "\n");
            place=atoi(tampon);
            add(place, tampon);
            strcat(tampon, "\nCette Place est libre\nSaisissez votre prénom\n");
        }
    }
    fclose(plist);
}

void lireMessage(char tampon[]) {
    printf("Saisir un message à envoyer :\n");
    fgets(tampon, MAX_BUFFER, stdin);
}

void envoiMenu1(char tampon[]) {
    printf("Menu1 Choisi :\n");
    sprintf(tampon,"\e[0;93m▌     1. Réserver un billet               ▌\n\n\033[0m Quelle place souhaitez vous réserver ? Tapez le numéro correspondant\n");
}

void envoiMenu2(char tampon[]) {
    printf("Menu2 Choisi :\n");
    sprintf(tampon, "\e[0;93m▌     2. Voir les places disponibles      ▌\n\033[0m");
}

void envoiMenu3(char tampon[]) {
    printf("Menu3 Choisi :\n");
    sprintf(tampon, "\e[0;93m▌     3. Supprimer son billet             ▌\033[0m Saisissez votre NOM suivi de votre n° de dossier \n");
}

int testMenu1(char tampon[]) {
    return strcmp(tampon, "1") == 0;
}

int testMenu2(char tampon[]) {
    return strcmp(tampon, "2") == 0;
}

int testMenu3(char tampon[]) {
    return strcmp(tampon, "3") == 0;
}

int testQuitter(char tampon[]) {
    return strcmp(tampon, EXIT) == 0;
}


int main(int argc, char const *argv[]) {
    int fdSocketAttente;
    int fdSocketCommunication;
    struct sockaddr_in coordonneesServeur;
    struct sockaddr_in coordonneesAppelant;
    char tampon[MAX_BUFFER];
    int nbRecu;
    int longueurAdresse;
    int pid;
    int STATE=0;


    fdSocketAttente = socket(PF_INET, SOCK_STREAM, 0);

    if (fdSocketAttente < 0) {
        printf("socket incorrecte\n");
        exit(EXIT_FAILURE);
    }

    // On prépare l’adresse d’attachement locale
    longueurAdresse = sizeof(struct sockaddr_in);
    memset(&coordonneesServeur, 0x00, longueurAdresse);

    coordonneesServeur.sin_family = PF_INET;
    // toutes les interfaces locales disponibles
    coordonneesServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    // toutes les interfaces locales disponibles
    coordonneesServeur.sin_port = htons(PORT);

    if (bind(fdSocketAttente, (struct sockaddr *) &coordonneesServeur, sizeof(coordonneesServeur)) == -1) {
        printf("erreur de bind\n");
        exit(EXIT_FAILURE);
    }

    if (listen(fdSocketAttente, 5) == -1) {
        printf("erreur de listen\n");
        exit(EXIT_FAILURE);
    }

    socklen_t tailleCoord = sizeof(coordonneesAppelant);

    int nbClients = 0;

    while (nbClients < MAX_CLIENTS) {
        if ((fdSocketCommunication = accept(fdSocketAttente, (struct sockaddr *) &coordonneesAppelant,
                                            &tailleCoord)) == -1) {
            printf("erreur de accept\n");
            exit(EXIT_FAILURE);
        }

        printf("Client connecté - %s:%d\n",
               inet_ntoa(coordonneesAppelant.sin_addr),
               ntohs(coordonneesAppelant.sin_port));

        if ((pid = fork()) == 0) {
            close(fdSocketAttente);

            while (1) {
                // on attend le message du client
                // la fonction recv est bloquante
                nbRecu = recv(fdSocketCommunication, tampon, MAX_BUFFER, 0);

                if (nbRecu > 0) {
                    tampon[nbRecu] = 0;
                    printf("Recu de %s:%d : %s\n",
                           inet_ntoa(coordonneesAppelant.sin_addr),
                           ntohs(coordonneesAppelant.sin_port),
                           tampon);
                    if (testMenu1(tampon)) {
                        STATE=1;
                        envoiMenu1(tampon);                  
                    }
                    else if (testMenu2(tampon)) {
                        STATE=2;
                        envoiMenu2(tampon);                    
                    }
                    else if (testMenu3(tampon)) {
                        STATE=3;
                        envoiMenu3(tampon);
                    }
                    else if (testQuitter(tampon)) {
                        break; // on quitte la boucle
                    }
                    else {
                        actualiser(tampon, STATE);
                        printf("%s",tampon);
                        if((STATE==4)&&(strstr(tampon,"Cette Place est déjà prise / n'existe pas. Tapez le numéro correspondant")==NULL)){
                            STATE=5;
                        }
                        else if(STATE==6)STATE=2;
                        else if(STATE==5)STATE=6;
                        else if(STATE==1)STATE=4;
                        
                    }
                    printf("\n%d\n", STATE);

                }

                if (testQuitter(tampon)) {
                    send(fdSocketCommunication, tampon, strlen(tampon), 0);
                    break; // on quitte la boucle
                }
                actualiser(tampon, STATE);
                // on envoie le message au client
                send(fdSocketCommunication, tampon, strlen(tampon), 0);
            }

            exit(EXIT_SUCCESS);
        }

        nbClients++;
    }

    close(fdSocketCommunication);
    close(fdSocketAttente);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        wait(NULL);
    }

    printf("Fin du programme.\n");
    return EXIT_SUCCESS;
}
