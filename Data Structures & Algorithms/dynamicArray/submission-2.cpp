class DynamicArray {
public:

    DynamicArray(int capacity) {
        //assume capacity is gt 0 based on parameters
        m_Size = capacity;
        m_DynamicArray = new int[capacity];
        m_LastUsedIndex = -1;
    }

    int get(int i) {
        //assuming i is between 0 and m_Size base on params
        return m_DynamicArray[i];
    }

    void set(int i, int n) {
        //assuming i is between 0 and m_Size base on params
        m_DynamicArray[i] = n;
    }

    void pushback(int n) {
        ++m_LastUsedIndex;
        if(m_LastUsedIndex >= m_Size)
        {
            resize();
        }
        m_DynamicArray[m_LastUsedIndex] = n;
    }
    

    int popback() {
        return m_DynamicArray[m_LastUsedIndex--];
    }

    void resize() {
        
        int* newArray = new int[m_Size * 2];
        for(int i = 0; i  <m_Size; i++)
        {
            newArray[i] = m_DynamicArray [i];
        }
        delete[] m_DynamicArray;
        m_Size *= 2;
        m_DynamicArray = newArray;
    }

    int getSize() {
        return m_LastUsedIndex + 1;
    }

    int getCapacity() {
        return m_Size;
    }
    private:
    int* m_DynamicArray;
    int m_Size;
    int m_LastUsedIndex;
};
