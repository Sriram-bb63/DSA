class node:
    
    def __init__(self, value):
        self.value = value
        self.nextnode = None


class linked_list:

    def __init__(self, head = None):
        self.head = head

    def insert(self, value):
        new_node = node(value)
        if self.head == None:
            self.head = new_node
        else:
            node_iterator = self.head
            while node_iterator.nextnode != None:
                node_iterator = node_iterator.nextnode
            node_iterator.nextnode = new_node

    def print_linked_list(self):
        node_iterator = self.head
        while node_iterator != None:
            print(node_iterator.value)
            node_iterator = node_iterator.nextnode

demo_linked_list = linked_list()
for i in range(10):
    demo_linked_list.insert(i)
demo_linked_list.print_linked_list()