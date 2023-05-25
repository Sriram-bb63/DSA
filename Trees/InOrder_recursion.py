class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.left = None
        self.right = None

    def __repr__(self) -> str:
        return self.val

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)

def traverse(node) -> None:
    if node:
        traverse(node.left)
	print(node.val)
        traverse(node.right)

traverse(root)
