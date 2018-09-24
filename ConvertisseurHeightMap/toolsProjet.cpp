#include "toolsProjet.h"
#include <string>
namespace PM3D {

   void printIntoStream(std::ostream& stream, std::string text) {
      stream << text << std::endl;
   }

   void convertFloatIntoBinary(float number) {
      char* bits = reinterpret_cast<char*>(&number);
      long result = bits[sizeof number];
      for (std::size_t n = (sizeof number) -1; n > 0; --n) {
         result = (result << 8) | bits[n];
      }
      std::cout << std::bitset<32>(result) << std::endl;
      for (std::size_t n = 0; n < sizeof number; ++n) {
         std::cout << std::bitset<8>(bits[n]);
      }
      std::cout << std::endl;

      std::cout << std::bitset<sizeof(float) * CHAR_BIT>(number) << std::endl;

   }

   //float convertBinaryIntoFloat

}