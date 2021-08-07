// Developed by -------- Jayanta Paul
// Date ---------------  02/05/2021
// Question Link ------------ https://www.codechef.com/problems/CIELRCPT    

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int items_price[11];
  int userPrice;
  double temp;
  int current_price;
  int items_count[11];
  int count = 0;
  //items name
  string no_of_items[] = {

      "eel flavored water",
      "deep-fried eel bones",
      "clear soup made with eel livers	",
      "grilled eel livers served with grated radish	",
      "savory egg custard with eel	",
      "eel fried rice (S)	",
      "eel fried rice (L)	",
      "grilled eel wrapped in cooked egg	",
      "eel curry rice	",
      "grilled eel over rice	",
      "deluxe grilled eel over rice	",
      "eel full-course	"

  };

  //taking the price of each items
  for (int i = 0; i <= 11; i++)
  {
    items_price[i] = pow(2, i);
    cout << items_price[i] << endl;
  }

  //getting user price
  cout << "Enter your total price ";
  cin >> temp;
  userPrice = int(temp);
  // main calculation

  for (int i = 11; i >= 0; i--)
    {items_count[i]=0;
      if( userPrice % items_price[i] >=0){
      count = userPrice / items_price[i];
      userPrice -= count * items_price[i];
      items_count[i]=count;
      }
      count=0;
      // cout << "User current price " << userPrice << endl;
    }

  cout << "Your balance is " << userPrice << endl;
   cout << "You orders are "<<endl;
  for(int i=0;i<=11;i++){
   if(!items_count[i]==0){
     cout << "Name : "<<no_of_items[i]<<" No is "<<items_count[i] <<endl;
   }
  }

  return 0;
}