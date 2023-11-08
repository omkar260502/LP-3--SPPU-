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

pair<char, int> encode(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCode[root->data] = code;
        return make_pair(root->data, root->freq);
    }
    auto left_pair = encode(root->left, code + "0", huffmanCode);
    auto right_pair = encode(root->right, code + "1", huffmanCode);

    return make_pair('\0', left_pair.second + right_pair.second);
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

    while (!pq.empty())
    {
        cout << pq.top()->freq << " ";
        pq.pop();
        // Node *left = pq.top();
        // pq.pop();
        // Node *right = pq.top();
        // pq.pop();
        // Node *parent = new Node('$', left->freq + right->freq);
        // parent->left = left;
        // parent->right = right;
        // pq.push(parent);
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
        cout << entry.first << ": " << entry.second << ", Count: " << count(text.begin(), text.end(), entry.first) << endl;
    }

    string encodedMessage = encodeMessage(text, huffmanCode);
    cout << "\nEncoded Message: " << encodedMessage << endl;

    return 0;
}
/*
The overall time complexity of the provided code is \(O(n + k \log k)\), and the overall space complexity is \(O(k + n)\), where:

- n is the length of the input text.
- k is the number of unique characters in the input text.
*/
