class MyHashSet
{
private:
    static constexpr int SIZE = 1'000'001;
    vector<int> HashMap;

public:
    MyHashSet() : HashMap(SIZE, -1) {}

    void add(int key)
    {
        HashMap[key] = key;
    }

    void remove(int key)
    {
        HashMap[key] = -1;
    }

    bool contains(int key)
    {
        int value = HashMap[key];
        if (value != -1 && value == key)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */