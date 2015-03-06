#include <string>
#include <cstring>

class word_input{
	private:
		string pl;
		string en;
		string fr;
	public:
		word_input(string a, string b, string c);
		~word_input();
		void showMeaning();
};