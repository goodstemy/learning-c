# Linked list

# Tests:

```bash
docker build --tag 'c-linked-list' . && docker run c-linked-list
```

# Performance:

`append(int, List*)` - O(n)

`prepend(int, List*)` - O(1)

`appendAt(int, int, List*)` - O(n)

# About

Naive implementation of linked list on c. Size >= 1 only if head created. Otherwise size = 0;