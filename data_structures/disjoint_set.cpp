/**
    Disjoint set - Union find with path compression.
**/

class DisjointSet {
private:
    int size; // The number of elements in this union find
    vector<int> sz; // Used to track the size of each of the component
    vector<int> id; // id[i] points to the parent of i, if id[i] = i then i is a root node
    int numComponents; // Tracks the number of components in the union find
public:
    DisjointSet(int n);
    int find(int p);
    bool connected(int p, int q);
    int componentSize(int p);
    int getSize();
    int components();
    void unify(int p, int q);
};

DisjointSet::DisjointSet(int n) {
    size = n;
    numComponents = n;
    sz = vector<int>(n);
    id = vector<int>(n);

    for (int i = 0; i < n; i++) {
      id[i] = i; // Link to itself (self root)
      sz[i] = 1; // Each component is originally of size one
    }
}

int DisjointSet::find(int p) {
    // Find the root of the component/set
    int root = p;
    while (root != id[root]) root = id[root];

    // Compress the path leading back to the root.
    // Doing this operation is called "path compression"
    // and is what gives us amortized time complexity.
    while (p != root) {
      int next = id[p];
      id[p] = root;
      p = next;
    }

    return root;
}

// Return whether or not the elements 'p' and 'q' are in the same components/set.
bool DisjointSet::connected(int p, int q) {
    return find(p) == find(q);
}

// Return the size of the components/set 'p' belongs to
int DisjointSet::componentSize(int p) {
    return sz[find(p)];
}

// Return the number of elements in this UnionFind/Disjoint set
int DisjointSet::getSize() {
    return size;
}

  // Returns the number of remaining components/sets
int DisjointSet::components() {
    return numComponents;
}

// Unify the components/sets containing elements 'p' and 'q'
void DisjointSet::unify(int p, int q) {
    if (connected(p, q)) return; // These elements are already in the same group!

    int root1 = find(p);
    int root2 = find(q);

    // Merge smaller component/set into the larger one.
    if (sz[root1] < sz[root2]) {
      sz[root2] += sz[root1];
      id[root1] = root2;
    } else {
      sz[root1] += sz[root2];
      id[root2] = root1;
    }

    // Since the roots found are different we know that the number of components/sets has decreased by one.
    numComponents--;
}
