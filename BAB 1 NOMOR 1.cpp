#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {
    int index = 0;
    int n = chars.size();

    for(int i = 0; i < n;) {
        char currentChar = chars[i];
        int count = 0;

        while(i < n && chars[i] == currentChar) {
            count++;
            i++;
        }
        chars[index++] = currentChar;

        if(count > 1) {
            string countStr = to_string(count);
            for(char c : countStr) {
                chars[index++] = c;
            }
        }
    }
    return index;
}
    int main () {
        vector<char>chars = {'a','a','b','b','c','c','c'};
        int length = compress(chars);

        cout << "Panjang Array setelah Kompresi " << length << endl;
        cout << "Array setelah Kompresi: ";
        for(int i = 0; i < length; i++) {
            cout << chars[i] << " ";
        }
        cout << endl;
        return 0;
    }
