class OrderedStream {
public:
    OrderedStream(int n) {
        stream = vector<string>(n);
        haveInputted = vector<bool>(n, false);
        this->n=n;
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey-1]=value;
        haveInputted[idKey-1]=true;
        vector<string> returnVal;
        while(pos<n&&haveInputted[pos]){
            returnVal.push_back(stream[pos]);
            ++pos;
        }
        return returnVal;
    }
private:
    vector<string> stream;
    vector<bool> haveInputted;
    int n;
    int pos = 0;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
