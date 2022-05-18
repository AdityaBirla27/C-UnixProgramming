#include <stdio.h>
#include <string.h>
struct hardwareData{
  unsigned int recordNumber;
  char nameTool[31];
  unsigned int Quantity;
  double costTool;
};
unsigned int choiceMenu(void);
void addRecord(FILE *filePtr);
void deleteRecord(FILE *filePtr);
void updateRecord(FILE *filePtr);
void appendRecord(FILE *rptr);
void displayRecord(FILE *filePtr);

int main(){
  FILE *filePtr;
  FILE *filePtr1;
  struct hardwareData initialTools ={ 0, "", 0, 0.0 };
  while((filePtr = fopen("hardware.dat", "r+b")) ==NULL){
      if((filePtr1 = fopen("hardware.dat", "wb")) == NULL )
        printf("This File can not be open.\n" );
      else {
        for(int index = 1; index <= 10; index++ ){
          fwrite(&initialTools, sizeof( struct hardwareData ), 1, filePtr1);
        }
        fclose(filePtr1);
      }
  }
  if((filePtr = fopen("hardware.dat", "r+b")) ==NULL)
      printf("Issue With Opening File\n");
  else{
    unsigned int ch;
    while((ch = choiceMenu()) != 0){
      switch (ch){
        case 1:
            addRecord(filePtr);
          break;
        case 2:
          deleteRecord(filePtr);
          break;
        case 3:
          updateRecord(filePtr);
          break;
        case 4:
            appendRecord(filePtr);
          break;
        case 5:
          displayRecord(filePtr);
          break;
        default:
          printf("Invalid choice!");
          break;
        }
    }
    fclose(filePtr);
  }
}

void appendRecord(FILE *rptr){
  FILE *outFile;
  if((outFile = fopen("hardware.txt", "w")) == NULL){
      printf("File cannot be open.");
  }
  else{
      rewind(rptr);
      fprintf(outFile, "%-10s %-20s%-10s%-10s\nRecord #", "Tool Name", "Quantity", "Cost");
      while(!feof(rptr)){
        struct hardwareData initialTools ={0, "", 0, 0.0};
        int res = fread(&initialTools, sizeof(struct hardwareData), 1, rptr);
        if(res != 0 && initialTools.recordNumber != 0){
          fprintf(outFile, "%-8d %-20s %-10d %-10f\n",initialTools.recordNumber,initialTools.nameTool,initialTools.Quantity,initialTools.costTool);
        }
      }
      fclose(outFile);
  }
}

void updateRecord(FILE *filePtr){
  unsigned int rnum;
  printf("%s", "Enter the record number to update that record (1 - 100): ");
  scanf("%d", &rnum);
  fseek(filePtr, (rnum - 1) * sizeof(struct hardwareData), SEEK_SET);
  struct hardwareData initialTools ={0, "", 0, 0.0};
  fread(&initialTools, sizeof(struct hardwareData), 1, filePtr);
  if(initialTools.recordNumber == 0){
      printf("Record #%d is empty.\n", rnum);
  }
  else{
      printf("%-10d %-20s %-10d %-10f\n\n",initialTools.recordNumber,initialTools.nameTool,initialTools.Quantity,initialTools.costTool);
      unsigned int opt;
      printf("1:Update name of the tool\n2:Update the quantity of the tool\n3: Update cost of tool\n4:Exit\nChoose: ");
      scanf("%d", &opt);
      while (opt != 4){
        switch(opt){
          case 1:
            printf("Enter the new name of the tool: ");
            while (getchar() != '\n');
            fgets(initialTools.nameTool, 30, stdin);
            int lindex;
            lindex = strlen(initialTools.nameTool)-1;
            if (initialTools.nameTool[lindex] =='\n')
              initialTools.nameTool[lindex] = '\0';
            break;
          case 2:
            printf("Enter the new quantity: ");
            scanf("%d", &initialTools.Quantity);
            break;
          case 3:
            printf("Enter the new cost of tool: ");
            scanf("%lf", &initialTools.costTool);
            break;
          default:
            printf("Invalid choice!");
            break;
        }
        printf("\nChoose: ");
        scanf("%d", &opt);
      }
      printf("%-10d %-20s %-10d %-10f\n\n",initialTools.recordNumber, initialTools.nameTool, initialTools.Quantity,initialTools.costTool);
      fseek(filePtr, (rnum - 1) * sizeof(struct hardwareData), SEEK_SET);
      fwrite(&initialTools, sizeof(struct hardwareData), 1, filePtr);
      }
}

void deleteRecord(FILE *filePtr){
  unsigned int rnum;
  printf("%s", "Enter a record number to delete (1 - 100): ");
  scanf("%d", &rnum);
  fseek(filePtr, (rnum - 1) * sizeof(struct hardwareData), SEEK_SET);
  struct hardwareData tool_rec;
  fread(&tool_rec, sizeof(struct hardwareData), 1, filePtr);
  if(tool_rec.recordNumber == 0){
      printf("Record #%d does not exist.\n", rnum);
  }
  else
  {
      fseek(filePtr, (rnum - 1) * sizeof(struct
      hardwareData), SEEK_SET);
      struct hardwareData emptyRec ={0, "", 0, 0.00};
      fwrite(&emptyRec, sizeof(struct hardwareData), 1, filePtr);
  }
}

void addRecord(FILE *filePtr){ //addRecord
  struct hardwareData tool_rec ={ 0, "", 0, 0.0 };
  printf("Enter a record number ( 1 - 100, 0 to return to main menu): ");
  scanf("%d", &tool_rec.recordNumber );
  if(tool_rec.recordNumber < 0 || tool_rec.recordNumber >100)
      printf(" invalid record number.\n");
  else{
      while(tool_rec.recordNumber != 0){
        printf("Enter the name of the tool: ");
        while (getchar() != '\n');
        fgets(tool_rec.nameTool, 30, stdin);
        int lindex;
        lindex = strlen(tool_rec.nameTool)-1;
        if (tool_rec.nameTool[lindex] == '\n')
          tool_rec.nameTool[lindex] = '\0';
        printf("Enter the quantity of the tool: ");
        scanf("%d", &tool_rec.Quantity);
        printf("Enter the cost of tool: " );
        scanf("%lf", &tool_rec.costTool);
        fseek(filePtr, (tool_rec.recordNumber - 1) *sizeof(struct hardwareData), SEEK_SET);
        fwrite(&tool_rec, sizeof(struct hardwareData ), 1, filePtr);
        printf("\nEnter another record number, enter 0 to exit: " );
        scanf("%d", &tool_rec.recordNumber );
      }

  }

}


void displayRecord(FILE *filePtr){//Details for the Records
  unsigned int rnum;
  printf("%s", "Enter a record number (1 - 100): ");
  scanf("%d", &rnum);
  fseek(filePtr, (rnum - 1) * sizeof(struct hardwareData), SEEK_SET);
  struct hardwareData tool_rec ={0, "", 0, 0.0};
  fread(&tool_rec, sizeof(struct hardwareData), 1, filePtr);
  if(tool_rec.recordNumber == 0){
      printf("Record #%d does not exist.\n", rnum);
  }
  else{
      fseek(filePtr, (rnum - 1) * sizeof(struct hardwareData), SEEK_SET);
      if(tool_rec.recordNumber != 0 ){
        printf("%-10d %-20s %-10d %-10f\n",tool_rec.recordNumber, tool_rec.nameTool,tool_rec.Quantity,tool_rec.costTool);
      }
      else{
        printf("This record does not exist!\n");
      }
  }

}

unsigned int choiceMenu(){//Display Menu
  printf("%s", "\n Pick from the following choices :\n"
        "1 - ADD  record\n"
        "2 - DELETE  record\n"
        "3 - UPDATE  record\n"
        "4 - record changes made  to txt file ( only AFTER YOU HAVE ADDED RECORDS,DELETED RECORDS, UPDATED RECORDS ) \n"
        "5 - DISPLAY  record\n"
        "0 - END program\n Choice : ");
  unsigned int user_choice;
  scanf("%d", &user_choice);
  return user_choice;
}
