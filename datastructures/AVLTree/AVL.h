struct AVLNode{
    struct AVLNode *left;
    struct AVLNode *right;
    int    data;
    int    height;
};

//Memory operation
extern struct AVLNode *newAVLNode(int const data);

//data modification
extern struct AVLNode *insert(struct AVLNode *root, int const);
extern struct AVLNode *deleteAVLNode(struct AVLNode *root, int const);
extern struct AVLNode *freeAllMemoryInAVLTree(struct AVLNode * const);

//tree balancing
extern struct AVLNode *rotateLeft(struct AVLNode * const);
extern struct AVLNode *rotateRight(struct AVLNode *const);

//read node property
extern int updateHeight(struct AVLNode * const);
extern int balanceFactorOfAVLNode(struct AVLNode * const);
extern int heightOfAVLNode(struct AVLNode * const);

//utility function
extern int max(int const, int const);

//Log and debug
extern void printAVLTree(struct AVLNode * const);
extern void printAVLNode(struct AVLNode * const);
