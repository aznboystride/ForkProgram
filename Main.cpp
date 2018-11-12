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

  pid_t pid = fork();

  while(true) {
    if(!pid) {
      // write child code
    } else {
      cout << "[+]Enter String To Replace Followed By Replacement String: ";
      getline(cin, user_choice);
      if(user_choice == "!wq") {
        break;
      }
      size_t spacepos = user_choice.find(" ");
      int count = replace(user_choice.substr(0, spacepos), user_choice.substr(spacepos+1, user_choice.length()), argv[1]);
      cout << count << endl;
    }
  }
  return 0;
}

int replace(string str, string rep, string path) {
  fstream fs(path, ios::in);
  string contents, line;
  int count = 0;
  if(fs.fail()) {
    cerr << "[!] Failure opening " << path << endl;
    exit(-1);
  }
  while(getline(fs, line)) {
    contents += (line + "\n");
  }
  
  size_t pos = contents.find(str);
  while(pos != string::npos) {
    contents.replace(pos, str.length(), rep);
    pos = contents.find(str);
    count++;
  }
  fs.close();

  fs.open(path, ios::out);
  if(fs.fail()) {
    cerr << "[!] Failure opening " << path << endl;
    exit(-1);
  }
  fs << contents;
  fs.close();
  return count;
}
