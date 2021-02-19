#include <iostream>
using namespace std;

int binary_search(bool xdir, int value, int l, int r)
{
    char str[10];
    int res = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        cout << "? ";
        if (xdir)
        {
            cout << value << " " << mid << endl; 
            fflush(stdout);
            cin >> str;
        }
        else
        {
            cout << mid << " " << value << endl; 
            fflush(stdout);
            cin >> str;
        }
        if (str[0] == 'N')
        {
            r = mid - 1;
        }
        else 
        {
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}
long long pr()
{
    int rect_base, tri_base, tri_height;

    rect_base = binary_search(false, 0, 0, 1000) * 2;
    tri_base = binary_search(false, rect_base, 0, 1000) * 2;
    tri_height = binary_search(true, 0, rect_base, 1000) - rect_base;
    return (rect_base * rect_base) + ((tri_base * tri_height) / 2);
}

int main(int argc,const char *argv[] ) {
    long long ret;
    ret = pr();
    cout << "! " << ret << endl;
    return 0;
}
