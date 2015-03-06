#include <iostream>
//#include "class.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class word_input{
  public:
    string pl;
    string en;
    string fr;
  public:
    word_input();
    /* ~word_input(){
      cout<<"destruktor"<<endl;
    }
    */
    void showMeaning();
    int wordCompare(int tra, string given);
};
//word_input::~word_input();
word_input::word_input(){
  cout << "Wpisz polskie znaczenie: " << endl;
  cin >> pl;

  cout << "Enter english meaning: " << endl;
  cin >> en;

  cout << "Francois - lel: " << endl;
  cin >> fr;
}

void word_input::showMeaning(){
  cout<<"Polish meaning: "<<pl<<endl;
  cout<<"English meaning: "<<en<<endl;
  cout<<"French - lul: "<<fr<<endl;
}

int word_input::wordCompare(int tra, string given){
  if(tra==1) {
      return pl.compare(given);
  }
  else if(tra==2) {
      return en.compare(given);
  }
  else if(tra==3) {
        return fr.compare(given);
  }
}

ostream& operator<< (ostream &output, const word_input &i) {        
 output << i.pl<< ";" << i.en<< ";" <<  i.fr<< ";";                
}

istream& operator>> (istream &input, word_input &i) {       
 input >> i.pl;
 input >> i.en;
 input >> i.fr;
 return input;
}

int main(){
  vector<word_input> dict;
  int condition=1;
  int translation;
  while (condition){
    cout<<"1 - add word"<<endl<<"2 - search meaning"<<endl<<"3 - save to file" << endl << "4 - read from file" << endl << "0 - exit"<<endl;
    cin>>condition;

    if (condition == 1){
      word_input a;
      dict.push_back(a);
    }

    else if (condition == 2){
      cout<<"1 - polskie tlumaczenie"<<endl<<"2 - english translation"<<endl<<"3 - francois - lel"<<endl;
      cin>> translation;
      string wordTranslation;
      cout << "Type in the word to translate:" <<endl;
      cin >> wordTranslation;

      for(int i =0; i<dict.size(); i++){
        if (dict[i].wordCompare(translation, wordTranslation)==0){
          dict[i].showMeaning();
          break;
        } //if
      } //for
    } //else if
    else if (condition ==3){
      ofstream out;
      out.open("dictionary.txt");
      if (!out) { cout << "Error when opening the file to write" << endl; return 0;}
      for(int i=0; i<dict.size(); i++) { out << dict[i]; }
      out.close();     
    } //else if 3
    else if(condition == 4) {
       ifstream ins;
       ins.open("dictionary.txt");
      if (!ins) { cout << "Error when opening the file to read" << endl; return 0;}
      while(!ins.eof()) {word_input i; ins >> i; dict.push_back(i); }
      ins.close();
      dict.erase (dict.begin()+dict.size());
    }  // else if 4
  }//while (condition)
 return 0;
} //main