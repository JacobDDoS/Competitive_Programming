class Spreadsheet {
public:
    unordered_map<int, unordered_map<int, int>> s;

    int col(string c) {
        return c[0]-'A';
    }

    int row(string c) {
        return stoi(c.substr(1));
    }
    
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        s[row(cell)-1][col(cell)] = value;
    }
    
    void resetCell(string cell) {
        s[row(cell)-1][col(cell)] = 0;
    }
    
    int getValue(string formula) {
        string op1 = "", op2 = "";
        bool seenPlus = false;
        for (int i=1;i<formula.size();i++) {
            char c = formula[i];
            if (c == '+') {
                seenPlus = true;
                continue;
            }
            if (seenPlus) {
                op2.push_back(c);
            } else {
                op1.push_back(c);
            }
        }

        int val1 = ((op1[0]>='A' && op1[0] <= 'Z') ? s[row(op1)-1][col(op1)] : stoi(op1));
        int val2 = ((op2[0]>='A' && op2[0] <= 'Z') ? s[row(op2)-1][col(op2)] : stoi(op2));
        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */