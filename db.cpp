#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	struct student
	{
		char first_name[50],last_name[50];
		char course[100];
		int section;
	};
	struct student e;
	char xfirst_name[50],xlast_name[50];
	long int recsize;
	fp=fopen("users.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("user.txt","wb+");
		if(fp==NULL)
		{
			puts("cannot open file");
			return 0;
		}
	}
	recsize=sizeof(e);
	while(1)
	{
		system("cls");
		cout<<"\t\t======STUDENT DATABASE MANAGEMENT SYSTEM======";
		cout<<"\n\n";
		cout<<"\n\t\t\t 1.add    records";
		cout<<"\n\t\t\t 2.list   records";
		cout<<"\n\t\t\t 3.modify records";
		cout<<"\n\t\t\t 4.delete records";
		cout<<"\n\t\t\t 5.exit   program";
		cout<<"\nselect your choice:";
		fflush(stdin);
		choice=getche();
		switch (choice)
		{
			case '1':
				fseek(fp,0,SEEK_END);
				another ='Y';
				while(another=='Y'||another=='y')
				{
					system("cls");
					cout<<"enter the first name:";
					cin>>e.first_name;
					cout<<"enter the last name:";
					cin>>e.last_name;
					cout<<"enter the course:";
					cin>>e.course;
					cout<<"enter the section:";
					cin>>e.section;
					fwrite(&e,recsize,1,fp);
					cout<<"\nadd another record (Y/N)";
					fflush(stdin);
					another=getchar();
				}
				break;
				case '2':
					system("cls");
					rewind(fp);
					cout<<"===view the records in the database===\n";
					while(fread(&e,recsize,1,fp)==1)
					{
						cout<<"\n\n"<<e.first_name<<setw(10)<<e.last_name;
						cout<<"\n\n"<<e.course<<setw(10)<<e.section;
					}
					cout<<"\n\n";
					system("pause");
					break;
					case '3':
					system("cls");
					another='Y';
						while(another=='Y'||another=='y')
						{
							cout<<"\nenter the last name of the student:";
							cin>>xlast_name;
							rewind(fp);
							while(fread(&e,recsize,1,fp)==1)
							{
								if(strcmp(e.last_name,xlast_name)==0)
								{
									cout<<"enter new first name:";
									cin>>e.first_name;
									cout<<"enter the new last name:";
					                cin>>e.last_name;
					                cout<<"enter the new course:";
					                cin>>e.course;
					                cout<<"enter new section:";
					                cin>>e.section; 
					                fseek(fp,-recsize,SEEK_CUR);
					                fwrite(&e,recsize,1,fp);
					                break;
								}
								else
								cout<<"\n modify another record (Y/N)";
								fflush(stdin);
								another=getchar();
							}
							break;
							case '4':
								system("cls");
					another='Y';
						while(another=='Y'||another=='y')
						{
							cout<<"\nenter the last name of the student to delete:";
							cin>>xlast_name;
							ft=fopen("temp.dat","wb");
							rewind(fp);
								while(fread(&e,recsize,1,fp)==1)
								
								if(strcmp(e.last_name,xlast_name)!=0)
								{
									fwrite(&e,recsize,1,ft);
								}
						fclose(fp);
						fclose(ft);
						remove("users.txt");
						rename("temp.dat","usrs.txt");
						fp=fopen("users.txt","rb+");
						cout<<"\ndelete another record (Y/N)";
						fflush(stdin);
						another=getchar();
						}
						break;
					}
	}}
}
