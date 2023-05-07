#include "RedAndBlackTree.h"
// Tworzenie drzewa Red-Black.
// Inicjalizacja koloru NIL na 0 (czarny), wskaźników left i right na nullptr oraz ustawienie korzenia na NIL.
RedAndBlackTree::RedAndBlackTree() {
    NIL = new Node;
    NIL->color = 0;
    NIL->left = nullptr;
    NIL->right = nullptr;
    root = NIL;
    size = 0;
}

// Usuwanie drzewa Red-Black.
// Usunięcie korzenia oraz NIL-a.
RedAndBlackTree::~RedAndBlackTree() {
    delete (root);
    delete NIL;
}

NodePtr RedAndBlackTree::searchTreeHelper(NodePtr node, int key) {
    if (key == node->data) {
        return node;
    }
    if (node == NIL) {
        return nullptr;
    }
    if (key < node->data) {
        return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
}

// naprawa drzewa po usunieciu wierzcholka
void RedAndBlackTree::deleteFix(NodePtr x) {
    NodePtr s;
    while (x != root && x->color == 0) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == 0 && s->right->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->right->color == 0) {
                    s->left->color = 0;
                    s->color = 1;
                    rightRotate(s);
                    s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->right->color = 0;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->color == 1) {
                s->color = 0;
                x->parent->color = 1;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == 0 && s->left->color == 0) {
                s->color = 1;
                x = x->parent;
            } else {
                if (s->left->color == 0) {
                    s->right->color = 0;
                    s->color = 1;
                    leftRotate(s);
                    s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = 0;
                s->left->color = 0;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 0;
}

void RedAndBlackTree::rbTransplant(NodePtr u, NodePtr v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedAndBlackTree::deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = NIL;
    NodePtr x, y;
    while (node != NIL) {
        if (node->data == key) {
            z = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (z == NIL) {
        cout << "Nie znaleziono klucza w drzewie" << endl;
        return;
    }

    y = z;
    int y_original_color = y->color;
    if (z->left == NIL) {
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            rbTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    size--;
    if (y_original_color == 0) {
        deleteFix(x);
    }
}

// naprawa drzewa po dodaniu wierzcholka
void RedAndBlackTree::insertFix(NodePtr k) {
    NodePtr u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;

            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = 0;
}

void RedAndBlackTree::printHelper(NodePtr ptr, int level) {
    if (ptr != NIL) {
        printHelper(ptr->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "    ";
        }
        if (ptr->color) {
            cout << ptr->data << " (R)" << endl;
        } else {
            cout << ptr->data << " (B)" << endl;
        }
        printHelper(ptr->left, level + 1);
    }
}

NodePtr RedAndBlackTree::searchTree(int k) {
    return searchTreeHelper(this->root, k);
}

NodePtr RedAndBlackTree::minimum(NodePtr node) {
    while (node->left != NIL) {
        node = node->left;
    }
    return node;
}

//rotacja w lewo
void RedAndBlackTree::leftRotate(NodePtr x) {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
//rotacja w prawo
void RedAndBlackTree::rightRotate(NodePtr x) {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != NIL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        this->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// dodawanie wierzcholka do drzewa
void RedAndBlackTree::insert(int key) {
    auto node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = NIL;
    node->right = NIL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != NIL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == nullptr) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }
    size++; //zwiększenie zmiennej size o 1 po dodaniu wierzchołka

    if (node->parent == nullptr) {
        node->color = 0;
        return;
    }

    if (node->parent->parent == nullptr) {
        return;
    }

    insertFix(node);
}

//usuwanie wierzcholka
void RedAndBlackTree::deleteNode(int data) {
    deleteNodeHelper(this->root, data);
}
// wyswietlanie drzewa
void RedAndBlackTree::printTree() {
    if (root) {
        printHelper(this->root,0);
    }
}