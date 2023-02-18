/* This is an example solution to the "Toilet Seat" problem from
 * KTH Challenge 2012, held on March 3, 2012.
 *
 * The solution is provided as-is, is not documented, and may be
 * generally difficult to read.
 *
 * This work by KTH CSC (http://www.csc.kth.se/) is licensed under a Creative
 * Commons Attribution-Share Alike 2.5 Sweden License
 * (http://creativecommons.org/licenses/by-sa/2.5/se/deed.en).  You are free to
 * redistribute it as you like as long as this license information is not
 * removed.
 */
//Solution by Mikael Goldmann
#include<iostream>
#include<string>

using namespace std;

int same(const string &s, char c)
{
  int n = s.size();
  int cnt = 0;
  if (s[0] != s[1]) ++cnt;
  if (c != s[1]) ++cnt;
  for (int i = 2; i < n; ++i)
    if (s[i] != c) cnt += 2;
  return cnt;
}


int mix(const string &s)
{
  int n = s.size();
  int cnt = 0;
  for (int i = 1; i < n; ++i)
    if (s[i-1] != s[i])
      cnt += 1;
  return cnt;
}


int main()
{
  string s;
  cin >> s;
  // down, up, mix
  cout << same(s, 'U') << endl;
  cout << same(s, 'D') << endl;
  cout << mix(s) << endl;
}
