/*Name : Prachi Mehetre
Roll no. : 47
Class : TY-B2
Assignment 3 : Develop a program to implement Huffman Encoding using a greedy strategy.
*/
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

// Function to create a new tree node
Node* createNode(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

// Comparison function for the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;  // lower frequency has higher priority
    }
};

// Function to store Huffman Codes by traversing the Huffman Tree
void storeCodes(Node* root, string code, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr) return;

    // If the node is a leaf, store the code
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCode[root->ch] = code;
    }

    // Recursive traversal for left and right children
    storeCodes(root->left, code + "0", huffmanCode);
    storeCodes(root->right, code + "1", huffmanCode);
}

// Main function to build the Huffman Tree and calculate the average code length
void buildHuffmanTree(const string &text) {
    // Step 1: Count frequency of each character
    unordered_map<char, int> frequency;
    for (char ch : text) {
        frequency[ch]++;
    }

    // Step 2: Create a priority queue and push all characters as leaf nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto &pair : frequency) {
        pq.push(createNode(pair.first, pair.second));
    }

    // Step 3: Build the Huffman Tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node with left and right children
        int combinedFreq = left->freq + right->freq;
        pq.push(createNode('\0', combinedFreq, left, right));
    }

    // Root of the Huffman Tree
    Node* root = pq.top();

    // Step 4: Traverse the Huffman Tree and store codes
    unordered_map<char, string> huffmanCode;
    storeCodes(root, "", huffmanCode);

    // Step 5: Display the Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto &pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Step 6: Calculate the average code length
    double totalLength = 0;
    int totalFrequency = 0;
    for (auto &pair : frequency) {
        char ch = pair.first;
        int freq = pair.second;
        int codeLength = huffmanCode[ch].length();

        totalLength += freq * codeLength;
        totalFrequency += freq;
    }
    double averageCodeLength = totalLength / totalFrequency;
    
    cout << "\nOriginal string:\n" << text << "\n";
    cout << "Average code length per character: " << averageCodeLength << "\n";
}

int main() {
    string text;
    cout << "Enter a string to encode: ";
    getline(cin, text);
    buildHuffmanTree(text);
    return 0;
}
/*
OUTPUT :
Enter a string to encode: bcaadddccacacac
Huffman Codes:
a: 11
d: 101
b: 100
c: 0

Original string:
bcaadddccacacac
Average code length per character: 1.86667

*/