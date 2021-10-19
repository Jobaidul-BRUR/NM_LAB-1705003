#include <bits/stdc++.h>

#define EPS      1E-15
#define watch(x) (#x)
#define PI       acos(-1)
#define sq(x)    ((x)*(x))

using namespace std;
const int  INF =  2139062143;
const long double e = 2.7182818284590452353602874713527L;
const int PRECI = 10;

class POLY
{
protected:
    vector<long double> a, b; int n;
public:
    POLY()
    {
        cout << "Input degree of polynomial: "; cin >> n;
        a.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            cout << "Input " << i;
            if (i == 1) cout << "st";
            else if (i == 2) cout << "nd";
            else if (i == 3) cout << "rd";
            else cout << "th";
            cout << " degree polynomial coefficient a(" << i << "): ";

            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            b.push_back(a[i]*i);
        }
    }
    long double f(long double x)
    {
        return horner(a, x);
    }
    long double fDash(long double x)
    {
        return horner(b, x);
    }
    long double horner(vector<long double>&a, long double x)
    {
        int n = a.size()-1;
        long double ans = a[n];
        for (int i = n-1; i >= 0; i--)
        {
            ans = ans*x + a[i];
        }
        return ans;
    }
};
class NM : public POLY
{
public:
    NM()
    {

    }
    void BISECT()
    {
        long double x1, x2, x0; int num_of_iteration;
        while (1)
        {
            cout << "\nInput starting value\n";
            cout << "x(1): "; cin >> x1;
            cout << "x(2): "; cin >> x2;
            if (f(x1)*f(x2) <= 0) break;
            else
            {
                cout << "\nThe given values does not bracket a root\n";
                string sel;
                cout << "Try with different values? Y/n";
                while (1)
                {
                    cin >> sel;
                    if (tolower(sel[0]) == 'y' or tolower(sel[0]) == 'n') break;
                    else cout << "Invalid input\n";
                }
                if (tolower(sel[0]) == 'n') return;
            }
        }
        cout << "input number of iteration: "; cin >> num_of_iteration;

        x0 = (x1+x2)/2;
        for (int i = 0; i < num_of_iteration; i++)
        {
            if (f(x0)*f(x1) <= 0) x2 = x0;
            else x1 = x0;
            x0 = (x1+x2)/2;
        }
        cout << "The root is: " << x0 << endl;
        getchar(); getchar();
    }
    void FALSE()
    {
        long double x1, x2, x0; int num_of_iteration;
        while (1)
        {
            cout << "\nInput initial guesses\n";
            cout << "x(1): "; cin >> x1;
            cout << "x(2): "; cin >> x2;
            if (f(x1)*f(x2) <= 0) break;
            else
            {
                cout << "\nThe given values does not bracket a root\n";
                string sel;
                cout << "Try with different values?(Y/n): ";
                while (1)
                {
                    cin >> sel;
                    if (tolower(sel[0]) == 'y' or tolower(sel[0]) == 'n') break;
                    else cout << "Invalid input\n";
                }
                if (tolower(sel[0]) == 'n') return;
            }
        }
        cout << "input number of iteration: "; cin >> num_of_iteration;

        x0 = x1-f(x1)*(x2-x1)/(f(x2)-f(x1));
        for (int i = 0; i < num_of_iteration; i++)
        {
            if (f(x0)*f(x1) <= 0) x2 = x0;
            else x1 = x0;
            if (fabs(f(x2)-f(x1)) < EPS) break;
            x0 = x1-f(x1)*(x2-x1)/(f(x2)-f(x1));
        }
        cout << "The root is: " << x0 << endl;
        getchar(); getchar();
    }
    void NEWTON()
    {
        long double x; int num_of_iteration;

        cout << "\nInput initial guess\n";
        cout << "x(0): "; cin >> x;
        cout << "input number of iteration: "; cin >> num_of_iteration;

        for (int i = 0; i < num_of_iteration; i++)
        {
            if (fabs(fDash(x)) < EPS) break;
            x = x-f(x)/fDash(x);
        }
        cout << "The root is: " << x << endl;
        getchar(); getchar();
    }
    void SECANT()
    {
        long double x1, x2, x0; int num_of_iteration;
        cout << "\nInput initial guesses\n";
        cout << "x(1): "; cin >> x0;
        cout << "x(2): "; cin >> x1;
        cout << "input number of iteration: "; cin >> num_of_iteration;
        x2 = x1;
        for (int i = 0; i < num_of_iteration; i++)
        {
            if (fabs(f(x1)-f(x0)) < EPS) break;
            x2 = x1-f(x1)*(x1-x0)/(f(x1)-f(x0));
            x0 = x1;
            x1 = x2;
        }
        cout << "The root is: " << x2 << endl;
        getchar(); getchar();
    }
};

int main()
{
    cout.precision(PRECI); cout << fixed;

    //Bisection(4).solve();
    //False_position(4).solve();
    NM nm;
    int op;
    do
    {
        cout << "#####     MAIN MENU     #####\n\n";
        cout << "0. Exit\n";
        cout << "1. Evaluate the Polynomial\n";
        cout << "2. Solve by Bisection Method\n";
        cout << "3. Solve by False Position Method\n";
        cout << "4. Solve by Newton-Raphson Method\n";
        cout << "5. Solve by Secant Method\n";
        cout << "6. Enter a new Polynomial\n";
        cout << "Enter your option\n";
        cin >> op;

        switch(op)
        {
        case 0:
            cout << "#####   Exit   #####\n";
            break;
        case 1:
            cout << "#####   Polynomial Evaluation   #####\n";
            while (1)
            {
                long double x;
                cout << "input the value of x(point of evaluation): "; cin >> x;
                cout << "f(x): " << nm.f(x) << endl;

                string sel;
                cout << "Evaluate with different value?(Y/n): ";
                while (1)
                {
                    cin >> sel;
                    if (tolower(sel[0]) == 'y' or tolower(sel[0]) == 'n') break;
                    else cout << "Invalid input\n";
                }
                if (tolower(sel[0]) == 'n') break;
            }
            getchar(); getchar();
            break;
        case 2:
            cout << "#####   Bisection Method   #####\n";
            nm.BISECT();
            break;
        case 3:
            cout << "#####   False-Position Method   #####\n";
            nm.FALSE();
            break;
        case 4:
            cout << "#####   Newton-Raphson Method   #####\n";
            nm.NEWTON();
            break;
        case 5:
            cout << "#####   Secant Method   #####\n";
            nm.SECANT();
            break;
        case 6:
            nm = NM();
        default:
            cout << "Invalid choice\n";
        }
    } while (op != 0);

    getchar();
    return 0;
}
