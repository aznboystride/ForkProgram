#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

void replace(string&, string&, string&);

int main(int argc, char** argv)
{
  if(argc != 2) {
    cout << "[!]Enter a file path to edit\n";
    exit(-1);
  }

  string user_choice;
  cout << "[+] Enter String To Replace Followed By Replacement String: ";
  getline(cin, user_choice);
  pid_t pid = fork();
  while(user_choice != "!wq") {
    if(!pid) {
      // write child code
    } else {
      cout << "[+]Enter String To Replace Followed By Replacement String: ";
      getline(cin, user_choice);
    }
  }
  return 0;
}

void replace(string& str, string& rep, string& path) {
  
}
