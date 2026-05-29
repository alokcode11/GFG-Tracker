class myQueue {

    stack<int> firstStack;
    stack<int> secondStack;

  public:

    myQueue() {
        
    }

    // Push element into queue
    void enqueue(int x) {

        // Push directly into first stack
        firstStack.push(x);
    }

    // Remove front element
    void dequeue() {

        // If queue empty
        if(firstStack.empty() && secondStack.empty()) {
            return;
        }

        // Transfer only when second stack empty
        if(secondStack.empty()) {

            while(!firstStack.empty()) {

                secondStack.push(firstStack.top());

                firstStack.pop();
            }
        }

        // Remove front element
        secondStack.pop();
    }

    // Return front element
    int front() {

        // If queue empty
        if(firstStack.empty() && secondStack.empty()) {
            return -1;
        }

        // Transfer elements if needed
        if(secondStack.empty()) {

            while(!firstStack.empty()) {

                secondStack.push(firstStack.top());

                firstStack.pop();
            }
        }

        return secondStack.top();
    }

    // Return total size
    int size() {

        return firstStack.size() + secondStack.size();
    }
};