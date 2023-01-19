#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring_slow(string s) {
  int subLength;
  int longestSubLength = 0;
  set<char> charset;
  char prevChar;
  char searchChar;

  // cout << "string: " << s << "\n";


  if (s.length() <= 1)
    return s.length();

  // dvdf
  // pwwkew
  // bbbb
  // au

  prevChar = s[0];
  charset.insert(prevChar);
  subLength = 1;
  // cout << prevChar;

  for (long unsigned int i = 1; i < s.length(); i++) {

    // currenct character is same as previous character
    if (s[i] == prevChar) {
      if (longestSubLength < subLength)
        longestSubLength = subLength;

      // cout << " subLength: " << subLength << ". Same as prev char.\n";
      // cout << s[i];
      charset.clear();
      charset.insert(s[i]);
      subLength = 1;
    }
    else {
      prevChar = s[i];

      // new character so add to charmap
      if (charset.find(s[i]) == charset.end()) {
        charset.insert(s[i]);
        subLength++;
        // cout << s[i];
      }
      else {
        // character seen before
        // cout << " subLength: " << subLength << ". Char seen before.\n";
        if (longestSubLength < subLength)
          longestSubLength = subLength;

        searchChar = s[i];
        i--;
        while (s[i] != searchChar)
          i--;

        subLength = 0;
        prevChar = searchChar;
        charset.clear();
      }
    }
  }

  // cout << " subLength: " << subLength << "\n";
  if (subLength > longestSubLength)
    longestSubLength = subLength;

  return longestSubLength;

}

// optimized using https://www.youtube.com/watch?v=wiGpQwVHdE0s
int lengthOfLongestSubstring(string s) {
  set<char> charset;
  int left = 0;
  int result = 0;

  // pwwkew

  // going through every single character
  for (int i = 0; i < s.length(); i++) {

    // if current character is in the character map, update window and charset
    while (charset.count(s[i])) {
      // remove left character from the set
      charset.erase(s[left]);
      left++;
    }
    charset.insert(s[i]);
    result = max(result, i - left + 1);
  }

  return result;

}

int main(int argc, char const *argv[]) {
  // string s = "abcabcbb";
  string s = "pwwkew";
  // string s = "auntn";
  // string s = "dvdf";
  // string s = "dvasfdf";
  // string s = "bbb";

  cout << lengthOfLongestSubstring(s) << "\n";

  return 0;
}
