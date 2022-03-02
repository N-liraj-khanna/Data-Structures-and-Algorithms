class Solution {
public:
    string interpret(string command) {
        string goal="";
        for(int i=0;i<command.size();i++){
            if(command[i]=='G')
                goal+="G";
            else if(command[i]=='(' && command[i+1]==')'){
                goal+="o";
                i++;
            }else{
                goal+="al";
                i+=3;
            }
        }   
        return goal;
    }
};