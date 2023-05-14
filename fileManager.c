#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char filename[100];
    int choice;
    printf("\n Name: Shashank Parth Sinha\n");
    printf("Section : J\n");
    printf("\n----------------------------\n");
    printf("File Manager Program\n");
    printf("-----------------------------\n");
    
    while(1)
    {
        printf("\n1. Create a new file\n");
        printf("2. Modify an existing file\n");
        printf("3. Delete a file\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nEnter the name of the file to create: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                
                if(fp == NULL)
                {
                    printf("\nError creating file. Please try again.\n");
                }
                else
                {
                    printf("\nFile created successfully.\n");
                    fclose(fp);
                }
                break;
            
            case 2:
                printf("\nEnter the name of the file to modify: ");
                scanf("%s", filename);
                fp = fopen(filename, "a");
                
                if(fp == NULL)
                {
                    printf("\nError opening file. Please try again.\n");
                }
                else
                {
                    printf("\nEnter the text to append to the file: ");
                    char text[100];
                    scanf("%s", text);
                    fprintf(fp, "%s", text);
                    printf("\nText added successfully.\n");
                    fclose(fp);
                }
                break;
            
            case 3:
                printf("\nEnter the name of the file to delete: ");
                scanf("%s", filename);
                int status = remove(filename);
                
                if(status == 0)
                {
                    printf("\nFile deleted successfully.\n");
                }
                else
                {
                    printf("\nError deleting file. Please try again.\n");
                }
                break;
            
            case 4:
                printf("\nExiting program.\n");
                exit(0);
            
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

