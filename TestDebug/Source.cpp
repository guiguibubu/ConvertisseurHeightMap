#include <iostream>    
#include <stdio.h>
#include <direct.h>
#include <iostream>
#include <string>

using namespace std; 

std::string current_working_directory()
{
   char* cwd = _getcwd(0, 0); // **** microsoft specific ****
   std::string working_directory(cwd);
   std::free(cwd);
   return working_directory;
}

int main() {
   std::cout << "i am now in " << current_working_directory() << endl;

   cout << "\n";
   cout << "--------------------------------------------" << endl;
   cout << "Appuyer sur 'Enter' pour fermer le programme" << endl;
   cout << "--------------------------------------------" << endl;
   string reponse;
   getline(cin, reponse);
   return 0;
}