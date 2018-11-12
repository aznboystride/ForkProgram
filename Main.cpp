#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int replace(string, string, string);

int main(int argc, char** argv)
{
  if(argc != 2) {
    cout << "[!]Enter a file path to edit\n";
    exit(-1);
  }

  string user_choice;

  pid_t pid = fork(); // Creates a child process

  while(true) {
    if(!pid) { // Child process executes code here
      // write child code
    } else { // Parent process executes code here
      cout << "[+]Enter String To Replace Followed By Replacement String: ";
      getline(cin, user_choice);
      if(user_choice == "!wq") {
        break; // loop ends after user types in '!wq'
      }

      size_t spacepos = user_choice.find(" ");
      int count = replace(user_choice.substr(0, spacepos), user_choice.substr(spacepos+1, user_choice.length()), argv[1]); // Count of replacements in file
      cout << count << endl;
    }
  }
  return 0;
}

/**
 * This function opens a file specified by the string 'path',
 * and replaces every occurence of string 'str' in that file  
 * with string 'rep'
 */
int replace(string str, string rep, string path) {
  fstream fs(path, ios::in);
  string contents, line;
  int count = 0;
  if(fs.fail()) {
    cerr << "[!]Failure opening " << path << endl;
    exit(-1);
  }
  while(getline(fs, line)) {
    contents += (line + "\n");
  }
  
  size_t pos;
  while(pos = contents.find(str) != string::npos) {
    contents.replace(pos, str.length(), rep);
    count++;
  }
  fs.close();

  fs.open(path, ios::out);
  if(fs.fail()) {
    cerr << "[!]Failure opening " << path << endl;
    exit(-1);
  }
  fs << contents;
  fs.close();
  return count;
}
