#include <bits/stdc++.h>
using namespace std;
class login;
class employee;
void admin();
void employee_login();
void create_employee();
void leavify(employee e);
void handle_leavify();
class about{
public:
    void details()
    {
        ifstream infile;
        infile.open("details.txt");
        while(infile)
        {
            string s;
            getline(infile,s);
            cout<<s<<endl;
        }
        infile.close();
    }
};
class contact{
    public:
    void details()
    {
        ifstream infile;
        infile.open("details1.txt");
        while(infile)
        {
            string s;
            getline(infile,s);
            cout<<s<<endl;
        }
        infile.close();
    }
};
class employee
{
    string name,id,pass,designation,sec;
    int salary;
public:
    void details()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Student ID: "<<id<<endl;
        cout<<"designation: "<<designation<<endl;
        cout<<"salary "<<salary<<endl;
        cout<<"section: "<<sec<<endl<<endl;
    }
    friend login;
    friend void create_employee();
    friend void employee_login();
    friend void leavify (employee e);
};
class khan
{
private:
    string s="KHAN CORPORATE LTD.";
};
class login:public khan
{
public:
     void process()
    {
        int n;
        cout <<"LOGIN PORTAL"<<endl<<endl;
        cout << "Enter number to access menu" << endl;
        cout << "1.Employee Login" << endl;
        cout << "2.Admin Login" << endl;
        cout<<endl<<"Choose a login Option: ";
        cin>>n;
        cout<<endl;
        if(n==2)
        {
            admin();
        }
        if(n==1)
        {
            employee_login();
        }
    }
    friend void admin();
    friend void create_employee();
    friend void employee_login();
    friend void leavify (employee e);
    friend void handle_leavify();

};
void leavify(employee e)
{
    cout << "Enter number to access menu" << endl<<endl;
    cout << "1.Previous requests" << endl;
    cout << "2.Add new requests " << endl;
    cout<<"3.Go to previous menu"<<endl<<endl;
    while(1)
    {
    int n;
    cout<<"Choose a leave option: ";
    cin>>n;cout<<endl;
    if(n==3)break;
    else if(n==2) {
    string a,b,c,s;
    cout<<"Starting Date: ";
    cin>>a;
    cout<<"Ending Date: ";
    cin>>b;
    cout<<"Add reason: ";
    getline(cin,s);
    getline(cin,c);
    ofstream outfile;
        outfile.open("leave_request.txt",ios::app);
        outfile<<"Employee id: "<<e.id<<endl;
        outfile<<"From "<<" "<<a<<" "<<"to"<<" "<<b<<endl;
        outfile<<"Reason:"<<c<<endl;
        outfile<<"Status: Pending"<<endl;
        outfile<<"..."<<endl;
        outfile.close();
        cout<<"Request successful"<<endl<<endl;
    }
    else if(n==1)
    {
        ifstream infile;
        infile.open("leave_request.txt");
        int flag=0;
        while(infile)
        {
            string s;
            getline(infile,s);
            string k="Employee id: "+e.id;
            if(s==k){
                while(s!="...")
                {
                    cout<<s<<endl;
                    getline(infile,s);
                }
                flag++;
                break;

            }
            if(flag>0)break;
        }
        if(flag==0)cout<<"No previous requests"<<endl;
        infile.close();
    }
}

}
void employee_login()
{

    string id,pass,a,b,f;
    cout<<"Enter employee id: ";
    cin>>id;
    cout<<"Enter password: ";
    cin>>pass;cout<<endl;
    f="employee/"+id+".txt";
    ifstream infile;
    infile.open(f);
    if(infile.is_open())
    {
        employee e;
        string s;
        getline(infile,s);
        e.id=s;
        getline(infile,s);
        e.pass=s;
        getline(infile,s);
        e.name=s;
        getline(infile,s);
        e.designation=s;
        getline(infile,s);
        e.sec=s;
        getline(infile,s);
        e.salary=stoi(s);
        if(e.id==id&&e.pass==pass)
        {
            cout<<"Welcome "<<e.name<<endl<<endl;
            cout << "Enter number to access menu" << endl;
            cout << "1.My info" << endl;
            cout << "2.Request a leave " << endl;
            cout << "3.Give attendance" << endl;
            cout<<"5.Logout"<<endl;
            cout<<endl;
            while(1)
            {
                cout<<"Choose a employee login option: ";
                int n;
                cin>>n;cout<<endl;
                if(n==5)break;
                else if(n==1)e.details();
                else if(n==2) leavify(e);
                else if(n==3)
                {

                    ofstream outfile;
                    outfile.open("attendance.txt");
                    outfile<<e.name<<" \t"<<e.id<<endl;
                    outfile.close();
                    cout<<"Attendance given successfully."<<endl<<endl;

                }
            }
        }
        else cout<<"Wrong id or password"<<endl;
        }

    else{
        cout<<"Account does not exist"<<endl;
    }

}
void handle_leavify()
{
    cout << "Enter number to access menu" << endl;
    cout << "1.Get all requests" << endl;
    cout << "2.Accept request " << endl;
    cout<<"3.Decline request"<<endl;
    cout<<"4.Go to previous menu"<<endl;
    while(1)
    {
        int n;cout<<"Choose a leave handeling option: ";
        cin>>n;
        if(n==4)break;
        if(n==1)
        {
            ifstream infile;
            infile.open("leave_request.txt");
            string s;
            while(infile)
            {
                getline(infile,s);
                cout<<s<<endl;
            }
            infile.close();
        }
        if(n==2)
        {
            cout<<"Enter employee id: ";
            string id;cin>>id;
            id="Employee id: "+id;
            vector<string> v;
            ifstream infile;
            infile.open("leave_request.txt");
            while(infile)
            {
                string s;
                getline(infile,s);
                if(s==id)
                {
                    v.push_back(s);
                    getline(infile,s);
                    v.push_back(s);
                    getline(infile,s);
                    v.push_back(s);
                    getline(infile,s);
                    s="Status Accepted";
                    v.push_back(s);
                }
                else v.push_back(s);
            }
            infile.close();
            ofstream outfile;
            outfile.open("leave_request.txt");
            for(int i=0;i<v.size();i++)
            {
                outfile<<v[i]<<endl;
            }
            outfile.close();
            cout<<"Update Successful"<<endl<<endl;


        }
        if(n==3)
        {
            cout<<"Enter employee id: ";
            string id;cin>>id;
            id="Employee id: "+id;
            vector<string> v;
            ifstream infile;
            infile.open("leave_request.txt");
            while(infile)
            {
                string s;
                getline(infile,s);
                if(s==id)
                {
                    v.push_back(s);
                    getline(infile,s);
                    v.push_back(s);
                    getline(infile,s);
                    v.push_back(s);
                    getline(infile,s);
                    s="Status Declained";
                    v.push_back(s);
                }
                else v.push_back(s);
            }
            infile.close();
            ofstream outfile;
            outfile.open("leave_request.txt");
            for(int i=0;i<v.size();i++)
            {
                outfile<<v[i]<<endl;
            }
            outfile.close();
            cout<<"Update Successful"<<endl<<endl;
        }
    }
}
void admin()
{
    string id,pass,a,b;
    cout<<"Enter admin id: ";
    cin>>id;
    cout<<"Enter password: ";
    cin>>pass;
    ifstream infile;
    infile.open("admin.txt");
    getline(infile,a);
    getline(infile,b);
    infile.close();
    if(id==a&&pass==b)
    {
        cout<<"\nWelcome Admin."<<endl;
        cout << "Enter number to access menu" << endl;
        cout << "1.Add New Employee" << endl;
        cout << "2.Get List of All Employee " << endl;
        cout << "3.Leave Requests" << endl;
        cout<<"4.Today Present Employee"<<endl;
        cout<<"5.Close office"<<endl;
        cout<<"6.Logout"<<endl;
        cout<<endl;
        while(1)
        {
            int n;
            cout<<"Choose an admin option: ";
            cin>>n;cout<<endl;
            if(n==6) break;
            else if(n==1)
            {
                create_employee();
            }
            else if(n==2)
            {
                ifstream infile;
                infile.open("all_employee.txt");
                string s;
                while(infile)
                {
                    getline(infile,s);
                    cout<<s<<endl;
                }
                infile.close();
            }
            else if(n==3)
            {
                handle_leavify();
            }
            else if(n==4)
            {
                ifstream infile;
                infile.open("attendence.txt");
                while(infile)
                {
                    string s;
                    getline(infile,s);
                    cout<<s<<endl;
                }
                infile.close();
            }
            else if(n==5)
            {
                ofstream outfile;
                outfile.open("attendance.txt");
                outfile.close();
                cout<<"Office closed"<<endl;
            }
        }
    }
        else cout<<"Wrong id or password"<<endl;
}
void create_employee()
{

    employee em;
    cout<<"Enter employee name ";
    cin>>em.name;
    cout<<"Enter employee id ";
    cin>>em.id;
    cout<<"Enter employee password ";
    cin>>em.pass;
    cout<<"Enter employee designation ";
    cin>>em.designation;
    cout<<"Enter employee salary ";
    cin>>em.salary;
    cout<<"Enter employee section ";
    cin>>em.sec;
    ofstream outfile;
    string fname="employee/"+em.id+".txt";
    outfile.open(fname);
    outfile<<em.id<<'\n'<<em.pass<<'\n'<<em.name<<'\n'<<em.designation<<'\n'<<em.sec<<'\n'<<em.salary<<endl;
    outfile.close();
    ifstream infile;
    infile.open(fname);
    if(infile.is_open())
    {
        string a,b;
        getline(infile,a);
        getline(infile,b);
        infile.close();
        cout<<"\nEmployee added successfully "<<endl;
        ofstream outfile;
        outfile.open("all_employee.txt",ios::app);
        outfile<<a<<" "<<b<<endl;
        outfile.close();
    }
    else{
        cout<<"Could not add employee"<<endl;
    }



}
int main()
{
   cout << "WELCOME TO KHAN CORPORATE LTD." << endl<<endl;
    cout << "Main Menu\nEnter number to access menu" << endl;
    cout << "1.About us" << endl;
    cout << "2.Contact us" << endl;
    cout << "3.Login" << endl;
    cout<<"0. Terminate Session"<<endl;
    cout<<endl;
    while(1)
    {
        int n; cout<<"Choose a Main Option: ";
        cin>>n; cout<<endl;
        if(n==0) break;
        else if(n==1)
         {
             about a;
             a.details();

         }
         else if(n==2)
         {
             contact b;
             b.details();
         }
         else if(n==3)
         {
             login l;
             l.process();
         }
    }
}
