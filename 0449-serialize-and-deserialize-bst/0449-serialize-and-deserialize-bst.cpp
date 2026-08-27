/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }

private:
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "#,";
            return;
        }
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    TreeNode* deserializeHelper(const string& data, int& pos) {
        // extract next token up to comma
        int commaPos = data.find(',', pos);
        string token = data.substr(pos, commaPos - pos);
        pos = commaPos + 1;

        if (token == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(data, pos);
        node->right = deserializeHelper(data, pos);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;