#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
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

	/*for ( string word; ifs >> word; )
	{
		bool found {};
		for ( st i {}; i < words.size(); ++i )
		{
			if ( word == words.at(i) )
			{
				found = true;
				break;
			}
		}
		if ( ! found )
			words.push_back(word);	
			}*/
	std::copy_if(std::istream_iterator<std::string>(ifs),std::istream_iterator<std::string>(),std::back_inserter(words),[&words](const std::string& word){ return std::find(begin(words),end(words),word) == end(words);});

	cout << "All unique words: ";

	/*for ( st i {}; i < words.size(); ++i )
	{
		cout << words.at(i) << "\n";
		}*/
	std::copy(begin(words),end(words),std::ostream_iterator<string>(std::cout,", ")
		  );
	std::cout << "\n"; 
	std::sort(begin(words), end(words),
		  [](std::string const & w1, std::string const & w2)
			{
				return !(w2.length() > w1.length() || 
					(w2.length() == w1.length() && w2 > w1));
			});
	  /*[](string const s1, string const s2)
		  {return (w2.length() > w1.length() || 
	  		   (w2.length() == w1.length() && w2 > w1));})
	/*for ( st i {}; i < words.size(); ++i )
	{
		for ( auto j = words.size() - 1; j > i; --j )
		{
			auto & w1 = words.at(i);
			auto & w2 = words.at(j);
			if (w2.length() > w1.length() || (w2.length() == w1.length() && w2 > w1))
				std::swap(w1, w2);
		}
	}
	*/
	cout << "Sorted: ";

	/*for ( st i {}; i < words.size(); ++i )
	{
		cout << words.at(i) << " ";
		}*/
	std::copy(begin(words), end(words), std::ostream_iterator<std::string>(std::cout," "));
	std::string all = std::accumulate(words.begin(), words.end(), std::string{});
	std::cout << all;
	return 0;
}


