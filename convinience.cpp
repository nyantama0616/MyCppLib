// ２つのvectorをzip
template <class T0, class T1> void zip(vector<T0> v0, vector<T1> v1, vector<pair<T0, T1>>& res) {
    int n = v1.size();
    for (int i = 0; i < n; i++) {
        res[i] = {v0[i], v1[i]};
    }
}


// 約数全列挙
void make_divisors(ll x, V& res) {
    ll u = sqrt(x) + 1;
    int pos = 0;
    rep2(i, 1, u) {
        if (x % i == 0) {
            res.insert(res.begin() + pos, i);
            res.insert(res.end() - pos, x / i);
            ++pos;
        }
    }
    _unique(res); // 状況に応じて消す
}

template <class T> void tally(vector<T> v, unordered_map<T, ll>& res) {
    for (T x : v) {
        if (!res.count(x)) {
            res[x] = 1;
        } else {
            ++res[x];
        }
    }
}
