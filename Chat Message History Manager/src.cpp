// Chat Message History Manager
// Concept: Store messages, allow undo/redo of sent messages.
// Tech: Uses queue for incoming messages, stack for undo/redo actions, and timestamp tracking.
// Build: g++ -std=c++17 -O2 chatmgr.cpp -o chatmgr
// Run:   ./chatmgr

#include <bits/stdc++.h>
using namespace std;

struct Message {
    int id;
    string text;
    time_t timestamp;
};

class ChatManager {
    int nextMsgId = 1;
    queue<Message> inbox;                // incoming messages
    vector<Message> sentHistory;         // all sent messages
    stack<Message> undoStack;            // for undo
    stack<Message> redoStack;            // for redo

public:
    void receiveMessage(const string &text) {
        Message m{nextMsgId++, text, time(nullptr)};
        inbox.push(m);
        cout << "Received message queued: [" << m.text << "]\n";
    }

    void sendMessage() {
        if (inbox.empty()) {
            cout << "No incoming messages to send.\n";
            return;
        }
        Message m = inbox.front();
        inbox.pop();
        sentHistory.push_back(m);
        undoStack.push(m);
        while (!redoStack.empty()) redoStack.pop(); // clear redo history after new send
        cout << "Sent: [" << m.text << "] at " << ctime(&m.timestamp);
    }

    void undoLast() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }
        Message m = undoStack.top();
        undoStack.pop();
        redoStack.push(m);
        // remove from sentHistory
        if (!sentHistory.empty() && sentHistory.back().id == m.id)
            sentHistory.pop_back();
        cout << "Undo: [" << m.text << "]\n";
    }

    void redoLast() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }
        Message m = redoStack.top();
        redoStack.pop();
        sentHistory.push_back(m);
        undoStack.push(m);
        cout << "Redo: [" << m.text << "]\n";
    }

    void showInbox() {
        cout << "\nInbox Messages (queue):\n";
        if (inbox.empty()) { cout << "(empty)\n"; return; }
        auto q = inbox;
        while (!q.empty()) {
            auto m = q.front(); q.pop();
            cout << "#" << m.id << " [" << m.text << "]\n";
        }
    }

    void showHistory() {
        cout << "\nSent History:\n";
        if (sentHistory.empty()) { cout << "(none)\n"; return; }
        for (auto &m : sentHistory) {
            cout << "#" << m.id << " [" << m.text << "] at " << ctime(&m.timestamp);
        }
    }
};

int main() {
    ChatManager cm;
    while (true) {
        cout << "\n1) Receive Message  2) Send Message  3) Undo  4) Redo  5) Show Inbox  6) Show History  0) Exit\nChoice: ";
        int c; cin >> c;
        if (!cin) break;
        if (c==0) break;
        if (c==1) {
            cout << "Enter message: ";
            string text; cin.ignore(); getline(cin, text);
            cm.receiveMessage(text);
        } else if (c==2) cm.sendMessage();
        else if (c==3) cm.undoLast();
        else if (c==4) cm.redoLast();
        else if (c==5) cm.showInbox();
        else if (c==6) cm.showHistory();
    }
}
