#include<iostream>
#include<string.h>
using namespace std;

class game{
    private:
        int players;
        char dis;
        string type;
    public:
        void check_type();
        void indoor();
        void outdoor();
};

void game :: check_type()
{
    cout << "Outdoor Or Indoor Game ?"<<endl;
    cin >> dis;
    if(dis=='i' || dis=='I')
    {
        indoor();
    }
    else
    {
        outdoor();
    }
} 

void game :: outdoor()
{
    cin.ignore('\n',10);
    cout << "Your game need more than 10 players"<<endl;
    cin >> dis;
    if(dis =='y' || dis == 'Y')
    {
        cout << "Depends on Time"<<endl;
        cin >> dis;
        if(dis == 'y' || dis == 'Y')
        {
            cout << "Using Stick ?"<<endl;
            cin >> dis ;
            if(dis == 'y' || dis == 'Y')
            {
                cout << "Congratulation , I found your game \n Your Game is Hocky"<<endl;
                exit(0);
            }
            else
            {
                cout << "Congratulation , I found your game \n Your Game is Football"<<endl;
                exit(0);
            }
            
            //Hocky or Football
        }
        else
        {
            cout << "Congratulation , I found your game \n Your Game is Cricket"<<endl;
            exit(0);
        }
        
        
    }
    else
    {
            cout << "Small Area or Big Area"<< endl ;
            cin >> dis;
            if(dis == 's' || dis == 'S')
            {
                cout << "Congratulation , I found your game \n Your Game is Table Tenis"<<endl;
                exit(0);
            }
            else
            {
               cout << "Congratulation , I found your game \n Your Game is Badminton"<<endl;
               exit(0);
            }
            
    }
    
}


void game :: indoor()
{
    cin.ignore('\n',10);
    cout << "Single Players Or Multiple players"<<endl;
    cin >> dis;
    if(dis == 'm' || dis == 'M')
    {
        cout << "Intelligence or Skill or Luck" <<endl;
        cin >> dis;
        if(dis == 'i' || dis =='I')
        {
            cout << "Congratulation , I found your game \n Your Game is Chess"<<endl;
        }
        else if(dis == 's' || dis == 'S')
        {
            cout << "Congratulation , I found your game \n Your Game is Caram"<<endl;
        }
        else
        {
            cout << "Releated to money"<< endl;
            cin >> dis;
            if(dis == 'y' || dis=='Y')
            {
                cout << "Congratulation , I found your game \n Your Game is Business Game"<<endl;
            }
            else
            {
                cout << "Congratulation , I found your game \n Your Game is Ludo"<<endl;
            }
            
        }
        
    }
    else
    {
        cout << "Congratulation , I found your game \n Your Game is PC game"<<endl;
    }
    
}

int main()
{
    char dic;
    game g;
    cout << "|------------------------------------------------------------|"<< endl;
    cout << "|--------------|  Hi, Welcome To The Game |------------------|"<< endl;
    cout << "|------------------------------------------------------------|"<< endl;
    cout << "Choose any game below of these ?"<<endl;
    cout << "1.Cricket\n2.Hocky\n3.Football\n4.Table Tenis\n5.Batminton\n6.Chess\n7.Ludo\n8.Caram\n9.PC game\n10.Business Game"<<endl;
    cout << "If you choose then you put Ready to beign this game otherwise you can stop " << endl;
    cin >> dic;
    (dic == 'R' || dic == 'r') ? g.check_type() : exit(0);
    return 0;
}