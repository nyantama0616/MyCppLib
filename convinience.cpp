// ２つのvectorをzip
template <class T0, class T1> void zip(vector<T0> v0, vector<T1> v1, vector<pair<T0, T1>>& res) {
    int n = v1.size();
    for (int i = 0; i < n; i++) {
        res[i] = {v0[i], v1[i]};
    }
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

// l <= x <= rの配列生成
void make_ary(ll l, ll r, V& res) {
        random_device rd;
        default_random_engine eng(rd());
        uniform_int_distribution<int> distr(l, r);
 
        ll n = res.size();
        rep(i, n) {
            res[i] = distr(eng);
        }
}

// 1234 => {4, 3, 2, 1}
void digits(ll x, V& res, ll base=10) {
    while (x > 0) {
        res.push_back(x % base);
        x /= base;
    }
}

/* 
いい感じにインクリメントしてくれる。
a^dの全列挙とかに使える
長さdのvectorを渡す。
base^dになると0に戻る
*/
void increment(V& x, ll i, ll d, ll base=10) {
    if (i == d - 1) {
        if (x[i] < base - 1) {
            ++x[i];
        } else {
            x[i] = 0;

        }
    } else {
        if (x[i] < base - 1) {
            ++x[i];
        } else {
            increment(x, i + 1, d, base);
            x[i] = 0;
        }
    }
}
