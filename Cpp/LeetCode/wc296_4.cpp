#include "usual.h"

class TextEditor {
    list<char> l;
    list<char>::iterator p;

public:
    TextEditor(): p(l.end()) {

    }
    
    void addText(string text) {
        for (const auto& c : text) {
            l.insert(p, c);
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while (cnt < k && p != l.begin()) {
            p = prev(p);
            ++cnt;
            p = l.erase(p);
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        for (int i = 0; i < k && p != l.begin(); ++i) {
            p = prev(p);
        }
        string ans;
        auto q = p;
        for (int i = 0; i < 10 && q != l.begin(); ++i) {
            q = prev(q);
            ans.push_back(*q);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        for (int i = 0; i < k && p != l.end(); ++i) {
            p = next(p);
        }
        string ans;
        auto q = p;
        for (int i = 0; i < 10 && q != l.begin(); ++i) {
            q = prev(q);
            ans.push_back(*q);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TextEditor textEditor = TextEditor(); // 当前 text 为 "|" 。（'|' 字符表示光标）
    textEditor.addText("leetcode"); // 当前文本为 "leetcode|" 。
    textEditor.deleteText(4); // 返回 4
                            // 当前文本为 "leet|" 。
                            // 删除了 4 个字符。
    textEditor.addText("practice"); // 当前文本为 "leetpractice|" 。
    textEditor.cursorRight(3); // 返回 "etpractice"
                            // 当前文本为 "leetpractice|". 
                            // 光标无法移动到文本以外，所以无法移动。
                            // "etpractice" 是光标左边的 10 个字符。
    textEditor.cursorLeft(8); // 返回 "leet"
                            // 当前文本为 "leet|practice" 。
                            // "leet" 是光标左边的 min(10, 4) = 4 个字符。
    textEditor.deleteText(10); // 返回 4
                            // 当前文本为 "|practice" 。
                            // 只有 4 个字符被删除了。
    textEditor.cursorLeft(2); // 返回 ""
                            // 当前文本为 "|practice" 。
                            // 光标无法移动到文本以外，所以无法移动。
                            // "" 是光标左边的 min(10, 0) = 0 个字符。
    textEditor.cursorRight(6); // 返回 "practi"
                            // 当前文本为 "practi|ce" 。
                            // "practi" 是光标左边的 min(10, 6) = 6 个字符。
    return 0;
}
