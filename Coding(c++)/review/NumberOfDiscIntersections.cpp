#include <algorithm>

typedef struct Disc{
    long long int l;
    long long int r;
    Disc(long long int l, long long int r):l(l), r(r){};
}Disc;

bool cmp_l(Disc& d1, Disc& d2) {
    return d1.l < d2.l;
}

int firstNotOverlap(std::vector<Disc>& Ds, int low, int high, long long int r) {
    int ans = high+1;
    while (low <= high) {
        int mid = (low+high) / 2;
        if (Ds[mid].l <= r) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    std::vector<Disc> Ds(N, Disc(0, 0));
    for (int i=0; i<A.size(); i++) {
        long long int center = i;
        long long int radius = A[i];
        Ds[i].l = center-radius;
        Ds[i].r = center+radius;
    }
    std::sort(Ds.begin(), Ds.end(), cmp_l);
    int ans = 0;
    for (int i=0; i<N; i++) {
        int j = firstNotOverlap(Ds, i+1, N-1, Ds[i].r);
        ans += (j-i-1);
        if (ans > 1e7) return -1;
    }
    return ans;
}
