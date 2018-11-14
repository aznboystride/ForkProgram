#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>

int replace(std::string, std::string, const char*);

int main(int argc, char** argv) {

  if(argc != 2) {
    printf("Usage: %s <path>\n", argv[0]);
    exit(1);
  }
  std::fstream fs(argv[1], std::ios::in);
  if(fs.fail()) {
    printf("Failure opening file: %s\n", argv[1]);
    exit(1);
  }
  fs.close();

  pid_t pid;
  int numOfReplacement;
  std::string toReplace, replaceWith;

  while(true) {

    std::cout << "Enter string to replace or !wq to quit: "; 
    getline(std::cin, toReplace);

    if(toReplace == "!wq") {
      break; // loop ends after user types in '!wq'
    }
    
    std::cout << "Enter string replacement: ";
    getline(std::cin, replaceWith);
    
    if(pid = fork()) { // creats child process
      wait(NULL); // Wait for child process to terminate
    } else {
      while(!(numOfReplacement = replace(toReplace, replaceWith, argv[1]))) { // Inserted bug
        std::cout << "." << std::flush;
      }
      std::cout << "Replaced " << numOfReplacement << " occurences\n";
      return 0;
    }
  }
  return 0;
}

/**
 * This function opens a file specified by the string variable 'path',
 * and replaces every occurence of string contained in the variable 'str' in that file  
 * with string 'rep'
 */
int replace(std::string str, std::string rep, const char* path) {
	
  std::fstream fs(path, std::ios::in);
  std::string contents, line;
  int numOfReplacement = 0;
  size_t pos;

  while(getline(fs, line)) {
    contents += (line + "\n");
  }
  while((pos = contents.find(str)) != std::string::npos) {
    contents.replace(pos, str.length(), rep);
    numOfReplacement++;
  }
  fs.close();

  fs.open(path, std::ios::out);
  fs << contents;
  fs.close();
  
  return numOfReplacement;
}

