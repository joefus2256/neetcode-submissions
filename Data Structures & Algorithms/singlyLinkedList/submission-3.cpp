class LinkedList {
private:
    class Node{
        public:
        int m_Value;
        Node* m_NextNode;

        Node(int value)
        {
            m_Value = value;
            m_NextNode = nullptr;
        }
    };

public:
    LinkedList() {
        m_ListHead = nullptr;
        m_ListTail = m_ListHead;
    }

    int get(int index) {
        int i = 0;
        int returnValue = -1;
        Node* walkingNode = m_ListHead;
        while(walkingNode != nullptr )
        {
            if(i == index)
            {
                returnValue = walkingNode->m_Value;
                break;
            }
            ++i;
            walkingNode = walkingNode->m_NextNode;
        }

        return returnValue;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->m_NextNode = m_ListHead;
        m_ListHead = newNode;
        if(m_ListTail == nullptr)
        {
            m_ListTail = newNode;
        }
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);

        //non empty list,update the current tail
        if(m_ListTail != nullptr)
        {
            m_ListTail->m_NextNode = newNode;
        }

        m_ListTail = newNode;

        if(m_ListHead == nullptr)
        {
            m_ListHead = newNode;
        }
    }

    bool remove(int index) {
        int i = 0;
        Node* walkingNode = m_ListHead;
        Node* slowWalkingNode = nullptr;
        bool returnValue = false;
        while(walkingNode != nullptr)
        {
            if(i == index)
            {
                if(walkingNode == m_ListHead)
                {
                    m_ListHead = walkingNode->m_NextNode;
                    delete walkingNode;
                }
                else if(walkingNode == m_ListTail)
                {
                    m_ListTail = slowWalkingNode;
                    delete walkingNode;
                    m_ListTail->m_NextNode = nullptr;
                }
                else
                {
                    slowWalkingNode->m_NextNode = walkingNode->m_NextNode;
                    delete walkingNode;
                }

                returnValue = true;
                break;
            }
            ++i;
            slowWalkingNode = walkingNode;
            walkingNode = walkingNode->m_NextNode;
        }

        return returnValue;
    }

    vector<int> getValues() {
        vector<int> returnValue;
        Node* walkingNode = m_ListHead;
        while (walkingNode != nullptr)
        {
            returnValue.push_back(walkingNode->m_Value);
            walkingNode = walkingNode->m_NextNode;
        }

        return returnValue;
    }


private:
    Node* m_ListHead;
    Node* m_ListTail;  //saves me time on tail inserts but also makes things more of a pain

};
