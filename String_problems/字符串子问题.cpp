#include<iostream>
using namespace std;
class solution{
public:
	void fun(char*w, int m){
		int i = 0;
		int len = strlen(w);
		if (m >= len) return;
		while (len - m > 0 || (m = 0) != 0){
			w[len] = w[0];
			++m;
			for (i = 0; i < len; ++i){
				w[i] = w[i + 1];
			}
		}
		w[len - m] = '\0';
	}
};
int main(){
	char w[] = "ABCDEFGHI";
	cout << "w: " << w << endl;
	solution s;
	s.fun(w, 3);
	cout << "after removed: " << w << endl;
	system("pause");
	return 0;
}