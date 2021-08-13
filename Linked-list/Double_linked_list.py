class node:

    def __init__(self, value):
        self.value = value
        self.nextnode = None
        self.prevnode = None
    

class double_linked_list:

    def __init__(self):
        self.head = None

    def insert_node(self, value):
        new_node = node(value)
        if self.head == None:
            self.head = new_node
        else:
            node_iterator = self.head
            while node_iterator.nextnode != None:
                node_iterator = node_iterator.nextnode
            node_iterator.nextnode = new_node
            new_node.prevnode = node_iterator

    def print_linked_list(self):
        node_iterator = self.head
        while node_iterator != None:
            print(node_iterator.value)
            node_iterator = node_iterator.nextnode
        
    def delete_node(self, index):
        i = 0
        node_iterator = self.head
        while node_iterator.nextnode != None and i != index:
            node_iterator = node_iterator.nextnode
            i += 1
        left = node_iterator.prevnode
        right = node_iterator.nextnode
        left.nextnode = right
        right.prevnode = left

demo_linked_list = double_linked_list()
for i in range(10):
    demo_linked_list.insert_node(i)
demo_linked_list.print_linked_list()
