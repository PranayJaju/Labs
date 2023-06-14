#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} n;

n* create_node(char data, int freq) 
{
    n* node = (n*) malloc(sizeof(n));
    *node = (n) {data, freq, NULL, NULL};
    return node;
}

n* build_tree(char data[], int freq[], int len) 
{
    n *nodes[len], *temp;
    for (int i = 0; i < len; i++) nodes[i] = create_node(data[i], freq[i]);
    
    int num_nodes = len;
    while (num_nodes > 1) 
    {
        int min1 = 0, min2 = 1;
        if (nodes[min1]->freq > nodes[min2]->freq) min1 = 1, min2 = 0;
        
        for (int i = 2; i < num_nodes; i++) 
        {
            if (nodes[i]->freq < nodes[min1]->freq) min2 = min1, min1 = i;
            else if (nodes[i]->freq < nodes[min2]->freq) min2 = i;
        }

        temp = create_node('%', nodes[min1]->freq + nodes[min2]->freq);
        temp->left = nodes[min1];
        temp->right = nodes[min2];
        nodes[min1] = temp;
        nodes[min2] = nodes[num_nodes-1];
        num_nodes--;
    }
    return nodes[0];
}

void print_codes(n* root, char prefix[], int prefix_len) {
    if (root) {
        if (root->data != '%') 
        {
            prefix[prefix_len] = '\0';
            printf("%c: %s\n", root->data, prefix);
        }
        
        prefix[prefix_len] = '0';
        print_codes(root->left, prefix, prefix_len+1);
        
        prefix[prefix_len] = '1';
        print_codes(root->right, prefix, prefix_len+1);
    }
}

int main() 
{
    char data[MAX_SIZE];
    int freq[MAX_SIZE], len;

    printf("Enter the number of characters: ");
    scanf("%d", &len);
    
    printf("Enter the characters and their frequencies:\n");
    for (int i = 0; i < len; i++) scanf(" %c %d", &data[i], &freq[i]);
    
    n* root = build_tree(data, freq, len);
    char prefix[MAX_SIZE];
    
    printf("Huffman codes:\n");
    print_codes(root, prefix, 0);
    return 0;
}