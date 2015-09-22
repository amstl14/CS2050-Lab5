#include "head.h"
/*---------------------------------------------------------------------
 
                          MAIN FUNCTION
 
 ---------------------------------------------------------------------*/

int main(int argc,char *argv[]) {
    FILE *fp3;
    char line3[128];
   
    
    if (argc != 4) //ERROR CHECK NUMBER OF ARGS
    {
        printf("\n Babbage USEAGE: <./a.out> <positive.txt> <negative.txt> <review#.txt> \n ");
        printf("\n Netbeans USEAGE: <positive.txt> <negative.txt> <review#.txt> \n ");
        return 0;
    }
    
    LIST1 *current1, *temp;
    LIST2 *temp2;
    current1 = positive_list(argv[1]); //ASSIGN CURRENT1 TO THE POSITIVE LIST

    LIST2 *current2;
    current2 = negative_list(argv[2]); //ASSIGN CURRENT2 TO THE NEGATIVE LIST
    
    if ((fp3 = fopen(argv[3], "r")) == NULL) //ERROR CHECK FILE OPENING
    {
        printf("\nError opening file");
        return 0;
    }
    
    int numPositive = 0, numNegative = 0;
    
    char *token;
    
    printf("\n----------- FOUND WORDS -----------\n\n");
    
    while(!feof(fp3)){
        fscanf(fp3,"%s\n",line3);

        token = strtok(line3," ,.\n");
        
        for(temp = current1; temp ; temp=temp->next){
            
            
            if(strcmp(token,temp->positive) == 0)
            {
                printf("The token \"%s\" was a valid positive word.\n",temp->positive); //PRINT OUT POSITIVE TOKENS
                numPositive++;
            }
            
        }
        
        for(temp2 = current2; temp2 ; temp2=temp2->next){
            
            if(strcmp(token,temp2->negative) == 0)
            {
                printf("The token \"%s\" was a valid negative word.\n",temp2->negative); //PRINT OUT NEGATIVE TOKENS
                numNegative++;
            }
        }
    }
    
    fclose(fp3); //CLOSE FILE
    print(numPositive,numNegative,argv[3]);
    freePos(current1);
    freeNeg(current2);
    
    return 0;
}

/*---------------------------------------------------------------------
 
                      POSITIVE LIST FUNCTION
 
 ---------------------------------------------------------------------*/

LIST1* positive_list(char* filename)
{
    FILE *fp1;
    LIST1 *current1, *head1;
    char line1[128];
    
    head1 = current1 = NULL;
    if((fp1 = fopen(filename, "r")) == NULL) //ERROR CHECK FILE CONTENTS
    {
        printf("\nError opening file");
        return 0;
    }
    
    while(fgets(line1, 128, fp1)){ //POPULATE THE POSITIVE LIST
        LIST1 *node1 = malloc(sizeof(LIST1));
        node1->positive = strdup(line1);
        node1->next =NULL;
        node1->positive[strlen(node1->positive) - 1] = '\0';
        
        if(head1 == NULL){
            current1 = head1 = node1;
        } else {
            current1 = current1->next = node1;
        }
    }
    fclose(fp1);

    
    return head1;
    


}

/*---------------------------------------------------------------------
 
                        NEGATIVE LIST FUNCTION
 
 ---------------------------------------------------------------------*/

LIST2* negative_list(char* filename)
{
    FILE *fp2;
    LIST2 *current2, *head2;
    char line2[128];
    
    head2 = current2 = NULL;
    if((fp2 = fopen(filename, "r")) == NULL) //ERROR CHECK FILE CONTENTS
    {
        printf("\nError opening file");
        return 0;
    }
    
    
    while(fgets(line2, 128, fp2)){ //POPULATE THE NEGATIVE LIST
        if(feof(fp2)){
            break;
        }
        LIST2 *node2 = malloc(sizeof(LIST2));
        node2->negative = strdup(line2);
        node2->next =NULL;
        node2->negative[strlen(node2->negative) - 1] = '\0';
        if(head2 == NULL){
            current2 = head2 = node2;
        }
        else {
            current2 = current2->next = node2;
        }
        
        
    }
    fclose(fp2);
    
    
    return head2;
    
    
}

/*---------------------------------------------------------------------
 
                             PRINT FUNCTION
 
 ---------------------------------------------------------------------*/

void print(int numPositive, int numNegative, char* file)
{
    
    printf("\n----------- RESULT -----------");
    
    if(numPositive > numNegative){  //CHECK TO SEE IF THE REVIEW WAS MORE POSITIVE OR NEGATIVE
        
        printf("\n\nThe file \"%s\" is a POSITIVE review.",file);
    }
    else if(numPositive < numNegative){
        printf("\n\nThe file \"%s\" is a NEGATIVE review.",file);
    }
    else if((numPositive && numNegative) == 0){
        printf("\n\nThe file \"%s\" was NEITHER a positive nor negative review.",file);
    }
    else if(numPositive == numNegative){
        printf("\n\nThe file \"%s\" was an EQUALLY positive/negative review.",file);
    }

}

/*---------------------------------------------------------------------
 
                        FREE POSITIVE FUNCTION
 
 ---------------------------------------------------------------------*/

void freePos(LIST1* current1)
{
    LIST1* temp;
    
    for(temp = current1; temp ; temp=temp->next){
        
        free(temp->positive); 
        
        
    }
    
}


/*---------------------------------------------------------------------
 
                         FREE NEGATIVE FUNCTION
 
 ---------------------------------------------------------------------*/

void freeNeg(LIST2* current2)
{
    LIST2* temp;
    
    for(temp = current2; temp ; temp=temp->next){
        
        free(temp->negative);
        
        
    }
    
}



