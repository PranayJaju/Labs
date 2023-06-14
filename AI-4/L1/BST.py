class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(node, key):
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node

def inorder(root):
    if root is not None:
        inorder(root.left)
        print(str(root.key), end=' ')
        inorder(root.right)

def preorder(root):
    if root is not None:
        print(str(root.key), end=' ')
        preorder(root.left)
        preorder(root.right)

def postorder(root):
    if root is not None:
        postorder(root.left)
        postorder(root.right)
        print(str(root.key), end=' ')

tree = [15,50,10,22,35,70,4,12,18,24,31,44,66,90]

root = None
root = insert(root, 25)
for i in tree:
    root = insert(root, i)

print('Inorder: ', end='')
inorder(root)
print('\nPreorder: ', end='')
preorder(root)
print('\nPostorder: ', end='')
postorder(root)