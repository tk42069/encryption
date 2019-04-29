#include <stdio.h>

void rot_enc(int k);
void rot_dec(int k);

void sub_enc(int k);
void sub_dec(int k);

int k;

int main()
{
    
    
    printf("\n***Input Plain/Cipher Text via 'input.txt'***\n\n");      //what he said
    printf("Menu: Enter 'x' to select:\n\n");                             // simple menu
    printf(" 0 - Encrypt 'input.txt' using rotation cypher\n");
    printf(" 1 - Decrypt 'input.txt' using rotation cypher\n");
    printf(" 2 - Encrypt 'input.txt' using substitution cypher\n");
    printf(" 3 - Decrypt 'input.txt' using substitution cypher\n\n");
    
    int n;
    scanf("%d", &n);            // reading selection from std.in
    switch(n)                   //switch-case statements to select which function to run
    {
        case 0:                //running desired function and ending program
            rot_enc(k);
            break;
            
        case 1:
            rot_dec(k);
            break;
        
        case 2:
            sub_enc(k);
            break;
            
        case 3:
            sub_dec(k);
            break;
        
        default:                 // default statement to tell user they shanked it
            printf("Error. Option does not exist");
            break;
    }
    
return 0;
}

void rot_enc(int k)       /// rotation encryption function
{
    printf("Enter key: ");
    scanf("%d", &k);
    
    int i = 0;          // i = index
    FILE *input;        // file pointer
    FILE *output;       // fp
    char array[100];       // making array to store message on
    input = fopen("input.txt", "r");      // opening input file in read mode
    output = fopen("output.txt", "w");      // opening output file in write mode
    
    while (fscanf(input, "%c", &array[i]) != EOF)         //while the file is still reading
    {
        if (array[i] >= 97 && array[i] <= 122)            // if ASCII lower case
        {
            array[i] = array[i] - 32;                  //convert to upper case
        }
        if (array[i] == 32)                     // if it is a space goto poo and print straight away
        {
            goto poo;
        }
        int temp;                       //declare temp
        temp = array[i]-65+k;           //bring to zero and add key
        
        if (temp < 0)                   // if ASCII is negative make it positive
        {
            temp = temp + 26;
        }
        
        temp = temp%26;                 //modulus rotaterboi
        temp = temp + 65;               //add ya 65 back idunnowhyyatookitinthefirstplacebutitworkssowe'llleaveit
        array[i] = temp;                // assign encoded character back to array[i]               
        
        poo:
        fprintf(output, "%c", array[i]);
        printf("%c", array[i]);                 //printing character
        i++;                  //count up
    }
    fclose(input);           //close files
    fclose(output);
}

void rot_dec(int k)             /// rotation decryption function
{
    printf("Enter key: ");
    scanf("%d", &k);
    
    int i = 0;          // i = index
    FILE *input;            // input = file pointer
    FILE *output;           // fp
    char array[100];  // making array to store message on     
    input = fopen("input.txt", "r");     // opening file in read mode
    output = fopen("output.txt", "w");
    
    while (fscanf(input, "%c", &array[i]) != EOF)
    {
        if (array[i] >= 97 && array[i] <= 122)            // if ASCII lower case
        {
        array[i] = array[i] - 32;                  //convert to upper case
        }
    
        if (array[i] == 32)
        {
            goto poo;
        }
    
    int temp;                       //declare temp
    temp = array[i]-65-k;           //bring to zero and add key
    
    if (temp < 0)
    {
        temp = temp + 26;
    }
    temp = temp%26;                 //modulus rotaterboi
    temp = temp + 65;               //add ya 65 back idunnowhyyatookitinthefirstplace
    array[i] = temp;                // assign encoded character back to array[i]               // ***DONT FORGET TO FIX 'SPACE' = ?****
    
    poo:
    fprintf(output, "%c", array[i]);
    printf("%c", array[i]);                 //printing character
    i++;                  //count up
    }
    fclose(input);
    fclose(output);
}

void sub_enc(int k)                         /// substitution encryption function
{
    int i = 0;
    FILE *input;
    FILE *output;
    
    char array[100];
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    while (fscanf(input, "%c", &array[i]) != EOF)
    {
        if (array[i] == 32)
        {
            goto poo;
        }
        if (array[i] >= 97 && array[i] <= 122)            // if ASCII lower case
        {
            array[i] = array[i] - 32;                  //convert to upper case
        }
        if (array[i] == 'A')                    /// hard coded all substitutions
        {
            array[i] = 'Q';
            goto poo;
        }
        if (array[i] == 'B')
        {
            array[i] = 'W';
            goto poo;
        }
        if (array[i] == 'C')
        {
            array[i] = 'E';
            goto poo;
        }
        if (array[i] == 'D')
        {
            array[i] = 'R';
            goto poo;
        }
        if (array[i] == 'E')
        {
            array[i] = 'T';
            goto poo;
        }
        if (array[i] == 'F')
        {
            array[i] = 'Y';
            goto poo;
        }
        if (array[i] == 'G')
        {
            array[i] = 'U';
            goto poo;
        }if (array[i] == 'H')
        {
            array[i] = 'I';
            goto poo;
        }if (array[i] == 'I')
        {
            array[i] = 'O';
            goto poo;
        }if (array[i] == 'J')
        {
            array[i] = 'P';
            goto poo;
        }if (array[i] == 'K')
        {
            array[i] = 'A';
            goto poo;
        }if (array[i] == 'L')
        {
            array[i] = 'S';
            goto poo;
        }if (array[i] == 'M')
        {
            array[i] = 'D';
            goto poo;
        }if (array[i] == 'N')
        {
            array[i] = 'F';
            goto poo;
        }if (array[i] == 'O')
        {
            array[i] = 'G';
            goto poo;
        }if (array[i] == 'P')
        {
            array[i] = 'H';
            goto poo;
        }if (array[i] == 'Q')
        {
            array[i] = 'J';
            goto poo;
        }if (array[i] == 'R')
        {
            array[i] = 'K';
            goto poo;
        }if (array[i] == 'S')
        {
            array[i] = 'L';
            goto poo;
        }if (array[i] == 'T')
        {
            array[i] = 'Z';
            goto poo;
        }if (array[i] == 'U')
        {
            array[i] = 'X';
            goto poo;
        }if (array[i] == 'V')
        {
            array[i] = 'C';
            goto poo;
        }if (array[i] == 'W')
        {
            array[i] = 'V';
            goto poo;
        }if (array[i] == 'X')
        {
            array[i] = 'B';
            goto poo;
        }if (array[i] == 'Y')
        {
            array[i] = 'N';
            goto poo;
        }if (array[i] == 'Z')
        {
            array[i] = 'M';
            goto poo;
        }
    poo:
    fprintf(output, "%c", array[i]);
    printf("%c", array[i]);                 //printing character
    i++;   
    }
    fclose(input);
    fclose(output);
}

void sub_dec(int k)                             /// substitution decryption function
{
    int i = 0;
    FILE *input;
    FILE *output;
    
    char array[100];
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    
    while (fscanf(input, "%c", &array[i]) != EOF)
    {
        if (array[i] == 32)
        {
            goto poo;
        }
        if (array[i] >= 97 && array[i] <= 122)            // if ASCII lower case
        {
            array[i] = array[i] - 32;                  //convert to upper case
        }
        if (array[i] == 'Q')
        {
            array[i] = 'A';                     /// hard coded substitutions
            goto poo;
        }
        if (array[i] == 'W')
        {
            array[i] = 'B';
            goto poo;
        }
        if (array[i] == 'E')
        {
            array[i] = 'C';
            goto poo;
        }
        if (array[i] == 'R')
        {
            array[i] = 'D';
            goto poo;
        }
        if (array[i] == 'T')
        {
            array[i] = 'E';
            goto poo;
        }
        if (array[i] == 'Y')
        {
            array[i] = 'F';
            goto poo;
        }
        if (array[i] == 'U')
        {
            array[i] = 'G';
            goto poo;
        }
        if (array[i] == 'I')
        {
            array[i] = 'H';
            goto poo;
        }
        if (array[i] == 'O')
        {
            array[i] = 'I';
            goto poo;
        }
        if (array[i] == 'P')
        {
            array[i] = 'J';
            goto poo;
        }
        if (array[i] == 'A')
        {
            array[i] = 'K';
            goto poo;
        }
        if (array[i] == 'S')
        {
            array[i] = 'L';
            goto poo;
        }
        if (array[i] == 'D')
        {
            array[i] = 'M';
            goto poo;
        }
        if (array[i] == 'F')
        {
            array[i] = 'N';
            goto poo;
        }
        if (array[i] == 'G')
        {
            array[i] = 'O';
            goto poo;
        }
        if (array[i] == 'H')
        {
            array[i] = 'P';
            goto poo;
        }
        if (array[i] == 'J')
        {
            array[i] = 'Q';
            goto poo;
        }
        if (array[i] == 'K')
        {
            array[i] = 'R';
            goto poo;
        }
        if (array[i] == 'L')
        {
            array[i] = 'S';
            goto poo;
        }
        if (array[i] == 'Z')
        {
            array[i] = 'T';
            goto poo;
        }
        if (array[i] == 'X')
        {
            array[i] = 'U';
            goto poo;
        }
        if (array[i] == 'C')
        {
            array[i] = 'V';
            goto poo;
        }
        if (array[i] == 'V')
        {
            array[i] = 'W';
            goto poo;
        }
        if (array[i] == 'B')
        {
            array[i] = 'X';
            goto poo;
        }
        if (array[i] == 'N')
        {
            array[i] = 'Y';
            goto poo;
        }
        if (array[i] == 'M')
        {
            array[i] = 'Z';
            goto poo;
        }
    poo:
    fprintf(output, "%c", array[i]);
    printf("%c", array[i]);                 //printing character
    i++;   
    }
    fclose(input);
    fclose(output);         // close files
}
