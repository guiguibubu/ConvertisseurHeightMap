#ifndef TOOLS_PROJET

#define TOOLS_PROJET

#include <iostream> 
#include <string>
#include <bitset>

namespace PM3D {

   template<class T> void printIntoStream(std::ostream& stream, T n, bool retourLigne) {
      (retourLigne) ? stream << n << std::endl : stream << n;
   }

   template<class T> void printIntoStream(std::ostream& stream, T n) {
      printIntoStream(stream, n, true);
   }

}
#endif

