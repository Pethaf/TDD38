#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]) 
{

	if ( argc != 2 )
	{
		cerr << "Call as \"" << argv[0] << " input_file\"\n";
		return 1;
	}

	vector<string> words;

	using st = vector<string>::size_type;

	ifstream ifs {argv[1]};

	if (!ifs)
 	{
		cerr << "Couldn't open file \"" << argv[1] << "\" exiting!\n";
		return 2;
	}

	//Boiler plate to setup input/output

	//Copying all words from file using copy

	copy_if(istream_iterator<string>(ifs),
             istream_iterator<string>(),
		back_inserter(words),
		[&words](string const & s) { return find(begin(words),end(words),s) == end(words);});

	cout << "All unique words: "; 
	copy(begin(words),end(words),std::ostream_iterator<string> (std::cout, "\n"));
	cout << "Sorted: ";
	sort(begin(words),end(words),[](const string& s1, const string& s2){ return !(s2.length() > s1.length()        || (s2.length() == s1.length() && s2 > s1));});
	copy(begin(words),end(words),std::ostream_iterator<string> (std::cout, "\n"));
	string all { accumulate(begin(words),end(words),string{})};
	cout << "\n\nOne long string: " << all << endl;
	return 0;
}
