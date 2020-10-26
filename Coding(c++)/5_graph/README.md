Table of Contents
=================
  * [Representation](#Representation)
  * [Traversal](#Traversal)

## Representation
#### Adjcency List
#### Adjcency Matrix

## Traversal
#### BFS(Breadth-First-Search)
```
std::vector<bool> visited(N, false)
std::vector<int> srcs = {0};
std::vector<int> dsts;
int step = 0;
while (step < N) {
    step += 1;
    dsts.clear();
    for (int src : srcs) {
        for (int dst : AdjList[src]) {
            if (!visited[dst]) {
                dsts.push_back(dst);
                visited[dst] = true;
            }
        }
    }
    srcs.assign(dsts.begin(), dsts.end());
}
```

