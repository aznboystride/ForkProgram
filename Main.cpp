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

  pid_t pid;
  int numOfReplacement = 0;
  std::string toReplace, replaceWith;

  while(true) {

	std::cout << "Enter string to replace or !wq to quit: "; 
	getline(std::cin, toReplace);

    if(toReplace == "!wq") {
      break; // loop ends after user types in '!wq'
    }
	
	std::cout << "Enter string replacement: ";
	getline(std::cin, replaceWith);
	
    pid = fork(); // Creates a child process
    if(pid) {
      wait(NULL); // Wait for child process to terminate
    } else {
      numOfReplacement = replace(toReplace, replaceWith, argv[1]); // Count of replacements in file
      while(!numOfReplacement) { // Inserted bug
		numOfReplacement = replace(toReplace, replaceWith, argv[1]);
		std::cout << "." << std::flush;
      }
      return 0;
    }
  }
  return 0;
}

/**
 * This function opens a file specified by the string 'path',
 * and replaces every occurence of string 'str' in that file  
 * with string 'rep'
 */
int replace(std::string str, std::string rep, const char* path) {
	
  std::fstream fs(path, std::ios::in);
  std::string contents, line;
  int numOfReplacement = 0;
  size_t pos;
  
  if(fs.fail()) {
    std::cerr << "[!]Failure opening " << path << "\n";
    exit(1);
  }
  while(getline(fs, line)) {
    contents += (line + "\n");
  }
  
  while((pos = contents.find(str)) != std::string::npos) {
    contents.replace(pos, str.length(), rep);
    numOfReplacement++;
  }
  fs.close();

  fs.open(path, std::ios::out);
  if(fs.fail()) {
    std::cerr << "[!]Failure opening " << path << "\n";
    exit(1);
  }
  
  fs << contents;
  fs.close();
  
  return numOfReplacement;
}

