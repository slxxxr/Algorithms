#pragma once
#include <bits/stdc++.h>

#define debug(x) my_debug(x,#x);

using namespace std;
using ll = long long;


template <typename T1, typename T2>
ostream& operator << (ostream& out, const pair<T1, T2>& para) {
	out << "(" << para.first << ", " << para.second << ")";
	return out;
}

template <typename T>
ostream& operator << (ostream& out, const vector<T>& arr) {
	out << "[";
	for (auto it = arr.begin(); it != arr.end();) {
		cout << *it;
		out << (++it == arr.end() ? "]" : " ");
	}
	return out;
}

template <typename T>
void my_debug(T& x, const char* x_name) {
	cout << "{" << x_name << "} = " << x << endl;
}

template <typename T>
void my_debug(vector<T>& arr, const char* arr_name) {
	cout << arr_name << " = {";
	for (auto it = arr.begin(); it != arr.end();) {
		cout << *it;
		if (++it != arr.end()) {
			cout << ", ";
		}
	}
	cout << "}\n";
}

template <typename T>
void my_debug(vector<vector<T>>& arr, const char* arr_name) {
	cout << arr_name << " = [\n";
	for (ll i = 0, n = arr.size(); i < n; i++) {
		cout <<"\t[" << i << "] = {";
		for (auto it = arr[i].begin(); it != arr[i].end();) {
			cout << *it;
			if (++it != arr[i].end()) {
				cout << ", ";
			}
		}
		if (i != n - 1) { cout << "},\n"; }
		else { cout << "}\n"; }
	}
	cout << "]\n";
}

template <typename T>
void my_debug(set<T>& arr, const char* arr_name) {
	cout << arr_name << " = {";
	for (auto it = arr.begin(); it != arr.end();) {
		cout << *it;
		if (++it != arr.end()) {
			cout << ", ";
		}
	}
	cout << "}\n";
}

template <typename T>
void my_debug(unordered_set<T>& arr, const char* arr_name) {
	cout << arr_name << " = {";
	for (auto it = arr.begin(); it != arr.end();) {
		cout << *it;
		if (++it != arr.end()) {
			cout << ", ";
		}
	}
	cout << "}\n";
}

template <typename T1,typename T2>
void my_debug(map<T1, T2>& mapa, const char* mapa_name) {
	cout << mapa_name << " = {\n";
	for (auto [key, value] : mapa) {
		cout << '\t' << key << ": " << value << '\n';
	}
	cout << "}\n";
}

template <typename T1, typename T2>
void my_debug(unordered_map<T1, T2>& mapa, const char* mapa_name) {
	cout << mapa_name << " = {\n";
	for (auto [key, value] : mapa) {
		cout << '\t' << key << ": " << value << '\n';
	}
	cout << "}\n";
}
