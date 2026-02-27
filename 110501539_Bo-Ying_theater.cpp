#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int seat[15]={0};
int sel;
int i;
char ans;
string username;
string pass;
string phoneno;
string member[15];
string pw[15];
string phone[15];
string filename;
fstream file;
string na, pa, ma;
int cou=0;
int selec;
string username1;
void show_member ()
{
    cout << "\n***NCU Theater Membership***"<< endl;
    if (member[0].empty()==0)
    {
        cout << "No.  Username"<< endl;
        for (int w=0 ; w<15 ; w++)
        {
            if (member[w].empty()==0 && w<9)
            {
                cout << w+1<< ".   "<<member[w]<< endl;
            }
            else if (member[w].empty()==0 && w>=9)
            {
                cout << w+1<< ".  "<<member[w]<< endl;
            }
        }
    }
}
void Member()
{
    while (1)
    {
        cout << "*** Welcome to NCU theater reservation system ***" << endl;
        cout << "***Welcome back "<<username<<"***" << endl;
        cout << "Please type 1 to make a new reservation" << endl;
        cout << "Please type 2 to cancel an existing reservation" << endl;
        cout << "Please type 3 to show the all available seats" << endl;
        cout << "Please type 4 to show the status of all current seats" << endl;
        cout << "Please type 5 to log-out" << endl;
        cout << "Please type 6 to show member" << endl;
        cout << "Please type 7 to load member information" << endl;
        cout << "Please type 8 to change member data" << endl;
        cout << "Please type 9 to find member data" <<endl;
        cout << "Please type 10 to exit the system" << endl;
        cout << "Enter your selection Here: ";
        cin >>sel;
        while (sel!=1 && sel!=2 && sel!=3 && sel!=4 && sel!=5 && sel!=6 && sel!=7 && sel!=8 && sel!=9 && sel!=10 || cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Invalid input, please enter your selection again: ";
            cin >>sel;
        }
        if (sel==10)
        {
            cout << "\nThank you for using our system\nHave a nice day~~";
            break;
        }
        else if (sel==1)
        {
            cout << "\n***Make a new reservation***\nDo you need a specified seat? (y/n) ";
            cin >>ans;
            if (ans!='y' && ans!='n')
            {
                cout << "Invalid input, please enter your selection again: ";
                cin >>ans;//prob wrong
            }
            if (ans=='y')
            {
                cout << "Enter the seat number: ";
                cin >>i;
                while (i>15 || i<1 || cin.fail())
                {
                    cin.clear();
                    cin.sync();
                    cout << "Invalid input, please enter your selection again: ";
                    cin >>i;
                }
                while (seat[i-1]!=0)
                {
                    cout << "The seat has been reserved, please enter your selection again: ";
                    cin >>i;
                }
                seat[i-1]=10;
                cout << "The seat number "<<i<<" is reserved for you...\n"<< endl;
            }
            else if (ans=='n')
            {
                for (i=1 ; i<16 ; i++)
                {
                    if (seat[i-1]!=10)
                    {
                        cout << "The seat number "<<i<<" is reserved for you...\n" << endl;
                        seat[i-1]=10;
                        break;
                    }
                }


            }
        }
        else if (sel==2)
        {
            cout << "\n***Cancel an existing reservation***\nPlease enter the seat number which you want to cancel: ";
            cin >>i;
            if (seat[i-1]==0)
            {
                cout << "The seat is not reserved\n" << endl;

            }
            else
            {
                seat[i-1]=0;
                cout << "The seat number "<<i<<" is available now...\n" << endl;
            }
        }
        else if (sel==3)
        {
            cout << "\n***Show the all available seats***" << endl;
            for (i=1 ; i<16 ; i++)
            {
                if (seat[i-1]==0)
                {
                    cout << "seat "<<i<<endl;
                }
            }
            cout << "\n";
        }
        else if (sel==4)
        {
            cout << "\n***Show the status of all seats***" << endl;
            cout << "Seat number       Status" << endl;
            for (i=1 ; i<10 ; i++)
            {
                if (seat[i-1]==10)
                    cout << "Seat "<<i<<"            reserved" << endl;
                else if (seat[i-1]==0)
                    cout << "Seat "<<i<<"            available" << endl;
            }
            for (i=10 ; i<16 ; i++)
            {
                if (seat[i-1]==10)
                    cout << "Seat "<<i<<"           reserved" << endl;
                else if (seat[i-1]==0)
                    cout << "Seat "<<i<<"           available" << endl;
            }
            cout << "\n";
        }
        else if (sel==5)
        {
            cout << endl;
            break;
        }
        else if (sel==6)
        {
            show_member();
            if (member[0].empty() )
            {
                cout << "No Member."<< endl;
            }
            cout << "\n";
        }
        else if (sel==7)
        {
            cout << "\n***Load member information***"<< endl;
            cout << "Please enter the member file name: ";
            cin >>filename;
            file.open(filename,ios::in);
            if (!file)
            {
                cout << "File could not be opened.\n"<< endl;
            }
            else
            {
                cout << "The file "<<filename<<" has been loaded...\n"<< endl;
            }
            file >>na >>pa >>ma;
            while (file >>member[cou]>>pw[cou]>>phone[cou])
            {
                cou++;
            }

        }
        else if (sel==8)
        {
            cout << "\n***Change member data***"<< endl;
            cout << "Please type 1 to change password"<< endl;
            cout << "Please type 2 to change phone number"<< endl;
            cout << "Enter your selection Here: ";
            cin>>selec;
            while (selec!=1 && selec!=2)
            {
                cout << "Invalid input, please enter your selection again: ";
                cin >>selec;
            }
            cout << "Enter Username: ";
            cin >>username1;
            cout << "Enter Password: ";
            cin >>pass;
            for (int z=0; z<15; z++)
            {
                if (username1==member[z] && pass==pw[z] && selec==1)
                {
                    cout << "Enter the new password: ";
                    cin >>pass;
                    pw[z]=pass;
                    break;
                }
                if (username1==member[z] && pass==pw[z] && selec==2)
                {
                    cout << "Enter the new phone number: ";
                    cin >>phoneno;
                    phone[z]=phoneno;
                    break;
                }
                else if (z==14 && pass!=pw[14])
                {
                    cout << "The username and the password don't match."<< endl;
                }
                else if (z==14 && username1!=member[14])
                {
                    cout << "The username and the password don't match."<< endl;
                }
            }
            cout << "\n";
        }
        else if (sel==9)
        {
            string key;
            cout << "\n***Find member data***"<< endl;
            cout << "Please enter the search keyword: ";
            cin >>key;
            cout << "\nThe searching keyword is \""<<key<<"\"..."<< endl;
            if (member[0].find(key)!=string::npos || member[1].find(key)!=string::npos || member[2].find(key)!=string::npos || member[3].find(key)!=string::npos || member[4].find(key)!=string::npos || member[5].find(key)!=string::npos || member[6].find(key)!=string::npos || member[7].find(key)!=string::npos || member[8].find(key)!=string::npos || member[9].find(key)!=string::npos ||  member[10].find(key)!=string::npos ||  member[11].find(key)!=string::npos ||  member[12].find(key)!=string::npos || member[13].find(key)!=string::npos ||  member[14].find(key)!=string::npos)
            {
                cout << "The searching results are as follows:"<< endl;
                cout << "*** Customer Information ***" <<endl;
                cout << "Name       Password       Phone"<< endl;
            }
            else
            {
                cout << "\nWe cannot find the keyword." <<endl;
            }
            for (int i=0 ; i<15 ; i++)
            {
                if (member[i].find(key)!=string::npos)
                {
                    cout <<left<<setw(11)<<member[i]<<left<<setw(15)<<pw[i]<<phone[i]<<endl;
                }
            }
            cout << "\n";
        }
    }


}

int main()
{
    char ans1,ans2;
    while (1)
    {
        if (sel==10)
            break;
        cout << "*** Welcome to NCU theater reservation system ***" << endl;
        cout << "Please type 1 to make a new reservation" << endl;
        cout << "Please type 2 to cancel an existing reservation" << endl;
        cout << "Please type 3 to show the all available seats" << endl;
        cout << "Please type 4 to show the status of all current seats" << endl;
        cout << "Please type 5 to member center" << endl;
        cout << "Please type 6 to show member" << endl;
        cout << "Please type 7 to load member information" << endl;
        cout << "Please type 8 to change member data" << endl;
        cout << "Please type 9 to find member data" <<endl;
        cout << "Please type 10 to exit the system" << endl;
        cout << "Enter your selection Here: ";
        cin >>sel;
        while (sel!=1 && sel!=2 && sel!=3 && sel!=4 && sel!=5 && sel!=6 && sel!=7 && sel!=8 && sel!=9 && sel!=10 || cin.fail())
        {
            cin.clear();
            cin.sync();
            cout << "Invalid input, please enter your selection again: ";
            cin >>sel;
        }
        if (sel==10)
        {
            cout << "\nThank you for using our system\nHave a nice day~~";
            break;
        }
        else if (sel==1)
        {
            cout << "\n***Make a new reservation***\nDo you need a specified seat? (y/n) ";
            cin >>ans;
            if (ans!='y' && ans!='n')
            {
                cout << "Invalid input, please enter your selection again: ";
                cin >>ans;//prob wrong
            }
            if (ans=='y')
            {
                cout << "Enter the seat number: ";
                cin >>i;
                while (i>15 || i<1 || cin.fail())
                {
                    cin.clear();
                    cin.sync();
                    cout << "Invalid input, please enter your selection again: ";
                    cin >>i;
                }
                while (seat[i-1]!=0)
                {
                    cout << "The seat has been reserved, please enter your selection again: ";
                    cin >>i;
                }
                seat[i-1]=10;
                cout << "The seat number "<<i<<" is reserved for you...\n"<< endl;
            }
            else if (ans=='n')
            {
                for (i=1 ; i<16 ; i++)
                {
                    if (seat[i-1]!=10)
                    {
                        cout << "The seat number "<<i<<" is reserved for you...\n" << endl;
                        seat[i-1]=10;
                        break;
                    }
                }
            }
        }
        else if (sel==2)
        {
            cout << "\n***Cancel an existing reservation***\nPlease enter the seat number which you want to cancel: ";
            cin >>i;
            if (seat[i-1]==0)
            {
                cout << "The seat is not reserved\n" << endl;

            }
            else
            {
                seat[i-1]=0;
                cout << "The seat number "<<i<<" is available now...\n" << endl;
            }
        }
        else if (sel==3)
        {
            cout << "\n***Show the all available seats***" << endl;
            for (i=1 ; i<16 ; i++)
            {
                if (seat[i-1]==0)
                {
                    cout << "seat "<<i<<endl;
                }
            }
            cout << "\n";
        }
        else if (sel==4)
        {
            cout << "\n***Show the status of all seats***" << endl;
            cout << "Seat number       Status" << endl;
            for (i=1 ; i<10 ; i++)
            {
                if (seat[i-1]==10)
                    cout << "Seat "<<i<<"            reserved" << endl;
                else if (seat[i-1]==0)
                    cout << "Seat "<<i<<"            available" << endl;
            }
            for (i=10 ; i<16 ; i++)
            {
                if (seat[i-1]==10)
                    cout << "Seat "<<i<<"           reserved" << endl;
                else if (seat[i-1]==0)
                    cout << "Seat "<<i<<"           available" << endl;
            }
            cout << "\n";
        }
        else if (sel==5)
        {

            cout << "\n***NCU Theater Member Center***"<< endl;
            cout << "Do you have the membership? (y/n) ";
            cin >>ans1;
            if (ans1=='y')
            {
                cout << "Enter Username: ";
                cin >>username;
                cout << "Enter Password: ";
                cin >>pass;
                for (int z=0;z<15;z++)
                {
                    if (username==member[z] && pass==pw[z])
                    {
                        cout << endl;
                        Member();
                        break;
                    }
                    else if (z==14 && username!=member[14] && pass!=pw[14])
                    {
                        cout << "The username and the password don't match.\n"<< endl;
                    }
                    else if (z==14 && pass!=pw[14])
                    {
                        cout << "The username and the password don't match.\n"<< endl;
                    }
                    else if (z==14 && username!=member[14])
                    {
                        cout << "The username and the password don't match.\n"<< endl;
                    }
                }
            }
            else if (ans1=='n')
            {
                cout << "Would you like to sign up? (y/n) ";
                cin >>ans2;
                if (ans2=='y')
                {
                    cout << "Enter Username: ";
                    cin >>username;
                    for (int x=0; x<15; x++)
                    {
                        if (member[x].empty())
                        {
                            member[x]=username;
                            break;
                        }
                    }
                    cout << "Enter Password: ";
                    cin >>pass;
                    for (int y=0; y<15; y++)
                    {
                        if (pw[y].empty())
                        {
                            pw[y]=pass;
                            break;
                        }
                    }
                    cout << "Enter Phone number: ";
                    cin >>phoneno;
                    for (int y=0; y<15; y++)
                    {
                        if (phone[y].empty())
                        {
                            phone[y]=phoneno;
                            break;
                        }
                    }
                    cout << "Welcome! You are now a member of NCU theater.\nPlease log in again.\n"<< endl;
                }
                else if (ans2=='n')
                {
                    cout << "Okay! Have a nice day.\n"<< endl;
                }
            }
        }
        else if (sel==6)
        {
            show_member();
            if (member[0].empty() )
            {
                cout << "No Member."<< endl;
            }
            cout << "\n";
        }
        else if (sel==7)
        {
            cout << "\n***Load member information***"<< endl;
            cout << "Please enter the member file name: ";
            cin >>filename;
            file.open(filename,ios::in);
            if (!file)
            {
                cout << "File could not be opened.\n"<< endl;
            }
            else
            {
                cout << "The file "<<filename<<" has been loaded...\n"<< endl;
            }
            file >>na >>pa >>ma;
            while (file >>member[cou]>>pw[cou]>>phone[cou])
            {
                cou++;
            }

        }
        else if (sel==8)
        {
            cout << "\n***Change member data***"<< endl;
            cout << "Please type 1 to change password"<< endl;
            cout << "Please type 2 to change phone number"<< endl;
            cout << "Enter your selection Here: ";
            cin>>selec;
            while (selec!=1 && selec!=2)
            {
                cout << "Invalid input, please enter your selection again: ";
                cin >>selec;
            }
            cout << "Enter Username: ";
            cin >>username;
            cout << "Enter Password: ";
            cin >>pass;
            for (int z=0; z<15; z++)
            {
                if (username==member[z] && pass==pw[z] && selec==1)
                {
                    cout << "Enter the new password: ";
                    cin >>pass;
                    pw[z]=pass;
                    break;
                }
                if (username==member[z] && pass==pw[z] && selec==2)
                {
                    cout << "Enter the new phone number: ";
                    cin >>phoneno;
                    phone[z]=phoneno;
                    break;
                }
                else if (z==14 && pass!=pw[14])
                {
                    cout << "The username and the password don't match."<< endl;
                }
                else if (z==14 && username!=member[14])
                {
                    cout << "The username and the password don't match."<< endl;
                }
            }
            cout << "\n";
        }
        else if (sel==9)
        {
            string key;
            cout << "\n***Find member data***"<< endl;
            cout << "Please enter the search keyword: ";
            cin >>key;
            cout << "\nThe searching keyword is \""<<key<<"\"..."<< endl;
            if (member[0].find(key)!=string::npos || member[1].find(key)!=string::npos || member[2].find(key)!=string::npos || member[3].find(key)!=string::npos || member[4].find(key)!=string::npos || member[5].find(key)!=string::npos || member[6].find(key)!=string::npos || member[7].find(key)!=string::npos || member[8].find(key)!=string::npos || member[9].find(key)!=string::npos ||  member[10].find(key)!=string::npos ||  member[11].find(key)!=string::npos ||  member[12].find(key)!=string::npos || member[13].find(key)!=string::npos ||  member[14].find(key)!=string::npos)
            {
                cout << "The searching results are as follows:"<< endl;
                cout << "*** Customer Information ***" <<endl;
                cout << "Name       Password       Phone"<< endl;
            }
            else
            {
                cout << "\nWe cannot find the keyword." <<endl;
            }
            for (int i=0 ; i<15 ; i++)
            {
                if (member[i].find(key)!=string::npos)
                {
                    cout <<left<<setw(11)<<member[i]<<left<<setw(15)<<pw[i]<<phone[i]<<endl;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
