#include <iostream>

#include <string>



using namespace std;



int main()

{

    string s, t;

    cin >> s >> t;

    int pos = 0;
    cout<<s[0]<<endl;
    for (int i = 0; i < t.length(); ++i)

    {

        if (t[i] == s[pos])
        {
            cout<<t[i]<<endl;
            pos += 1;

        }

    }

    cout << pos + 1 << endl;

    return 0;

}
