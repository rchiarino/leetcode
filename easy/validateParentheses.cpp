class Solution {
public:
    bool isValid(string s) {
        stack<char> characterStack;
        for (char character : s){
            if (character == '(' || character == '{' || character == '['){
                characterStack.push(character);
            } else {
                if (characterStack.empty()){
                    return false;
                }
                char top = characterStack.top();
                if ((character == ')' && top != '(') || (character == '}' && top != '{') || (character == ']' && top != '[')){
                    return false;
                }
                characterStack.pop();
            }
        }
        return characterStack.empty();
    }
};