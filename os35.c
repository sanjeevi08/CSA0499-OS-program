#include <stdio.h>
#include <stdlib.h>

// Structure to represent a block
struct Block {
    int blockNumber;
    char data[256]; // Adjust the size as needed for your blocks
};

int main() {
    FILE *file;
    struct Block block;
    int blockNumber;
    // Create an index block that contains pointers to data blocks
    long indexBlock[100] = {0}; // Adjust the size as needed

    // Open or create a file in write mode (for writing blocks)
    file = fopen(&quot;indexed_file.txt&quot;, &quot;w&quot;);
    if (file == NULL) {
        printf(&quot;Error opening the file.\n&quot;);
        return 1;
    }

    // Write blocks and update the index block
    printf(&quot;Enter blocks (Enter '0' as block number to exit):\n&quot;);
    while (1) {
        printf(&quot;Block Number: &quot;);
        scanf(&quot;%d&quot;, &block.blockNumber);
        if (block.blockNumber == 0) {
            break;
        }

        // Input data for the block
        printf(&quot;Data: &quot;);
        scanf(&quot; %[^\n]&quot;, block.data);

        // Write the block to the file
        fwrite(&block, sizeof(struct Block), 1, file);

        // Update the index block with the pointer to the data block
        indexBlock[block.blockNumber] = ftell(file) - sizeof(struct Block);
    }
    fclose(file);

    // Reopen the file in read mode (for reading blocks)
    file = fopen(&quot;indexed_file.txt&quot;, &quot;r&quot;);
    if (file == NULL) {
        printf(&quot;Error opening the file.\n&quot;);
        return 1;
    }

    // Read a specific block from the file
    while (1) {
        printf(&quot;Enter the block number to read (0 to exit): &quot;);
        scanf(&quot;%d&quot;, &blockNumber);
        if (blockNumber == 0) {
            break;
        }
        if (indexBlock[blockNumber] == 0) {
            printf(&quot;Block not found.\n&quot;);
        } else {
            // Seek to the data block using the index block
            fseek(file, indexBlock[blockNumber], SEEK_SET);
            fread(&block, sizeof(struct Block), 1, file);
            printf(&quot;Block Number: %d\n&quot;, block.blockNumber);
            printf(&quot;Data: %s\n&quot;, block.data);
        }
    }
    fclose(file);
    return 0;
}
```
