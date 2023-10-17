#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void encode(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCode[root->data] = code;
        return;
    }
    encode(root->left, code + "0", huffmanCode);
    encode(root->right, code + "1", huffmanCode);
}

unordered_map<char, string> buildHuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char c : text)
    {
        freq[c]++;
    }

    priority_queue<Node *, vector<Node *>, CompareNodes> pq;
    for (auto entry : freq)
    {
        pq.push(new Node(entry.first, entry.second));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    Node *root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    return huffmanCode;
}

string encodeMessage(string text, unordered_map<char, string> &huffmanCode)
{
    string encodedMessage = "";
    for (char c : text)
    {
        encodedMessage += huffmanCode[c];
    }
    return encodedMessage;
}

int main()
{
    string text;
    cout << "Enter the text you want to encode: ";
    cin >> text;

    unordered_map<char, string> huffmanCode = buildHuffmanTree(text);

    cout << "Huffman Codes:" << endl;
    for (auto entry : huffmanCode)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    string encodedMessage = encodeMessage(text, huffmanCode);
    cout << "\nEncoded Message: " << encodedMessage << endl;

    return 0;
}
