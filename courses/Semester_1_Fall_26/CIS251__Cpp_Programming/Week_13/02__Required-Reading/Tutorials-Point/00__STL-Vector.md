# C++ Library - `<vector>`

[Previous](https://tutorialspoint.com/cpp_standard_library/unordered_multiset.htm) | 
[Quiz](https://tutorialspoint.com/cpp_standard_library/quiz_on_vector.htm "Practice Quiz on C++ Library - `<vector>`") | 
[Next](https://tutorialspoint.com/cpp_standard_library/algorithm.htm)

## Introduction

Vectors are sequence container that can change size. Container is a objects that hold data of same type. Sequence containers store elements strictly in linear sequence.

Vector stores elements in contiguous memory locations and enables direct access to any element using subscript operator \[\]. Unlike array, vector can shrink or expand as needed at run time. The storage of the vector is handled automatically.

To support shrink and expand functionality at runtime, vector container may allocate some extra storage to accommodate for possible growth thus container have actual capacity greater than the size. Therefore, compared to array, vector consumes more memory in exchange for the ability to manage storage and grow dynamically in an efficient way.

Zero sized vectors are also valid. In that case vector.begin() and vector.end() points to same location. But behavior of calling front() or back() is undefined.

## Definition

Below is definition of std::vector from `<vector>` header file

```cpp
template < class T, class Alloc = allocator<T> > class vector;
```

## Parameters

*   **T** − Type of the element contained.
    
    T may be substituted by any other data type including user-defined type.
    
*   **Alloc** − Type of allocator object.
    
    By default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent.
    

## Member types

Following member types can be used as parameters or return type by member functions.

| Sr.No. | Member types | Definition |
| --- | --- | --- |
| 1   | value\_type | T (First parameter of the template) |
| 2   | allocator\_type | Alloc (Second parameter of the template) |
| 3   | reference | value\_type& |
| 4   | const\_reference | const value\_type& |
| 5   | pointer | value\_type\* |
| 6   | const\_pointer | const value\_type\* |
| 7   | iterator | a random access iterator to value\_type |
| 8   | const\_iterator | a random access iterator to const value\_type |
| 9   | reverse\_iterator | std::reverse\_iterator <iterator> |
| 10  | const\_reverse\_iterator | std::reverse\_iterator <const\_iterator> |
| 11  | size\_type | size\_t |
| 12  | difference\_type | ptrdiff\_t |

## Functions from `<vector>`

Below is list of all methods from `<vector>` header.

### Constructors

| Sr.No. | Method & Description |
| --- | --- |
| 1   | [vector::vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_default_constructor.htm) default constructor<br><br>Constructs an empty container, with zero elements. |
| 2   | [vector::vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_fill_constructor.htm) fill constructor<br><br>Constructs a container with n elements and assignd val to each element. |
| 3   | [vector::vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_range_constructor.htm) range constructor<br><br>Constructs a container with as many elements in range of first to last. |
| 4   | [vector::vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_copy_constructor.htm) copy constructor<br><br>Constructs a container with copy of each elements present in existing container x. |
| 5   | [vector::vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_move_constructor.htm) move constructor<br><br>Constructs the container with the contents of other using move semantics. |
| 6   | [vector::vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_initializer_constructor.htm) initializer list constructor<br><br>Constructs a container from initializer list. |

### Destructor

| Sr.No. | Method & Description |
| --- | --- |
| 1   | [vector::~vector](https://tutorialspoint.com/cpp_standard_library/cpp_vector_destructor.htm)<br><br>Destroys container by deallocating container memory. |

### Member functions

| Sr.No. | Method & Description |
| --- | --- |
| 1   | [vector::assign](https://tutorialspoint.com/cpp_standard_library/cpp_vector_assign_fill.htm) fill version<br><br>Assign new values to the vector elements by replacing old ones. |
| 2   | [vector::assign](https://tutorialspoint.com/cpp_standard_library/cpp_vector_assign_range.htm) range version<br><br>Assign new values to the vector elements by replacing old ones. |
| 3   | [vector::assign](https://tutorialspoint.com/cpp_standard_library/cpp_vector_assign_initializer_list.htm) initializer list version<br><br>Assign new values to the vector elements by replacing old ones. |
| 4   | [vector::at](https://tutorialspoint.com/cpp_standard_library/cpp_vector_at.htm)<br><br>Returns reference to the element present at location n in the vector. |
| 5   | [vector::back](https://tutorialspoint.com/cpp_standard_library/cpp_vector_back.htm)<br><br>Returns a reference to the last element of the vector. |
| 6   | [vector::begin](https://tutorialspoint.com/cpp_standard_library/cpp_vector_begin.htm)<br><br>Return a random access iterator pointing to the first element of the vector. |
| 7   | [vector::capacity](https://tutorialspoint.com/cpp_standard_library/cpp_vector_capacity.htm)<br><br>Returns the size of allocate storage, expressed in terms of elements. |
| 8   | [vector::cbegin](https://tutorialspoint.com/cpp_standard_library/cpp_vector_cbegin.htm)<br><br>Returns a constant random access iterator which points to the beginning of the vector. |
| 9   | [vector::cend](https://tutorialspoint.com/cpp_standard_library/cpp_vector_cend.htm)<br><br>Returns a constant random access iterator which points to the beginning of the vector. |
| 10  | [vector::clear](https://tutorialspoint.com/cpp_standard_library/cpp_vector_clear.htm)<br><br>Destroys the vector by removing all elements from the vector and sets size of vector to zero. |
| 11  | [vector::crbegin](https://tutorialspoint.com/cpp_standard_library/cpp_vector_crbegin.htm)<br><br>Returns a constant reverse iterator which points to the reverser beginning of the container. |
| 12  | [vector::crend](https://tutorialspoint.com/cpp_standard_library/cpp_vector_crend.htm)<br><br>Returns a constant reverse iterator which points to the reverse end of the vector. |
| 13  | [vector::data](https://tutorialspoint.com/cpp_standard_library/cpp_vector_data.htm)<br><br>Returns a pointer to the first element of the vector container. |
| 14  | [vector::emplace](https://tutorialspoint.com/cpp_standard_library/cpp_vector_emplace.htm)<br><br>Extends container by inserting new element at position. |
| 15  | [vector::emplace\_back](https://tutorialspoint.com/cpp_standard_library/cpp_vector_emplace_back.htm)<br><br>Inserts new element at the end of vector. |
| 16  | [vector::empty](https://tutorialspoint.com/cpp_standard_library/cpp_vector_empty.htm)<br><br>Tests whether vector is empty or not. |
| 17  | [vector::end](https://tutorialspoint.com/cpp_standard_library/cpp_vector_end.htm)<br><br>Returns an iterator which points to past-the-end element in the vector container. |
| 18  | [vector::erase](https://tutorialspoint.com/cpp_standard_library/cpp_vector_erase_position.htm) position version<br><br>Removes single element from the the vector. |
| 19  | [vector::erase](https://tutorialspoint.com/cpp_standard_library/cpp_vector_erase_range.htm) range version<br><br>Removes single element from the the vector. |
| 20  | [vector::front](https://tutorialspoint.com/cpp_standard_library/cpp_vector_front.htm)<br><br>Returns a reference to the first element of the vector. |
| 21  | [vector::get\_allocator](https://tutorialspoint.com/cpp_standard_library/cpp_vector_get_allocator.htm)<br><br>Returns an allocator associated with vector. |
| 22  | [vector::insert](https://tutorialspoint.com/cpp_standard_library/cpp_vector_insert_single_element.htm) single element version<br><br>Extends iterator by inserting new element at position. |
| 23  | [vector::insert](https://tutorialspoint.com/cpp_standard_library/cpp_vector_insert_fill.htm) fill version<br><br>Extends vector by inserting new element in the container. |
| 24  | [vector::insert](https://tutorialspoint.com/cpp_standard_library/cpp_vector_insert_range.htm) range version<br><br>Extends vector by inserting new element in the container. |
| 25  | [vector::insert](https://tutorialspoint.com/cpp_standard_library/cpp_vector_insert_move.htm) move version<br><br>Extends vector by inserting new element in the container. |
| 26  | [vector::insert](https://tutorialspoint.com/cpp_standard_library/cpp_vector_insert_initializer_list.htm) initializer list version<br><br>Extends vector by inserting new element in the container. |
| 27  | [vector::max\_size](https://tutorialspoint.com/cpp_standard_library/cpp_vector_max_size.htm)<br><br>Returns the maximum number of elements can be held by vector. |
| 28  | [vector::operator=](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_assignment_copy.htm) copy version<br><br>Assign new contents to the vector by replacing old ones and modifies size if necessary. |
| 29  | [vector::operator=](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_assignment_move.htm) move version<br><br>Assign new contents to the vector by replacing old ones and modifies size if necessary. |
| 30  | [vector::operator =](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_assignment_initializer_list.htm) initializer list version<br><br>Assign new contents to the vector by replacing old ones and modifies size if necessary. |
| 31  | [vector::operator\[\]](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_subscript.htm)<br><br>Returns a reference to the element present at location n. |
| 32  | [vector::pop\_back](https://tutorialspoint.com/cpp_standard_library/cpp_vector_pop_back.htm)<br><br>Removes last element from vector and reduces size of vector by one. |
| 33  | [vector::push\_back](https://tutorialspoint.com/cpp_standard_library/cpp_vector_push_back.htm)<br><br>Inserts new element at the end of vector and increases size of vector by one. |
| 34  | [vector::rbegin](https://tutorialspoint.com/cpp_standard_library/cpp_vector_rbegin.htm)<br><br>Returns a reverse iterator which points to the last element of the vector. |
| 35  | [vector::rend](https://tutorialspoint.com/cpp_standard_library/cpp_vector_rend.htm)<br><br>Returns a reverse iterator which points to the reverse end of the vector. |
| 36  | [vector::reserve](https://tutorialspoint.com/cpp_standard_library/cpp_vector_reserve.htm)<br><br>Requests to reserve vector capacity be at least enough to contain n elements. |
| 37  | [vector::resize](https://tutorialspoint.com/cpp_standard_library/cpp_vector_resize.htm)<br><br>Changes the size of vector. |
| 38  | [vector::shrink\_to\_fit](https://tutorialspoint.com/cpp_standard_library/cpp_vector_shrink_to_fit.htm)<br><br>Requests the container to reduce it's capacity to fit its size. |
| 39  | [vector::size](https://tutorialspoint.com/cpp_standard_library/cpp_vector_size.htm)<br><br>Returns the number of elements present in the vector. |
| 40  | [vector::swap](https://tutorialspoint.com/cpp_standard_library/cpp_vector_swap.htm)<br><br>Exchanges the content of vector with contents of vector x. |

### Non-member overloaded functions

| Sr.No. | Method & Description |
| --- | --- |
| 1   | [operator ==](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_equal_to.htm)<br><br>Tests whether two vectors are equal or not. |
| 2   | [operator !=](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_not_equal_to.htm)<br><br>Tests whether two vectors are equal or not. |
| 3   | [operator <](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_less_than.htm)<br><br>Tests whether first vector is less than other or not. |
| 4   | [operator <=](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_less_than_or_equal_to.htm)<br><br>Tests whether first vector is less than or equal to other or not. |
| 5   | [operator >](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_greater_than.htm)<br><br>Tests whether first vector is greater than other or not. |
| 6   | [operator >=](https://tutorialspoint.com/cpp_standard_library/cpp_vector_operator_greater_than_or_equal_to.htm)<br><br>Tests whether first vector is greater than or equal to other or not. |
| 7   | [swap](https://tutorialspoint.com/cpp_standard_library/cpp_vector_swap_vector.htm)<br><br>Exchanges the contents of two vector. |