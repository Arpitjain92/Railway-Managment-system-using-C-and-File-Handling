#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<stdlib.h>
using namespace std;
static int t=0;
int a1,a2,i;
class user
{
protected: char email[20],pass[20];
public: void signup()
	{
	 system("cls");
	 cout<<"*\n";
	 cout<<"|^^^^^^^^^^^^^^^^^^^^^^Vande Matram Express^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cout<<"*\n\n";
	 cout<<"^^^^^^^^^^^^^^^^^^^^^^ENTER YOUR EMAIL^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cin>>email;
	 cout<<"^^^^^^^^^^^^^^^^^^^^^ENTER YOUR PASSWORD^^^^^^^^^^^^^^^^^^^^^\n";
	 cin>>pass;
	 cout<<"*\n";
	 cout<<"|^^^^^^^^^^^^^^^PLEASE REMEMBER YOUR PASSWORD^^^^^^^^^^^^^^^^\n";
	 cout<<"*\n\n";
	 ofstream us;
	 us.open("user.txt",ios::binary);
	 us<<email<<endl<<pass;
	 us.close();
	}
	int login()
	{
	 system("cls");
	 cout<<"*\n";
	 cout<<"|^^^^^^^^^^^^^^^^^^^^^^Vande Matram Express^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cout<<"*\n\n";
	 char email2[20],pass2[20];
	 cout<<"^^^^^^^^^^^^^^^^^^^^^ENTER YOUR EMAIL^^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cin>>email2;
	 cout<<"^^^^^^^^^^^^^^^^^^^ENTER YOUR PASSWORD^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cin>>pass2;
	 ifstream in;
	 in.open("user.txt",ios::binary);
	 while(!in.eof())
	 {
	  in>>email;
	  a1=strcmp(email,email2);
	  in>>pass;
	  a2=strcmp(pass,pass2);
	  if(a1==0&&a2==0)
	  {
	  cout<<"^^^^^^^^^^^^^^^^^^^^^^^^LOGGED IN^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	  return 1;
	  }
	  else
	  {
	  cout<<"^^^^^^^^^^^^^^^^^^^WRONG ID//PASSWORD^^^^^^^^^^^^^^^^^^^^^^^^\n";
	  return 0;
	  }
	 }
	 return 0;
	 }
};
class passenger
{
protected: char namep[20];
	   char mob[20];
	   char email[20];
	   int age;
	   int seat;
public:
       void addpass()
       { seat=0;
       system("cls");
       cout<<"*\n";
       cout<<"|^^^^^^^^^^^^^^^^^^^^^^Vande Matram Express^^^^^^^^^^^^^^^^^^^^^^^^^\n";
       cout<<"*\n\n";
       fstream out;
       fstream in;
       int count=1;
       in.open("passen.txt",ios::in|ios::binary);
       out.open("passen1.txt",ios::out|ios::binary|ios::app);
       while(in>>namep>>mob>>email>>age>>seat)
	 {
	  out<<namep<<" "<<mob<<" "<<email<<" "<<age<<" "<<seat<<"\n";
	  count++;
	 }
       out.close();
       fstream outt;
       outt.open("passen.txt",ios::out|ios::binary);
       cout<<"^^^^^^^^^^ENTER THE NO OF PASSENGER YOU WANT TO ADD^^^^^^^^^^\n";
       cin>>i;
       for(i;i>0;i--)
       {
       system("cls");
       cout<<"*\n";
       cout<<"|^^^^^^^^^^^^^^^^^^^^^^Vande Matram Express^^^^^^^^^^^^^^^^^^^^^^^^^\n";
       cout<<"*\n\n";
       cout<<"\tENTER PASSENGER NAME-";
       cin>>namep;
       outt<<namep<<" ";
       cout<<"\n\tENTER MOBILE NO-";
       cin>>mob;
       outt<<mob<<" ";
       cout<<"\n\tENTER EMAIL-";
       cin>>email;
       outt<<email<<" ";
       cout<<"\n\tENTER YOUR AGE-";
       cin>>age;
       outt<<age<<" ";
       seat=count++;
       outt<<seat<<" ";
       }
       cout<<"\n\n^^^^^^^^^^^^^^^^^^^^^^PASSENGER ADDED SUCCESSFULLY^^^^^^^^^^^^^^^^^^^^\n";
       out.close();
       }
};

class train:passenger
{
protected:char namet[20],tid[20];
	  char o[20],d[20],t1[5],t2[5];
public:void booktc()
       {
	 system("cls");
	 cout<<"*\n";
	 cout<<"|^^^^^^^^^^^^^^^^^^^^^^Vande Matram Express^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cout<<"*\n\n";
	 cout<<"@*@\n";
	 char oa[20],od[20];
	 int count=0;
	 cout<<"^^^^^^^^^^^^^^^^ENTER BOARDING STATION^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cin>>oa;
	 cout<<"^^^^^^^^^^^^^^^^^^ENTER DESTINATION^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cin>>od;
	 fstream in;
	 in.open("train11.txt",ios::in|ios::binary);
	 while(in>>tid>>namet>>o>>d>>t1>>t2)
	 {
	  if(!strcmp(oa,o)&&!strcmp(od,d))
	  {
	   system("cls");
	   cout<<"*\n";
	   cout<<"\t\tTRAIN ID-"<<tid<<"\tTRAIN NAME-"<<namet<<endl;
	   cout<<"\t\tORIGIN STATION-"<<o<<"\tDESTINATION STATION-"<<d<<endl;
	   cout<<"\tTIME AT ORIGIN STATION-"<<t1<<" TIME AT DESTINATION STATION-"<<t2<<endl;
	   cout<<"\n**\n";
	   count++;
	  }
	  if(count==1)
	  break;
	 }
	 if(count==0)
	 cout<<"^^^^^^^^^^^^^^^NO TRAINS AVAILABLE FOR THIS ROUTE^^^^^^^^^^^^^^^^\n";
	 cout<<"^^^^IF YOU WANT TO BOOK TICKETS PRESS 1/ANY OTHER KEY TO EXIT^^^^\n";
	 cin>>count;
	 if(count==1)
	 {
	  addpass();
	 }
	 fstream out;
	 in.seekg(ios::beg);
	 out.open("ticket.txt",ios::out|ios::binary);
	  while(in>>tid>>namet>>o>>d>>t1>>t2)
	 {
	 if(!strcmp(oa,o)&&!strcmp(od,d))
	  {
	   out<<tid<<"\t"<<namet;
	   out<<"\t"<<o<<"\t"<<d;
	   out<<"\t"<<t1<<"t"<<t2;
	  }
	  fstream inn;
	  inn.open("passen.txt",ios::in|ios::binary);
	  while(in>>namep>>mob>>email>>age>>seat)
	  {
	   out<<namep<<"\t"<<mob<<"\t"<<email<<"\t"<<age<<"\t"<<seat<<endl;
	  }
	  out.close();
	  in.close();
	  inn.close();
	 }
	 getch();
	 system("cls");
       }
       void addtrain()
       {
	       system("cls");
	       cout<<"*\n";
	       cout<<"|^^^^^^^^^^^^^^^^^^^^^^Vande Matram Express^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	       cout<<"*\n\n";
	       fstream out;
	       out.open("train11.txt",ios::app|ios::out|ios::binary);
	       cout<<"^^^^^^^^^^^^^^^^^^^^ENTER TRAIN DETAILS^^^^^^^^^^^^^^^^^^^^^^\n";
	       cout<<"\n\tTRAIN ID- ";
	       cin>>tid;
	       out<<tid<<" ";
	       cout<<"\tTRAIN NAME- ";
	       cin>>namet;
	       out<<namet<<" ";
	       cout<<"\n\tORIGIN STATION- ";
	       cin>>o;
	       out<<o<<" ";
	       cout<<"\n\tDESTINATION- ";
	       cin>>d;
	       out<<d<<" ";
	       cout<<"\n\tENTER TIME OF ORIGIN STATION- ";
	       cin>>t1;
	       out<<t1<<" ";
	       cout<<"\n\tENTER TIME OF DESTINATION STATION- ";
	       cin>>t2;
	       out<<t2<<"\n";
	       cout<<"TRAIN ADDED SUCCESSFULLY\n";
	       out.close();
	       return;
       }
       void deltrain()
       {
	 system("cls");
	 cout<<"*\n";
	 cout<<"|^^^^^^^^^^^^^^^^^^^^^^INDIAN TRAIN^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	 cout<<"*\n\n";
	 char line[20],no[20];
	 cout<<"^^^^^^^^^^^^^^^^ENTER TRAIN NO. TO BE DELETED^^^^^^^^^^^^^^^^^\n";
	 cin>>no;
	 ifstream in;
	 ofstream out;
	 in.open("train11.txt",ios::binary);
	 in.seekg(0);
	 out.open("temp.txt",ios::binary);
	 while(in>>tid>>namet>>o>>d>>t1>>t2)
	 {
	  if(!strcmp(tid,no))
	  {
	  cout<<"^^^^^^^^^^^^^^^^^^TRAIN REMOVED SUCCESSFULLY^^^^^^^^^^^^^^^^^^^^^\n";
	  continue;
	  }
	  out<<tid<<" "<<namet<<" "<<o<<" "<<d<<" "<<t1<<" "<<t2<<"\n";
	 }
	 in.close();
	 out.close();
	 remove("train11.txt");
	 rename("temp.txt","train11.txt");
	 getch();
       }
	void showt()
 {
 fstream in;
 fstream inn;
 inn.open("passen.txt",ios::in|ios::binary);
 in.open("ticket.txt",ios::in|ios::binary);
 in>>tid>>namet>>o>>d>>t1>>t2;
 {
  system("cls");
  cout<<"\n";
  cout<<"TRAIN ID-"<<tid<<"    "<<"TRAIN NAME-"<<namet<<endl;
  cout<<"ORIGIN STATION-"<<o<<"    "<<"DESTINATION STATION-"<<d<<endl;
  cout<<"ARRIVAL TIME-"<<t1<<"    "<<"ESTIMATE TIME OF DESTINATION"<<t2<<endl;
  cout<<"\n\n\n";
 }
 inn>>namep;
 cout<<namep;
 inn.seekp(ios::beg);
 while(inn>>namep>>mob>>email>>age>>seat)
 {
  cout<<"\n";
  cout<<"PASSENGER NAME-"<<namep<<"    "<<"PASSENGER AGE-"<<age<<endl;
  cout<<"EMAIL ID-"<<email<<"  "<<"CONTACT NO-"<<mob<<"  "<<"SEAT NO-"<<seat<<endl;
  cout<<"\n";
 }
 getch();
 }
};
class ticket:train,virtual passenger,user
{
protected: char pnr[12];
	   int sn;
public:
};
class admin:train,passenger
{
public: void adminm()
	{
	system("cls");
	cout<<"*\n";
	cout<<"|^^^^^^^^^^^^^^^^^^^^^^INDIAN TRAIN^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"*\n\n";
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^ENTER PASSWORD^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cin>>a2;
	if(a2==1234)
	{
	 cout<<"^^^^^^^^^^^^^^^^^^^^^^^^LOGGED IN^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	}
	else
	{
	cout<<"^^^^^^^^^^^^^^^^^^^^^^WRONG PASSWORD^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	return;
	}
	while(1)
	{
	system("cls");
	cout<<"*\n";
	cout<<"|^^^^^^^^^^^^^^^^^^^^^^INDIAN TRAIN^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"*\n\n";
	cout<<"@*@\n";
	cout<<"\t1-PRESS 1 TO ADD TRAIN\n\t2-PRESS 2 TO DELETE TRAIN\n\t3-PRESS 3 TO EXIT\n";
	cin>>i;
	switch(i)
	{
	case 1:addtrain();break;
	case 2:deltrain();break;
	case 3:break;
	}
	if(i==3)
	{
	system("cls");
	return;
	}
	}
    }
};
  int main()
  {
	system("cls");
	admin am;
	train tn;
	passenger ps;
	ticket tc;
	user u;
	int i;
	cout<<"*\n";
	cout<<"|^^^^^^^^^^^^^^^^^^^^^^INDIAN ** TRAIN^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"*\n\n";
	cout<<"^^^^^^^^^PRESS 1 TO LOGIN//\\ PRESS 0 TO SIGN UP^^^^^^^^^^^^^\n";
	cin>>i;
	if(i)
	{
	  a1=u.login();
	}
	else
	{
	  u.signup();
	  a1=u.login();
	}
	if(a1==1)
	{
	while(1)
	{
	  system("cls");
	  cout<<"*\n";
	  cout<<"|^^^^^^^^^^^^^^^^^^^^^^INDIAN ** TRAIN^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	  cout<<"*\n\n";
	  cout<<"@@\n";
	  cout<<"\t1-PRESS 1 TO BOOK TICKETS\n\t2-PRESS 2 TO CHECK BOOKING HISTORY\n\t3-PRESS 3 TO CANCEL TICKET\n\t4-PRESS 4 TO EXIT\n\t5-PRESS 5 FOR ADMIN MODE\n";
	  cout<<"@@\n";
	  cin>>i;
	  switch(i)
	  {
   case 1:tn.booktc();break;
   case 2:tn.showt();break;
  // case 3:cancel();break;
   case 4:exit(0);
   case 5:am.adminm();
	  }
	}
	}
  return 0;

  }
