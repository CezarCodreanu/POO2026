#include <string>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    string text, separators = " ,.?!";
    getline(fin, text);

    map<string, int> words;

    string word = "";
    for (const char &ch : text) {
        if (separators.find(ch) != string::npos) {
            if (!word.empty()) {
                words[word]++; 
                word.clear();
            }       
        }
        else {
            word += tolower(ch);
        }
    }

    priority_queue<pair<int, string>, vector<pair<int,string>>, greater<pair<int,string>>> wordQueue;
    for (const auto &it : words) {
        wordQueue.push({-it.second, it.first});
    }

    while (!wordQueue.empty()) {
        fout << wordQueue.top().second << " => " << -wordQueue.top().first << endl;
        wordQueue.pop();
    }
    return 0;
}
