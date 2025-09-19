class Spreadsheet {
private:
    vector<vector<int>> sheet;

public:
    Spreadsheet(int rows) {
        sheet = vector<vector<int>>(26, vector<int>(rows, 0));
    }
    
    void setCell(string cell, int value) {
        // cout<<"SET"<<endl;
        sheet[cell[0]-'A'][stoi(cell.substr(1))-1]=value;
    }
    
    void resetCell(string cell) {
        // cout<<"RESET"<<endl;
        sheet[cell[0]-'A'][stoi(cell.substr(1))-1]=0;
    }
    
    int getValue(string formula) {
        // cout<<"VALUE"<<endl;
        string left = formula.substr(1, formula.find('+')-1);
        // cout<<left<<endl;
        string right = formula.substr(formula.find('+')+1);
        // cout<<right<<endl;
        int leftVal, rightVal;
        if(isdigit(left[0])){
            leftVal = stoi(left);
        }
        else{
            leftVal=sheet[left[0]-'A'][stoi(left.substr(1))-1];
        }
        if(isdigit(right[0])){
            rightVal = stoi(right);
        }
        else{
            rightVal=sheet[right[0]-'A'][stoi(right.substr(1))-1];
        }
        return leftVal+rightVal;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
