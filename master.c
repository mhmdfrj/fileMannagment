#include <stdio.h>
#include <stdlib.h>

struct emp {
  /* data */
  int no;
  char name[20];
  int dept;
}emp[3];

void writeIntoFile() {
      //text into file1
  FILE *fp = fopen("file1.txt", "w");
  fputs("my name is ali\nmy name is sara\nmy name is omer\t",fp);
  fclose(fp);
    //degits inti file2
  FILE *sp = fopen("file2.txt", "w");
  putc(15,sp);
  putc(8,sp);
  putc(4,sp);
  putc(20,sp);
  fclose(sp);

    //struct into test
  FILE *tp = fopen("test.txt", "w");

  fprintf(tp,"%s\t\t","NO.");
  fprintf(tp,"%s\t\t","NAME.");
  fprintf(tp,"%s\t\t\n","Department");

  for(int i = 0; i < 4; i++){
  printf("\nEnter Employee Number   : ");
  scanf("%d",&emp[i].no);
  fprintf(tp,"%d\t\t",emp[i].no);
  printf("\nEnter Employee Number  %d  Name   : ", emp[i].no);
  scanf("%s",emp[i].name);
  fprintf(tp,"%s\t\t",emp[i].name);
  printf("\nWhich Department Does  %s  Work In [1,2,3] ?!   : ", emp[i].name);
  scanf("%d",&emp[i].dept);
  fprintf(tp,"%d\t\t\n",emp[i].dept);
}
fclose(tp);

}
  int countLines(){

    FILE *fp = fopen("file1.txt", "r");
    int ch = 0;
    int lines = 0;
    lines++;
    while ((ch = fgetc(fp)) != EOF) {

      if(ch == '\n')
       lines++;

  }
  return lines;
  fclose(fp);
}

void switchWord(){
  FILE *fs = fopen("file1.txt", "r+");
  fseek(fs, -5, SEEK_END);
  fputs("sahar", fs);
  fclose(fs);
}

void temp(){
  char ch;
  FILE *fs = fopen("file1.txt", "r");
  FILE *ft = fopen("temp.txt", "w");
  fprintf(ft, "%s", "my name is alaa\n");
  while (1) {
    ch = fgetc(fs);
    if(ch == EOF){
      break;
    }
    else{
      fputc(ch,ft);
    }
  }
  fclose(fs);
  fclose(ft);
}
void appendingToBegin(){
  temp();
  FILE *ft = fopen("temp.txt", "r");
  FILE *fs = fopen("file1.txt", "w");
  char ch;
  while (1) {
    ch = fgetc(ft);
    if(ch == EOF){
      break;
    }
    else{
      fputc(ch,fs);
    }
  }
  fclose(ft);
  fclose(fs);
}

void copyContents(){
  FILE *fp = fopen("file1.txt", "r");
  FILE *fsp = fopen("file3.txt", "w");
  char ch;
  while (1) {
    ch = fgetc(fp);
    if(ch == EOF){
      break;
    }
    else{
      fputc(ch,fsp);
    }
  }
  fclose(fp);
  fclose(fsp);
}

int searchChar(){
  char cha;
  printf("%s","enter the char you are looking for");
  scanf("%s",&cha);
  FILE *fp = fopen("file1.txt", "r");
  char ch;
  int pos = 0;
  while ((ch = fgetc(fp)) != EOF) {
      pos++;
    if(ch == cha)
     return pos;
 }
 fclose(fp);
}
void modifyStruct() {
  int no;
  FILE *tp = fopen("test.txt", "r");
  printf("%s","Enter The struct Number you Wish To Edit  : " );
  scanf("%d",&no);
  printf("\nEmployee Number: %d ", emp[no].no);
  printf("\nEmployee Number  %d  Name: %s ", emp[no].no,emp[no].name);
  printf("\nEmployee Department  : %d \n", emp[no].dept);
  fseek(tp,2*(sizeof(emp)),SEEK_SET);
  fprintf(tp,"%s",fgets("%s",7,tp));
  fclose(tp);
}
void sortAscending() {
  FILE *sp = fopen("file2.txt", "r+");
  int arr[4];
  int i = 0;
  int temp;

  for (i; i < 4; i++) {
    arr[i] = getc(sp);
  }


  for (i=0; i < 4; i++) {
    for (int j = i+1; j < 4; j++) {
      /* code */
      if(arr[i] > arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  fseek(sp,0,SEEK_SET);
  for (i; i < 4; i++) {
   putc(arr[i],sp);
  }
  fclose(sp);
}
void reversingFile() {
  FILE *sp = fopen("file2.txt", "r+");
  int arr[4];
  int i = 0;

  for (i; i < 4; i++) {
    arr[i] = getc(sp);
  }

  fseek(sp,0,SEEK_SET);
  for (i=3; i >= 0; i--) {
    putc(arr[i],sp);
  }
  fclose(sp);
}
void drawRect() {
  FILE *fp = fopen("shape.txt", "w");
  int col,row;
  printf("%s","Enter The Width  : ");
  scanf("%d",&row);
  printf("%s","Enter The Hights  : ");
  scanf("%d",&col);

  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      /* code */
      printf("%s","*");
      fprintf(fp,"%s","*");
    }
    printf("%s","\n" );
    fprintf(fp,"%s","\n" );


  }
  fclose(fp);
}
void viewContent(int no) {
  char c;
  if(no == 1){
    FILE *fp = fopen("file1.txt", "r");
    while ((c = getc(fp)) != EOF) {
      putchar(c);
    }
    fclose(fp);
  }else if(no == 2){
    FILE *sp = fopen("file2.txt", "r");
    while ((c = getc(sp)) != EOF) {
      putchar(c);
    }
    fclose(sp);
  }else if(no == 3){
    FILE *tp = fopen("test.txt", "r");
    while ((c = getc(tp)) != EOF) {
      putchar(c);
    }
    fclose(tp);
  }else if(no == 4){
    FILE *ffp = fopen("shape.txt", "r");
    while ((c = getc(ffp)) != EOF) {
      putchar(c);
    }
    fclose(ffp);
  }
}

void main(){
  int sel;
  again:
  printf("%s","Chose a Number  :  ");
  scanf("%d",&sel);

  if(sel == 1){
    writeIntoFile();
    goto again;
  }else if(sel == 2){
    countLines();
    goto again;
  }else if(sel == 3){
    switchWord();
    goto again;
  }else if(sel == 4){
    appendingToBegin();
    goto again;
  }else if(sel == 5){
    copyContents();
    goto again;
  }else if(sel == 6){
    printf("%d\n",searchChar());
    goto again;
  }else if(sel == 7){
    modifyStruct();
    goto again;
  }else if(sel == 8){
    sortAscending();
    goto again;
  }else if(sel == 9){
    reversingFile();
    goto again;
  }else if(sel == 10){
    drawRect();
    goto again;
  }else if(sel == 11){
    viewContent(1);
    goto again;
  }else if(sel == 12){
    viewContent(2);
    goto again;
  }else if(sel == 13){
    viewContent(3);
    goto again;
  }else if(sel == 14){
    viewContent(4);
    goto again;
  }else if(sel == 15){
    exit(0);
  }




    }
