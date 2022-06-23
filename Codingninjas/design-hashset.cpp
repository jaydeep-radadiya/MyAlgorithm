class HashSet {
   public:
    vector<bool> arr;
    HashSet() {
        arr = vector<bool>(1e6+1,false);
    }
    void add(int key) {
        arr[key] = true;
    }
    int removeElement(int key) {
        if(arr[key]==true){
            arr[key] = false;
            return key;
        }
        else{
            return -1;
        }
    }
    bool contains(int key) {
        return arr[key];
    }
};