class node:
    
    def __init__(self, value):
        self.value = value
        self.nextnode = None


class linked_list:

    def __init__(self, head = None):
        self.head = head

    def print_linked_list(self):
        node_iterator = self.head
        while node_iterator != None:
            print(node_iterator.value)
            node_iterator = node_iterator.nextnode

    def insert_node(self, value):
        new_node = node(value)
        if self.head == None:
            self.head = new_node
        else:
            node_iterator = self.head
            while node_iterator.nextnode != None:
                node_iterator = node_iterator.nextnode
            node_iterator.nextnode = new_node

    def delete_node(self, index):
        i = 0
        node_iterator = self.head
        while node_iterator.nextnode != None and i != index - 1:
            node_iterator = node_iterator.nextnode
            i += 1
        node_iterator.nextnode = node_iterator.nextnode.nextnode

    def find_node_index(self, val):
        i = 0
        node_iterator = self.head
        while node_iterator.nextnode != None and node_iterator.value != val:
            node_iterator = node_iterator.nextnode
            i += 1
        return i

    def find_node_value(self, index):
        i = 0
        node_iterator = self.head
        while node_iterator != None and i != index:
            node_iterator = node_iterator.nextnode
            i += 1
        return node_iterator.value

demo_linked_list = linked_list()
for i in range(10):
    demo_linked_list.insert_node(i)
demo_linked_list.print_linked_list()