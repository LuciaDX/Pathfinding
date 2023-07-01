struct Node{
  int x;
  int y;
  int z;
  float h;
  float g;
  float f;
  struct Node* p;
};

struct Node* createNode(int sx, int sy, int sz, struct Node* sp, float sh, float sg) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->x = sx;
  newNode->y = sy;
  newNode->z = sz;
  newNode->p = sp;
  newNode->h = sh;
  newNode->g = sg;
  newNode->f = sh + sg;
  return newNode;
}

int nodeEquals(struct Node* n1, struct Node* n2) {
  return n1->x == n2->x && n1->y == n2->y && n1->z == n2->z;
}

struct NodeHash {
  size_t operator()(struct Node const* n) const noexcept {
    size_t h1 = std::hash<int>{}(n->x);
    size_t h2 = std::hash<int>{}(n->y);
    size_t h3 = std::hash<int>{}(n->z);
    return h1 ^ h2 ^ h3;
  }
};