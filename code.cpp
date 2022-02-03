#include <bits/stdc++.h>
using namespace std;

int longestPalSubstr(string str)
{
	
	int maxLength = 1;
	int start = 0;
	int len = str.length();
	int low, high;

	for (int i = 1; i < len; ++i) {
		low = i - 1;
		high = i;
		while (low >= 0 && high < len
			&& str[low] == str[high]) {
			--low;
			++high;
		}

		++low; --high;
		if (str[low] == str[high] && high - low + 1 > maxLength) {
			start = low;
			maxLength = high - low + 1;
		}

		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len
			&& str[low] == str[high]) {
			--low;
			++high;
		}

		++low; --high;
		if (str[low] == str[high] && high - low + 1 > maxLength) {
			start = low;
			maxLength = high - low + 1;
		}
	}

	//cout <<"Best Drug :  ";
	int ans = maxLength;
	while(ans--)
		cout<<str[start++];

	return maxLength;
}

int main()
{
	string str = "DGAABBAAKGHV";
	longestPalSubstr(str);
	return 0;
}

//Input - DGAABBAAKGHV
//Output - AABBAA
//Time complexity - O(n^2)
//Space complexity - O(1)
