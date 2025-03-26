
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char filename[] = &quot;file.txt&quot;;
    int new_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; // rw-rw-r--

    if (chmod(filename, new_permissions) == 0) {
        printf(&quot;File permissions changed successfully.\n&quot;);
    } else {
        perror(&quot;chmod&quot;);
        return 1;
    }

    return 0;
}
```
