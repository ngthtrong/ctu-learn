#include <stdlib.h>
#include <string.h>
typedef char DataType;
struct Node
{
  DataType Data;
  int Key, key;
  struct Node *Left, *Right, *left, *right;
};
typedef struct Node *Tree;

Tree initTree()
{
  Tree temp;
  temp = NULL;
  return temp;
}

int isEmpty(Tree tr)
{
  return tr == NULL;
}

void preOrder(Tree tr)
{
  if (tr != NULL)
  {
    printf("%d ", tr->Key);
    preOrder(tr->Left);
    preOrder(tr->Right);
  }
}

void in_order(Tree tr)
{
  if (tr != NULL)
  {
    in_order(tr->left);
    printf("%d ", tr->key);
    in_order(tr->right);
  }
}

void post_order(Tree tr)
{
  if (tr != NULL)
  {
    post_order(tr->left);
    post_order(tr->right);
    printf("%d ", tr->key);
  }
}

Tree search(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->key)
      return search(x, tr->right);
    else if (x < tr->key)
      return search(x, tr->left);
    else if (x == tr->key)
    {
      return tr;
    }
  }
  return NULL;
}

Tree getNext(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
      return getNext(x, tr->Right);
    else if (x < tr->Key)
      return getNext(x, tr->Left);
    else if (x == tr->Key)
    {
      if (tr->Right != NULL)
        return tr->Right;
      return NULL;
    }
  }
  return tr;
}

Tree getPrevious(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
      return getPrevious(x, tr->Right);
    else if (x < tr->Key)
      return getPrevious(x, tr->Left);
    else if (x == tr->Key)
    {
      if (tr->Left != NULL)
        return tr->Left;
      return NULL;
    }
  }
  return tr;
}

Tree rightSibling(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
    {
      return rightSibling(x, tr->Right);
    }
    else if (x < tr->Key)
    {
      if (x == tr->Left->Key)
        return tr->Right;
      return rightSibling(x, tr->Left);
    }
    return NULL;
  }
  return tr;
}

Tree getParent(int x, Tree tr)
{
  if (x < tr->Key)
  {
    if (x == tr->Left->Key)
      return tr;
    return getParent(x, tr->Left);
  }
  else if (x > tr->Key)
  {
    if (x == tr->Right->Key)
      return tr;
    return getParent(x, tr->Right);
  }
  return NULL;
}

void print_path(int x, Tree tr)
{
  {
    if (tr != NULL)
    {
      printf("%d ", tr->key);
      if (x > tr->key)
      {
        print_path(x, tr->right);
      }
      else if (x < tr->key)
      {
        print_path(x, tr->left);
      }
      else if (x == tr->key)
      {
        printf(" --> Tim thay");
      }
    }
    else
      printf(" --> Tim khong thay");
  }
}

void insertNode(int x, Tree *tr)
{
  if ((*tr) != NULL)
  {
    if (x < (*tr)->Key)
      insertNode(x, &((*tr)->Left));
    else if (x > (*tr)->Key)
      insertNode(x, &((*tr)->Right));
  }
  else
  {
    struct Node *tempN = (struct Node *)malloc(sizeof(struct Node));
    (*tr) = tempN;
    (*tr)->Key = x;
    (*tr)->Left = NULL;
    (*tr)->Right = NULL;
  }
}

Tree insert_node(int x, Tree root)
{
  if (root == NULL)
  {
    Tree temp = (Tree)malloc(sizeof(struct Node));
    root = temp;
    root->key = x;
    root->right = NULL;
    root->left = NULL;
  }
  else if (x < root->key)
  {
    root->left = insert_node(x, root->left);
  }
  else if (x > root->key)
  {
    root->right = insert_node(x, root->right);
  }
  return root;
}

void posOrder(Tree tr)
{
  if (tr != NULL)
  {
    posOrder(tr->Left);
    posOrder(tr->Right);
    printf("%d ", &tr->Key);
  }
}

int get_height(Tree tr)
{
  if (tr != NULL)
  {
    if (tr->left != NULL && tr->right != NULL)
    {
      int tempR = get_height(tr->right);
      int tempL = get_height(tr->left);
      return 1 + (tempR > tempL ? tempR : tempL);
    }
    else if (tr->left != NULL)
      return 1 + get_height(tr->left);
    else
      return 1 + get_height(tr->right);
  }
  return -1;
}

int hNode(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
      return hNode(x, tr->Right);
    else if (x < tr->Key)
      return hNode(x, tr->Left);
    else if (x == tr->Key)
    {
      if (tr->Left != NULL && tr->Right != NULL)
      {
        int tempR = hNode(tr->Right->Key, tr->Right);
        int tempL = hNode(tr->Left->Key, tr->Left);
        return 1 + (tempR >= tempL ? tempR : tempL);
      }
      else if (tr->Left != NULL)
        return 1 + hNode(tr->Left->Key, tr->Left);
      else if (tr->Right != NULL)
        return 1 + hNode(tr->Right->Key, tr->Right);
      else
        return 0;
    }
    return -1;
  }
  return -1;
}

void deleteNode(int x, Tree *tr)
{
  if ((*tr) != NULL)
  {
    if (x < (*tr)->Key)
      deleteNode(x, &((*tr)->Left));
    else if (x > (*tr)->Key)
      deleteNode(x, &((*tr)->Right));
    else
    {
      if ((*tr)->Left == NULL && (*tr)->Right == NULL)
      {
        free((*tr));
        (*tr) = NULL;
      }
      else if ((*tr)->Left == NULL)
      {
        Tree delNode = (*tr);
        (*tr) = (*tr)->Right;
        free(delNode);
        delNode = NULL;
      }
      else if ((*tr)->Right == NULL)
      {
        Tree delNode = (*tr);
        (*tr) = (*tr)->Left;
        free(delNode);
        delNode = NULL;
      }
      else
      {
        Tree minNode = (*tr)->Right;
        while (minNode->Left != NULL)
          minNode = minNode->Left;
        (*tr)->Key = minNode->Key;
        deleteNode(minNode->Key, &((*tr)->Right));
      }
    }
  }
}

Tree delete_node(int x, Tree root)
{
  if (root != NULL)
  {
    if (x < root->key)
      root->left = delete_node(x, root->left);
    else if (x > root->key)
      root->right = delete_node(x, root->right);
    else
    {
      if (root->left == NULL && root->right == NULL)
      {
        free(root);
        root = NULL;
        return NULL;
      }
      else if (root->left == NULL)
      {
        Tree delNode = root;
        root = root->right;
        free(delNode);
        return delNode;
      }
      else if (root->right == NULL)
      {
        Tree delNode = root;
        root = root->left;
        free(delNode);
        delNode = NULL;
        return delNode;
      }
      else
      {
        Tree minNode = root->right;
        while (minNode->left != NULL)
          minNode = minNode->left;
        root->key = minNode->key;
        root->right = delete_node(minNode->key, root->right);
      }
    }
  }
  return root;
}

Tree convertTree(Tree root)
{
  if (root != NULL)
  {
    Tree mir;
    mir = createNode(root->Data);
    mir->Left = convertTree(root->Right);
    mir->Right = convertTree(root->Left);
    return mir;
  }
  return NULL;
}

char findMax(Tree tr)
{
  if (tr != NULL)
  {
    DataType l = -1, r = -1;
    if (tr->Right != NULL)
      r = findMax(tr->Right);
    else if (tr->Left != NULL)
      l = findMax(tr->Left);
    return l > r ? l : r;
  }
  return -1;
}

int main()
{
  printf("Hello world");
}
