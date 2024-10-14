#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// A tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Comparator for the priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; // Min-heap based on frequency
    }
};

// Function to generate Huffman codes
void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If this is a leaf node, store the character and its code
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = str;
    }

    // Traverse left and right
    generateCodes(root->left, str + "0", huffmanCodes);
    generateCodes(root->right, str + "1", huffmanCodes);
}

// Function to build the Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequencies) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Iterate until there is more than one node in the queue
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with these two nodes as children
        Node* internalNode = new Node('\0', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    // The remaining node is the root of the Huffman tree
    return minHeap.top();
}

// Function to encode the input string
string encode(const string& input, unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char ch : input) {
        encodedString += huffmanCodes[ch];
    }
    return encodedString;
}

// Function to decode the encoded string
string decode(Node* root, const string& encodedString) {
    string decodedString;
    Node* currentNode = root;

    for (char bit : encodedString) {
        currentNode = (bit == '0') ? currentNode->left : currentNode->right;

        // If we reach a leaf node
        if (!currentNode->left && !currentNode->right) {
            decodedString += currentNode->ch;
            currentNode = root; // Go back to the root
        }
    }
    return decodedString;
}

int main() {
    string input = "huffman coding example";
    unordered_map<char, int> frequencies;

    // Calculate frequency of each character
    for (char ch : input) {
        frequencies[ch]++;
    }

    // Build Huffman Tree
    Node* root = buildHuffmanTree(frequencies);

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Encode the input string
    string encodedString = encode(input, huffmanCodes);
    cout << "Encoded String: " << encodedString << endl;

    // Decode the encoded string
    string decodedString = decode(root, encodedString);
    cout << "Decoded String: " << decodedString << endl;

    return 0;
}
