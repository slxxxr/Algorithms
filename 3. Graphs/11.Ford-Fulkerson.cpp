struct edge {
	ll to;    // вершина, куда ведёт ребро
	ll cap;   // пропускная способность ребра
	ll flow;  // поток, текущий по ребру

	edge() { to = -1; cap = -1; flow = -1; } // хуйня майкрософта не дает скомпилить без конструктора по умолчанию, не ебу почему. надеюсь, когда-нибудь мы перейдем на другой компилятор

	edge(ll _to, ll _cap, ll _flow) {
		to = _to; cap = _cap; flow = _flow;
	}

	ll res() { // пропускная способность ребра в остаточной сети
		return cap - flow;
	}
};


vector<edge> edges;
vector<vector<ll>> gr;
vector<ll> used;
ll n, m, s, t; // s - istok, t - stok 


void add_edge(ll x, ll y, ll c) {
	gr[x].push_back(edges.size());  // номер ребра в списке
	edges.push_back(edge(y, c, 0)); // прямое ребро

	gr[y].push_back(edges.size());  // номер ребра
	edges.push_back(edge(x, 0, 0)); // обратное ребро
}



ll dfs(ll v, ll delta) {

	used[v] = 1;
	if (v == t) {
		return delta;
	}

	for (ll edg_ind : gr[v]) {
		if (used[edges[edg_ind].to] or edges[edg_ind].res() == 0) {
			continue;
		}

		ll new_delta = dfs(edges[edg_ind].to, min(delta, edges[edg_ind].res()));
		if (new_delta > 0) { // если нихуя не понятно, то лучше сохранять предка и потом в конце отдельно все это сделать, если че обьясню
			edges[edg_ind].flow += new_delta;
			edges[edg_ind ^ 1].flow -= new_delta;
			return new_delta;
		}
	}

	return 0;
}



ll maxflow() { // time complexity O(F*M) F = max flow, M = edges count
	ll result = 0;
	while (true) {
		used.assign(n, 0);
		ll new_flow = dfs(s, inf);
		if (new_flow > 0) {
			result += new_flow;
		}
		else {
			break;
		}
	}

	return result;
}
