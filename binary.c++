#include<bits/stdc++.h>
using namespace std;
#define ll long long





int main(){

    int N;
    cin >> N;
    vector<pair<double,double>> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].first >> pts[i].second;
    }
    double T;
    cin >> T;

    // 1. Compute centroid of the vertices
    double cx = 0, cy = 0;
    for (auto &p : pts) {
        cx += p.first;
        cy += p.second;
    }
    cx /= N; 
    cy /= N;

    // 2. Sort points by angle around (cx, cy)
    sort(pts.begin(), pts.end(),
         [&](auto &A, auto &B){
             double angA = atan2(A.second - cy, A.first - cx);
             double angB = atan2(B.second - cy, B.first - cx);
             return angA < angB;
         });

    // 3. Compute area via shoelace formula
    double sum = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        sum += pts[i].first * pts[j].second 
             - pts[j].first * pts[i].second;
    }
    double area = fabs(sum) / 2.0;

    // 4. Output
    cout << fixed << setprecision(2) << area << "\n";
    if (area > T) cout << "Sacred\n";
    else          cout << "Not Sacred\n";

}