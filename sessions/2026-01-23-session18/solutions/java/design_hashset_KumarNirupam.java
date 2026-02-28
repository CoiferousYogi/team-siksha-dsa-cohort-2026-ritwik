/*
Problem link :-https://leetcode.com/problems/design-hashset/
*/


import java.util.LinkedList;

class MyHashSet {

    private int tableSize = 1009; // hashtable size
    private LinkedList<Integer>[] buckets; // ech buket in hashtable is a linked list 

    public MyHashSet() {
        buckets = new LinkedList[tableSize];
        for(int i=0 ; i< tableSize ; i++){
            buckets[i] = new LinkedList<>();
        } // each bucket is LinkedList assigment
    }

    // hashfunction

    private int hashFunc (int key){
        return key % tableSize ;
    }
    
    public void add(int key) {
        int index  = hashFunc(key); // we get the index of after the key is passed via hash-function

        if(!buckets[index].contains(key)){

            buckets[index].add(key);
        }
    }
    
    public void remove(int key) {
        int index = hashFunc(key);

        buckets[index].remove((Integer)key);
    }
    
    public boolean contains(int key) {
        int index = hashFunc(key);
        return buckets[index].contains(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */