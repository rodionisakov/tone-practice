#include <stdio.h> // main header
#include <stdlib.h>
#include <string.h>

int main(){
    printf("\tWelcome to chinese language tone practice!\n");
    printf("\tThis program aims to help you with your chinese tones\n");
    printf("Diclaimer: All tones are displayed and should be written in lowercase letters\n with tone numbers after the syllable\n\t Example: ni3hao3\n");
    printf("Enter 1 to Study\nEnter 2 to Test yourself\nEnter 3 to Review the words you have learned\nEnter here: ");
    int mode, i;
    scanf("%d", &mode);
    /* Study section */
    if (mode == 1 && mode != 2){
        printf("Choose topic(1-30): ");
        scanf("%d",&i);//i stands for the number of the topic in the book
        char num[10];
        char fname[] ="topic";
        /*integer to string in order to open files with similar names
		with different numbers at the end i.e. Topic1.txt, Topic2.txt etc.*/
		sprintf(num,"%d",i);
        strcat(fname,num);//appending the name of the file
        strcat(fname,".txt");
        FILE *fp;
        fp = fopen(fname,"r");//Opens the wordlibrary needed
        char topic[150];
        while (fscanf(fp, "%s", topic)!=EOF)
            printf("\t%s\n",topic);   //output the whole wordlibrary     
        fclose(fp);
		}
	/*Test section*/	
     else if (mode == 2 && mode != 1){
		printf("Choose topic(1-30): ");
        scanf("%d",&i);//i stands for the number of the topic in the book
		char num[10];
        char fname[] ="topic";
        /*integer to string in order to open files with similar names
		with different numbers at the end i.e. Topic1.txt, Topic2.txt etc.*/
        sprintf(num,"%d",i);
        strcat(fname,num);//appending the name of the file
        strcat(fname,".txt");
        FILE *fp;
		fp = fopen(fname,"r");
		if (fp == NULL) {
		    printf("topic does not exist, try again\n");
		    return 0;
		}
		FILE *ofp;
		ofp = fopen("review.txt", "a"); //appends or creates a txt file for review purposes in mode 3
		if (ofp == NULL) {
		    printf("cannot create review file\n");
		    return 0;
		}		  
        char line[80];//line variable
        char *word;//pinyin variable
        char *trans;//english variable
        while(fgets(line, sizeof(line),fp)){//loop to read each line of the wordline separately
            word = strtok(line, "_");//spliting string into tokens to assign variables from the wordlibrabry
            trans = strtok(NULL, "");
            
            printf("Please translate this: %s\n", trans);
            char answer[80];
            scanf("%s", answer);
            if (strcmp(answer, word) == 0){//function to compare input and wordlibrary strings
                printf("well done!\n");
                fprintf(ofp, "%s\n", line);//record for review section text file
            }
            else {
                for (int i=0; i<2; i++) { // loop allowing for 3 attempts if the varibles are not the same
                    printf("try again: ");
                    scanf("%s", answer);
                    if (strcmp(answer, word) == 0) {
                        printf("well done!\n");
                        fprintf(ofp, "%s\n", line);                        
                        break;
                    }
                }
            }
        }    
        fclose(fp);
        fclose(ofp);
    }
    /*review section*/
    else if (mode == 3){
    	printf("Below are the words you have learned");
    	FILE*ofp;
    	ofp = fopen("review.txt","r"); //open review textfile
    	if (ofp == NULL) {
		    printf("Error openening file or no words have been learned\n");
		    return 0;
		}
		char review[150];
        while (fscanf(ofp, "%s", review)!=EOF)
            printf("\t\n%s", review);//output as a string
        fclose(ofp);
		}
	return 0;
}
    
