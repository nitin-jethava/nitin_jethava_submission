class Stack:
    def __init__(self):
        self.stack = []  # List to store stack elements

    def push(self, item):
        """Pushes an item onto the stack"""
        self.stack.append(item)
        print(f"Pushed: {item}")

    def pop(self):
        """Pops the top item off the stack"""
        if not self.is_empty():
            popped_item = self.stack.pop()
            print(f"Popped: {popped_item}")
        else:
            print("Stack is empty")

    def peek(self):
        """Returns the top item without removing it"""
        if not self.is_empty():
            return self.stack[-1]
        else:
            print("Stack is empty")
            return None

    def is_empty(self):
        """Checks if the stack is empty"""
        return len(self.stack) == 0

    def display(self):
        """Displays the stack elements"""
        if self.is_empty():
            print("Stack is empty")
        else:
            print("Stack:", self.stack)

# Example usage
s = Stack()
s.push(10)
s.push(20)
s.pop()
s.display()
