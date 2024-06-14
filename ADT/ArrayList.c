#include<stdio.h>
#include<conio.h>

typedef struct {
	char fname[20];
	char lname[20];
}studName;

typedef struct{
	int month;
	int year;
}bday;

typedef struct{
	studName name;
	bday birthdate;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[20];
	int studCount;
}classRecord;

void initList(classRecord *R){
	R->studCount=0;
}

void insertlast(classRecord *R){
	printf("---INSERT LAST---\n");
	printf("Enter Fname:");
    scanf("%s", R->studList[R->studCount].name.fname);
    printf("Enter Lname:");
    scanf("%s", R->studList[R->studCount].name.lname);
    printf("Enter Month (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &R->studList[R->studCount].birthdate.month);
    printf("Enter Year (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &R->studList[R->studCount].birthdate.year);
    printf("Enter Age:");
    scanf("%d", &R->studList[R->studCount].age);
    printf("Enter ID Num:");
    scanf("%d", &R->studList[R->studCount].idNum);
    R->studCount++;
}

void insertfirst(classRecord *R){
	printf("---INSERT FIRST---\n");
	int x;
	//shifting cells to the right 
	for (x=R->studCount;x>0;x--) {
        R->studList[x]=R->studList[x-1];
    }
    
    printf("Enter Fname:");
    scanf("%s", R->studList[0].name.fname);
    printf("Enter Lname:");
    scanf("%s", R->studList[0].name.lname);
    printf("Enter Month (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &R->studList[0].birthdate.month);
    printf("Enter Year (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &R->studList[0].birthdate.year);
    printf("Enter Age:");
    scanf("%d", &R->studList[0].age);
    printf("Enter ID Num:");
    scanf("%d", &R->studList[0].idNum);
    
    R->studCount++;
}

void insertindex(classRecord *R){
	printf("---INSERT AT INDEX---\n");
	int x,index;
	printf("Enter What index:");
	scanf("%d", &index);
	
	if(index < 0 || index >= 20 || R->studCount >= 20) {
        printf("Invalid index or list is full.\n");
        return;
    }

    // Shift cells to make space for the cell
    for (x=R->studCount;x>index; x--) {
        R->studList[x]=R->studList[x-1];
    }
    
    printf("Enter Fname:");
    scanf("%s", R->studList[index].name.fname);
    printf("Enter Lname:");
    scanf("%s", R->studList[index].name.lname);
    printf("Enter Month (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &R->studList[index].birthdate.month);
    printf("Enter Year (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &R->studList[index].birthdate.year);
    printf("Enter Age:");
    scanf("%d", &R->studList[index].age);
    printf("Enter ID Num:");
    scanf("%d", &R->studList[index].idNum);
    R->studCount++;
}

void insertsorted(classRecord *R){
	   printf("---INSERT SORTED---\n");
    if (R->studCount >= 20) {
        printf("List is full.\n");
        return;
    }

    int i, j;
    studentInfo temp;

    // Input the new record
    printf("Enter Fname:");
    scanf("%s", temp.name.fname);
    printf("Enter Lname:");
    scanf("%s", temp.name.lname);
    printf("Enter Month (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &temp.birthdate.month);
    printf("Enter Year (1-Jan,2-Feb,3-March,etc.):");
    scanf("%d", &temp.birthdate.year);
    printf("Enter Age:");
    scanf("%d", &temp.age);
    printf("Enter ID Num:");
    scanf("%d", &temp.idNum);

    // Find correct position to insert the new record based on age
    for (i = 0; i < R->studCount; i++) {
        if (R->studList[i].age > temp.age) {
            break;
        }
    }

    // Shift elements to make space for the new record
    for (j = R->studCount; j > i; j--) {
        R->studList[j] = R->studList[j - 1];
    }

    // Insert the new record at the correct position
    R->studList[i] = temp;
    R->studCount++;
}

void display(classRecord R){
	int x;
	for(x=0;x<R.studCount;x++){
  	  	printf("Fname: %s\n", R.studList[x].name.fname);
        printf("Lname: %s\n", R.studList[x].name.lname);
        printf("BirthMonth: %d\n", R.studList[x].birthdate.month);
        printf("BirthYear: %d\n", R.studList[x].birthdate.year);
        printf("Age: %d\n", R.studList[x].age);
        printf("IdNum: %d", R.studList[x].idNum);
        printf(" INDEX-%d\n", x);
	}
	printf("Total Cells: %d\n", R.studCount);
}

void deletelast(classRecord *R){
	printf("---DELETE LAST---\n");
	R->studCount--;
}

void deletefirst(classRecord *R){
	printf("---DELETE FIRST---\n");
	int x;
    // Shift cell to remove the first cell
    for (x=0;x<R->studCount-1;x++) {
        R->studList[x]=R->studList[x+1];
    }

    R->studCount--;
}

void deleteindex(classRecord *R){
	printf("---DELETE AT INDEX---\n");
	int x,index;
	printf("Enter What index:");
	scanf("%d", &index);

    // Shift cells to make space for the cell
    for (x=R->studCount;x>index; x++) {
        R->studList[x]=R->studList[x+1];
    }
    
    R->studCount--;
}

int main(){
	classRecord R;
	initList(&R);
	int choice;
	
	while(choice<=8){
		printf("DISPLAY - 1\n");
		printf("INSERT FIRST - 2\n");
		printf("INSERT LAST - 3\n");
		printf("INSERT INDEX - 4\n");
		printf("INSERT SORT(age) - 5\n");
		printf("DELETE FIRST - 6\n");
		printf("DELETE LAST - 7\n");
		printf("DELETE INDEX - 8\n");
		printf("ENTER CHOICE:");
		scanf("%d", &choice);
		system("cls");
		
			switch (choice) {
  				case 1:
    				display(R); 
    				break;
  				case 2:
   					insertfirst(&R);
   					break;
				case 3:
   					insertlast(&R);
   					break;
				case 4:
   					insertindex(&R); 
   					break;	
   				case 5:
   					insertsorted(&R);
   					break;
   				case 6:
   					deletefirst(&R);
   					break;
   				case 7:
  		 			deletelast(&R);
  		 			break;
  		 		case 8:
   					deleteindex(&R);
   					break;
    	}
	}
	
	
	
	return 0;
}
