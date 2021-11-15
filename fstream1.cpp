#include <fstream>

int main() {

  // First we create an output stream object
  std::ofstream square_file;
  // We then open the file we write to
  square_file.open("square.txt");

  // Then we write to file
  for (int i = 0; i < 10; ++i) {
    // notice that cout is replaced with square_file
    square_file << i << "^2 = " << i * i << std::endl;
  }
  // Remember to close the file
  square_file.close();
}
