#include <iostream>
#include <vector>
#define L first
#define R second
using namespace std;
using Soldiers = vector<pair<int, int>>;
using Sections = vector<int>;

void PrintSec(Sections secs)
{
    cout << "Sections: ";
    for (int g : secs)  cout << g << ' ';
    cout << '\n';
}

int RemoveTwo(Soldiers soldiers, Sections secs, int guarded, int r1)
{
    int loss, loss_min = 5001;
    cout << "Removeing Soldier " << r1 << "...\n";
    for (int i = soldiers[r1].L; i <= soldiers[r1].R; i++)
        if (--secs[i] == 0)  guarded--;
    PrintSec(secs);
    soldiers.erase(soldiers.begin() + r1);
    for (auto soldier : soldiers) {
        loss = 0;
        for (int i = soldier.L; i <= soldier.R; i++)
            if (secs[i] == 1)  loss++;
        if (loss == 0)  return guarded;
        loss_min = min(loss ,loss_min);
    }
    // for (int i = 0; i < soldiers.size(); i++) {
    //     if (i == r1)    continue;
    //     loss = 0;
    //     for (int j = soldiers[i].L; j <= soldiers[i].R; j++)
    //         if (secs[j] == 1)  loss++;
    //     if (loss == 0)  return guarded;
    //     loss_min = min(loss ,loss_min);
    // }
    return guarded - loss_min;
}

void Sol()
{
    int n, q, guarded = 0, ans = 0;
    cin >> n >> q;
    Soldiers soldiers(q);
    Sections secs(n);
    for (int i = 0; i < q; i++) {
        cin >> soldiers[i].L >> soldiers[i].R;
        soldiers[i].L--;
        soldiers[i].R--;
        for (int j = soldiers[i].L; j <= soldiers[i].R; j++)
            if (++secs[j] == 1) guarded++;
    }
    cout << "No Soldiers Removed:\n";
    PrintSec(secs);
    for (int i = 0; i < q; i++)
        ans = max(RemoveTwo(soldiers, secs, guarded, i), ans);
    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) Sol();
    return 0;
}