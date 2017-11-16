#include <curses.h>
#include <iostream>
class Window
{
public:
  void 
private:
  WINDOW* win = nullptr;
  int curs_status {1}; 
}

int main()
try 
{
	WINDOW * win = initscr();             // Initialize a curses-window
	curs_set(0);                          // Disable the cursor

	// No changes in the following block!
	{
		const int start_x {10};
		const int start_y {10};
		const int columns {10};
		wmove(win, start_y, start_x - 1);      // Move to a given position in a window
		wechochar(win, '>');                   // Print a char in window
		wmove(win, start_y, start_x + columns);
		wechochar(win, '<');

		for ( int i {}; i < 3 * columns; ++i )
		{
			int x_pos = start_x + i % columns;
			wmove(win, start_y, x_pos); 
			wechochar(win, '*');       
			napms(200);                         // Wait for 200ms
			wmove(win, start_y, x_pos);
			wechochar(win, ' ');
		}
		wmove(win, start_y + 2, start_x - 1);
		waddstr(win, "Done, exiting");          // Print string to window
		wrefresh(win);					        // Update window
		napms(1500);
	}
	// Changes allowed below

	// throw 1;   // uncomment this line to get "intresting" behavior (an error without reseting graphical mode)

	curs_set(1);					
	endwin();						// exit graphical mode
	delwin(win);					// release memory used by window
}
catch ( ... )
{
	std::cerr << "Some error in main!\n";
}
