// 組み合わせ
template <typename T> class Combination {
    vector<T> list;
    vector<bool> bool_list;
    bool state;
    int n;
    int r;

public:
    Combination(vector<T> list, int r) : state(true), n(list.size()), r(r) {
        sort(list.begin(), list.end());
        this->list = list;
        
        bool_list = vector<bool>(n, true);
        for (int i = 0; i < r; ++i) {
            bool_list[i] = false;
        }
    }

    // 要素数rのvectorを渡す
    bool next(vector<T>& res) {
        if (!state) return false;
        
        int pos = 0;
        rep(i, n) {
            if (!bool_list[i]) {
                res[pos++] = list[i];
            }
        }

        state = next_permutation(bool_list.begin(), bool_list.end());
        return true;
    }
};

// nCr
ll binomial(ll n, ll r) {
    if (n < r) return 0;
    r = min(r, n - r);
    ll ans = 1;
    rep(i, r) {
        ans *= n - i;
    }
    rep_rev2(i, 2, r + 1) {
        ans /= i;
    }

    return ans;
}

// x以下の素数全列挙
void make_primes(ll x, V& res) {
    vector<bool> flag(x + 1, false);
    rep2(i, 2, x + 1) {
        if (!flag[i]) {
            res.push_back(i);
            for (ll j = 2*i; j < x + 1; j += i) {
                flag[j] = true;
            }
        }
    }
}

// 素因数分解
void prime_divise(ll x, V& res, V primes) {
    for (ll t : primes) {
        if (x == 1) break;
        while (x % t == 0) {
            res.push_back(t);
            x /= t;
        }
    }
    if (x > 1) res.push_back(x);
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
    
    // 状況に応じて消す
    ll n = res.size();
    if (res[n/2-1] == res[n/2]) {
        res.erase(res.begin() + n/2);
    }
}
