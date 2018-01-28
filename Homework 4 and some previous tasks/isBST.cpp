bool left(Node* root, int pdata) {
    if (root == NULL) return true;
    if (root->data >= pdata) return false;
    return left(root->left, root->data) && left(root->left, pdata) && left(root->right, pdata) && right(root->right, root->data);
}

bool right(Node* root, int pdata) {
    if (root == NULL) return true;
    if (root->data <= pdata) return false;
    return right(root->right, root->data) && right(root->right, pdata) && right(root->left, pdata) && left(root->left, root->data);
}

bool checkBST(Node* root) {
	return (left(root->left, root->data) && right(root->right, root->data));
}
