#include <iostream>
#include <stack>
using namespace std;

const char SPACE = ' ';

int main()
{
    string sentence;
    cout << "Original sentence: "; // hope is what defines humanity
    getline(cin, sentence);
    cout << endl;

    string word;
    stack<string> wordStack;
    for (char c : sentence)
    {
        if (c == SPACE)
        {
            wordStack.push(word);
            word = "";
        }
        else
            word += c;
    }
    if (word != "")
        wordStack.push(word);

    cout << "New sentence: ";
    while (!wordStack.empty())
    {
        cout << wordStack.top() << SPACE;
        wordStack.pop();
    }
    cout << endl;
    return 0;
}