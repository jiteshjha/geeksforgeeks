#include <bits/stdc++.h>

using namespace std;

string look_and_say(int num) {
    if(num == 1) return "1";
    if(num == 2) return "11";

    string str = "11";
    for(int i = 3; i <= num; i++) {
        str += '$';
        string temp = "";
        int cnt = 1;
        for(int j = 1; j < str.length(); j++ ) {
            if(str[j-1] != str[j]) {
                temp += cnt + '0';
                temp += str[j-1];
                cnt = 1;
            }
            else
                cnt++;
        }
        str = temp;
    }
    return str;
}

int main() {
    cout<<look_and_say(5);
    return 0;
}
