// 基本的にTにはポインタ使う
template <typename T> class Heap {
    vector<T> v;
    function<bool(T, T)> comb;

public:
    Heap(function<bool(T, T)> comb=less<T>()) : v({}), comb(comb) {}
    Heap(vector<T>& v, function<bool(T, T)> comb=less<T>()) : v(v), comb(comb) {
        make_heap(all(v), comb);
    }

    ll size() {return length(v);}
    bool empty() { return v.empty();}

    T& peek() {
        pop_heap(all(v), comb);
        return v.back();
    }

    T& pop() {
        T& res = peek();
        v.pop_back();
        return res;
    }

    void push(T x) {
        v.push_back(x);
        push_heap(all(v), comb);
    }
};
