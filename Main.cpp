#include <iostream>
#include <sys/types.h>

using namespace std;

int main()
{
  char user_choice[50];
  cout << "[+] Enter String To Replace Followed By Replacement String: ";
  cin >> user_choice;
  while(strcmp(user_choice, "!wq")) {
    cout << "[+] Enter String To Replace Followed By Replacement String: ";
    cin >> user_choice;
  }
  return 0;
}
