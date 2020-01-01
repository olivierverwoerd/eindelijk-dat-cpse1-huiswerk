#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main( int argc, char **argv ){
      string line;
      ifstream myfile (argv[ 2 ]);
      getline (myfile,line);
      cout 
      << "#include  \"converter.hpp\"\n"
      << "const char * " << argv[ 1 ] << "(){\n"
      << "   return \"" << line << "\";\n"
      << "}\n";
}