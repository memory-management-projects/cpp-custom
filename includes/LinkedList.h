#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

namespace cpp_custom {
class LinkedList {
public:
    struct Node {
        Node *m_Next;
        std::size_t m_Value;
    };
    Node *m_Head;

    void SearchFirst(const std::size_t v, Node *&curr, Node *&prev);
    void SearchBest(const std::size_t v, Node *&curr, Node *&prev);
};
} // namespace cpp_custom

#endif // !LINKED_LIST_H
