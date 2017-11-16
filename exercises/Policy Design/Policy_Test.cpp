/*
 * policy-test.cc
 */
#include <iostream>
#include "smart_pointer.h"
#include "testutils.icc"
using namespace std;

/*#ifdef ALLOW_CONVERSION
   typedef smart_pointer<X, allow_conversion> Smart_Pointer;
#else
   typedef smart_pointer<X, disallow_conversion> Smart_Pointer;
#endif

*/int main()
{
   Smart_Pointer sp1;

   Smart_Pointer sp2(new X(1));  // One X is created here.

   Smart_Pointer sp3(sp2);       // An X is copied here (we now have two X).

   cout << "sp2->get_m(): " << sp2->get_m() << endl;
   cout << "sp3->get_m(): " << sp3->get_m() << endl;

   sp1 = sp3;                    // An X is copied here (we now have three X).

   cout << "sp3->get_m(): " << sp3->get_m() << endl;
   cout << "sp1->get_m(): " << sp1->get_m() << endl;
   cout << "sp2->get_m(): " << sp2->get_m() << endl;

   X* xp = sp1;  // not allowed if 'disallow_conversion'

   cout << "xp->get_m(): " << xp->get_m() << endl;

   return 0;                     // Three X are now to be destructed.
}
