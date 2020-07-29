#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class faculty
{
	protected:
		string name,date_of_birth,subject,password,enrollment_no;
		double mark;
		int q;
	public:
		faculty()
	{
		q=0;
		password="";
	}
		void setdetails()
		{
			ofstream k;
			k.open("details.txt");
			cout<<"enter the details of teacher"<<endl;
			cout<<"name:-";
			cin>>name;
			cout<<endl<<"date of birth:-";
			cin>>date_of_birth;
			cout<<endl<<"subject:-";
			cin>>subject;
			char ch;
			cout<<endl<<"password:-";
			ch=_getch();
			while(ch!=13)
			{
				password.push_back(ch);
				cout<<"*";
				ch=_getch();
			}
			cout<<endl<<"enter enrollment no:-";
			cin>>enrollment_no;
			k<<name<<endl;
			k<<date_of_birth<<endl;
			k<<subject<<endl;
			k<<password<<endl;
			k<<enrollment_no<<endl;
			k.close();
		}
		void attendance()
		{
		ofstream a;
			a.open("attendance.txt");
			char ch;
			int p=0;
			cout<<"enter the attendance"<<endl;
			cin>>ch;
			if(ch=='Y')
			{
			p++;
			q+=p;
			a<<q;
		}
			else
		{
				p=0;
				q+=p;
				a<<p;
					}
					a.close();
			
		}
		double marks()
	{
		ofstream a;
		a.open("marks.txt");
		cout<<"enter the marks";
		cin>>mark;
		a<<mark;
		a.close();
	}
	void change_password(int n)
	{
		if(n==1)
		{
			char ch;
			cout<<endl<<"password:-";
			ch=_getch();
			while(ch!=13)
			{
				password.push_back(ch);
				cout<<"*";
				ch=_getch();
			}
			
		}
			}
	void show_details()
		{
			
			cout<<"name = "<<name<<endl;
		
			cout<<"date of birth = "<<date_of_birth<<endl;
			cout<<"enrollment number = "<<enrollment_no<<endl;
			cout<<"subject = "<<subject<<endl;
			
		}		
};
class management: public virtual faculty
{
	protected:
		double cgpa;
	public:
		void calculate()
		{
			double sum=0;
			sum= sum+mark;
		cgpa=sum	;
		}
		void display()
		{
			cout<<"cgpa secured"<<endl<<cgpa;
			
		}
};
class students:public virtual faculty,management
{
	private:
		string na,enrollment_no,password,course_name,subject,date_of_birth;
		int semester;
	public:
		students()
		{
			password="";
		}
		void details()
		{
			ofstream k;
			k.open("details1.txt");
			cout<<"enter the details"<<endl;
			cout<<"name:-";
			cin>>na;
			cout<<endl<<"enrollment no:-";
			cin>>enrollment_no;
			char ch;
			cout<<endl<<"password:-";
			ch=_getch();
			while(ch!=13)
			{
				password.push_back(ch);
				cout<<"*";
				ch=_getch();
			}
			cout<<endl<<"enter course:-";
			cin>>course_name;
			cout<<endl<<"enter date of birth:-";
			cin>>date_of_birth;
			cout<<endl<<"enter semester:-";
			cin>>semester;
			k<<na<<endl;
			k<<date_of_birth<<endl;
			k<<course_name<<endl;
			k<<password<<endl;
			k<<enrollment_no<<endl;
			k<<semester<<endl;
			k.close();
		}
		void show_attendance()
		{
			
			ifstream s;
			s.open("attendance.txt");
			int t;
			while(!s.eof())
			{
				s>>t;
				cout<<"no of present classes:-"<<t;
			}
			s.close();
		}
		void show_marks()
		{
			ifstream s;
			s.open("marks.txt");
			int t;
			while(!s.eof())
			{
				s>>t;
				cout<<"marks secured:-"<<t<<endl;
			}
			s.close();
		}
		void change_password()
		{
			int n;
			cout<<"enter 1 to change password"<<endl;
			cin>>n;
			if(n==1)
			{
			char ch;
			cout<<endl<<"password:-";
			ch=_getch();
			while(ch!=13)
			{
				password.push_back(ch);
				cout<<"*";
				ch=_getch();
			}
			}
		}
		void show_cgpa()
		{
			
		
			cout<<"cgpa secured in semester "<<semester<<" are"<<endl;
			display();
		}
		void show_details()
		{
			
			cout<<"name = "<<na<<endl;
			cout<<"semester = "<<semester<<endl;
			cout<<"date of birth = "<<date_of_birth<<endl;
			cout<<"enrollment number = "<<enrollment_no<<endl;
			cout<<"course name = "<<course_name<<endl;
			
		}
};
int main()
{
	int n, i,j;
	for(j=1; ;j++)
	{
	
	cout<<"enter 1 for teacher"<<endl<<"enter 2 for student"<<endl;
	cin>>n;
	if(n==1)
	{
		faculty m[10];
		int choice,position;
		for(i=0;i<1;i++)
		{
			m[i].setdetails();
		}
		cout<<"enter 1 for details"<<endl<<"enter 2 to change password"<<endl<<"enter 3 to input attendance"<<endl;
		cin>>choice;
		cout<<"enter the position"<<endl;
		cin>>position;
		if(choice==1)
		{
		m[position].show_details();
	     }
	     else if(choice==2)
	     {
	     	m[position].change_password(1);
		 }
		 else 
		 {
		 	m[position].attendance();
		 }
}
	else if(n==2)
	{
		students f[250];
		int choice1,position1;
		for(i=0;i<1;i++)
		{
			f[i].details();
		}
		cout<<"enter 1 for attendance"<<endl<<"enter 2 for exam marks"<<endl<<"enter 3 for details"<<endl<<"enter 4 to change password"<<endl<<"enter 5 for cgpa"<<endl;
		cin>>choice1;
		cout<<"enter the position"<<endl;
		cin>>position1;
		if(choice1==1)
		{
		f[position1].show_attendance();	
		}
		else if(choice1==2)
		{
			f[position1].show_marks();
		}
		else if(choice1==3)
		{
			f[position1].show_details();
		}
		else if(choice1==4)
		{
			f[position1].change_password();
		}
		else if(choice1==5)
		{
			f[position1].show_cgpa();
		}
		
	}
	cout<<"press 1 to exit"<<endl;
	int q;
	cin>>q;
	if(q==1)
	break;
}
}

