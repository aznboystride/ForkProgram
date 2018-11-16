#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int replace(const char*, const char*, const char*);

int main(int argc, char** argv) {

  if(argc != 2) {
    printf("Usage: %s <path>", argv[0]);
    exit(1);
  }
  // std::fstream fs(argv[1], std::ios::in);
  // if(fs.fail()) {
  //   std::cout << "Failure opening file: " << argv[1] << "\n";
  //   exit(1);
  // }
  // fs.close();

  // int numOfReplacement;
  // std::string toReplace, replaceWith;

  // while(true) {

  //   std::cout << "Enter string to replace or !wq to quit: "; 
  //   getline(std::cin, toReplace);

  //   if(toReplace == "!wq")
  //     break; // loop ends after user types in '!wq'
    
  //   std::cout << "Enter string replacement: ";
  //   getline(std::cin, replaceWith);
    
  //   if(fork()) // creats child process
  //     wait(NULL); // Wait for child process to terminate
  //   else {
  //     while(!(numOfReplacement = replace(toReplace, replaceWith, argv[1]))) // Inserted bug
  //       std::cout << ".";
  //     std::cout << "Replaced " << numOfReplacement << " occurences\n";
  //     return 0;
  //   }
  // }
  return 0;
}

/**
 * This function opens a file specified by the string variable 'path',
 * and replaces every occurence of string contained in the variable 'str' in that file  
 * with string 'rep'
 */
int replace(const char* str, const char* rep, const char* path) {
	
  return 0;
}

