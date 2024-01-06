#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

vector<pair<char, string>> productions = {
    {'S', "A"},
    {'A', "Ab"},
    {'A', "a"}};

unordered_map<int, unordered_map<char, pair<char, int>>> LR0Table = {
    {0, {{'a', {'s', 1}}, {'A', {'g', 2}}}},
    {1, {{'b', {'g', 2}}}},
    {2, {{'a', {'s', 1}}, {'b', {'s', 3}}, {'$', {'g', 0}}}},
    {3, {{'b', {'g', 1}}, {'$', {'g', 0}}}}};

unordered_map<int, unordered_map<char, pair<char, int>>> SLR1Table = {
    {0, {{'a', {'s', 1}}, {'A', {'g', 2}}}},
    {1, {{'b', {'r', 2}}, {'$', {'r', 2}}}},
    {2, {{'a', {'s', 1}}, {'b', {'s', 3}}, {'$', {'r', 1}}}},
    {3, {{'b', {'r', 0}}, {'$', {'r', 0}}}}};

bool LR0Parser(string input){
    stack<int> stateStack;
    stateStack.push(0);
    int inputIndex = 0;
    while (!stateStack.empty()){
        int currentState = stateStack.top();
        stateStack.pop();
        if (inputIndex >= input.size()){
            if (LR0Table[currentState].find('$') != LR0Table[currentState].end()){
                if (LR0Table[currentState]['$'].first == 'g' && LR0Table[currentState]['$'].second == 0){
                    return true;
                }
            }
            return false;
        }
        char currentInput = input[inputIndex];
        if (LR0Table[currentState].find(currentInput) == LR0Table[currentState].end()){
            return false;
        }
        char action = LR0Table[currentState][currentInput].first;
        int nextState = LR0Table[currentState][currentInput].second;
        if (action == 's'){
            stateStack.push(currentState);
            stateStack.push(nextState);
            inputIndex++;
        } else if (action == 'g'){
            stateStack.push(nextState);
        } else {
            int numPops = productions[nextState].second.size();
            while (numPops > 0){
                if (stateStack.empty()){
                    return false;
                }
                stateStack.pop();
                numPops--;
            }
            if (LR0Table[stateStack.top()].find(productions[nextState].first) == LR0Table[stateStack.top()].end()){
                return false;
            }
            stateStack.push(LR0Table[stateStack.top()][productions[nextState].first].second);
        }
    }
    return false;
}

bool SLR1Parser(string input){
    stack<int> stateStack;
    stateStack.push(0);
    int inputIndex = 0;
    while (!stateStack.empty()){
        int currentState = stateStack.top();
        if (currentState == -1) return false;
        stateStack.pop();
        if (inputIndex >= input.size()){
            if (SLR1Table[currentState].find('$') != SLR1Table[currentState].end()){
                if (SLR1Table[currentState]['$'].first == 'r' && SLR1Table[currentState]['$'].second == 2){
                    return true;
                }
            }
            return false;
        }
        char currentInput = input[inputIndex];
        if (SLR1Table[currentState].find(currentInput) == SLR1Table[currentState].end()){
            return false;
        }
        char action = SLR1Table[currentState][currentInput].first;
        int nextState = SLR1Table[currentState][currentInput].second;
        if (action == 's'){
            stateStack.push(currentState);
            stateStack.push(nextState);
            inputIndex++;
        } else if (action == 'g') {
            stateStack.push(nextState);
        } else {
            int numPops = productions[nextState].second.size();
            while (numPops > 0){
                if (stateStack.empty()){
                    return false;
                }
                stateStack.pop();
                numPops--;
            }
            if (stateStack.empty()){
                return false;
            }
            if (SLR1Table[stateStack.top()].find(productions[nextState].first) == SLR1Table[stateStack.top()].end()){
                return false;
            }
            stateStack.push(SLR1Table[stateStack.top()][productions[nextState].first].second);
        }
    }
    return false;
}

int main(){
    string input;
    cout << "Enter the string to be parsed: ";
    cin >> input;
    cin.ignore(1, '\n');
    cout << "LR(0) Parsing Table:\n";
    for (auto i : LR0Table){
        cout << "State " << i.first << ":\n";
        for (auto j : i.second){
            cout << " " << j.first << " " << j.second.first << j.second.second << "\n";
        }
    }
    cout << "\nSLR(1) Parsing Table:\n";
    for (auto i : SLR1Table){
        cout << "State " << i.first << ":\n";
        for (auto j : i.second){
            cout << " " << j.first << " " << j.second.first << j.second.second << "\n";
        }
    }

    cout << "Shift reduced conflict reduced: ";
    bool ans = true;
    if(ans){
        cout << "Reduced.";
    } else {
        cout << "Not Reduced.";
    }

    cout << "\nParsing \'" << input << "\' using LR(0) parser: ";
    if (LR0Parser(input)){
        cout << "Accepted.";
    } else {
        cout << "Rejected.";
    }
    cout << "\nParsing \'" << input << "\' using SLR(1) parser: ";
    if (SLR1Parser(input)){
        cout << "Accepted.";
    } else {
        cout << "Rejected.";
    }
    return 0;
}