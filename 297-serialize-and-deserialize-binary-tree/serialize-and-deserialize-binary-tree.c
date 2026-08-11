static char* tokens;
static char* ptr;

void encode(struct TreeNode* root, char* res, int* pos) {
    if (!root) {
        (*pos) += sprintf(res + *pos, "#,");
        return;
    }

    (*pos) += sprintf(res + *pos, "%d,", root->val);

    encode(root->left, res, pos);
    encode(root->right, res, pos);
}

struct TreeNode* decode() {
    if (*ptr == '#') {
        ptr += 2;
        return NULL;
    }

    int sign = 1;
    int val = 0;

    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }

    while (*ptr >= '0' && *ptr <= '9') {
        val = val * 10 + (*ptr - '0');
        ptr++;
    }

    ptr++;

    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val * sign;
    node->left = decode();
    node->right = decode();

    return node;
}

char* serialize(struct TreeNode* root) {
    char* res = malloc(300000);
    int pos = 0;

    encode(root, res, &pos);

    return res;
}

struct TreeNode* deserialize(char* data) {
    ptr = data;
    return decode();
}