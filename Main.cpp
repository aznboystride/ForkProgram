#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
  char user_choice[50];
  cout << "[+] Enter String To Replace Followed By Replacement String: ";
  cin >> user_choice;
  pid_t pid = fork();
  while(strcmp(user_choice, "!wq")) {
    if(!pid) {
      // write child code
    } else {
      cout << "[+] Enter String To Replace Followed By Replacement String: ";
      cin >> user_choice;
    }
  }
  return 0;
}
