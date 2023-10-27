long long gcd(long long a, long long b) { // always positive
    a = abs(a);
    b = abs(b);
    while (a) {
        b %= a;
        swap(a, b);
    }
    return b;
}

struct JiDriverSegmentTree {
    static const ll T = (1 << 20);
    static const long long INF = 1e15 + 7;

    struct Node {
        long long min;
        ll minCnt;
        long long secondMin;

        long long max;
        ll maxCnt;
        long long secondMax;

        long long sum;
        long long diffGcd;

        long long pushSum;
        long long pushEq;
        // If we have pushEq, no other pushes should be made. They're all combined together in pushEq.
        // Otherwise we first apply pushSum and then min= and max= pushes (in any order btw).
    } tree[T];

    ll n;

    void doPushEq(ll v, ll l, ll r, long long val) {
        tree[v].min = tree[v].max = tree[v].pushEq = val;
        tree[v].minCnt = tree[v].maxCnt = r - l;
        tree[v].secondMax = -INF;
        tree[v].secondMin = INF;

        tree[v].sum = val * (r - l);
        tree[v].diffGcd = 0;
        tree[v].pushSum = 0;
    }

    void doPushMinEq(ll v, ll l, ll r, long long val) {
        if (tree[v].min >= val) {
            doPushEq(v, l, r, val);
        }
        else if (tree[v].max > val) {
            if (tree[v].secondMin == tree[v].max) {
                tree[v].secondMin = val;
            }
            tree[v].sum -= (tree[v].max - val) * tree[v].maxCnt;
            tree[v].max = val;
        }
    }

    void doPushMaxEq(ll v, ll l, ll r, long long val) {
        if (tree[v].max <= val) {
            doPushEq(v, l, r, val);
        }
        else if (tree[v].min < val) {
            if (tree[v].secondMax == tree[v].min) {
                tree[v].secondMax = val;
            }
            tree[v].sum += (val - tree[v].min) * tree[v].minCnt;
            tree[v].min = val;
        }
    }

    void doPushSum(ll v, ll l, ll r, long long val) {
        if (tree[v].min == tree[v].max) {
            doPushEq(v, l, r, tree[v].min + val);
        }
        else {
            tree[v].max += val;
            if (tree[v].secondMax != -INF) {
                tree[v].secondMax += val;
            }

            tree[v].min += val;
            if (tree[v].secondMin != INF) {
                tree[v].secondMin += val;
            }

            tree[v].sum += (r - l) * val;
            tree[v].pushSum += val;
        }
    }

    void pushToChildren(ll v, ll l, ll r) {
        if (l + 1 == r) {
            return;
        }
        ll mid = (r + l) / 2;
        if (tree[v].pushEq != -1) {
            doPushEq(2 * v, l, mid, tree[v].pushEq);
            doPushEq(2 * v + 1, mid, r, tree[v].pushEq);
            tree[v].pushEq = -1;
        }
        else {
            doPushSum(2 * v, l, mid, tree[v].pushSum);
            doPushSum(2 * v + 1, mid, r, tree[v].pushSum);
            tree[v].pushSum = 0;

            doPushMinEq(2 * v, l, mid, tree[v].max);
            doPushMinEq(2 * v + 1, mid, r, tree[v].max);

            doPushMaxEq(2 * v, l, mid, tree[v].min);
            doPushMaxEq(2 * v + 1, mid, r, tree[v].min);
        }
    }

    void updateFromChildren(ll v) {
        tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;

        tree[v].max = max(tree[2 * v].max, tree[2 * v + 1].max);
        tree[v].secondMax = max(tree[2 * v].secondMax, tree[2 * v + 1].secondMax);
        tree[v].maxCnt = 0;
        if (tree[2 * v].max == tree[v].max) {
            tree[v].maxCnt += tree[2 * v].maxCnt;
        }
        else {
            tree[v].secondMax = max(tree[v].secondMax, tree[2 * v].max);
        }
        if (tree[2 * v + 1].max == tree[v].max) {
            tree[v].maxCnt += tree[2 * v + 1].maxCnt;
        }
        else {
            tree[v].secondMax = max(tree[v].secondMax, tree[2 * v + 1].max);
        }

        tree[v].min = min(tree[2 * v].min, tree[2 * v + 1].min);
        tree[v].secondMin = min(tree[2 * v].secondMin, tree[2 * v + 1].secondMin);
        tree[v].minCnt = 0;
        if (tree[2 * v].min == tree[v].min) {
            tree[v].minCnt += tree[2 * v].minCnt;
        }
        else {
            tree[v].secondMin = min(tree[v].secondMin, tree[2 * v].min);
        }
        if (tree[2 * v + 1].min == tree[v].min) {
            tree[v].minCnt += tree[2 * v + 1].minCnt;
        }
        else {
            tree[v].secondMin = min(tree[v].secondMin, tree[2 * v + 1].min);
        }

        tree[v].diffGcd = gcd(tree[2 * v].diffGcd, tree[2 * v + 1].diffGcd);

        long long anyLeft = tree[2 * v].secondMax; // any value that's not equal to left child max and min
        long long anyRight = tree[2 * v + 1].secondMax; // any value that's not equal to right child max and min
        if (anyLeft != -INF && anyLeft != tree[2 * v].min && anyRight != -INF && anyRight != tree[2 * v + 1].min) {
            tree[v].diffGcd = gcd(tree[v].diffGcd, anyLeft - anyRight); // connect two spanning trees
        }

        long long any = -1; // any value that's not equal to current vertex max and min
        if (anyLeft != -INF && anyLeft != tree[2 * v].min) {
            any = anyLeft;
        }
        else if (anyRight != -INF && anyRight != tree[2 * v + 1].min) {
            any = anyRight;
        }

        // adding all values that are not max and min anymore to diffGcd
        for (long long val : {tree[2 * v].min, tree[2 * v].max, tree[2 * v + 1].min, tree[2 * v + 1].max}) {
            if (val != tree[v].min && val != tree[v].max) {
                if (any != -1) {
                    tree[v].diffGcd = gcd(tree[v].diffGcd, val - any);
                }
                else {
                    any = val;
                }
            }
        }
    }

    void build(ll v, ll l, ll r, const vector<ll>& inputArray) {
        tree[v].pushSum = 0;
        tree[v].pushEq = -1;
        if (l + 1 == r) {
            tree[v].max = inputArray[l];
            tree[v].secondMax = -INF;
            tree[v].maxCnt = 1;

            tree[v].min = inputArray[l];
            tree[v].secondMin = INF;
            tree[v].minCnt = 1;

            tree[v].diffGcd = 0;
            tree[v].sum = inputArray[l];
        }
        else {
            ll mid = (r + l) / 2;
            build(2 * v, l, mid, inputArray);
            build(2 * v + 1, mid, r, inputArray);
            updateFromChildren(v);
        }
    }

    void build(const vector<ll>& inputArray) {
        n = inputArray.size();
        build(1, 0, n, inputArray);
    }

    void updateMinEq(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr <= l || r <= ql || tree[v].max <= val) {
            return;
        }
        if (ql <= l && r <= qr && tree[v].secondMax < val) {
            doPushMinEq(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        updateMinEq(2 * v, l, mid, ql, qr, val);
        updateMinEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateMinEq(ll ql, ll qr, ll val) {
        updateMinEq(1, 0, n, ql, qr, val);
    }

    void updateMaxEq(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr <= l || r <= ql || tree[v].min >= val) {
            return;
        }
        if (ql <= l && r <= qr && tree[v].secondMin > val) {
            doPushMaxEq(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        updateMaxEq(2 * v, l, mid, ql, qr, val);
        updateMaxEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateMaxEq(ll ql, ll qr, ll val) {
        updateMaxEq(1, 0, n, ql, qr, val);
    }

    void updateEq(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            doPushEq(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        updateEq(2 * v, l, mid, ql, qr, val);
        updateEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updateEq(ll ql, ll qr, ll val) {
        updateEq(1, 0, n, ql, qr, val);
    }

    void updatePlusEq(ll v, ll l, ll r, ll ql, ll qr, ll val) {
        if (qr <= l || r <= ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            doPushSum(v, l, r, val);
            return;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        updatePlusEq(2 * v, l, mid, ql, qr, val);
        updatePlusEq(2 * v + 1, mid, r, ql, qr, val);
        updateFromChildren(v);
    }

    void updatePlusEq(ll ql, ll qr, ll val) {
        updatePlusEq(1, 0, n, ql, qr, val);
    }

    long long findSum(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return tree[v].sum;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        return findSum(2 * v, l, mid, ql, qr) + findSum(2 * v + 1, mid, r, ql, qr);
    }

    long long findSum(ll ql, ll qr) {
        return findSum(1, 0, n, ql, qr);
    }

    long long findMin(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr <= l || r <= ql) {
            return INF;
        }
        if (ql <= l && r <= qr) {
            return tree[v].min;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        return min(findMin(2 * v, l, mid, ql, qr), findMin(2 * v + 1, mid, r, ql, qr));
    }

    long long findMin(ll ql, ll qr) {
        return findMin(1, 0, n, ql, qr);
    }

    long long findMax(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr <= l || r <= ql) {
            return -INF;
        }
        if (ql <= l && r <= qr) {
            return tree[v].max;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        return max(findMax(2 * v, l, mid, ql, qr), findMax(2 * v + 1, mid, r, ql, qr));
    }

    long long findMax(ll ql, ll qr) {
        return findMax(1, 0, n, ql, qr);
    }

    long long findGcd(ll v, ll l, ll r, ll ql, ll qr) {
        if (qr <= l || r <= ql) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            long long ans = tree[v].diffGcd;
            if (tree[v].secondMax != -INF) {
                ans = gcd(ans, tree[v].secondMax - tree[v].max);
            }
            if (tree[v].secondMin != INF) {
                ans = gcd(ans, tree[v].secondMin - tree[v].min);
            }
            ans = gcd(ans, tree[v].max);
            return ans;
        }
        pushToChildren(v, l, r);
        ll mid = (r + l) / 2;
        return gcd(findGcd(2 * v, l, mid, ql, qr), findGcd(2 * v + 1, mid, r, ql, qr));
    }

    long long findGcd(ll ql, ll qr) {
        return findGcd(1, 0, n, ql, qr);
    }
} segTree;
