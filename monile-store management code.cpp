#include<stdio.h>
#include <stdlib.h>
#include<string.h>                 
#include<ctype.h>                                       
      #include<time.h>
      #define RETURNTIME 15
char catagories[][15]={"Samsung","Apple","Nokia","Sony","LG","HTC"};
      void returnfunc(void);
       void mainmenu(void);
       void addstaff(void);
       void deletestaff(void);
       void editstaff(void);
       void searchstaff(void);
       void viewstaff(void);
       void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void Password();
void issuerecord();
void loaderanim();
FILE *fp,*ft,*fs;
int s;
char findstaff;
char password[10]={"pass"};
struct meroDate
{
int mm,dd,yy;
};
struct staff
{
int id;
char stname[20];
char name[20];
char available[20];
int qty;
int price;
int count;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};
struct staff a;

int main()
{
Password();
return 0;
}
void mainmenu()
{  
int i;
int choice;
printf(" \t\tMAIN MENU \n");
printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
printf("<1> Add Mobile Record\n");
printf("<2> View Mobile list\n");
printf("<3> Search Mobile Record\n");
printf("<4> Edit Mobile Record\n");
printf("<5> Delete Mobile Record\n");
printf("<6> Close The Application\n");
t();
printf("Enter your choice:");
fflush(stdin);
scanf("%d",&choice);
switch(choice)
{
case 1:
addstaff();
break;
case 2:
viewstaff();
break;
case 3:
searchstaff();
break;
case 4:
editstaff();	
break;
case 5:
deletestaff();
break;
case 6:
{  
printf("\tMobile Store Management System\n");
printf("\tProject in C");
printf("is brought to you by\n");
printf("\tBATCH-2\n");
exit(0);	
}
default:
{
printf("\n\aWrong Entry!!Please re-entered correct option");
mainmenu();
}
}
}
void addstaff(void)    
{ 
int i;
int temp;
printf("SELECT BRANDS\n");
printf("<1> Samsung\n");
printf("<2> Apple\n");
printf("<3> Nokia\n");
printf("<4> Sony\n");
printf("<5> LG\n");
printf("<6> HTC\n");
printf("<7> Back to main menu\n");
printf("Enter your choice:");
scanf("%d",&s);
if(s==7)
mainmenu() ;  
fp=fopen("stf.dat","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
printf("The record is sucessfully saved\n");
printf("Save any more?(1-y / 0-n):");
fflush(stdin);
scanf("%d",&temp);
if(temp==0)
mainmenu();
else
addstaff();
}
}
void deletestaff()    
{
int d,b;
int another=1;
while(another==1)  
{  
findstaff='f';
printf("Enter the Mobile ID to  delete:");
scanf("%d",&d);
fp=fopen("stf.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
printf("\nThe Mobile record is available");
printf("\nStaff name is %s",a.name);
findstaff='t';
}
}
if(findstaff!='t')
{
printf("\nNo record is found modify the search\n");
mainmenu();
}
if(findstaff=='t' )
{
printf("\nDo you want to delete it?(1-Y/0-N):");
fflush(stdin);
scanf("%d",&b);
if(b==1)
{
ft=fopen("test.dat","wb+");  
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); 
}
}
fclose(ft);
fclose(fp);
remove("stf.dat");
rename("test.dat","stf.dat"); 
fp=fopen("stf.dat","rb+");    
if(findstaff=='t')
{
printf("\nThe record is sucessfully deleted\n");
printf("\n\tDelete another record?(Y/N)");
}
fclose(fp);
}
else
mainmenu();
fflush(stdin);
printf("\n\tDelete another record?(Y/N)");
scanf("%d",&another);
}
}
mainmenu();
}
void searchstaff()
{  
int d;
int c,e;
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2xB2\Xb                               2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Search Mobile\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n1. Search By ID\n");
printf("2. Search By model Name\n");
printf("Enter Your Choice:");
fflush(stdin);
scanf("%d",&c);
fp=fopen("stf.dat","rb+"); 
rewind(fp);   
switch(c)
{
case 1:
{  
printf("\xB2\xB2\xB2\xB2\xB2\xB2Search Mobile By Id\xB2\xB2\xB2\xB2\xB2\xB2");
printf("Enter the Mobile id:");
scanf("%d",&d);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
printf("The Mobile is available\n");
printf("\nID:%d",a.id);
printf("\nBrand:%s",a.cat);
printf("\nName:%s",a.name);
printf("\nAvailability:%s ",a.available);
printf("\nQuantity:%i ",a.qty);
printf("Price:%i ",a.price);
findstaff='t';
}
}
if(findstaff!='t')
{
printf("\aNo Record Found\n");
}
fclose(fp);
printf("Try another search?(1-y/0-n)");
fflush(stdin);
scanf("%d",&e);
if(e==1)
searchstaff();
else
mainmenu();
break;
}
case 2:
{
char s[15];  
printf("\xB2\xB2\xB2\xB2\xB2\xB2Search Mobile By model Name\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\nEnter Model Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) 
{
		printf("\nThe Staff is available");
		printf("\nID:%d",a.id);
		printf("\nName:%s",a.name);
		printf("\nAvailability:%s",a.available);
		printf("\nQuantity:%i",a.qty);
		printf("\nPrice:%i",a.price);
		d+=6;
}
}
if(d==0)
printf("\n\aNo Record Found");
printf("\nTry another search?(1-Y/0-N)");
fflush(stdin);
scanf("%d",&e);
if(e==1)
		searchstaff();

else
		mainmenu();
break;
}
default :  
searchstaff();
      }
fclose(fp);
}
void viewstaff(void)  
{
int i=0,j;  
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Mobile List\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\n BRAND\t\tID\tMODEL NAME\tAVAILABILITY\tQUANTITY\tPRICE\n");
j=4;
fp=fopen("stf.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{
printf("%s",a.cat);
printf("\t\t%d",a.id);
printf("\t%s",a.name);
printf("\t\t%s",a.available);
printf("\t%i",a.qty);
printf("\t\t%i",a.price);
printf("\n\n");
j++;
}
fclose(fp);
returnfunc();
}
void editstaff(void)
{ 
int c=0;
int d,e;
printf("\n\xB2\xB2\xB2\xB2\xB2\xB2Edit Mobile Section \xB2\xB2\xB2\xB2\xB2\xB2");
int another=1;
while(another==1)
{  
printf("\nEnter Mobile Id to be edited:");
scanf("%d",&d);
fp=fopen("stf.dat","rb+");
     while(fread(&a,sizeof(a),1,fp)==1)
      {
if(checkid(d)==0)
{
    printf("\nThe Mobile is availble");
    printf("\nThe Mobile ID:%d",a.id);
    printf("\nEnter new name:");
   scanf("%s",a.name);
   printf("\nEnter new Availability Status:");
   scanf("%s",a.available);
   printf("\nEnter new Quantity:");
  	   scanf("%i",&a.qty);
   printf("\nEnter new Price:");
 	   scanf("%i",&a.price);
  printf("\nThe record is modified");
  fseek(fp,ftell(fp)-sizeof(a),0);
  fwrite(&a,sizeof(a),1,fp);
  fclose(fp);
c=1;
        }
if(c==0)
{
    printf("\nNo record found");
}
}
    printf("\nModify another Record?(1-Y/0-N)");
    fflush(stdin);
    scanf("%d",&another);
    //another=getch() ;
 }
  returnfunc();
      }
void returnfunc(void)
{
mainmenu();
 }
int getdata()
{
int t;
printf("\nEnter the Information Below");
printf("\nBrand:");
printf("%s",catagories[s-1]);
printf("\nMBL ID:\t");
scanf("%d",&t);
if(checkid(t) == 0)
{
     printf("\n\aThe id already exists\a\n\n");  
     mainmenu();
     return 0;
}
a.id=t;
printf("\nModel Name:");
scanf("%s",a.name);
printf("\nAvailability:");
scanf("%s",a.available);
printf("\nQuantity:");
scanf("%i",&a.qty);
printf("\nPrice:");
scanf("%i",&a.price);
return 1;
}
int checkid(int t)  
{
 rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
     if(a.id==t)
return 0;  
return 1; 
}



int t(void) 
{
time_t t;
time(&t);
printf("\nDate and time:%s\n",ctime(&t));
return 0 ;
}
void Password(void) 
{ 
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
	printf("\t\t\t\tWELCOME\n\t\t\t\t  To \n\t\t   \xB2\xB2\xB2\xB2\xB2\xB2 Mobile Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\t \n\n\n Enter Password:");
        scanf("%s",&pass);
/*while(ch!=13)
{
ch=getch();
if(ch!=13 && ch!=8)
{
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';   */


if(strcmp(pass,password)==0)
{
printf("\n\n\n\t\tPassword matched!!");
printf("\n\n\tPress any key to countinue.....");  
mainmenu();
}
else
{
printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");
Password();
}
}




