#include<iostream>

using namespace std;

void getlevel(node * ptr, int t) {
    if (t == 0) {
        a.push_back(ptr);
    }
    else {
        if (ptr != NULL) {
            getlevel(ptr->leftnode, t - 1);
            getlevel(ptr->rightnode, t - 1);
        }
        else {
            getlevel(NULL, t - 1);
            getlevel(NULL, t - 1);
        }
    }
}

void printarr() {
    int k = 0, gl, ls, ms, t = 0;
    int n = calheight(root), j;
    cout << "in print tree\n";

    for (int i = 0; i < calheight(root); i++) {

        ls = pow(2, n - i) - 1;
        ms = pow(2, n - i + 1) - 1;
        gl = pow(2, max(0, n - i - 1));

        for (j = 0; j < ls; j++)
            cout << " ";

        getlevel(root, i);

        for (int y = t; y < a.size(); y++) {
            if (a[y] == NULL)
                cout << " ";
            else
                cout << a[y]->data;

            for (j = 0; j < ms ; j++)
                cout << " ";
        }

        for (j = 0; j<gl-1; j++) {
            cout << "\n";

            for (int p = 0; p < ls - j; p++)
                cout << " ";
            for (int l = t; l < a.size(); l++) {
                if (a[l] != NULL) {
                    if (a[l]->leftnode != NULL)
                        cout << "/";
                    else
                        cout << " ";
                    for (int p = 0; p < (2 * j + 1); p++)
                        cout << " ";
                    if (a[l]->rightnode != NULL)
                        cout << "\\";
                    else
                        cout << " ";
                    for (int mss = 0; mss < (ms - 2 * j - 2); mss++) {
                        cout << " ";
                    }
                }
                else {
                    cout << " ";
                    for (int p = 0; p < (2 * j + 1); p++)
                        cout << " ";
                    cout << " ";
                    for (int mss = 0; mss < (ms - 2 * j - 2); mss++) {
                        cout << " ";
                    }
                }
            }
        }
        cout << "\n";
        t = a.size();
    }
    a.erase(a.begin(),a.end());
}
