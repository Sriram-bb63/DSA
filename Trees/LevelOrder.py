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

def levelOrder(root):
    level = [root]
    nextLevel = []
    while level != []:
        for node in level:
            print(node.val)
            if node.left:
                nextLevel.append(node.left)
            if node.right:
                nextLevel.append(node.right)
        level = nextLevel
        nextLevel = []

levelOrder(root)