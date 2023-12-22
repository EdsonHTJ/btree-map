
# B-Tree Library

## Introduction
This library offers a versatile B-Tree implementation in C, ideal for efficient key-value storage and retrieval. It supports various key types, making it suitable for a wide range of applications.

## Building the Library
Compile the library with the following command:

```bash
make
```

## Usage Examples

### Adding and Finding an Entry
This example demonstrates how to add an entry to the B-Tree and retrieve it.

```c
btree_t* btree = new_btree();
add_entry(btree, "entry_1", sizeof("entry_1"), "value_1", sizeof("value_1"));
value_t* value = find_entry(btree, "entry_1", sizeof("entry_1"));
// Use 'value' as needed
free_tree(&btree);
```

### Working with Multiple Entries
Here's how to add multiple entries and list them.

```c
btree_t* btree = new_btree();
add_entry(btree, "entry_1", sizeof("entry_1"), "value_1", sizeof("value_1"));
// ... Add more entries
entry_list_t* list = list_entries(btree);
// Iterate over 'list' to access entries
free_entry_list(&list);
free_tree(&btree);
```

### Removing an Entry
This example shows how to remove an entry from the B-Tree.

```c
btree_t* btree = new_btree();
add_entry(btree, "entry_1", sizeof("entry_1"), "value_1", sizeof("value_1"));
remove_entry(btree, "entry_1", sizeof("entry_1"));
// 'entry_1' is now removed from the B-Tree
free_tree(&btree);
```

### Using Custom Key Types
The B-Tree can handle various key types. Here's an example using an integer key.

```c
btree_t* btree = new_btree();
uint32_t int_key = 123;
add_entry(btree, &int_key, sizeof(int_key), "value_123", sizeof("value_123"));
value_t* value = find_entry(btree, &int_key, sizeof(int_key));
// Use 'value' as needed
free_tree(&btree);
```

### Adding Custom Structs
You can also use custom structs as keys or values.

```c
typedef struct custom_key {
    uint32_t key_part1;
    uint32_t key_part2;
} custom_key_t;

btree_t* btree = new_btree();
custom_key_t my_key = {1, 2};
add_entry(btree, &my_key, sizeof(my_key), "custom_value", sizeof("custom_value"));
value_t* value = find_entry(btree, &my_key, sizeof(my_key));
// Use 'value' as needed
free_tree(&btree);
```

## License
MIT License

Copyright (c) [year] [fullname]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Contributions
Contributions to improve this library are welcome. Feel free to submit pull requests or raise issues.