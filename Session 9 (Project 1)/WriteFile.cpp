#include <iostream>
#include <fstream>

///To write to the file, use the insertion operator (<<).

using namespace std;

int main() {
  // Create and open a text file
  ofstream MyFile("filename.txt");

  // Write to the file
  MyFile << "Files can be tricky, but it is fun enough!";
  MyFile << endl;
  MyFile << "Today is Friday! \n";
  MyFile << "123\t456\t789\n";

  MyFile << 987654321<<endl;
  MyFile << 1.234<<endl;

  // Close the file
  MyFile.close();
}
