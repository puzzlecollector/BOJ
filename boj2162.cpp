#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <cstring> 
#include <algorithm>
#include <vector> 
#include <set> 
using namespace std;  
// Given (p1,q1), (p2,q2) do these two line segments intersect?  
struct Point{
    int x,y; 
    Point(int _x,int _y): x(_x),y(_y) {}
};
bool onSegment(Point p, Point q, Point r){
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false; 
}
// implementation of disjoint set (union find) 
// highly efficient
struct DisjointSet{
    vector<int> parent,rank,size;  
    DisjointSet(int n): parent(n),rank(n,1),size(n,1){
        for (int i = 0; i < n; i++){
            parent[i] = i; 
        }
    }
    int find(int u){
        if (u == parent[u]) return u;  
        return parent[u] = find(parent[u]); 
    }
    void merge(int u,int v){
        u = find(u), v = find(v); 
        if (u == v) return;  
        if (rank[u] > rank[v]) swap(u,v); 
        parent[u] = v; 
        size[v] += size[u]; 
        if (rank[u] == rank[v]) rank[v]++; 
    }
    bool same(int u, int v){
        return find(u) == find(v); 
    }
}; 
struct data{
    int a,b,c,d; 
}; 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
    int n; 
    cin >> n;  
    vector<data> v;  
    for (int i = 0; i < n; i++){
        data d; 
        cin >> d.a >> d.b >> d.c >> d.d;
        v.push_back(d);   
    }
    DisjointSet uf(n); // union_find
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            data d1 = v[i], d2 = v[j]; 
            Point p1(d1.a,d1.b); 
            Point q1(d1.c,d1.d); 
            Point p2(d2.a,d2.b); 
            Point q2(d2.c,d2.d); 
            if (doIntersect(p1,q1,p2,q2)){
                uf.merge(i,j); 
            }
        }
    }
    set<int> chk; 
    vector<int> sizes; 
    for (int i = 0; i < n; i++){
        chk.insert(uf.find(i)); 
        sizes.push_back(uf.size[uf.find(i)]); 
    }
    cout << chk.size() << endl; 
    cout << *max_element(sizes.begin(),sizes.end()) << endl; 
    return 0;  
}
