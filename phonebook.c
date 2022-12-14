#include <termios.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct contact{
	char fname[31];
	char lname[31];
	char telep[15];
	char cellp[15];
};

#define TOTAL_CONTACTS 10
struct contact A[TOTAL_CONTACTS];

void clrscr(void);
void gotoxy(int x, int y);
void insert(void);
void delet(void);
void edit(void);
void search(void);
void searchf(void);
void searchl(void);
void searchp(void);
void searchc(void);
void list(void);
void list2(void);
void sort(void);
void sortf(void);
void sortl(void);
void sortp(void);
void sortc(void);
void help(void);
int last;
size_t get_input(char* dst, size_t max_size)
{
    size_t lensize = 0;
    char* input= NULL;
    size_t len = 0;
    lensize = getline(&input,&len,stdin);
    if(lensize < max_size)
    {
        input[lensize] = "/0";
        strncpy(dst,input,lensize);
    }
    else
    {
        input[max_size-1] = "/0";
        strncpy(dst,input,max_size);
    }
    free(input);


}
int main()
{
	int count=1;
	char n;
	while(count) {
	clrscr();						
	printf("\n|Phone Book12<::>Home|\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("Welcome to PHONE BOOK2022!\nYou have inserted ( %d ) contacts.\n\n",last);
	printf("\t[1] |--> Insert\n");
	printf("\t[2] |--> Delete\n");
	printf("\t[3] |--> Edit\n");
	printf("\t[4] |--> Search\n");
	printf("\t[5] |--> Show All\n");
	printf("\t[6] |--> Sort\n");
	printf("\t[7] |--> Help\n");
	printf("\t[8] |--> Exit\n");
	printf("\n\tPlease Enter Your Choice (1-8): ");
	n = getc(stdin);
	getc(stdin);
	 switch(n) {
		  case '1':
		  insert();
		  break;
		  case '2':
		  delet();
		  break;
		  case '3':
		  edit();
		  break;
		  case '4':
		  search();
		  break;
		  case '5':
		  list();
		  break;
		  case '6':
		  sort();
		  break;
		  case '7':
		  help();
		  break;
		  case '8':
		  exit(1);
		  break;
		  default:
		  printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-8!\nPress any key to continue...",n);
		  getc(stdin);
	      getc(stdin);
		  break;
	  }//End of swicth
	}
	return 0;
}//End of main function!

void insert(void)
{
	char ans='y';
	char *string = NULL;
	size_t len=0;
	size_t len_size=0;
	clrscr();
    printf("\nPhone Book12<::>Insert Contacts");
    printf("\n--------------------------------------------------------------------------------");

	
	while(ans=='y'){
		if(last == TOTAL_CONTACTS)
 			last = 0;
		else{
			printf("\n\nData of Contact %2.2d{\n",last+1);
			printf("\n\t  1-F.Name: ");
			len_size = get_input(A[last].fname, 31);
			strncpy(A[last].fname, string,31);
			
			printf("\t  2-L.Name: ");
			len_size = get_input(A[last].lname,31);
			strncpy(A[last].lname, string,31);
			
			printf("\t  3-Tele.P: ");
			len_size = get_input(A[last].telep,15);
			strncpy(A[last].telep, string,15);
			
			printf("\t  4-Cell.P: ");
			len_size = get_input(A[last].cellp,15);
			strncpy(A[last].cellp, string,15);

	    
			printf("\n|-->Data Recorded!}");
			printf("\n\t\t\tNext Contact?(y/n) Answer:");
		    ans = getc(stdin);
			getc(stdin);
		    last++;
			}
	}
printf("\n\nYou have inserted ( %d ) contact!\nPress a key to return main page & continue program|-->",last);
	getc(stdin);
}

void delet(void)
{
	char dfname_string[31],dlname_string[31];
	char *input = NULL;
	size_t len=0;
	size_t len_size=0;
	register int i,j,find=0;
	char ch;
	clrscr();
    printf("\nPhone Book12<::>Delete Contacts");
    printf("\n--------------------------------------------------------------------------------");
	printf ("\n::Enter data of the contact that you want delete it,please:");
	printf("\n\n  ::Enter first name: ");
	len_size = get_input(dfname_string,31);
	strncpy(dfname_string,input,31);

	printf("\n  ::Enter last name: ");
	len_size = get_input(dlname_string,31);
	strncpy(dlname_string,input,31);
    free(input);
	
	for (i = 0; i < last; i++) {
	 if (strcmp (dfname_string, A[i].fname) == 0 && strcmp (dlname_string, A[i].lname) == 0 ) {
	 
	    printf("\nContact was found! Details:");
		printf("\n\nCantact %2.2d{",i+1);
		printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
		printf("\n\nAre you sure you want to delete this contact?(y/n)");
		ch = getc(stdin);
		getc(stdin);
		if(ch == 'y'){
	   	for(j = i ; j <= last ; j++)
			A[j] = A[j+1];  

	   	last--;
	   	find = 1;
  	 	break;
		}
	 }
	}
	if (find==0)
		printf("\t\t\n<<This contact does not exist in this list or program can not delete it.>>");
	else
		printf("\t\t\n<<Target contact was successfully deleted from list!>>");
	printf("\n\n\nPress a key to return main page & continue program|-->");
	getc(stdin);
}

void edit()
{
	char input[31];
	char *dfname = NULL ,*dlname= NULL;
	size_t len=0;
	size_t len_size=0;
	register int i,j,find=0;
	char ch;
	clrscr();	
    printf("\nPhone Book12<::>Edit Contacts");
    printf("\n--------------------------------------------------------------------------------");
	printf ("\n::Enter data of the contact that you want edit it,please:");
	
	printf("\n\n  ::Enter first name: ");
	len_size = get_input(dfname,31);
	printf("\n  ::Enter last name: ");
	len_size = get_input(dlname,31);

	for (i=0; i < last; i++) {
	 if (strcmp (dfname, A[i].fname) == 0 && strcmp (dlname, A[i].lname) == 0 ) {
	 	printf("\nContact found! Details:");
		printf("\n\nCantact %2.2d{",i+1);
		printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
		printf("\n\nDo you want edit it?(y/n) ");
		ch = getc(stdin);
		getc(stdin);
		if(ch=='y'){
			printf("\n::Enter NEW data for this contact...");
			printf("\n >|Enter new first name: ");	
		
			scanf("%s",input);
			strncpy(A[i].fname,input,31);
			printf(" >|Enter new last name: ");
			scanf("%s",input);
			strncpy(A[i].lname,input,31);
			
			printf(" >|Enter new telephone number: ");
			scanf("%s",input);
			strncpy(A[i].telep,input,15);

			printf(" >|Enter new cellphone number: ");
			scanf("%s",input);
			strncpy(A[i].cellp,input,15);
			
		   	find=1;
		    break;
		}
	 }
	}
	if (find==0)
		printf("\t\t\n<<This contact does not exist or you chose not to Edit it.>>");
	else
		printf("\t\t\n<<Target contact was successfully updated!>>");
	printf("\n\n\n   ::Press a key to return main page & continue program|-->");
	getc(stdin);
}

void search(void)
{
	char ch;
	clrscr();
    printf("\nPhone Book12<::>$earch Contacts");
    printf("\n--------------------------------------------------------------------------------");
	printf("\nChoose search type,please:\n\n");
	printf("\t[1] |--> Search by first name\n");
	printf("\t[2] |--> Search by last name\n");
	printf("\t[3] |--> Search by phone number\n");
	printf("\t[4] |--> Search by cellphone number\n");
	printf("\t[5] |--> Main Menu\n");
	printf("\n\t::Enter a number (1-5): ");
	ch = getc(stdin);
	getc(stdin);
	printf("\n--------------------------------------------------------------------------------");
    switch(ch) {
		case '1':
		searchf();
	    break;
		case '2':
		searchl();
		break;
		case '3':
		searchp();
		break;
		case '4':
		searchc();
		break;
		case '5':
		default:
			return;
    }
}

void searchf(void)
{
	char *fname = NULL;
	register int i,find=0;
	size_t len=0;
	size_t len_size=0;
	printf("Enter a first name to search:");
	len_size = get_input(fname,31);
    for(i = 0;i < last; i++)
		if(strcmp(fname,A[i].fname) == 0) {
			find=1;
			break;
		}
	if(find==0)
		printf("\t\n<<Not Find!There is no contact with this name in phone book.>>");	
	else {
		printf("\t\n<<Target contact found! Details:>>");
		printf("\n\nCantact %2.2d{",i+1);
		printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
	}
	printf("\nPress a key to search another contact.");
	getc(stdin);
	search();
}


void searchl(void)
{
	char *lname = NULL;
	register int i,find=0;
	size_t len=0;
	size_t len_size=0;
	printf("\n::Enter a last name to search:");
	len_size = get_input(lname,31);
    for(i = 0;i < last; i++)
		if(strcmp(lname,A[i].lname) == 0) {
			find=1;
			break;
	 	}
	if(find==0)
		printf("\t\n<<Not Find!There is not contact with tish name in phone book.>>");	
	else {
		printf("\t\n<<Target contact found! Details:>>");
		printf("\n\nCantact %2.2d{",i+1);
		printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
	}
	printf("\nPress a key to search another contact.");
	getc(stdin);
	search();
}

void searchp(void)
{
	
	char *phone = NULL;
	int i,find=0;
	char telep[5];
	size_t len=0;
	size_t len_size=0;
	printf("\n::Enter a phone number to search:");
	len_size = get_input(phone,15);
	strncpy(telep, phone,15);
	for(i = 0;i < last; i++)
		if(strcmp(telep,A[i].telep) == 0) {
			find=1;
			break;
		}
	if(find==0)
		printf("\t\n<<Not Found!There is not contact with tish phone number  in phone book.>>");	
	else{
		printf("\t\n<<Target contact found! Details:>>");
		printf("\n\nCantact %2.2d{",i+1);
		printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
	}
	printf("\nPress a key to search another contact.");
	getc(stdin);
	search();
}

void searchc(void)
{
	
	char *phone = NULL;
	char cell[5];
	int i,find=0;
	size_t len=0;
	size_t len_size=0;
	printf("\n::Enter a cellphone number to search:");
	len_size = get_input(phone,15);
	strncpy(cell, phone,15);
	
    for(i = 0; i < last; i++)
		if(strcmp(cell,A[i].cellp) == 0) {
			find=1;
			break;
		}
	if(find==0)
		printf("\t\n<<Not Find!There is not contact with tish cellphone number in phone book.>>");	
	else {
	printf("\t\n<<Target contact found! Details:>>");
	printf("\n\nCantact %2.2d{",i+1);
	printf("\n\t   F.Name:%s\n\t   L.name:%s\n\t   Tele.P:%s\n\t   Cell.P:%s\n\t   }",A[i].fname,A[i].lname,A[i].telep,A[i].cellp);
	}
	printf("\nPress a key to search another contact.");
	getc(stdin);
	search();
}

void sort(void)
{
	char ch;
	clrscr();			
    printf("\nPhone Book12<::>$earch Contacts");
    printf("\n--------------------------------------------------------------------------------");
	printf("\nChoose sort type,please:\n\n");
	printf("\t[1] |--> Sort by first name\n");
	printf("\t[2] |--> Sort by last name\n");
	printf("\t[3] |--> Sort by phone number\n");
	printf("\t[4] |--> Sort by cellphone number\n");
	printf("\t[5] |--> Main Menu\n");	
	printf("\n\t::Enter a number (1-5): ");
	ch = getc(stdin);
	getc(stdin);
	printf("\n--------------------------------------------------------------------------------");
    switch(ch){
		case '1':
		sortf();
	    break;
		case '2':
		sortl();
		break;
		case '3':
		sortp();
		break;
		case '4':
		sortc();
		case '5':
		default:
			return ;
    }
}

void sortf(void)
{
	struct contact B;
	register int i,j;
	for(i= last-1 ;i > 0; i--)
		for(j = 0; j < i; j++)
			 if(strcmp(A[j].fname, A[j+1].fname) > 0) {
			 	B = A[j];
				A[j] = A[j+1];
				A[j+1] = B;
			 }
	printf("\nplease wait... .Contacts will be sorted by first names.");
	list2();
	printf("\n   ::Press any key to sort contact by another form... ");
	getc(stdin);
	sort();
}

void sortl(void)
{
	struct contact B;
	register int i,j;
	for(i = last-1 ; i > 0; i--)
		for(j = 0; j < i ; j++)
			if(strcmp(A[j].lname,A[j+1].lname) > 0) {
				B = A[j];
				A[j] = A[j+1];
				A[j+1] = B;
			}
	printf("\nplease wait... .Contacts will be sorted by last names.");
	list2();
	printf("\n   ::Press any key to sort contact by another form... ");
	getc(stdin);
	sort();
}
void sortp(void)
{
	struct contact B;
	register int i,j;
	for(i = last-1; i > 0; i--)
		for(j = 0; j < i; j++)
			if(strcmp(A[j].telep,A[j+1].telep) > 0) {
				B = A[j];
		  	    A[j] = A[j+1];
		        A[j+1] = B;
			}
	printf("\nplease wait... .Contacts will be sorted by telephone numbers.");
	list2();
	printf("\n   ::Press any key to sort contact by another form... ");
	getc(stdin);
	sort();
}
void sortc(void)
{
	struct contact B;
	register int i,j;
	for(i = last-1; i > 0; i--)
		for(j = 0; j < i; j++)
			if(strcmp(A[j].cellp,A[j+1].cellp) > 0) {
				B = A[j];
				A[j] = A[j+1];
				A[j+1] = B;
			}
	printf("\nPlease wait... .Contacts will be sort by cellphone numbers.");
	list2();
	printf("\n   ::Press any key to sort contact by another form... ");
	getc(stdin);
	sort();
}

void list()
{
	register int i;
	clrscr();
    printf("\nPhone Book12<::>All Contacts List");
    printf("\n--------------------------------------------------------------------------------");
	gotoxy(1,4);
	printf("Row");
	gotoxy(9,4);
	printf("First Name");
	gotoxy(27,4);
	printf("Last Name");
	gotoxy(44,4);
	printf("Telephone");
	gotoxy(60,4);
	printf("Cellphone");
	printf("\n--------------------------------------------------------------------------------");
	for(i = 0; i <= last; i++) {
		gotoxy(1,i+6);						 
		printf("%3.3d",i+1);
		gotoxy(9,i+6);
		printf("%s",A[i].fname);
		gotoxy(28,i+6);
		printf("%s",A[i].lname);
		gotoxy(44,i+6);
		printf("%s",A[i].telep);
		gotoxy(60,i+6);
		printf("%s",A[i].cellp);
	}
	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t    **********End Of list!**********");	
	printf("\n\n\n   ::Press a key to return main page & continue program.|-->");
	getc(stdin);
}

void list2(void)
{
	register int i;
    printf("\n--------------------------------------------------------------------------------");
	gotoxy(1,18);
	printf("Row");
	gotoxy(9,18);
	printf("First Name");
	gotoxy(27,18);
	printf("Last Name");
	gotoxy(44,18);
	printf("Telephone");
	gotoxy(60,18);
	printf("Cellphone");
	printf("\n--------------------------------------------------------------------------------");
	for(i = 0; i < last; i++) {
		gotoxy(1,i+21);						 
		printf("%3.3d",i+1);
		gotoxy(9,i+21);
		printf("%s",A[i].fname);
		gotoxy(27,i+21);
		printf("%s",A[i].lname);
		gotoxy(44,i+21);
		printf("%s",A[i].telep);
		gotoxy(60,i+21);
		printf("%s",A[i].cellp);
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n\t\t    **********End Of list!**********");	
}

void help(void)
{
	 clrscr();
	 gotoxy(26,1);
	 printf("--------------------------");
	 gotoxy(26,2);
	 printf("|Welcome To Phone Book12!|");
	 gotoxy(26,3);
	 printf("--------------------------");
	 gotoxy(1,5);
	 printf("PhoneBook12>>[Help & Instructions] \n");
	 printf("--------------------------------------------------------------------------------\n");
	 printf("\nAbout Phonebook12\n *Version: 2.5\n *Valence: 50 Contacts(MAX)\n  *By: Morteza Zakeri (2011-12)");
	 printf("\n\nThis program allows you to have a list of your contacts.\nIt also allows you to have your listing added or deleted from your list.\nOther features of this program include:\nSearch,edit,sort & list.\n\n   ::Press a key to return main page & continue program.|-->");
	 getc(stdin);
 }

 void clrscr()
 {
	 system("clear");
 }
 
 void gotoxy(int x, int y)
 {
	 printf("%c[%d;%df", 0x1B, y, x);
 }

